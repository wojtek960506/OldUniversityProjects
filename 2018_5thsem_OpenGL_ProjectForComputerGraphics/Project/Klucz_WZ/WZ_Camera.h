#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <vector>

//mozliwe ruchy kamery
enum Camera_Movement {
	FORWARD,
	BACKWARD,
	LEFT,
	RIGHT
};

// Domyslne wartosci
const GLfloat YAW			= -90.0f;
const GLfloat PITCH			= 0.0f;
const GLfloat SPEED			= 2.5f;
const GLfloat SENSITIVITY	= 0.1f;
const GLfloat ZOOM			= 45.0f;

#pragma once
class Camera
{
private:
	glm::vec3 position;
	glm::vec3 front;
	glm::vec3 up;
	glm::vec3 right;
	glm::vec3 worldUp;
	// Euler Angles
	GLfloat yaw;
	GLfloat pitch;
	// Camera options
	GLfloat movementSpeed;
	GLfloat mouseSensitivity;
	GLfloat zoom;

public:
	Camera();
	~Camera();

	// Returns the view matrix calculated using Euler Angles and the LookAt Matrix
	glm::mat4 getViewMatrix() {return glm::lookAt(position, position + front, up);}
	GLfloat getZoom() { return zoom; }
	glm::vec3 getPosition() { return position; }
	glm::vec3 getFront() { return front; }

	void processKeyboard(Camera_Movement, GLfloat);
	void processMouseMovement(GLfloat, GLfloat);
	void processMouseScroll(GLfloat);

private:
	void updateCameraVectors();
};

