
#include "glad.h"

#include <iostream>
#include <vector>

#include "Object.hpp"
#include "Shader.hpp"
#include "Level.hpp"
#include "World.hpp"
#include "Window.hpp"

World::World() {
	currentLevel = 0;

	levels.push_back(Level((char*)"test.lvl", 4, 4));

	window.AddToDrawList(std::bind(&World::Draw, this));
}

void World::Draw() {
	levels[currentLevel].Draw();
}