#ifndef CUBE_H
#define CUBE_H

#include "Prerequisites.h"
#include "Mesh.h"

class Cube : public Mesh {
	public:
		Cube();

		Cube(GLfloat, GLfloat, GLfloat, GLfloat);

		Cube(glm::vec3, GLfloat);

	private:
		void GenerateData();

		GLfloat m_Side;
};

#endif