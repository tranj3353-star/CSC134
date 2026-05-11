# Bad Apple ASCII (C++ Terminal Renderer)

A C++ terminal-based renderer for *Bad Apple!!* using a custom binary video format, ASCII mapping, and real-time convolution-based shading with an emboss kernel for a pseudo-3D effect.

---

## Features

- Decodes custom **BADV binary format** (RLE+DELTA)
- 1-bit monochrome video (160×120)
- XOR delta compression for high efficiency
- RLE decompression
- Real-time terminal ASCII rendering
- Emboss kernel for fake 3D lighting effect
- FPS-synced playback

---

## 3D Effect

The renderer applies a 3×3 emboss convolution kernel:
