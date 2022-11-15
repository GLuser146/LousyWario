
#include <iostream>
#include <functional>
#include <algorithm>
#include <cmath>
#include <vector>

#include "Object.hpp"
#include "Window.hpp"
#include "Player.hpp"
#include "InputManager.hpp"
#include "Level.hpp"

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

void Player::UpdateBBOX() {
	collider.bbox_topleft = glm::vec2(collider.pos.x+1 + collider.size.x / 2, collider.pos.y + collider.size.y / 2);
	collider.bbox_topright = glm::vec2(collider.pos.x+1 - collider.size.x / 2, collider.pos.y + collider.size.y / 2);
	collider.bbox_bottomleft = glm::vec2(collider.pos.x+1 + collider.size.x / 2, collider.pos.y - collider.size.y / 2);
	collider.bbox_bottomright = glm::vec2(collider.pos.x+1 - collider.size.x / 2, collider.pos.y - collider.size.y / 2);
}

void Player::Collision(std::vector<std::vector<Chunk>> chunks) {
	float exp = pow(BLOCK_SIZE, -1);

	glm::vec2 bbox_topleft = collider.bbox_topleft * exp;
	glm::vec2 bbox_topright = collider.bbox_topright * exp;
	glm::vec2 bbox_bottomleft = collider.bbox_bottomleft * exp;
	glm::vec2 bbox_bottomright = collider.bbox_bottomright * exp;


	glm::vec2 topleft_chunkpos = glm::vec2(
		);

	glm::vec2 topright_chunkpos = glm::vec2(,
		);

	glm::vec2 bottomleft_chunkpos = glm::vec2(,
		);


	 
	Chunk bottomright_chunk = chunks[(int)std::clamp((float)floor(bbox_bottomright.x / 8), (float)0, (float)chunks.size() - 1)]
		[(int)std::clamp((float)floor(bbox_bottomright.y / 8), (float)0, (float)chunks[0].size() - 1)];

	Chunk bottomleft_chunk = chunks[(int)std::clamp((float)floor(bbox_bottomleft.x / 8), (float)0, (float)chunks.size() - 1)]
		[(int)std::clamp((float)floor(bbox_bottomleft.y / 8), (float)0, (float)chunks[0].size() - 1)];

	Chunk topright_chunk = chunks[(int)std::clamp((float)floor(bbox_topright.x / 8), (float)0, (float)chunks.size() - 1)]
		[(int)std::clamp((float)floor(bbox_topright.y / 8), (float)0, (float)chunks[0].size() - 1)];

	Chunk topleft_chunk = chunks[(int)std::clamp((float)floor(bbox_topleft.x / 8), (float)0, (float)chunks.size() - 1)]
		[(int)std::clamp((float)floor(bbox_topleft.y / 8), (float)0, (float)chunks[0].size() - 1)];
}		