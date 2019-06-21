#include "Window.h"

#include <iostream>

Window::Window(std::string title, GLint width, GLint height) :
	m_Title(title),
	m_Width(width),
	m_Height(height),
	m_AspectRatio(static_cast<GLfloat>(width/height)) {

}

GLboolean Window::Create() {
	if (!glfwInit()) {
		std::cout << "Error: GLFW failed to initialize. Try again." << std::endl;
		return GL_FALSE;
	}

	std::cout << "Info: GLFW initialized." << std::endl;

	glfwWindowHint(GLFW_SAMPLES, 4);
	m_Window = glfwCreateWindow(m_Width, m_Height, m_Title.c_str(), nullptr, nullptr);
	
	glfwMakeContextCurrent(m_Window);
	glfwSetWindowUserPointer(m_Window, this);

	return GL_TRUE;
}