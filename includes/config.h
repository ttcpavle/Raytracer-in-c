#pragma once

// used to access files in objects and renders directories
// choose macro OBJECTS to access objects directory
// choose macro RENDERS to access renders directory
// example CONCAT_PATH(OBJECTS, "cube.obj")
#define CONCAT_PATH(PATH, FILENAME) PATH FILENAME

#ifdef VISUAL_STUDIO
// ignore security warnings for visual studio
#define _CRT_SECURE_NO_WARNINGS

#endif
// for constants like M_PI
#define _USE_MATH_DEFINES

// standard libraries
#include <stdio.h>
#include <stdlib.h>
#include <math.h> //i decided to include it here since almost all .c files use it

// ADJUST:
#define MAX_VERTEX 2000 // adjust size for large meshes
#define MAX_FACES 1000 // adjust size for large meshes
#define MAX_FACE_SIZE_SUPPORTED 10 // max face supported for triangulation

#define WIDTH 800     // width of render image
#define HEIGHT 600     // height of render image
#define MAX_RAY_DEPTH 3  // max recursion depth for ray tracing

#define CULLING // define if you want to check ray intersection only for camera facing faces

