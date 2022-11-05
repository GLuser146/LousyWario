#pragma once

#include <iostream>
#include <functional>
#include <vector>

#include "glad.h"
#include <GLFW/glfw3.h>

#include "Window.hpp"
#include "Player.hpp"
#include "Object.hpp"

extern float deltaTime;

class GameManager {
public:
	GameManager();
	void MainLoop();

	Player player;
private:

	void UpdateDeltaGame();
};
