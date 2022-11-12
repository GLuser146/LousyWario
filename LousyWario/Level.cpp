#include "Level.hpp"
#include "Object.hpp"
#include "Shader.hpp"

#include <iostream>
#include <vector>
#include <algorithm>

#include "glad.h"
#include <glm/glm.hpp>


Level::Level(char* path, int xSize, int ySize) {

	if ((float)xSize/8 != floor(xSize/8) || (float)ySize/8 != floor(ySize/8)) {
		std::cout << "\033[31m" << "ERROR: Level " << "\033[32m" << path << "\033[31m" << " size not divisible by 8 (standard"
			<< " chunk size)." << "\033[0m\n";
	}
	
	for (int x = 0; x < floor(xSize / 8); x++) {
		std::vector<Chunk> row;
		for (int y = 0; y < floor(ySize / 8); y++) {
			Chunk chunk;
			row.push_back(chunk);
		}
		chunks.push_back(row);
		row.clear();
	}

	// LOADING THE LEVEL
	std::string level = ReadFile(path);

	std::erase_if(level,
		[](auto ch)
		{
			return (ch == '\n');
		});

	for (int x = 0; x < xSize; x++) {
		std::vector<char> row;
		for (int y = 0; y < ySize; y++) {
			row.push_back(level[y*xSize+x]);			
		}
		levelDat.push_back(row);
		row.clear();
	}


	for (int x = 0; x < xSize; x++) {
		for (int y = 0; y < ySize; y++) {
				if (levelDat[x][y] != AIR) {
					blockDat.push_back(x * BLOCK_SIZE);
					blockDat.push_back((ySize - y - 1) * BLOCK_SIZE);
					switch (levelDat[x][y]) {
					case DIRT:
						blockDat.push_back(1);
						break;
					default:
						blockDat.push_back(0);
						break;

					}
				}
		}
	}

	for (int x = 0; x <= xSize-8; x += 8) {
		for (int y = 0; y <= ySize-8; y += 8) {
			for (int x_ = 0; x_ < 8; x_++) {
				for (int y_ = 0; y_ < 8; y_++) {
					chunks[x/8][y/8].pos[x_][y_] = glm::vec2((x + x_) * CHUNK_SIZE, (y + y_) * CHUNK_SIZE);
					chunks[x/8][y/8].type[x_][y_] = levelDat[x + x_][y + y_]; //PAIN IS VIRTUE PAIN IS VIRTUE PAIN IS VIRTUE PAIN IS VIRTUE
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

	glGenBuffers(1, &object.textureVBO);
	glBindBuffer(GL_ARRAY_BUFFER, object.textureVBO);

	glBufferData(GL_ARRAY_BUFFER, sizeof(cubeVertices), cubeTexCoords, GL_STATIC_DRAW);
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 0, (void*)0);

	glGenBuffers(1, &object.EBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, object.EBO);

	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(cubeIndices), cubeIndices, GL_STATIC_DRAW);

	glGenBuffers(1, &object.instanceVBO);
	glBindBuffer(GL_ARRAY_BUFFER, object.instanceVBO);

	glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * blockDat.size(), &blockDat[0], GL_DYNAMIC_DRAW);

	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);

	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	glEnableVertexAttribArray(2);

	glVertexAttribDivisor(1, 1);

	/////////

	shader = CreateShader((char*)"block.vert", (char*)"block.frag");

	glUseProgram(shader.program);
	glUniform1i(glGetUniformLocation(shader.program, "dirtTex"), 0);

	this->xSize = xSize;
	this->ySize = ySize;

}

void Level::Draw() {
	glUseProgram(shader.program);
	glBindVertexArray(object.VAO); 

	glUniform1f(glGetUniformLocation(shader.program, "uSize"), BLOCK_SIZE);

	glDrawElementsInstanced(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0, blockDat.size()/3);
}