#pragma once

#include <iostream>

#include "glad.h"
#include <GLFW/glfw3.h>

#include "Window.hpp"
#include "Player.hpp"
#include "Object.hpp"

class GameManager {
public:
	GameManager();
	void MainLoop();

	Player player;
private:
};
