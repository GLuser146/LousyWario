#pragma once

#include <iostream>

#include "glad.h"
#include <GLFW/glfw3.h>

#include "Window.hpp"
#include "Player.hpp"
#include "Object.hpp"


#define FIXED_UPDATE_FREQUENCY 0.0167 // seconds

extern float deltaTime;
extern float lastFrame;

void KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);

class GameManager {
public:
	GameManager();
	void MainLoop();

	Player player;
private:

	void UpdateDeltaTime();
	void Update();
	void FixedUpdate();

	float sinceLastUpdate = 0;
};
