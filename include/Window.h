#ifndef WINDOW_H
#define WINDOW_H

#include "Prerequisites.h"

#include "Camera.h"

class Window {
	public:
		Window(std::string title, GLint width, GLint height);

		GLboolean Create(std::shared_ptr<Camera>);

		GLdouble DisplayFPS() const;

		void ProcessInput(GLdouble) const;

		void PollEvents() const;

		void SwapBuffers() const;

		GLboolean ShouldClose() const;

		void Close();

		glm::mat4 ViewMatrix() const;

		glm::mat4 ProjectionMatrix() const;

	private:
		GLFWwindow *m_Window;

		std::shared_ptr<Camera> m_Camera;

		std::string m_Title;

		int m_Width;

		int m_Height;

		GLfloat m_AspectRatio;
};

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

inline glm::mat4 Window::ViewMatrix() const {
	return m_Camera->ViewMatrix();
}

inline glm::mat4 Window::ProjectionMatrix() const {
	return m_Camera->ProjectionMatrix(m_AspectRatio);
}

#endif