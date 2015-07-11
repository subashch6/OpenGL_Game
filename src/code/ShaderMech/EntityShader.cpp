#include "EntityShader.h"

EntityShader::EntityShader(const char* vertShaderPath, const char* fragShaderPath):AbstractShader(vertShaderPath,fragShaderPath)
{
	loadUniformLocations();
}

void EntityShader::loadUniformLocations()
{
	locations["move"] = glGetUniformLocation(getProgram(), "move");
	locations["viewMatrix"] = glGetUniformLocation(getProgram(), "viewMatrix");
	locations["projectionMatrix"] = glGetUniformLocation(getProgram(), "projectionMatrix");
	locations["transformationMatrix"] = glGetUniformLocation(getProgram(), "transformationMatrix");
}

void EntityShader::loadMove(float var)
{
	glUniform1f(locations["move"], (GLfloat) var);
}

void EntityShader::loadViewMatrix(glm::mat4x4 viewMatrix)
{
	float *viewArray = glm::value_ptr(viewMatrix);
	glUniformMatrix4fv(locations["viewMatrix"], 1,false,viewArray);
	fprintf(stdout, "%f \n  %f \n %f \n %f \n %f \n %f", viewArray[0], viewArray[1], viewArray[2],viewArray[3], viewArray[4], viewArray[5]);
}

void EntityShader::loadProjectionMatrix(glm::mat4x4 projectionMatrix)
{
	float *projectionArray = glm::value_ptr(projectionMatrix);
	glUniformMatrix4fv(locations["projectionMatrix"], 1,false,projectionArray);
	fprintf(stdout, "%f", projectionArray[0]);
}

void EntityShader::loadTransformationMatrix(glm::mat4x4 transformationMatrix)
{
	float *transformArray = glm::value_ptr(transformationMatrix);
	glUniformMatrix4fv(locations["transformationMatrix"], 1,false,transformArray);
	fprintf(stdout, "%f", transformArray[0]);
}
