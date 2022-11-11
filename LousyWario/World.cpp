
#include "glad.h"

#include <iostream>
#include <vector>

#include "Object.hpp"
#include "Shader.hpp"
#include "Level.hpp"
#include "World.hpp"
#include "Window.hpp"
#include "ImageLoader.hpp"

World::World() {
	currentLevel = 0;

	levels.push_back(Level((char*)"test.lvl", 8, 8));

	textures.push_back(LoadImage((char*)"dirt.png"));

	window.AddToDrawList(std::bind(&World::Draw, this));
}

void World::Draw() {
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, textures[0]);

	levels[currentLevel].Draw();
}