#include "Model.h"

Model::Model(std::vector<glm::vec3> vertices, std::vector<glm::vec2> uvs, std::vector<int> indexVector, std::vector<glm::vec3>  normals)
{
    
    vao = Loader::makeModel(&vertices);
    size = indexVector.size();
    indicies = indexVector;
}

Model::~Model()
{
	glDeleteVertexArrays(1, &vao);
}
