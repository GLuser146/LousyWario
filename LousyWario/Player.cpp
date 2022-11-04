
#include <iostream>
#include <functional>

#include "Object.hpp"
#include "Window.hpp"
#include "Player.hpp"

#include "glad.h"
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>


Player::Player() {
	glGenVertexArrays(1, &object.VAO);
	glBindVertexArray(object.VAO);

	glGenBuffers(1, &object.VBO);
	glBindBuffer(GL_ARRAY_BUFFER, object.VBO);

	glBufferData(GL_ARRAY_BUFFER, sizeof(cubeVertices), cubeVertices, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, (void*)0);

	glGenBuffers(1, &object.EBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, object.EBO);

	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(cubeIndices), cubeIndices, GL_STATIC_DRAW);

}

std::function<void()> Player::Draw() {
	glUseProgram(shader.program);
	glBindVertexArray(object.VAO);
	glDrawElements(GL_TRIANGLES, 2, GL_UNSIGNED_INT, 0);
	return 0;
}