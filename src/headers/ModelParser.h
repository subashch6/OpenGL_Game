
#ifndef _MODELPARSER_H
#define _MODELPARSER_H


#include <string.h>
#include <string>
#include "GL/glew.h"
#include <fstream>
#include "glm/vec3.hpp"
#include <vector>
#include <sstream>
#include <iostream>

class ModelParser
{
	std::vector<glm::vec3> vertices;
public:
	ModelParser(std::string );
	~ModelParser();
	std::vector<glm::vec3> *getVertices();
private:
	glm::vec3 splitString(std::string , std::string );
};

#endif 
