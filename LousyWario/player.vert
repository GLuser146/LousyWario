#version 460 core

layout (location = 0) in vec2 aPos;

uniform vec2 uSize;

void main(){
	gl_Position = vec4(aPos.x * uSize.x, aPos.y * 1.78 * uSize.y, 0.0, 1.0);
}