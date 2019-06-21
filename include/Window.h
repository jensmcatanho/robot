#ifndef WINDOW_H
#define WINDOW_H

#include <string>

#include "GLFW\glfw3.h"

class Window {
	public:
		Window(std::string title, GLint width, GLint height);

		GLboolean Create();

		GLFWwindow* GetPointer() const;

		void PollEvents() const;

		void SwapBuffers() const;

		GLboolean ShouldClose() const;

		void Close();

	private:
		GLFWwindow *m_Window;

		std::string m_Title;

		int m_Width;

		int m_Height;

		GLfloat m_AspectRatio;
};

inline GLFWwindow* Window::GetPointer() const {
	return m_Window;
}

inline void Window::PollEvents() const {
	glfwPollEvents();
}

inline void Window::SwapBuffers() const {
	glfwSwapBuffers(m_Window);
}

inline GLboolean Window::ShouldClose() const {
	return glfwWindowShouldClose(m_Window);
}

inline void Window::Close() {
	glfwDestroyWindow(m_Window);
	glfwTerminate();
}

#endif