#include "EntityShader.h"

EntityShader::EntityShader(const char* vertShaderPath, const char* fragShaderPath):AbstractShader(vertShaderPath,fragShaderPath)
{
	loadUniformLocations();
}

void EntityShader::loadUniformLocations()
{
	locations["viewMatrix"] = glGetUniformLocation(getProgram(), "viewMatrix");
	locations["projectionMatrix"] = glGetUniformLocation(getProgram(), "projectionMatrix");
	locations["transformationMatrix"] = glGetUniformLocation(getProgram(), "transformationMatrix");
}

void EntityShader::loadViewMatrix(glm::mat4 viewMatrix)
{
	glUniformMatrix4fv(locations["viewMatrix"], 1,GL_FALSE, glm::value_ptr(viewMatrix));
}

void EntityShader::loadProjectionMatrix(glm::mat4 projectionMatrix)
{
	glUniformMatrix4fv(locations["projectionMatrix"], 1,GL_FALSE,glm::value_ptr(projectionMatrix));
}

void EntityShader::loadTransformationMatrix(glm::mat4 transformationMatrix)
{
	glUniformMatrix4fv(locations["transformationMatrix"], 1,GL_FALSE,glm::value_ptr(transformationMatrix));
}
