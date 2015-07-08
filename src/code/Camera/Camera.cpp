#include "Camera.h"

Camera::Camera(glm::vec3 eye, glm::vec3 lookat, glm::vec3 upVec)
{
	pos = &eye;
	lookAt = &lookat;
	up = &upVec;
}	