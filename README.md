# Simple ray-tracer in C
<p align="center">
    <img src="/Raytracer/renders/monkey.png" alt="Rendered image example" width="50%"/>
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
3) Run
```bash
cmake ..
```

After those steps:
- If you are using windows, open the `Raytracer.sln` solution (if visual studio was selected compiler). Select the Raytracer as startup project and run. Header files should appear in solution explorer under Header files.
- If you are using linux, run generated files for building a project. If cmake generated makefile, run `make` and than run the executable `./Raytracer`
<p>
Required software: <br>
Cmake installation: https://www.youtube.com/watch?v=8_X5Iq9niDE <br>
Git installation: https://www.youtube.com/watch?v=JgOs70Y7jew <br>
</p>


## How to use
Everything is controlled in `main()` function, there is no console or windows interface, this is only a simple rendering software. You can see in the example how things are set up:
1) Adjust settings in config.h accoring to your preferences
2) Read object, set material, transform it and export it if you want
3) Set up objects array and lights array (currently rendering supports a single object and light)
4) Set up camera (point look_at which is where camera is looking, eye which is camera location, fov and aspect ratio ideally set to `(float)WIDTH/HEIGHT`
5) Render the scene (Color* is image which is array or flat memory matrix of colors)
6) Export image with `stbi_image_write()` which is available in stb_image_write.h library from Sean Barrett

- Info about functions is available in .h or .c files
- More render examples in Raytracer/renders/
- **REMEMBER TO EDIT CONFIG.H**

### Features:

- Faces are triangulated while reading wavefront (fan triangulation)
- Exported object will maintain triangulated faces
- Moller Trumbore algorighm is used for ray triangle intersection
- Gauss-Jordan algorithm is used for inverse matrix
- You can follow render progress on console
- Smooth shaded object (Gouraud shading)
- Project is tested on windows (visual studio) and linux fedora

### Not supported:
- preserving group information in .obj files
- reading .mtl files
- rendering multiple objects/lights and shadows
- preserving n-gon faces
- using isGlass property
- undo transforms

### Improvement to do:
- Render multiple objects/lights
- Better shading with isGlass information (reflection and refraction)
- Rendering equation (Monte Carlo integration)
- Origin of object fixes
- OpenGL or windows.h for GUI
