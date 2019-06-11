#include "Window.h"

Window::Window(int argc, char **argv) {
	glutInit(&argc, argv);
}

bool Window::Create(std::string title, int width, int height) {
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(width, height);
	glutCreateWindow(title.c_str());

	return true;
}