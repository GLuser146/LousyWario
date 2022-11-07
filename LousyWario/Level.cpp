#include "Level.hpp"
#include "Object.hpp"
#include "Shader.hpp"

#include <iostream>

#include "glad.h"


Level::Level(char* path) {
	std::string level = ReadFile(path);
	unsigned int atX = 0;
	unsigned int atY = 0;

	std::string xSize;
	std::string ySize;


	short sizeIndex = 0;
	while (level[sizeIndex] != '\n') {
		xSize += level[sizeIndex];
		sizeIndex++;
	}
	sizeIndex++;
	while (level[sizeIndex] != '\n') {
		ySize += level[sizeIndex];
		sizeIndex++;
	}

	levelDat = (uint8_t**)malloc(sizeof(uint8_t) * std::stoi(xSize));

	for (int i = 0; i < std::stoi(xSize); i++) {
		levelDat[i] = (uint8_t*)malloc(sizeof(uint8_t) * std::stoi(ySize));
	}

	while (level[atX * atY] + sizeIndex != '\0') {
		while (level[atX * atY] + sizeIndex != '\n') {

		}
	}
}