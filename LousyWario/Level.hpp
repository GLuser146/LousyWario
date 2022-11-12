#pragma once

#include "glad.h"
#include <glm/glm.hpp>

#include <iostream>
#include <vector>
#include <algorithm>

#include "Object.hpp"
#include "Shader.hpp"

#define AIR ' '
#define DIRT '1'

#define BLOCK_SIZE 0.1
#define CHUNK_SIZE 8

typedef struct Chunk {
	glm::vec2 pos[CHUNK_SIZE][CHUNK_SIZE];
	int type[CHUNK_SIZE][CHUNK_SIZE];
};

class Level {
public:
	Level() { std::cout << "\033[33m" << "WARNING: No level path provided" << "\033[0m\n"; }
	Level(char* path, int xSize, int ySize);
	void Draw();

	int xSize, ySize;

	std::vector<std::vector<Chunk>> chunks;
private:
	std::vector<std::vector<char>> levelDat;
	InstancedObject object;
	Shader shader;

	std::vector<GLfloat> blockDat; 
};
