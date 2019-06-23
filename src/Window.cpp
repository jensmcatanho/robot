#include "Window.h"

std::shared_ptr<Camera> cameraPtr;

void resizeCallback(GLFWwindow* window, int width, int height);
void mouseCallback(GLFWwindow* window, double xPos, double yPos);
void scrollCallback(GLFWwindow* window, double xOffset, double yOffset);

Window::Window(std::string title, GLint width, GLint height) :
	m_Title(title),
	m_Width(width),
	m_Height(height),
	m_AspectRatio(static_cast<GLfloat>(width/height)) {

}

GLboolean Window::Create(std::shared_ptr<Camera> camera) {
	m_Camera = camera;
	cameraPtr = camera;

	if (!glfwInit()) {
		std::cout << "Error: GLFW failed to initialize. Try again." << std::endl;
		return GL_FALSE;
	}

	std::cout << "Info: GLFW initialized." << std::endl;

	glfwWindowHint(GLFW_SAMPLES, 4);
	m_Window = glfwCreateWindow(m_Width, m_Height, m_Title.c_str(), nullptr, nullptr);
	
	glfwMakeContextCurrent(m_Window);
	glfwSetWindowUserPointer(m_Window, this);

	glfwSetFramebufferSizeCallback(m_Window, resizeCallback);
	glfwSetCursorPosCallback(m_Window, mouseCallback);
	glfwSetScrollCallback(m_Window, scrollCallback);

	return GL_TRUE;
}

GLdouble Window::DisplayFPS() const {
	static GLdouble fps = 0.0f;
	static GLdouble lastFrame = 0.0f;
	GLdouble currentFrame = glfwGetTime();

	++fps;

	GLdouble deltaTime = currentFrame - lastFrame;

	if (deltaTime > 1.0f) {
		lastFrame = currentFrame;
		
		std::stringstream stream;
		stream << m_Title << " - " << fps << " FPS";

		glfwSetWindowTitle(m_Window, stream.str().c_str());
		fps = 0;
	}

	return deltaTime;
}

void Window::ProcessInput(GLdouble deltaTime) const {
	if (glfwGetKey(m_Window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(m_Window, GL_TRUE);

	if (glfwGetKey(m_Window, GLFW_KEY_W) == GLFW_PRESS)
		m_Camera->Move(FORWARD, deltaTime);

	if (glfwGetKey(m_Window, GLFW_KEY_S) == GLFW_PRESS)
		m_Camera->Move(BACKWARD, deltaTime);

	if (glfwGetKey(m_Window, GLFW_KEY_A) == GLFW_PRESS)
		m_Camera->Move(LEFT, deltaTime);

	if (glfwGetKey(m_Window, GLFW_KEY_D) == GLFW_PRESS)
		m_Camera->Move(RIGHT, deltaTime);

}

GLboolean firstMouse = GL_TRUE;
GLdouble lastX = 512.0f;
GLdouble lastY = 384.0f;

void resizeCallback(GLFWwindow* window, int width, int height) {
	glViewport(0, 0, width, height);
}

void mouseCallback(GLFWwindow* window, double xPos, double yPos) {
	if (firstMouse) {
		lastX = xPos;
		lastY = yPos;
		firstMouse = GL_FALSE;
	}

	cameraPtr->Rotate(xPos - lastX, lastY - yPos);

	lastX = xPos;
	lastY = yPos;
}

void scrollCallback(GLFWwindow* windows, double xOffset, double yOffset) {
	cameraPtr->Zoom(yOffset);
}