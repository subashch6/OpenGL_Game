#include "Loader.h"


Loader::Loader(glm::vec3 positions[], int num)
{
	glGenVertexArrays(1, &vaoID);
	glBindVertexArray(vaoID);
	glEnableVertexAttribArray(0);
	numElements = num;
	genBuffers();
	add(positions, numElements);
	load();
}

void Loader::genBuffers()
{ 
	glGenBuffers(1, vbos);
	glBindBuffer(GL_ARRAY_BUFFER, vbos[0]);
}

Loader::~Loader()
{
	glDisableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
	glDeleteVertexArrays(1, &vaoID);
	glDeleteBuffers(1, vbos);
}

GLuint Loader::getVaoId()
{
	return vaoID;
}

void Loader::load()
{
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void *)0);
	glDisableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);

}

void Loader::add(glm::vec3 positions[], int num)
{
	glBufferData(GL_ARRAY_BUFFER, num * sizeof(positions[0]), positions, GL_STATIC_DRAW);
}

int Loader::getNumElements()
{
	return numElements;
}
