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
	GLuint verticesCount = 36;
	GLuint normalsCount = 36;
	GLuint texCoordsCount = 36;
	
	m_Data.resize(verticesCount * 3 + normalsCount * 3 + texCoordsCount * 2);

	m_NumIndices = 36;
	m_Indices.resize(m_NumIndices);

	std::vector<GLfloat>::iterator d_iterator = m_Data.begin();

	// Front face
	*d_iterator++ = 0.0f; *d_iterator++ = 0.0f; *d_iterator++ = 0.0f;
	*d_iterator++ = 0.0f; *d_iterator++ = 0.0f; *d_iterator++ = 1.0f;
	*d_iterator++ = 0.0f; *d_iterator++ = 0.0f;

	*d_iterator++ = m_Side; *d_iterator++ = 0.0f; *d_iterator++ = 0.0f;
	*d_iterator++ = 0.0f; *d_iterator++ = 0.0f; *d_iterator++ = 1.0f;
	*d_iterator++ = 1.0f; *d_iterator++ = 0.0f;

	*d_iterator++ = m_Side; *d_iterator++ = m_Side; *d_iterator++ = 0.0f;
	*d_iterator++ = 0.0f; *d_iterator++ = 0.0f; *d_iterator++ = 1.0f;
	*d_iterator++ = 1.0f; *d_iterator++ = 1.0f;

	*d_iterator++ = m_Side; *d_iterator++ = m_Side; *d_iterator++ = 0.0f;
	*d_iterator++ = 0.0f; *d_iterator++ = 0.0f; *d_iterator++ = 1.0f;
	*d_iterator++ = 1.0f; *d_iterator++ = 1.0f;

	*d_iterator++ = 0.0f; *d_iterator++ = m_Side; *d_iterator++ = 0.0f;
	*d_iterator++ = 0.0f; *d_iterator++ = 0.0f; *d_iterator++ = 1.0f;
	*d_iterator++ = 0.0f; *d_iterator++ = 1.0f;

	*d_iterator++ = 0.0f; *d_iterator++ = 0.0f; *d_iterator++ = 0.0f;
	*d_iterator++ = 0.0f; *d_iterator++ = 0.0f; *d_iterator++ = 1.0f;
	*d_iterator++ = 0.0f; *d_iterator++ = 0.0f;

	// Right face
	*d_iterator++ = m_Side; *d_iterator++ = 0.0f; *d_iterator++ = 0.0f;
	*d_iterator++ = 1.0f; *d_iterator++ = 0.0f; *d_iterator++ = 0.0f;
	*d_iterator++ = 1.0f; *d_iterator++ = 0.0f;

	*d_iterator++ = m_Side; *d_iterator++ = 0.0f; *d_iterator++ = -m_Side;
	*d_iterator++ = 1.0f; *d_iterator++ = 0.0f; *d_iterator++ = 0.0f;
	*d_iterator++ = 1.0f; *d_iterator++ = 0.0f;

	*d_iterator++ = m_Side; *d_iterator++ = m_Side; *d_iterator++ = -m_Side;
	*d_iterator++ = 1.0f; *d_iterator++ = 0.0f; *d_iterator++ = 0.0f;
	*d_iterator++ = 1.0f; *d_iterator++ = 1.0f;

	*d_iterator++ = m_Side; *d_iterator++ = m_Side; *d_iterator++ = -m_Side;
	*d_iterator++ = 1.0f; *d_iterator++ = 0.0f; *d_iterator++ = 0.0f;
	*d_iterator++ = 1.0f; *d_iterator++ = 1.0f;

	*d_iterator++ = m_Side; *d_iterator++ = m_Side; *d_iterator++ = 0.0f;
	*d_iterator++ = 1.0f; *d_iterator++ = 0.0f; *d_iterator++ = 0.0f;
	*d_iterator++ = 1.0f; *d_iterator++ = 1.0f;

	*d_iterator++ = m_Side; *d_iterator++ = 0.0f; *d_iterator++ = 0.0f;
	*d_iterator++ = 1.0f; *d_iterator++ = 0.0f; *d_iterator++ = 0.0f;
	*d_iterator++ = 1.0f; *d_iterator++ = 0.0f;

	// Back face
	*d_iterator++ = 0.0f; *d_iterator++ = m_Side; *d_iterator++ = -m_Side;
	*d_iterator++ = 0.0f; *d_iterator++ = 0.0f; *d_iterator++ = -1.0f;
	*d_iterator++ = 0.0f; *d_iterator++ = 1.0f;

	*d_iterator++ = m_Side; *d_iterator++ = m_Side; *d_iterator++ = -m_Side;
	*d_iterator++ = 0.0f; *d_iterator++ = 0.0f; *d_iterator++ = -1.0f;
	*d_iterator++ = 1.0f; *d_iterator++ = 1.0f;

	*d_iterator++ = m_Side; *d_iterator++ = 0.0f; *d_iterator++ = -m_Side;
	*d_iterator++ = 0.0f; *d_iterator++ = 0.0f; *d_iterator++ = -1.0f;
	*d_iterator++ = 1.0f; *d_iterator++ = 0.0f;

	*d_iterator++ = m_Side; *d_iterator++ = 0.0f; *d_iterator++ = -m_Side;
	*d_iterator++ = 0.0f; *d_iterator++ = 0.0f; *d_iterator++ = -1.0f;
	*d_iterator++ = 1.0f; *d_iterator++ = 0.0f;

	*d_iterator++ = 0.0f; *d_iterator++ = 0.0f; *d_iterator++ = -m_Side;
	*d_iterator++ = 0.0f; *d_iterator++ = 0.0f; *d_iterator++ = -1.0f;
	*d_iterator++ = 0.0f; *d_iterator++ = 0.0f;

	*d_iterator++ = 0.0f; *d_iterator++ = m_Side; *d_iterator++ = -m_Side;
	*d_iterator++ = 0.0f; *d_iterator++ = 0.0f; *d_iterator++ = -1.0f;
	*d_iterator++ = 0.0f; *d_iterator++ = 1.0f;

	// Left face
	*d_iterator++ = 0.0f; *d_iterator++ = 0.0f; *d_iterator++ = -m_Side;
	*d_iterator++ = -1.0f; *d_iterator++ = 0.0f; *d_iterator++ = 0.0f;
	*d_iterator++ = 0.0f; *d_iterator++ = 0.0f;

	*d_iterator++ = 0.0f; *d_iterator++ = 0.0f; *d_iterator++ = 0.0f;
	*d_iterator++ = -1.0f; *d_iterator++ = 0.0f; *d_iterator++ = 0.0f;
	*d_iterator++ = 0.0f; *d_iterator++ = 0.0f;

	*d_iterator++ = 0.0f; *d_iterator++ = m_Side; *d_iterator++ = 0.0f;
	*d_iterator++ = -1.0f; *d_iterator++ = 0.0f; *d_iterator++ = 0.0f;
	*d_iterator++ = 0.0f; *d_iterator++ = 1.0f;

	*d_iterator++ = 0.0f; *d_iterator++ = m_Side; *d_iterator++ = 0.0f;
	*d_iterator++ = -1.0f; *d_iterator++ = 0.0f; *d_iterator++ = 0.0f;
	*d_iterator++ = 0.0f; *d_iterator++ = 1.0f;

	*d_iterator++ = 0.0f; *d_iterator++ = m_Side; *d_iterator++ = -m_Side;
	*d_iterator++ = -1.0f; *d_iterator++ = 0.0f; *d_iterator++ = 0.0f;
	*d_iterator++ = 0.0f; *d_iterator++ = 1.0f;

	*d_iterator++ = 0.0f; *d_iterator++ = 0.0f; *d_iterator++ = -m_Side;
	*d_iterator++ = -1.0f; *d_iterator++ = 0.0f; *d_iterator++ = 0.0f;
	*d_iterator++ = 0.0f; *d_iterator++ = 0.0f;

	// Bottom face
	*d_iterator++ = 0.0f; *d_iterator++ = 0.0f; *d_iterator++ = -m_Side;
	*d_iterator++ = 0.0f; *d_iterator++ = -1.0f; *d_iterator++ = 0.0f;
	*d_iterator++ = 0.0f; *d_iterator++ = 0.0f;

	*d_iterator++ = m_Side; *d_iterator++ = 0.0f; *d_iterator++ = -m_Side;
	*d_iterator++ = 0.0f; *d_iterator++ = -1.0f; *d_iterator++ = 0.0f;
	*d_iterator++ = 1.0f; *d_iterator++ = 0.0f;

	*d_iterator++ = m_Side; *d_iterator++ = 0.0f; *d_iterator++ = 0.0f;
	*d_iterator++ = 0.0f; *d_iterator++ = -1.0f; *d_iterator++ = 0.0f;
	*d_iterator++ = 1.0f; *d_iterator++ = 0.0f;

	*d_iterator++ = m_Side; *d_iterator++ = 0.0f; *d_iterator++ = 0.0f;
	*d_iterator++ = 0.0f; *d_iterator++ = -1.0f; *d_iterator++ = 0.0f;
	*d_iterator++ = 1.0f; *d_iterator++ = 0.0f;

	*d_iterator++ = 0.0f; *d_iterator++ = 0.0f; *d_iterator++ = 0.0f;
	*d_iterator++ = 0.0f; *d_iterator++ = -1.0f; *d_iterator++ = 0.0f;
	*d_iterator++ = 0.0f; *d_iterator++ = 0.0f;

	*d_iterator++ = 0.0f; *d_iterator++ = 0.0f; *d_iterator++ = -m_Side;
	*d_iterator++ = 0.0f; *d_iterator++ = -1.0f; *d_iterator++ = 0.0f;
	*d_iterator++ = 0.0f; *d_iterator++ = 0.0f;

	// Top face
	*d_iterator++ = 0.0f; *d_iterator++ = m_Side; *d_iterator++ = 0.0f;
	*d_iterator++ = 0.0f; *d_iterator++ = 1.0f; *d_iterator++ = 0.0f;
	*d_iterator++ = 0.0f; *d_iterator++ = 1.0f;

	*d_iterator++ = m_Side; *d_iterator++ = m_Side; *d_iterator++ = 0.0f;
	*d_iterator++ = 0.0f; *d_iterator++ = 1.0f; *d_iterator++ = 0.0f;
	*d_iterator++ = 1.0f; *d_iterator++ = 1.0f;

	*d_iterator++ = m_Side; *d_iterator++ = m_Side; *d_iterator++ = -m_Side;
	*d_iterator++ = 0.0f; *d_iterator++ = 1.0f; *d_iterator++ = 0.0f;
	*d_iterator++ = 1.0f; *d_iterator++ = 1.0f;

	*d_iterator++ = m_Side; *d_iterator++ = m_Side; *d_iterator++ = -m_Side;
	*d_iterator++ = 0.0f; *d_iterator++ = 1.0f; *d_iterator++ = 0.0f;
	*d_iterator++ = 1.0f; *d_iterator++ = 1.0f;

	*d_iterator++ = 0.0f; *d_iterator++ = m_Side; *d_iterator++ = -m_Side;
	*d_iterator++ = 0.0f; *d_iterator++ = 1.0f; *d_iterator++ = 0.0f;
	*d_iterator++ = 0.0f; *d_iterator++ = 1.0f;

	*d_iterator++ = 0.0f; *d_iterator++ = m_Side; *d_iterator++ = 0.0f;
	*d_iterator++ = 0.0f; *d_iterator++ = 1.0f; *d_iterator++ = 0.0f;
	*d_iterator++ = 0.0f; *d_iterator++ = 1.0f;

	std::vector<GLushort>::iterator i_iterator = m_Indices.begin();

	// Front face
	*i_iterator++ = 0; *i_iterator++ = 1; *i_iterator++ = 2;
	*i_iterator++ = 3; *i_iterator++ = 4; *i_iterator++ = 5;
	// Right face
	*i_iterator++ = 6; *i_iterator++ = 7; *i_iterator++ = 8;
	*i_iterator++ = 9; *i_iterator++ = 10; *i_iterator++ = 11;
	// Back face
	*i_iterator++ = 12; *i_iterator++ = 13; *i_iterator++ = 14;
	*i_iterator++ = 15; *i_iterator++ = 16; *i_iterator++ = 17;
	// Left face
	*i_iterator++ = 18; *i_iterator++ = 19; *i_iterator++ = 20;
	*i_iterator++ = 21; *i_iterator++ = 22; *i_iterator++ = 23;
	// Bottom face
	*i_iterator++ = 24; *i_iterator++ = 25; *i_iterator++ = 26;
	*i_iterator++ = 27; *i_iterator++ = 28; *i_iterator++ = 29;
	// Top face
	*i_iterator++ = 30; *i_iterator++ = 31; *i_iterator++ = 32;
	*i_iterator++ = 33; *i_iterator++ = 34; *i_iterator++ = 35;
}