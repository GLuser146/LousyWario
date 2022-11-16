#version 460 core

out vec4 oColor;

flat in int type;
in vec2 texCoord;

uniform sampler2D dirtTex;

void main(){
	if(type == 1){ 
		oColor = texture(dirtTex, texCoord);
	}
	else{
		oColor = vec4(1.0, 0.01149, 0.02, 1.0);
	}
}