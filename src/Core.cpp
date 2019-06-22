#include "Core.h"

#include "Window.h"

Core::Core() :
	m_Window(new Window("Mr. Robot", 1024, 768)) {

}

GLboolean Core::Setup() const {
	if (!m_Window->Create()) {
		std::cout << "Error: Window failed to be created." << std::endl;
		return GL_FALSE;
	}

	glewExperimental = GL_TRUE;
	if (glewInit() != GLEW_OK) {
		std::cout << "Error: GLEW failed to initialize." << std::endl;
		return GL_FALSE;
	}
	std::cout << "Info: GLEW initialized." << std::endl;

	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
	std::cout << "Info: Depth test enabled." << std::endl;

	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);
	std::cout << "Info: Back-face culling enabled." << std::endl;

	return GL_TRUE;
}

void Core::Run() {
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

	while (!m_Window->ShouldClose()) {
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		m_Window->SwapBuffers();
		m_Window->PollEvents();
	}

	m_Window->Close();
}