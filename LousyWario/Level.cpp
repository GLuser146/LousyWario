#include "Level.hpp"
#include "Object.hpp"
#include "Shader.hpp"

#include <iostream>
#include <vector>

#include "glad.h"


Level::Level(char* path, int xSize, int ySize) {
	// LOADING THE LEVEL
	std::string level = ReadFile(path);
	unsigned int atX = 0;
	unsigned int atY = 0;

	for (int x = 0; x < xSize+1; x++) {
		for (int y = 0; y < ySize+1; y++) {
			if (level[x * y] != '\n') {
				levelDat[xSize].push_back(level[x * y]);
			}
			
		}
	}

	for (int x = 0; x < xSize+1; x++) {
		for (int y = 0; y < ySize+1; y++) {
				if (levelDat[x][y] != AIR && levelDat[x][y] != '\n') {
					blockDat.push_back(x * BLOCK_SIZE);
					blockDat.push_back(y * BLOCK_SIZE);

					blockDat.push_back(levelDat[x][y]);
				}
		}
	}
	////////
	glGenVertexArrays(1, &object.VAO);
	glBindVertexArray(object.VAO);

	glGenBuffers(1, &object.VBO);
	glBindBuffer(GL_ARRAY_BUFFER, object.VBO);

	glBufferData(GL_ARRAY_BUFFER, sizeof(cubeVertices), cubeVertices, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, (void*)0);

	glGenBuffers(1, &object.EBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, object.EBO);

	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(cubeIndices), cubeIndices, GL_STATIC_DRAW);

	glGenBuffers(1, &object.instanceVBO);
	glBindBuffer(GL_ARRAY_BUFFER, object.instanceVBO);

	glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * blockDat.size(), &blockDat[0], GL_DYNAMIC_DRAW);

	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);


	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);

	glVertexAttribDivisor(1, 1);

	/////////

	shader = CreateShader((char*)"block.vert", (char*)"block.frag");

}