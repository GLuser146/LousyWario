#include <GLFW/glfw3.h>

#include "InputManager.hpp"
#include <iostream>

int keys[KEY_COUNT] = {};

void KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {
	switch (key) {
	case GLFW_KEY_A:
		keys[MOVE_LEFT] = action;
		break;
	case GLFW_KEY_D:
		keys[MOVE_RIGHT] = action;
		break;
	case GLFW_KEY_W:
		keys[JUMP] = action;
		break;
	case GLFW_KEY_S:
		keys[CROUCH] = action;
		break;
	}
}

