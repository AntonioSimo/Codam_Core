# Fract’ol
>Computer Graphics Fractals

## Overview

The **Fract’ol** project challenges to create a program that renders beautiful and intricate fractals using the power of computer graphics. Specifically, to work with the **Julia set** and the **Mandelbrot set**, two of the most well-known and visually striking fractals. This project requires you to display these fractals in a graphical window, allowing the user to interact with them by zooming in and out, as well as experimenting with different parameters and color schemes.

### Key Features:
- **Julia and Mandelbrot Sets**: The program must render these two classic fractals. These sets are infinite in nature, meaning that by zooming in, you reveal more detail.
- **Zooming Functionality**: The mouse wheel allows zooming in and out of the fractals, showcasing the infinite nature of fractals.
- **Fractal Parameterization**: The user can generate different Julia sets by passing specific parameters to the program.
- **Interactive Window**: The rendered fractals will be displayed in a graphical window. The window management must be smooth, ensuring that users can easily switch between windows, minimize, or close them.
- **Exit Mechanism**: The program should cleanly close the window and exit when the user presses the "ESC" key or clicks on the close button of the window frame.

### Technical Requirements:
- **MiniLibX Library**: The project must use the **MiniLibX** graphics library, either the version provided on the school machines or by installing it from its source. This library will be responsible for creating the window, handling user input, and rendering the fractals.
- **Makefile**: The project must include a `Makefile` that compiles your source files efficiently, without unnecessary relinking.
- **No Global Variables**: The use of global variables is strictly forbidden to maintain clean and maintainable code.

### Parameters and Fractal Generation:
The program must take command-line arguments that specify the type of fractal to display. If no parameters are provided, or if the parameters are invalid, the program should display a list of available options and exit gracefully. These are the key parameters:

- **Fractal Type**: The program should support displaying the Julia set and the Mandelbrot set. 
- **Fractal Customization**: You can allow additional parameters for fine-tuning the rendering of the fractals, such as color schemes or zoom levels.
  
If no parameters are given or if invalid ones are provided, the program should show a list of valid options and exit properly without crashing.

### Color and Visual Effects:
- **Coloring**: Fractals are visually stunning, and experimenting with color schemes is part of the fun! This adds a visual dimension to the fractals, making the rendering process more engaging and interesting.

### Graphical Management:
- The fractal image should be displayed in a window, where users can interact with it smoothly.
- The program must ensure that switching between windows, minimizing, and closing the window is handled seamlessly.
- The **ESC** key should be used to close the window and quit the program cleanly.
- Clicking the close button (cross) on the window frame should also close the program properly.

### How to Run:
To run the program, you need to pass parameters via the command line:

```bash
./fractol [fractal_type] [additional_parameters]
```

- **[fractal_type]** can be either julia or mandelbrot.

- **[additional_parameters]** are optional parameters you can use to tweak the rendering of the fractal.

If no parameters are provided, or if the parameters are invalid, the program will display a list of available options.

Example:
```bash
./fractol julia
```

This command will display the default Julia set fractal.
