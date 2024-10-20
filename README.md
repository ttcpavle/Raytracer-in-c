# Simple ray-tracer in C
<p align="left">
    <img src="/Raytracer/renders/monkey.png" alt="Rendered image example - monkey" width="45%"/>
    <img src="/Raytracer/renders/cube.png" alt="Rendered image example - cube" width="45%"/>
</p>

## What does this program do
You can:
- read/export wavefront files (files used for 3d objects with .obj extension)
- do basic transformations on objects such as rotation, scale and translation
- render object with simple local renderer

## How to run (windows/unix/macOS)

1) Clone the repository in desired directory
 ```bash
 git clone https://github.com/ttcpavle/Raytracer-in-c.git
 ```
2) Navigate to build directory
3) Run:
```bash
cmake ..
```

After those steps:
- If you are using windows, open the `Raytracer.sln` solution (if visual studio was selected compiler). Select the Raytracer as startup project and run. Header files should appear in solution explorer under Header files. HINT: change mode from debug to release for much faster rendering.
- If you are using linux, run generated files for building a project. If cmake generated makefile, run `make` and than run the executable `./Raytracer`
<p>
Required software: <br>
Cmake installation: https://www.youtube.com/watch?v=8_X5Iq9niDE <br>
Git installation: https://www.youtube.com/watch?v=JgOs70Y7jew <br>
</p>


## How to use
Everything is controlled in `main()` function, there is no console or windows interface, this is only a simple rendering software. You can see in the example how things are set up:
1) Adjust settings in settings.h accoring to your preferences
2) Read object, set material, transform it and export it if you want
3) Set up objects array and lights array (currently rendering supports a single object and light)
4) Set up camera (point look_at which is where camera is looking, eye which is camera location, fov and aspect ratio ideally set to `(float)WIDTH/HEIGHT`
5) Render the scene (Color* is image which is array or flat memory matrix of colors)
6) Export image with `stbi_image_write()` which is available in stb_image_write.h library from Sean Barrett

- Info about functions is available in .h or .c files
- More render examples in Raytracer/renders/
- **REMEMBER TO EDIT SETTINGS.H**
- OpenMP library is used for multithreading, enabling faster rendering. If you are using Visual Studio on Windows, make sure to enable OpenMP support in **Project** -> **Raytracer Properties** -> **C/C++** -> **Language** -> **Open MP Support**. Currently, multithreading does not work on Linux. If you find a solution, feel free to contribute.

### Features:
- Faces are triangulated while reading wavefront (fan triangulation)
- Exported object will maintain triangulated faces
- Moller Trumbore algorithm is used for ray triangle intersection
- Gauss-Jordan algorithm is used for inverse matrix
- You can follow render progress on console
- Smooth shaded object (Gouraud shading)
- Project is tested on windows (visual studio) and linux fedora
- Multithreading on windows

### Not supported:
- preserving group information in .obj files
- reading .mtl files
- rendering multiple objects/lights and shadows
- preserving n-gon faces
- undo transforms

### Improvement to do:
- Render multiple objects/lights
- Better shading with isGlass information (reflection and refraction)
- Rendering equation (Monte Carlo integration)
- Origin of object fixes
- windows.h for GUI (im not too familiar with this library)
- maybe rewrite everything in OpenGL
- fix multithreading for linux
- Bounding Volume Hierarchy
- Anti-aliaising

## How does it work?
Here is a very quick explaination on how this c program outputs ray traced image:

The idea is that calculating all lights in scene only for some of it to hit the camera is way too much computationally expensive, so we actually fire rays from camera which is the reverse approach.
1. For each pixel in the image (represented as a matrix of color values, e.g., `{255, 255, 255}` for white), a ray is casted into the scene containing objects (for now 1 object).
2. The ray is a 3D vector originating from the camera origin and extending toward a potential hit point on an object.
3. The program checks for collisions with each object in the scene and each triangle that makes up the object.
4. If no object is hit, the background color is used for pixel color.
5. If object is hit, data such as the object's material (in this case, just the color), normal of the hit triangle, and light sources in scene are used to compute color for the pixel.
6. This process is repeated for each pixel in the image, resulting in a complete image, which is then exported as png/jpeg using stb library.

<div align="center">
    <img src="https://github.com/user-attachments/assets/7a77eea1-790b-4417-862f-ba9ec079a307" alt="Ray_trace_diagram svg">
</div>

This program operates on cpu but in practice gpu-s are used for this kind of parallelized operations. More detailed explaination on how object is transfomed and rendered will be available on wiki soon!

Here is some more info: https://developer.nvidia.com/discover/ray-tracing

## Project structure:
```
Raytracer
|
|   CMakeLists.txt           # used for building project with cmake
|   
+---build                    # folder for all build files ( visual studio debug and release, makefile, executable etc.).
|       .keep                # keep this empty folder
|                    
+---docs
|       Fast MinimumStorage RayTriangle Intersection.pdf       # documentation for Moller-Trumbore algorithm used in render.c
|       
+---includes                 # header files that contain function prototypes, structures and descriptions
|       camera.h 
|       color.h
|       common.h
|       object.h
|       render.h
|       settings.h           # adjust settings for rendering in this file
|       stb_image_write.h    # for exporting images
|       transformations.h
|       vector.h
|       
+---objects                  # .obj files for 3d models also called wavefront files
|       cube.obj
|       monkey.obj
|       render.png
|       smooth_cube.obj
|       smooth_monkey.obj
|       sphere.obj
|       torus.obj
|       updated.obj
|       
+---renders                  # folder for output images
|       cube.png
|       monkey.png
|       render.png
|       smooth_monkey.png
|       sphere.png
|       
\---src                      # source files with function definitions
        camera.c             # functions for camera transform
        color.c              # some colors in form of vectors
        common.c             # common functions
        main.c               # starting point of program and setup for rendering
        object.c             # functions for reading, exporting and transforming objects
        render.c             # functions for rendering
        transformations.c    # transformation matrices and vector transform
        vector.c             # basic vector operations and quaternions
```
