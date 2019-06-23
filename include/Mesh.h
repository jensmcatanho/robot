#ifndef MESH_H
#define MESH_H

#include "Prerequisites.h"
#include "IDrawable.h"

class Mesh : public IDrawable {
	public:
		Mesh();

		Mesh(GLfloat, GLfloat, GLfloat);

		Mesh(glm::vec3);

		virtual ~Mesh();

		virtual void Init(GLuint) override;

		virtual void Draw(glm::mat4) const override;

	protected:
		glm::vec3 m_Position;

		std::vector<GLfloat> m_Data;

		std::vector<GLushort> m_Indices;

		GLuint m_NumIndices;

	private:
		GLuint m_ShaderProgram;

		GLuint m_VAOHandler;

		GLuint m_mvpUniformLocation;
};

#endif