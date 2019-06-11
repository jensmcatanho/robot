#ifndef WINDOW_H
#define WINDOW_H

#include <string>

#include <GL/glut.h>

class Window {
	public:
		Window(int argc, char **argv);

		bool Create(std::string title, int width, int height);

		void SwapBuffers() const;

		void SetDisplayCallback(void callback());
};

inline void Window::SwapBuffers() const {
	glutSwapBuffers();
}

inline void Window::SetDisplayCallback(void callback()) {
	glutDisplayFunc(callback);
}

#endif