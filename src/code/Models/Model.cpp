#include "Model.h"

Model::Model(GLuint Vao, double sizes)
{
	vao = Vao;
	size = sizes;
}

Model::~Model()
{
	glDeleteVertexArrays(1, &vao);
}


GLuint Model::getVao()
{
	return vao;
}

double Model::getSize()
{
	return size;
}