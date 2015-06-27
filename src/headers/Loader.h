#ifndef _LOADER_H
#define _LOADER_H

#include "GL/glew.h"
#include "glm/vec3.hpp"

class Loader
{
private:
	int numElements;
	GLuint vaoID;
	GLuint vbos[1];
public:
	Loader(glm::vec3 [], int);
	~Loader();
	void load();
	void clean();
	void add(glm::vec3 [], int );
	void genBuffers();
	GLuint getVaoId();
	int getNumElements();
};

#endif 