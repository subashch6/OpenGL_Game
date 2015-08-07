#ifndef _RENDERER_H
#define _RENDERER_H

#include "GL/glew.h"
#include <iostream>
#include "Loader.h"
#include "EntityShader.h"
#include "Camera.h"
#include "Matricies.h"
#include <thread>
#include <chrono>

class Renderer
{
	
public:
	Renderer(EntityShader*, Camera*);
	~Renderer();
	void render(Model*);
private:
	EntityShader *shader;
	Camera *camera;
	int indexes = 0;
	GLuint program;
	GLuint vao;
	static double RED, GREEN, BLUE, ALPHA;
};

#endif 
