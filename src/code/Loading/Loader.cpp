#include "Loader.h"


Loader::Loader()
{

}

GLuint Loader::makeModel(std::vector<glm::vec3> * vertices)
{
    float verts[vertices->size() * 3];
    for(int i = 0; i < vertices->size(); i++)
    {
       verts[3*i] = vertices->at(i).x;
       verts[3*i+1] = vertices->at(i).y;
       verts[3*i+2] = vertices->at(i).z;
    }
  printf("verticesSize = %zu\n", vertices->size());
	GLuint vaoID;
	glGenVertexArrays(1, &vaoID);
	glBindVertexArray(vaoID);
	GLuint vbos;
	glGenBuffers(1, &vbos);
	glBindBuffer(GL_ARRAY_BUFFER, vbos);
    glEnableVertexAttribArray(0);
	glBufferData(GL_ARRAY_BUFFER, sizeof(float)*3*vertices->size() , verts, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
    glDisableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
	glDeleteBuffers(1, &vbos);
    return vaoID;

}


Loader::~Loader()
{

}
