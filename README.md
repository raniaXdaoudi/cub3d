# cub3D

A 3D graphical project using raycasting, inspired by the famous game Wolfenstein 3D. This project is part of the 42 school curriculum and is completed as a team project.

## Description

This project is inspired by the world-famous Wolfenstein 3D game, which was the first FPS ever. The goal is to create a dynamic view inside a maze using raycasting principles, teaching the fundamentals of graphics programming.

## Features

The program implements:
- Textured walls with different textures for each direction (North, South, East, West)
- Minimap display
- Player movement (forward, backward, strafe left/right)
- Camera rotation (left/right)
- Collision detection
- Floor and ceiling colors
- Clean window management
- Smooth window operations (closing, switching, etc.)

## Getting Started

### Prerequisites
- GCC compiler
- Make
- MinilibX library
- X11 development libraries
- Unix-based operating system (Linux/Mac)

### Installation
```bash
git clone https://github.com/yourusername/cub3d.git
cd cub3d
make
```

### Usage
```bash
./cub3D path_to_map.cub
```

### Map Format
The map must be composed of these characters:
- `0` for empty space
- `1` for walls
- `N`/`S`/`E`/`W` for player start position and orientation
- ` ` (space) for empty space outside the map

Example map:
```
NO ./path_to_north_texture
SO ./path_to_south_texture
WE ./path_to_west_texture
EA ./path_to_east_texture

F 220,100,0
C 225,30,0

        1111111111111111111111111
        1000000000110000000000001
        1011000001110000000000001
        1001000000000000000000001
111111111011000001110000000000001
100000000011000001110111111111111
11110111111111011100000010001
11110111111111011101010010001
11000000110101011100000010001
10000000000000001100000010001
10000000000000001101010010001
11000001110101011111011110N0111
11110111 1110101 101111010001
11111111 1111111 111111111111
```

## Controls
- `W` or `↑` : Move forward
- `S` or `↓` : Move backward
- `A` : Strafe left
- `D` : Strafe right
- `←` : Rotate camera left
- `→` : Rotate camera right
- `ESC` or click on cross : Exit game

## Implementation Details

The program uses:
1. Raycasting technique for 3D rendering
2. DDA (Digital Differential Analysis) algorithm for ray calculations
3. Texture mapping for walls
4. Collision detection system
5. Event handling for inputs
6. Memory management for resources
7. File parsing for map loading

## Error Handling
The program handles various error cases:
- Invalid map format
- Missing textures
- Invalid texture files
- Memory allocation failures
- Invalid colors
- Map validation (closed walls, single player position)
- File access errors

## Building
The project includes a Makefile with the following rules:
- `make` - Compiles the program
- `make clean` - Removes object files
- `make fclean` - Removes object files and executable
- `make re` - Rebuilds the program

## Technical Details
- Uses MinilibX for graphics rendering
- Implements raycasting for 3D effect
- Handles textures in XPM format
- Manages window events
- Optimized for smooth rendering
- Proper memory management

## Authors
- Rania (radaoudi)
- Tamsi (tbesson)

## License
This project is part of the 42 school curriculum. Please refer to 42's policies regarding code usage and distribution.

## Acknowledgments
- 42 school for providing the project requirements and framework
- Wolfenstein 3D for the inspiration
- MinilibX documentation and resources
- Raycasting tutorials and documentation
