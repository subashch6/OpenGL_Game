#ifndef _ABSTRACTSHADER_H
#define _ABSTRACTSHADER_H


#include "GL/glew.h"
#include <string>
#include <fstream>
#include <stdlib.h>

class AbstractShader
{
public:
	GLuint getProgram();
	AbstractShader(const char*, const char*);
	~AbstractShader();

private:
	GLuint program;
	std::string LoadFileToString(const char*);
	GLuint loadShader(const char*, const char*);
	virtual void loadUniformLocations() = 0;
};


#endif