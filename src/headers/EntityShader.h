#ifndef _ENTITYSHADER_H
#define _ENTITYSHADER_H

#include "AbstractShader.h"
#include <string>
#include <map>

class EntityShader: public AbstractShader
{
public:
	EntityShader(const char*, const char*);
	void loadMove(float);
private:
	std::map<std::string,GLint> locations;
	void loadUniformLocations();
};



#endif