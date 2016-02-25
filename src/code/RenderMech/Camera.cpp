#include "Camera.h"

Camera::Camera(glm::vec3 eye, glm::vec3 lookat, glm::vec3 upVector, GLFWwindow* wind)
{
	pos = &eye;
	lookAt = &lookat;
	upVec = &upVector;
	window = wind;
}	

void Camera::checkChanges()
{
	int state;
	state = glfwGetKey(window, GLFW_KEY_E);
	if(state == GLFW_PRESS)
	{
        double ax = (lookAt->x - pos->x);
        double bx = (lookAt->y - pos->y);
        double cx = (lookAt->z - pos->z);
        double length = (ax*ax)+(bx*bx)+(cx*cx);
        pos->x += (ax)/(length);
        pos->y += (bx)/(length);
        pos->z += (cx)/(length);
	}
	state = glfwGetKey(window, GLFW_KEY_Q);
	if(state == GLFW_PRESS)
	{
       double ax = (lookAt->x - pos->x);
       double bx = (lookAt->y - pos->y);
       double cx = (lookAt->z - pos->z);
       double length = (ax*ax)+(bx*bx)+(cx*cx);
       pos->x -= (ax)/(length);
       pos->y -= (bx)/(length);
       pos->z -= (cx)/(length);
   	}
	state = glfwGetKey(window, GLFW_KEY_W);
	if(state == GLFW_PRESS)
	{
		lookAt->y += .1f;
	}
	state = glfwGetKey(window, GLFW_KEY_S);
	if(state == GLFW_PRESS)
	{
        lookAt->y -= .1f;
	}
	state = glfwGetKey(window, GLFW_KEY_D);
	if(state == GLFW_PRESS)
	{
        lookAt->x += .1f;
	}
	state = glfwGetKey(window, GLFW_KEY_A);
	if(state == GLFW_PRESS)
	{
		lookAt->x -= .1f;
	}

}
