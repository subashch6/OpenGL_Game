#ifndef _MODEL_H
#define _MODEL_H


#include "GL/glew.h"
#include <vector>
#include "glm/vec3.hpp"
#include "Loader.h"
#include "glm/vec2.hpp"

class Model
{
public:
	Model(std::vector<glm::vec3> , std::vector<glm::vec2>, std::vector<int> , std::vector<glm::vec3> );
	~Model();
    std::vector<int> indicies;
    GLuint vao;
    GLuint vbos[1];
	int size;	
};

#endif
