#ifndef CAMERA_H
#define CAMERA_H

#include "Prerequisites.h"

enum Direction {
	FORWARD,
	BACKWARD,
	LEFT,
	RIGHT
};

const GLfloat YAW = -89.9f;
const GLfloat PITCH = 0.0f;
const GLfloat SPEED = 0.5f;
const GLfloat SENSITIVITY = 0.1f;
const GLfloat ZOOM = 45.0f;

class Camera {
	public:
		Camera(glm::vec3);

		Camera(GLfloat, GLfloat, GLfloat);

		void Move(Direction, GLfloat);

		void Rotate(GLdouble, GLdouble);

		void Zoom(GLdouble);

		void LookAt(glm::vec3);
	
		glm::mat4 ViewMatrix() const;

		glm::mat4 ProjectionMatrix(GLfloat) const;

	private:
		void UpdateVectors();

		glm::vec3 m_Position;

		glm::vec3 m_U;

		glm::vec3 m_V;

		glm::vec3 m_W;

		glm::vec3 m_WorldUp;

		GLdouble m_Yaw;

		GLdouble m_Pitch;

		GLdouble m_Speed;

		GLdouble m_Sensitivity;

		GLdouble m_Zoom;
};

inline glm::mat4 Camera::ViewMatrix() const {
	return glm::lookAt(m_Position, m_Position - m_W, m_V);
}

inline glm::mat4 Camera::ProjectionMatrix(GLfloat aspectRatio) const {
	return glm::perspective(static_cast<GLdouble>(glm::radians(m_Zoom)), static_cast<GLdouble>(aspectRatio), 0.0001, 1000.0);
}

#endif