
#ifndef _MODELPARSER_H
#define _MODELPARSER_H

#include "Model.h"
#include <string.h>
#include <string>
#include "GL/glew.h"
#include <fstream>
#include "glm/vec3.hpp"
#include "glm/vec2.hpp"
#include <vector>
#include <sstream>
#include <iostream>

class Model;

class ModelParser
{
public:
	ModelParser();
	~ModelParser();
    static Model createModel(std::string);
};
#endif  

