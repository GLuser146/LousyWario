#pragma once

#include "glad.h"
#include <glm/glm.hpp>

typedef struct Object {
	GLuint VBO, VAO, EBO, textureVBO;
}Object;

typedef struct InstancedObject {
	GLuint VBO, VAO, EBO, textureVBO, instanceVBO;
}InstancedObject;

typedef struct Collider {
	glm::vec2 pos;
	glm::vec2 size;

	float bbox_topleft, bbox_topright, bbox_bottomleft, bbox_bottomright;
};

float cubeVertces[8] = {
	-0.5, -0.5,
	-0.5,  0.5,
	 0.5, -0.5,
	 0.5,  0.5
};

unsigned int cubeIndices[6] = {
	0, 1, 2,
	1, 2, 3
};