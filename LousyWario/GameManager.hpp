#pragma once

#include <iostream>

#include "glad.h"
#include <GLFW/glfw3.h>

#include "Window.hpp"

class GameManager {
public:
	GameManager(){};
	void MainLoop();
private:
};

extern GameManager gameManager;