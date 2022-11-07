
#include <iostream>
#include <functional>
#include <algorithm>
#include <cmath>

#include "Object.hpp"
#include "Window.hpp"
#include "Player.hpp"
#include "InputManager.hpp"

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

	glEnableVertexAttribArray(0);

	shader = CreateShader((char*)("player.vert"), (char*)("player.frag"));

	window.AddToDrawList(std::bind(&Player::Draw, this));
	
	sizeMultiplier = 0.1;

	collider.size.x = 0.75 * sizeMultiplier;
	collider.size.y = 2 * sizeMultiplier;

}

void Player::Draw() {
	glUseProgram(shader.program);
	glBindVertexArray(object.VAO);

	//uniforms
	glUniform2fv(glGetUniformLocation(shader.program, "uSize"), 1, glm::value_ptr(collider.size));
	glUniform2fv(glGetUniformLocation(shader.program, "uOffset"), 1, glm::value_ptr(collider.pos));


	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}

void Player::Movement() {
	if (keys[MOVE_LEFT]>0) {
		dir.x -= acc;
	}
	if (keys[MOVE_RIGHT]>0) {
		dir.x += acc;

		
	}

	dir.x = std::clamp(dir.x, -maxDirX, maxDirX);

	if (!keys[MOVE_LEFT] && !keys[MOVE_RIGHT]) {
		dir.x = std::lerp(dir.x, 0, deAcc);
	}

	collider.pos.x += dir.x / 1000;
}