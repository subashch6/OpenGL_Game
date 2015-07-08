#ifndef _CAMERA_H
#define _CAMERA_H

#include <glm/mat4x4.hpp>
#include <glm/vec3.hpp>


class Camera
{
public:
	glm::vec3 *pos;
	glm::vec3 *lookAt;
	glm::vec3 *up;
	float FOV = 60.0f;
	float aspect = 4.0f/3.0f;
	float near = 0.1f;
	float far = 100.0f;
	Camera(glm::vec3, glm::vec3, glm::vec3);
};

#endif