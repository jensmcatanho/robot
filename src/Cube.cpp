#include "Cube.h"

#include "Mesh.h"

Cube::Cube() :
	Mesh(0.0f, 0.0f, 0.0f),
	m_Side(1.0f) {

	GenerateData();
}

Cube::Cube(GLfloat x, GLfloat y, GLfloat z, GLfloat side) :
	Mesh(x, y, z),
	m_Side(side) {

	GenerateData();
}

Cube::Cube(glm::vec3 position, GLfloat side) :
	Mesh(position),
	m_Side(side) {

	GenerateData();
}

void Cube::GenerateData() {
	GLuint verticesCount = 8;
	GLuint texCoordsCount = 8;
	m_NumIndices = 36;
	m_Data.resize(verticesCount * 3 + texCoordsCount * 2);
	m_Indices.resize(m_NumIndices);

	std::vector<GLfloat>::iterator d_iterator = m_Data.begin();

	*d_iterator++ = 0.0f; *d_iterator++ = 0.0f; *d_iterator++ = 0.0f;
	*d_iterator++ = 0.0f; *d_iterator++ = 0.0f;
	*d_iterator++ = m_Side; *d_iterator++ = 0.0f; *d_iterator++ = 0.0f;
	*d_iterator++ = 1.0f; *d_iterator++ = 0.0f;
	*d_iterator++ = m_Side; *d_iterator++ = m_Side; *d_iterator++ = 0.0f;
	*d_iterator++ = 1.0f; *d_iterator++ = 1.0f;
	*d_iterator++ = 0.0f; *d_iterator++ = m_Side; *d_iterator++ = 0.0f;
	*d_iterator++ = 0.0f; *d_iterator++ = 1.0f;
	*d_iterator++ = 0.0f; *d_iterator++ = 0.0f; *d_iterator++ = -m_Side;
	*d_iterator++ = 0.0f; *d_iterator++ = 0.0f;
	*d_iterator++ = m_Side; *d_iterator++ = 0.0f; *d_iterator++ = -m_Side;
	*d_iterator++ = 1.0f; *d_iterator++ = 0.0f;
	*d_iterator++ = m_Side; *d_iterator++ = m_Side; *d_iterator++ = -m_Side;
	*d_iterator++ = 1.0f; *d_iterator++ = 1.0f;
	*d_iterator++ = 0.0f; *d_iterator++ = m_Side; *d_iterator++ = -m_Side;
	*d_iterator++ = 0.0f; *d_iterator++ = 1.0f;

	std::vector<GLushort>::iterator i_iterator = m_Indices.begin();

	// Front face
	*i_iterator++ = 0; *i_iterator++ = 1; *i_iterator++ = 2;
	*i_iterator++ = 2; *i_iterator++ = 3; *i_iterator++ = 0;
	// Right face
	*i_iterator++ = 1; *i_iterator++ = 5; *i_iterator++ = 6;
	*i_iterator++ = 6; *i_iterator++ = 2; *i_iterator++ = 1;
	// Back face
	*i_iterator++ = 7; *i_iterator++ = 6; *i_iterator++ = 5;
	*i_iterator++ = 5; *i_iterator++ = 4; *i_iterator++ = 7;
	// Left face
	*i_iterator++ = 4; *i_iterator++ = 0; *i_iterator++ = 3;
	*i_iterator++ = 3; *i_iterator++ = 7; *i_iterator++ = 4;
	// Bottom face
	*i_iterator++ = 4; *i_iterator++ = 5; *i_iterator++ = 1;
	*i_iterator++ = 1; *i_iterator++ = 0; *i_iterator++ = 4;
	// Top face
	*i_iterator++ = 3; *i_iterator++ = 2; *i_iterator++ = 6;
	*i_iterator++ = 6; *i_iterator++ = 7; *i_iterator++ = 3;
}

