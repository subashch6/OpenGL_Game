#include "Model.h"

Model::Model(GLuint Vao, double sizes, std::vector<int> indexVector)
{
	vao = Vao;
	size = sizes;
	indicies = indexVector;
}

Model::~Model()
{
	glDeleteVertexArrays(1, &vao);
}
