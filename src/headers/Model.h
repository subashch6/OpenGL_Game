#ifndef _MODEL_H
#define _MODEL_H


#include "GL/glew.h"
#include <vector>


class Model
{
public:
	Model(GLuint , double, std::vector<short>);
	~Model();
	std::vector<short> indicies;
	GLuint vao;
	double size;
	
};

#endif