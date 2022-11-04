
#include <iostream>

#include "glad.h"
#include <GLFW/glfw3.h>

#include "Window.hpp"
#include "GameManager.hpp"
#include "Object.hpp"



GameManager gameManager = GameManager();

void GameManager::MainLoop() {
	while (!glfwWindowShouldClose(window.window)) {
		window.Draw();

		glfwPollEvents();
	}
}

////IGNORE
float cubeVertices[8] = {
	-0.5, -0.5,
	-0.5,  0.5,
	 0.5, -0.5,
	 0.5,  0.5
};

unsigned int cubeIndices[6] = {
	0, 1, 2,
	1, 2, 3
};
/////