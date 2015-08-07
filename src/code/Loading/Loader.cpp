#include "Loader.h"


Loader::Loader()
{

}

Model* Loader::createModel(ModelParser *parser)
{
	GLuint vaoID;
	glGenVertexArrays(1, &vaoID);
	glBindVertexArray(vaoID);
	GLuint *vbos;
	glGenBuffers(1, vbos);
	glBindBuffer(GL_ARRAY_BUFFER, vbos[0]);
	std::vector <glm::vec3> vecs = parser->getVertices();
	glBufferData(GL_ARRAY_BUFFER, sizeof(glm::vec3) * vecs.size(), &vecs[0] , GL_STATIC_DRAW);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void *)0);
	glDisableVertexAttribArray(0);
	glBindVertexArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glDeleteBuffers(1,vbos);
	Model *model = new Model(vaoID, parser->getVertices().size());
	return model;
}

Loader::~Loader()
{

}