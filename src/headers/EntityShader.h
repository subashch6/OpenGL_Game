#ifndef _ENTITYSHADER_H
#define _ENTITYSHADER_H

#include "AbstractShader.h"
#include <string>
#include <map>
#include <glm/mat4x4.hpp>
#include <glm/gtc/type_ptr.hpp>

class EntityShader: public AbstractShader
{
public:
	EntityShader(const char*, const char*);
	void loadUniformLocations();
	void loadViewMatrix(glm::mat4);
	void loadProjectionMatrix(glm::mat4);
	void loadTransformationMatrix(glm::mat4);
private:
	std::map<std::string,GLuint> locations;
};



#endif