#include "Model.h"

Model::Model(std::vector<glm::vec3> vertices, std::vector<glm::vec2> uvs, std::vector<int> indexVector, std::vector<glm::vec3>  normals)
{
    
    std::vector<GLuint> vaoAndVbos  = Loader::makeModel(&vertices);
    vao = vaoAndVbos[0];
    vbos[0] = vaoAndVbos[1];
    size = indexVector.size();
    indicies = indexVector;
}

Model::~Model()
{
	glDeleteVertexArrays(1, &vao);
	glDeleteBuffers(1, vbos);
}
