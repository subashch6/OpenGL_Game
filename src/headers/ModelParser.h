
#ifndef _MODELPARSER_H
#define _MODELPARSER_H


#include <string.h>
#include <string>
#include "GL/glew.h"
#include <fstream>
#include "glm/vec3.hpp"
#include "glm/vec2.hpp"
#include <vector>
#include <sstream>
#include <iostream>

class ModelParser
{
public:
	ModelParser(std::string );
	~ModelParser();
	std::vector<glm::vec3> getVertices();

private:
	std::vector<glm::vec3> vertices;
	std::vector<glm::vec2> textureCoords;
	std::vector<glm::vec3> vertexNormals;
	glm::vec3 splitString3(std::string , std::string);
	glm::vec2 splitString2(std::string, std::string);
};

#endif  

