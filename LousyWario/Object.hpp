#pragma once

#include "glad.h"
#include <glm/glm.hpp>

typedef struct Object {
	GLuint VBO, VAO, EBO, textureVBO;
};

typedef struct InstancedObject {
	GLuint VBO, VAO, EBO, textureVBO, instanceVBO;
};

typedef struct Collider {
	glm::vec2 pos = glm::vec2(0, 0);
	glm::vec2 size = glm::vec2(1, 1);

	float bbox_topleft, bbox_topright, bbox_bottomleft, bbox_bottomright;
};

extern float cubeVertices[8];

extern unsigned int cubeIndices[6];