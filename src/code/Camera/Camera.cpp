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
	bool in;
	bool out;
	bool up;
	bool down;
	bool right;
	bool left;
	int state;
	state = glfwGetKey(window, GLFW_KEY_E);
	if(state == GLFW_PRESS)
	{
		in = true;
	}
	else
	{
		in = false;
	}
	state = glfwGetKey(window, GLFW_KEY_Q);
	if(state == GLFW_PRESS)
	{
		out = true;
	}
	else
	{
		out = false;
	}
	state = glfwGetKey(window, GLFW_KEY_W);
	if(state == GLFW_PRESS)
	{
		up = true;
	}
	else
	{
		up = false;
	}
	state = glfwGetKey(window, GLFW_KEY_S);
	if(state == GLFW_PRESS)
	{
		down = true;
	}
	else
	{
		down = false;
	}
	state = glfwGetKey(window, GLFW_KEY_D);
	if(state == GLFW_PRESS)
	{
		right = true;
	}
	else
	{
		right = false;
	}
	state = glfwGetKey(window, GLFW_KEY_A);
	if(state == GLFW_PRESS)
	{
		left = true;
	}
	else
	{
		left = false;
	}
	camChanges(in,out,up,down,right,left);

}

void Camera::camChanges(bool in, bool out, bool up, bool down, bool right, bool left)
{
	if(in)
	{
		pos->z -= .1f;
	}
	else if(out)
	{
		pos->z+= .1f;
	}
	if(up)
	{
		lookAt->y += .1f;
	}
	else if(down)
	{
		lookAt->y -= .1f;
	}
	if(right)
	{
		lookAt->x += .1f;
	}
	else if(left)
	{
		lookAt->x -= .1f;
	}

}