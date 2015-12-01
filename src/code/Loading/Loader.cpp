#include "Loader.h"


Loader::Loader()
{

}

Model* Loader::createModel(ModelParser *parser)
{
	GLuint vaoID;
	glGenVertexArrays(1, &vaoID);
	glBindVertexArray(vaoID);
	GLuint vbos[1];
	glGenBuffers(1, vbos);
	glBindBuffer(GL_ARRAY_BUFFER, vbos[0]);
	std::vector <glm::vec3> vecs = parser->vertices;
    for(int i = 0; i< vecs.size(); i++)
    {
        printf("verticies = %f, %f, %f\n", vecs[i][0], vecs[i][1], vecs[i][2]);
    }
    printf("size = %d\n", vecs.size());
	glBufferData(GL_ARRAY_BUFFER, sizeof(glm::vec3) * vecs.size(), &vecs[0] , GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
	glDeleteBuffers(1, vbos);
	Model *model = new Model(vaoID, parser->vertices.size(), parser->indicies);
	return model;
}

Loader::~Loader()
{

}
