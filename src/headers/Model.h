#ifndef _MODEL_H
#define _MODEL_H


#include "GL/glew.h"


class Model
{
public:
	Model(GLuint , double);
	~Model();
	GLuint getVao();
	double getSize();
private:
	GLuint vao;
	double size;
};

#endif