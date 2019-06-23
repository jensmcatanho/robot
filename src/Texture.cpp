#include "Texture.h"

Texture::Texture() :
	m_Id(0) {

}

Texture::~Texture() {
	glDeleteTextures(1, &m_Id);
}

void Texture::Init(unsigned char *data, GLint width, GLint height) {
	glGenTextures(1, &m_Id);
	glBindTexture(GL_TEXTURE_2D, m_Id);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
}

void Texture::Bind(GLuint slot) const {
	glActiveTexture(slot);
	glBindTexture(GL_TEXTURE_2D, m_Id);
}