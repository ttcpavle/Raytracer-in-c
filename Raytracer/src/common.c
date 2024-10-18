#include "common.h"

#ifdef WINDOWS

#include <windows.h>

void openImage(const char* filePath) {
    ShellExecute(0, "open", filePath, 0, 0, SW_SHOW);
}

#elif defined MACOS

#include <string.h>

void openImage(const char* filePath) {
    char command[256];
    strcpy(command, "open ");
    strcat(command, filePath);
    system(command);
}

#elif defined UNIXOS

#include <string.h>

void openImage(const char* filePath) {
    char command[256];
    strcpy(command, "xdg-open ");
    strcat(command, filePath);
    system(command);


#endif