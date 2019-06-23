#ifndef CORE_H
#define CORE_H

#include "Prerequisites.h"

class Core {
	public:
		Core();

		GLboolean Setup() const;

		void Run();

	private:
		std::stringstream ReadFile(std::string path) const;

		GLuint LoadShaders(const GLchar*, const GLchar*) const;

		unsigned char* LoadTexture(const std::string, GLint*, GLint*) const;

		std::shared_ptr<Window> m_Window;
};

#endif