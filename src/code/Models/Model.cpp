#include "Model.h"

Model::Model(std::vector<glm::vec3> vertices, std::vector<glm::vec2> uvs, std::vector<int> indexVector, std::vector<glm::vec3>  normals)
{
    
    vao = Loader::makeModel(&vertices);
    printf("finished1\n"); 
    printf("%d\n", vertices.size());
    size = vertices.size();
    indicies = indexVector;//
}

Model::~Model()
{
	glDeleteVertexArrays(1, &vao);
}
