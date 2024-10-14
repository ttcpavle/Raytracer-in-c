#ifndef SETTINGS_H
#define SETTINGS_H

// ADJUST:
#define MAX_VERTEX 2000 // adjust size for large meshes
#define MAX_FACES 1000 // adjust size for large meshes
#define MAX_FACE_SIZE_SUPPORTED 10 // max face supported for triangulation

#define WIDTH 800     // width of render image
#define HEIGHT 600     // height of render image
#define MAX_RAY_DEPTH 3  // max recursion depth for ray tracing

#define BACKGROUND_COLOR gray // select color from color.c
#define CULLING // define if you want to check ray intersection only for camera facing faces

#endif // SETTINGS_H
