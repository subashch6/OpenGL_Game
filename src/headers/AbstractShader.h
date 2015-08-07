#ifndef _ABSTRACTSHADER_H
#define _ABSTRACTSHADER_H


#include "GL/glew.h"
#include <string>
#include <fstream>
#include <stdlib.h>

class AbstractShader
{
public:
	GLint getProgram();
	AbstractShader(const char*, const char*);
	~AbstractShader();
	void startProgram();
	void stopProgram();
private:
	GLint program;
	std::string LoadFileToString(const char*);
	GLint loadShader(const char*, const char*);
	virtual void loadUniformLocations() = 0;
};


#endif