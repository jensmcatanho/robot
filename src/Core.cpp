#include "Core.h"

#include "Camera.h"
#include "Cube.h"
#include "Window.h"

Core::Core() :
	m_Window(new Window("Mr. Robot", 1024, 768)) {

}

GLboolean Core::Setup() const {
	auto camera = std::shared_ptr<Camera>(new Camera(0.0f, 0.0f, 5.0f));

	if (!m_Window->Create(camera)) {
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
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

	auto cube = std::shared_ptr<Cube>(new Cube());
	GLuint cubeProgram = LoadShaders("resources/cube.vert", "resources/cube.frag");
	cube->Init(cubeProgram);

	glm::mat4 viewMatrix;
	glm::mat4 projectionMatrix;

	while (!m_Window->ShouldClose()) {
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		viewMatrix = m_Window->ViewMatrix();
		projectionMatrix = m_Window->ProjectionMatrix();

		cube->Draw(projectionMatrix * viewMatrix);
		
		m_Window->SwapBuffers();
		m_Window->PollEvents();

		GLdouble deltaTime = m_Window->DisplayFPS();
		m_Window->ProcessInput(deltaTime);
	}

	m_Window->Close();
}

std::stringstream Core::ReadFile(std::string path) const {
	std::ifstream fileStream;
	std::stringstream stringStream;

	fileStream.exceptions(std::ifstream::badbit);

	try {
		fileStream.open(path);
		stringStream << fileStream.rdbuf();
		fileStream.close();

	} catch (std::ifstream::failure e) {
		std::cerr << "Error: Could not read file " << path << "." << std::endl;
	}

	return stringStream;
}

GLuint Core::LoadShaders(const GLchar* vertexShaderPath, const GLchar* fragShaderPath) const {
	GLint status;

	std::string vertexSource = ReadFile(vertexShaderPath).str();
	const GLchar* vertexCode = const_cast<const GLchar*>(vertexSource.c_str());

	GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vertexCode, nullptr);
	glCompileShader(vertexShader);
	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &status);

	if (!status) {
		char errorLog[512];

		glGetShaderInfoLog(vertexShader, 512, nullptr, errorLog);
		std::cout << "Vertex shader log: " << std::endl << errorLog << std::endl;

		return -1;
	}


	std::string fragSource = ReadFile(fragShaderPath).str();
	const GLchar* fragCode = const_cast<const GLchar*>(fragSource.c_str());

	GLuint fragShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragShader, 1, &fragCode, nullptr);
	glCompileShader(fragShader);
	glGetShaderiv(fragShader, GL_COMPILE_STATUS, &status);

	if (!status) {
		char errorLog[512];

		glGetShaderInfoLog(vertexShader, 512, nullptr, errorLog);
		std::cout << "Fragment shader log: " << std::endl << errorLog << std::endl;

		return -1;
	}

	GLuint shaderProgram = glCreateProgram();

	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragShader);

	glBindAttribLocation(shaderProgram, 0, "a_Position");
	glBindAttribLocation(shaderProgram, 1, "a_Normal");
	glBindAttribLocation(shaderProgram, 2, "a_TexCoord");

	glLinkProgram(shaderProgram);
	glGetProgramiv(shaderProgram, GL_LINK_STATUS, &status);

	if (!status) {
		char errorLog[512];

		glGetProgramInfoLog(shaderProgram, 512, nullptr, errorLog);
		std::cout << "Shader linking log: " << std::endl << errorLog << std::endl;

		return -1;
	}

	glDetachShader(shaderProgram, vertexShader);
	glDeleteShader(vertexShader);

	glDetachShader(shaderProgram, fragShader);
	glDeleteShader(fragShader);

	return shaderProgram;
}