#ifndef _LOADER_H
#define _LOADER_H

#include "GL/glew.h"
#include "glm/vec3.hpp"
#include "ModelParser.h"
#include "Model.h"

class Loader
{
private:
public:
	Loader();
	~Loader();
	static GLuint makeModel(std::vector<glm::vec3> *);
};

#endif 
