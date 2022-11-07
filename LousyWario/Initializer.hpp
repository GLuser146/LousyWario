#pragma once

#include "glad.h"
#include <GLFW/glfw3.h>

#include <iostream>
#include <conio.h>

#include "Window.hpp"
#include "GameManager.hpp"
#include "InputManager.hpp"

void InitAPI() {
	if (!glfwInit()) {
		std::cerr << "\033[31m" << "ERROR: Cannot initialize GLFW" << "\033[0m";
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);


#ifdef __APPLE__
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GLFW_TRUE);
#endif

	window = Window((char*)"DaMarussy>w<", WINDOW_WIDTH, WINDOW_HEIGHT);
	glfwMakeContextCurrent(window.window);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		std::cerr << "\033[31m" << "ERROR: Failed to initialize GLAD" << "\033[0m";
	}

	glViewport(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);
	glClearColor(0.0, 1.0, 1.0, 1.0);

	glfwSetKeyCallback(window.window, KeyCallback);

	glfwSwapInterval(0);

}