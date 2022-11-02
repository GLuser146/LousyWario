
#include <iostream>

#include "glad.h"
#include <GLFW/glfw3.h>

#include "Window.hpp"
#include "GameManager.hpp"



GameManager gameManager = GameManager();

void GameManager::MainLoop() {
	while (!glfwWindowShouldClose(window.window)) {
		window.Draw();

		glfwPollEvents();
	}
}