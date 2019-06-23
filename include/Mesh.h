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

		void SetDiffuseMap(std::shared_ptr<Texture>);

		void SetSpecularMap(std::shared_ptr<Texture>);

	protected:
		glm::vec3 m_Position;

		std::vector<GLfloat> m_Data;

		std::vector<GLushort> m_Indices;

		GLuint m_NumIndices;

	private:
		GLuint m_ShaderProgram;

		GLuint m_VAOHandler;

		GLuint m_mvpUniformLocation;

		std::shared_ptr<Texture> m_DiffuseMap;

		std::shared_ptr<Texture> m_SpecularMap;
};

inline void Mesh::SetDiffuseMap(std::shared_ptr<Texture> texture) {
	m_DiffuseMap = texture;
}

inline void Mesh::SetSpecularMap(std::shared_ptr<Texture> texture) {
	m_SpecularMap = texture;
}

#endif