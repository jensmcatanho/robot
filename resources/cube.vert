#version 430 core

layout(location = 0) in vec3 a_Position;
layout(location = 1) in vec3 a_Normal;
layout(location = 2) in vec2 a_TexCoord;

layout(location = 4) uniform mat4 u_mvpMatrix;

out vec3 vs_FragColor;
out vec2 vs_TexCoord;

void main() {
	gl_Position = vec4(a_Position.x - 0.5, a_Position.y - 0.5, a_Position.z + 0.5, 1.0);
	vs_FragColor = vec3(1.0, 0.0, 0.0);
	/*
	gl_Position = u_mvpMatrix * vec4(a_Position.x - 0.5, a_Position.y - 0.5, a_Position.z + 0.5, 1.0);
	
	vs_FragColor = vec3(a_Position.xy, -a_Position.z);
	vs_TexCoord = a_TexCoord;
	*/
}