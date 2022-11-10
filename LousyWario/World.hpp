#pragma once

#include "glad.h"

#include <iostream>
#include <vector>

#include "Object.hpp"
#include "Shader.hpp"
#include "Level.hpp"
#include "Window.hpp"

class World {
public:
	World();
	void Draw();

	std::vector<Level> levels;
	int currentLevel;
private:
};