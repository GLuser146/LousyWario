
#include <iostream>

#include "Object.hpp"
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
}

void Player::Draw() {

}