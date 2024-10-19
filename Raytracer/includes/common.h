#ifndef COMMON_H
#define COMMON_H

// Used to access files in /objects and /renders directories
// - choose macro OBJECTS to access objects directory
// - choose macro RENDERS to access renders directory
// - example FILEPATH(OBJECTS, "cube.obj")
#define FILEPATH(directory, filename) directory "/" filename

#define DEG_TO_RAD(angle) ((angle) * ((float)M_PI / 180.0f))

// ignore security warnings for visual studio
#ifdef VISUAL_STUDIO
#define _CRT_SECURE_NO_WARNINGS
#endif

// for constants like M_PI
#define _USE_MATH_DEFINES

// standard libraries
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "settings.h"

void openImage(const char* filePath); // open image command

#endif // COMMON_H