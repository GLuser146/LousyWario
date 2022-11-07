
#include <iostream>

#include "glad.h"
#include <GLFW/glfw3.h>

#include "Window.hpp"
#include "GameManager.hpp"
#include "Object.hpp"

float deltaTime = 0;
float lastFrame = 0;;

GameManager::GameManager() {
	player = Player();
}

void GameManager::MainLoop() {
	while (!glfwWindowShouldClose(window.window)) {
		FixedUpdate();
		Update();

		window.Draw();

		glfwPollEvents();
	}
}

void GameManager::Update() {
	UpdateDeltaTime();
}

void GameManager::FixedUpdate() {
	if (glfwGetTime() - sinceLastUpdate >= FIXED_UPDATE_FREQUENCY) {
		sinceLastUpdate = glfwGetTime();

		player.Movement();
	}
}

void GameManager::UpdateDeltaTime() {
	deltaTime = glfwGetTime() - lastFrame;
	lastFrame = glfwGetTime();
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
