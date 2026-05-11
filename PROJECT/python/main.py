import cv2
import numpy as np
import struct

# ============================================================
# CONFIG
# ============================================================

INPUT_VIDEO = "video.mp4"
OUTPUT_FILE = "data.bin"

WIDTH = 160
HEIGHT = 120
FPS_LIMIT = None  # set to integer if you want to cap fps

THRESHOLD = 127  # black/white threshold

# ============================================================
# HELPERS
# ============================================================

def pack_bits(binary_frame):
    """
    Convert 0/1 array into packed bytes.
    8 pixels per byte.
    """
    flat = binary_frame.flatten().astype(np.uint8)

    pad = (8 - (len(flat) % 8)) % 8
    if pad:
        flat = np.pad(flat, (0, pad))

    packed = np.packbits(flat)
    return packed.tobytes()


def xor_frames(curr_bits, prev_bits):
    """
    Delta frame using XOR.
    1 bit = changed pixel
    0 bit = same pixel
    """
    return np.bitwise_xor(curr_bits, prev_bits)


def rle_encode(data):
    """
    Simple byte RLE.

    Encodes:
        [count][value]

    count = 1..255
    """
    if len(data) == 0:
        return b""

    out = bytearray()

    current = data[0]
    count = 1

    for b in data[1:]:
        if b == current and count < 255:
            count += 1
        else:
            out.append(count)
            out.append(current)
            current = b
            count = 1

    out.append(count)
    out.append(current)

    return bytes(out)


# ============================================================
# VIDEO LOAD
# ============================================================

cap = cv2.VideoCapture(INPUT_VIDEO)

if not cap.isOpened():
    raise RuntimeError(f"Failed to open {INPUT_VIDEO}")

source_fps = cap.get(cv2.CAP_PROP_FPS)

if FPS_LIMIT is None:
    target_fps = int(round(source_fps))
else:
    target_fps = FPS_LIMIT

frames = []

frame_index = 0
frame_skip = max(1, int(round(source_fps / target_fps)))

while True:
    ret, frame = cap.read()

    if not ret:
        break

    if frame_index % frame_skip != 0:
        frame_index += 1
        continue

    # ========================================================
    # PREPROCESS
    # ========================================================

    # resize
    frame = cv2.resize(frame, (WIDTH, HEIGHT),
                       interpolation=cv2.INTER_AREA)

    # grayscale
    gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)

    # threshold -> 0/1
    _, bw = cv2.threshold(gray, THRESHOLD, 1, cv2.THRESH_BINARY)

    frames.append(bw)

    frame_index += 1

cap.release()

print(f"Loaded {len(frames)} frames")

# ============================================================
# ENCODE
# ============================================================

with open(OUTPUT_FILE, "wb") as f:

    # ========================================================
    # FILE HEADER
    # ========================================================

    # magic
    f.write(b"BADV")

    # width, height
    f.write(struct.pack("<H", WIDTH))
    f.write(struct.pack("<H", HEIGHT))

    # fps
    f.write(struct.pack("<H", target_fps))

    # frame count
    f.write(struct.pack("<I", len(frames)))

    prev_bits = None

    for i, frame in enumerate(frames):

        # packed 1-bit frame
        packed = np.frombuffer(pack_bits(frame), dtype=np.uint8)

        # ====================================================
        # KEYFRAME
        # ====================================================

        if prev_bits is None:

            frame_type = 0

            compressed = rle_encode(packed.tobytes())

            # frame header
            f.write(struct.pack("<B", frame_type))
            f.write(struct.pack("<I", len(compressed)))

            # data
            f.write(compressed)

            prev_bits = packed.copy()

            print(f"[{i}] KEYFRAME {len(compressed)} bytes")

        # ====================================================
        # DELTA FRAME
        # ====================================================

        else:

            delta = xor_frames(packed, prev_bits)

            compressed = rle_encode(delta.tobytes())

            frame_type = 1

            # frame header
            f.write(struct.pack("<B", frame_type))
            f.write(struct.pack("<I", len(compressed)))

            # data
            f.write(compressed)

            prev_bits = packed.copy()

            print(f"[{i}] DELTA {len(compressed)} bytes")

print(f"\nFinished -> {OUTPUT_FILE}")