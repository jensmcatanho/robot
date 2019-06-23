#include "Camera.h"

Camera::Camera(glm::vec3 position) :
	m_Position(position),
	m_WorldUp(0.0f, 1.0f, 0.0f),
	m_Yaw(YAW),
	m_Pitch(PITCH),
	m_Speed(SPEED),
	m_Sensitivity(SENSITIVITY),
	m_Zoom(ZOOM) {

	UpdateVectors();
}

Camera::Camera(GLfloat x, GLfloat y, GLfloat z) :
	m_Position(x, y, z),
	m_WorldUp(0.0f, 1.0f, 0.0f),
	m_Yaw(YAW),
	m_Pitch(PITCH),
	m_Speed(SPEED),
	m_Sensitivity(SENSITIVITY),
	m_Zoom(ZOOM) {

	UpdateVectors();
}

void Camera::Move(Direction direction, GLfloat deltaTime) {
	GLfloat velocity = m_Speed * deltaTime;

	if (direction == FORWARD)
		m_Position -= m_W * velocity;
	else if (direction == BACKWARD)
		m_Position += m_W * velocity;
	else if (direction == LEFT)
		m_Position -= m_U * velocity;
	else
		m_Position += m_U * velocity;
}

void Camera::Rotate(GLdouble x, GLdouble y) {
	m_Yaw += x * m_Sensitivity;
	m_Pitch += y * m_Sensitivity;

	if (m_Pitch > 89.9f)
		m_Pitch = 89.9f;
	
	if (m_Pitch < -89.9f)
		m_Pitch = -89.9f;

	UpdateVectors();
}

void Camera::Zoom(GLdouble yOffset) {
	if (m_Zoom >= 1.0f && m_Zoom <= 45.0f)
		m_Zoom -= yOffset;
	else if (m_Zoom <= 1.0f)
		m_Zoom = 1.0f;
	else if (m_Zoom >= 45.0f)
		m_Zoom = 45.0f;
}

void Camera::UpdateVectors() {
	glm::vec3 lookAt;

	lookAt.x = cos(glm::radians(m_Yaw)) * cos(glm::radians(m_Pitch));
	lookAt.y = sin(glm::radians(m_Pitch));
	lookAt.z = sin(glm::radians(m_Yaw)) * cos(glm::radians(m_Pitch));

	m_W = -glm::normalize(lookAt);
	m_U = glm::normalize(glm::cross(m_WorldUp, m_W));
	m_V = glm::cross(m_W, m_U);
}