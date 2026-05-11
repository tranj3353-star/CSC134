make python code that uses opencv to read the video.mp4 file and then rescale to 160x120 res to then compress via rle + delta based encoding into a data.bin file... then gimme a comprehensive prompt that details the layout of the data.bin file exactly... its purely black and white bad apple so keep that in mind for the compression to save on cost... though i scraped it off  youtube so the video is probably 3 channel still

Grid
Function	Description
Grid(rows, cols, defaultValue)	Creates a flat-array 2D grid
resize(rows, cols)	Resizes the grid
modifyCell(x, y, value)	Sets cell value
getCell(x, y)	Gets cell value
clear(value)	Fills entire grid
filter2D(kernel)	Applies a convolution/filter kernel

Renderer
Function	Description
renderer::draw(grid)	Draws ASCII frame from grid
renderer::clearScreen()	Clears previous frame


PARSER API SUMMARY
Parser(path)
- Opens .bin file
- Reads BADV file header
Usage:
Parser parser("data.bin");
==================================================
getHeader()
- Returns video metadata:
  width
  height
  fps
  totalFrames
Usage:
auto h = parser.getHeader();
==================================================
readNextFrame(Frame& outFrame)
- Reads one frame
- Automatically:
  - reads frame header
  - RLE decodes payload
  - applies XOR delta restoration
  - reconstructs final frame
Returns:
- true  = success
- false = EOF/error
After decode:
frame.data.size() == 2400
(frame remains packed 1-bit data)
Usage:
Frame frame;
while (parser.readNextFrame(frame))
{
    // frame.data = reconstructed packed frame
}
==================================================
unpackBits()
- Converts packed frame -> raw pixels
Input:
2400-byte packed frame
Output:
19200 pixels
Pixel values:
0 = black
1 = white
Usage:
auto pixels = parser.unpackBits(frame.data);
Access:
pixels[y * width + x]
==================================================
PLAYBACK PIPELINE
Parser parser("data.bin");
auto header = parser.getHeader();
Frame frame;
while (parser.readNextFrame(frame))
{
    auto pixels = parser.unpackBits(frame.data);
    // render pixels
}
==================================================
SIZES
Packed frame:
160*120/8 = 2400 bytes
Unpacked frame:
160*120 = 19200 bytes
==================================================
FRAME TYPES
type 0:
- keyframe
- full frame
type 1:
- delta frame
- stores previous XOR current
Parser reconstructs delta frames automatically.

take the data.bin and use it to make an animation in the console
start here in main.cpp... use filter2d for 3d effect (emboss for example)

```cpp
#include "include/grid.h"
#include "include/renderer.h"
#include "include/parser.h"


```

write me 2 cpp files along with their headers (grid.cpp, renderer.cpp)

grid.cpp should have a flat array that represents a 2d grid (should be able to set rows and cols). Should have a modifyCell function that can get x and y and modify the location with a specific number or value. getCell that gets the value at the x and y location... Also give me a filter2d function that.... well yk... accepts an array as argument

renderer.cpp is ascii art... should get the grid and use it to draw to the entire grid... map the number values to characters (higher numbers equal higher brightness, 0 is empty). Clamp if needed. Draw the grid in a way so that if you drew it twice the second one will supercede the previous one (ie you can only see the next one)

renderer.cpp should have its own namespace renderer... I think I hit all bases for ascii animation utilitity right? Also please give me a short blurb tha summarizes all functions args and descrptions