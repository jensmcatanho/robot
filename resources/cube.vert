#version 330

in vec3 a_Position;
in vec3 a_Normal;
in vec2 a_TexCoord;

uniform mat4 u_mvpMatrix;

out vec3 vs_FragColor;
out vec3 vs_Normal;
out vec2 vs_TexCoord;

void main() {
	gl_Position = u_mvpMatrix * vec4(a_Position.x - 0.5, a_Position.y - 0.5, a_Position.z + 0.5, 1.0);
	
	vs_FragColor = vec3(a_Position.xy, -a_Position.z);
	vs_Normal = a_Normal;
	vs_TexCoord = a_TexCoord;
}