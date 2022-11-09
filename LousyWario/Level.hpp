#pragma once

#include "glad.h"

#include <iostream>
#include <vector>

#include "Object.hpp"
#include "Shader.hpp"

#define AIR ' '
#define DIRT '0'

#define BLOCK_SIZE 0.1

class Level {
public:
	Level() { std::cout << "\033[33m" << "WARNING: No level path provided" << "\033[0m\n"; }
	Level(char* path, int xSize, int ySize);

	int xSize, ySize;
private:
	char** levelDat;
	InstancedObject object;
	Shader shader;

	std::vector<GLfloat> blockDat; 
};