#include "Level.hpp"
#include "Object.hpp"
#include "Shader.hpp"

#include <iostream>
#include <vector>

#include "glad.h"


Level::Level(char* path, int xSize, int ySize) {
	// LOADING THE LEVEL
	std::string level = ReadFile(path);

	levelDat = new char* [xSize];

	int atIndex = 0;
	for (int x = 0; x < xSize; x++) {
		levelDat[x] = new char[ySize];
		for (int y = 0; y < ySize+1; y++){
			if(level[atIndex] != '\n'){
				levelDat[x][y] = level[atIndex];
			}
			atIndex++;

		}
	}


	for (int x = 0; x < xSize; x++) {
		for (int y = 0; y < ySize + 1; y++) {
				if (levelDat[x][y] != AIR) {
					blockDat.push_back(x * BLOCK_SIZE);
					blockDat.push_back(y * BLOCK_SIZE);

					switch (levelDat[x][y]) {
					case DIRT:
						blockDat.push_back(0);
						break;
					default:
						blockDat.push_back(-1);
						break;

					}
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

void Level::Draw() {
	glUseProgram(shader.program);
	glBindVertexArray(object.VAO); 

	glDrawElementsInstanced(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0, blockDat.size() / 3);
}