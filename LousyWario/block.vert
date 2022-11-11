#version 460 core

layout (location = 0) in vec2 aPos;
layout (location = 1) in vec3 blockDat;
layout (location = 2) in vec2 aTexCoord;

uniform float uSize;

out vec2 texCoord;
flat out int type;

void main(){
	gl_Position = (vec4(aPos.x, aPos.y, 0.0, 1.0) * vec4(uSize, uSize, 1.0, 1.0)) * vec4(1.0, 1.78, 1.0, 1.0)
	+ vec4(blockDat.x - 0.95, blockDat.y  * 1.78 - 0.91, 0.0, 0.0);	

	texCoord = aTexCoord;
} 
//its trash
//but its MY trash