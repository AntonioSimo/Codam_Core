# cub3D
>My first RayCaster with miniLibX

**cub3D** is a project from the 42 coding school that introduces the fundamentals of 3D graphics using a technique called **raycasting**—similar to how early games like *Wolfenstein 3D* worked.  

The goal was to create a simple 3D graphical representation of a maze based on a 2D map, using the **MiniLibX** graphics library.  

This project was developed in **C** and carried out as a **team project of two people**, where we collaborated on implementing the core rendering engine, input handling, and map parsing system. 

The result is a lightweight yet functional 3D renderer capable of interpreting a custom map format and responding to real-time user input.

---

## Objectives
The main goal of this project was to recreate a simple 3D rendering engine from scratch using raycasting.
To achieve this, we focused on several key objectives:

- First, we needed to load and correctly parse a .cub map file, which contains all the configuration data: wall textures, colors, and the map layout itself.

- Then, we implemented a raycasting algorithm to project a 2D map into a pseudo-3D environment that the player can navigate in real time.

- We added user input controls, allowing the player to move using W, A, S, D keys and rotate the camera with the arrow keys—just like in classic first-person games.

- We also made sure that walls are textured based on their direction (North, South, East, or West), and that both floor and ceiling colors could be customized using RGB values.

- Finally, we paid close attention to smooth window behavior, ensuring that the application could be minimized, closed with ESC or the red cross, and exited cleanly at any time.

This combination of goals helped us dive deep into low-level graphics rendering and interactive programming in C.

## Features

-  Wall rendering with different textures per direction  
-  Configurable floor and ceiling colors  
-  Real-time player movement (W, A, S, D)  
-  Camera rotation with arrow keys  
-  Graceful exit via ESC key or red window cross  
-  Map parsing with full error handling  
-  Fully compliant with MiniLibX rendering  
-  Window remains responsive and interactive  

---

## Controls

| Key         | Action                |
|-------------|-----------------------|
| W         | Move forward          |
| S         | Move backward         |
| A         | Strafe left           |
| D         | Strafe right          |
| ← / →     | Rotate view           |
| ESC       | Exit the program      |
| 🟥 (Window X) | Exit the program      |

---

## Map Format (.cub file)
The .cub file is a key part of the project—it defines everything needed to render the scene. It includes texture paths, floor and ceiling colors, and the map layout itself. Here's how it must be structured:

## Texture Definitions
Each wall direction must be defined with a unique identifier followed by the relative path to its texture file:

```bash
NO ./path_to_north_texture
SO ./path_to_south_texture
WE ./path_to_west_texture
EA ./path_to_east_texture
```

## Floor and Ceiling Colors
Use RGB values (ranging from 0 to 255) to define the floor and ceiling colors:

```bash
F 220,100,0   # Floor color (R,G,B)
C 225,30,0    # Ceiling color (R,G,B)
```

## Map Layout
The actual map comes after the texture and color definitions. It must be a rectangular grid and fully enclosed by walls (1). Here's how the map characters work:

1 → Wall

0 → Empty space

N, S, E, W → Player’s spawn point and initial direction (North, South, East, West)

Minimal Example:
```bash
111111
100001
1000N1
111111
```

## Example of a Minimal .cub File
```bash
NO ./textures/north.xpm
SO ./textures/south.xpm
WE ./textures/west.xpm
EA ./textures/east.xpm
F 220,100,0
C 225,30,0

111111
100001
1000N1
111111
```

## Usage Example:

```bash
./cub3D maps/scene.cub
