#ifndef TEXTURE_H
#define TEXTURE_H

#include "Prerequisites.h"

class Texture {
	public:
		Texture();

		~Texture();

		void Init(unsigned char *data, GLint width, GLint height);

		void Bind(GLuint slot) const;

	private:
		GLuint m_Id;

};

#endif