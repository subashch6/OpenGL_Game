#include "Camera.h"

Camera::Camera(glm::vec3 eye, glm::vec3 lookat, glm::vec3 upVec, GLFWwindow* wind)
{
	pos = &eye;
	lookAt = &lookat;
	up = &upVec;
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
	if(state == GLFW_REPEAT)
	{
		in = true;
	}
	else
	{
		in = false;
	}
	state = glfwGetKey(window, GLFW_KEY_Q);
	if(state == GLFW_REPEAT)
	{
		out = true;
	}
	else
	{
		out = false;
	}
	state = glfwGetKey(window, GLFW_KEY_W);
	if(state == GLFW_REPEAT)
	{
		up = true;
	}
	else
	{
		up = false;
	}
	state = glfwGetKey(window, GLFW_KEY_S);
	if(state == GLFW_REPEAT)
	{
		down = true;
	}
	else
	{
		down = false;
	}
	state = glfwGetKey(window, GLFW_KEY_D);
	if(state == GLFW_REPEAT)
	{
		right = true;
	}
	else
	{
		right = false;
	}
	state = glfwGetKey(window, GLFW_KEY_A);
	if(state == GLFW_REPEAT)
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
		pos[2] -= .1f;
	}
	else if(out)
	{
		pos[2] += .1f;
	}
	if(up)
	{
		pos[1] += .1f;
	}
	else if(down)
	{
		pos[1] -= .1f;
	}
	if(right)
	{
		pos[0] += .1f;
	}
	else if(left)
	{
		pos[0] -= .1f;
	}

}