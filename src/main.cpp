#include <iostream>
#include <memory>

#include "GL/glut.h"
#include "Window.h"

void draw();

int main(int argc, char **argv) {
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

	auto window = std::make_shared<Window>(argc, argv);
	window->Create("Mr. Robot", 1024, 768);

	window->SetDisplayCallback(draw);
	glutMainLoop();

	return 0;
}

void draw() {
	glClear(GL_COLOR_BUFFER_BIT);
}