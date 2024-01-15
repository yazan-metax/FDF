<h1 align="center">FDF "wireframe"🦾
</h1>


# introduction 🥸:)

### FDF - 3D Wireframe Landscape Visualization:

is an innovative project focused on the creation of a simplified 3D graphical representation of relief landscapes. This project primarily revolves around constructing a "wireframe" model, effectively transforming numerical data representing geographical landscapes into visually interpretable 3D models.

Key aspects of this project include:

`3D Graphic Programming:` Discovering the basics of graphic programming, including the manipulation and visualization of spatial data points.

`MiniLibX Usage:` Utilizing the MiniLibX library, developed internally, for creating basic graphical interfaces, pixel manipulation, and event handling,
[`click`](https://github.com/yazan-metax/minilibX) to know more about Minilibx

`Data Interpretation:` Transforming raw data from files into meaningful visual representations, providing insights into various landscapes.

`Customizability:` Offering users the ability to choose different types of projections for their landscape models, including parallel, isometric, and conic projections.

This project is an exploration of the intersection between data and visual representation, offering a unique perspective into the world of computer graphics and data visualization. It's an ideal project for those interested in graphics programming, data interpretation, and 3D modeling.

## 📂file structure:

### .c files 
- where all our c functions will be written in
### .h (header file)
- the header file is important to provide access to various functions from any file that the header is included in,that means we will not over write the function that we want to use in every file that doesn't include that specific function.
- we can include all the headers that we will be using in our program in the .h file instead of including them in every file that our program has.

### makefile
- A Makefile is a special file used in software development that contains a set of rules and dependencies to automate the build process of a program, ensuring that files are compiled in the correct order.

in summary the makefile is going to do:
- compiling: it compiles all the files in our program at once.
- cleaning:by running the "make clean" command, the make file will delete the object files, by running the "make fclean" command,the make file will delete the object files alongside the execuable file for our program.

<h1 align="center"> preview😎
</h1>
       
<p align="center">
  <img src="https://github.com/yazan-metax/FDF/blob/main/image/Screenshot%202024-01-15%20at%2002.27.32.png">
  <img src="https://github.com/yazan-metax/FDF/blob/main/image/art.png">
  <img src="https://github.com/yazan-metax/FDF/blob/main/image/pylone.png">
  <img src="https://github.com/yazan-metax/FDF/blob/main/image/art2.png">
  <img src="https://github.com/yazan-metax/FDF/blob/main/image/fract.png">
</p>

# usage⚙️:

### requirements:
- GCC Compiler: This is essential for compiling the C code. GCC is a widely used compiler that turns the source code into an executable program.
- C Libraries: These are found in the header files of the project. They provide necessary functions and definitions used throughout the program. Ensure that all required libraries are accessible and included as per the project's header files.
- Operating System Compatibility: Ensure the program is compatible with your operating system, whether it's a variant of Windows, macOS, or Linux.
- MiniLibX: This graphical library is necessary for the FDF program's graphical output. It must be properly installed and configured.
- Memory and Processor Specifications: Adequate RAM and CPU power are required for smooth execution, especially for rendering complex graphics.

### Instructions:

- installation: First, ensure that GCC, the necessary C libraries, and MiniLibX are installed on your system. Download the FDF program from its repository.
- Compilation: Use the Makefile to compile the program. In the terminal, navigate to the program directory and run the command make.
- Running the Program: After compilation, you can start the program by typing `./fdf [path to the map file]` in the terminal. Ensure you have a valid map file in the specified format.
- Interacting with the Program: Once the program is running, you can interact with the graphical interface. This include zooming, rotating, or adjusting the view of your 3D landscape.
- Closing the Program: Exit the program by closing the window or using an exit command.















