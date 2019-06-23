#include "Mesh.h"

Mesh::Mesh() :
	m_Position(0.0f, 0.0f, 0.0f) {

}

Mesh::Mesh(GLfloat x, GLfloat y, GLfloat z) :
	m_Position(x, y, z) {

}

Mesh::Mesh(glm::vec3 position) :
	m_Position(position) {

}

Mesh::~Mesh() {
	glDeleteProgram(m_ShaderProgram);
	glDeleteVertexArrays(1, &m_VAOHandler);
}

void Mesh::Init(GLuint shaderProgram) {
	glGenVertexArrays(1, &m_VAOHandler);
	glBindVertexArray(m_VAOHandler);

	GLuint vbo;
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, m_Data.size() * sizeof(GLfloat), &m_Data.front(), GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (void *)0);
	/*
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (void *)(3 * sizeof(GLfloat)));

	glEnableVertexAttribArray(2);
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (void *)(2 * 3 * sizeof(GLfloat)));
	*/
	GLuint ebo;
	glGenBuffers(1, &ebo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, m_Indices.size() * sizeof(GLushort), &m_Indices.front(), GL_STATIC_DRAW);

	m_ShaderProgram = shaderProgram;

	glBindVertexArray(0);
	glDeleteBuffers(1, &vbo);
	glDeleteBuffers(1, &ebo);

	m_Data.clear();
	m_Data.shrink_to_fit();

	m_Indices.clear();
	m_Indices.shrink_to_fit();
}

void Mesh::Draw(glm::mat4 viewProjectionMatrix) const {
	glBindVertexArray(m_VAOHandler);
	glUseProgram(m_ShaderProgram);

	glm::mat4 modelMatrix;
	modelMatrix = glm::translate(modelMatrix, m_Position);
	glm::mat4 mvpMatrix = viewProjectionMatrix * modelMatrix;

	glUniformMatrix4fv(4, 1, GL_FALSE, glm::value_ptr(mvpMatrix));
	glDrawElements(GL_TRIANGLES, m_NumIndices, GL_UNSIGNED_SHORT, (void *)0);
}