#pragma once

#include <GLFW/glfw3.h>

#define MOVE_LEFT  0
#define MOVE_RIGHT 1
#define JUMP	   2
#define CROUCH	   3


#define KEY_COUNT 4

extern int keys[KEY_COUNT];

void KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
