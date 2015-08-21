
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
	std::vector<short> indicies;
	std::vector<glm::vec2> textureCoords;
	std::vector<glm::vec3> vertexNormals;
	std::vector<std::string> splitString(std::string , std::string);
	void processVertex(std::vector<std::string>, std::vector<glm::vec2>, std::vector<glm::vec3>);
};

#endif  

