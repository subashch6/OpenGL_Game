#include "Model.h"

Model::Model(GLuint Vao, double sizes, std::vector<short> indexVector)
{
	vao = Vao;
	size = sizes;
	indicies = indexVector;
}

Model::~Model()
{
	glDeleteVertexArrays(1, &vao);
}
