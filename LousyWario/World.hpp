#pragma once

#include "glad.h"

#include <iostream>
#include <vector>

#include "Object.hpp"
#include "Shader.hpp"
#include "Level.hpp"
#include "Window.hpp"
#include "ImageLoader.hpp"

class World {
public:
	World();
	void Draw();

	std::vector<Level> levels;
	std::vector<GLuint> textures;

	int currentLevel;
private:
};