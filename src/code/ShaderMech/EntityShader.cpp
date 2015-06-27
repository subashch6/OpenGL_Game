#include "EntityShader.h"

EntityShader::EntityShader(const char* vertShaderPath, const char* fragShaderPath):AbstractShader(vertShaderPath,fragShaderPath)
{
	loadUniformLocations();
}

void EntityShader::loadUniformLocations()
{
	locations["move"] = glGetUniformLocation(getProgram(), "move");
}

void EntityShader::loadMove(float var)
{
	glUniform1f(locations["move"], (GLfloat) var);
}