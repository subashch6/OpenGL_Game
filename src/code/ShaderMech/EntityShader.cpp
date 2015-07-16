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

void EntityShader::startProgram()
{
	glUseProgram(getProgram());
}

void EntityShader::loadViewMatrix(glm::mat4 viewMatrix)
{
	float *viewArray = glm::value_ptr(viewMatrix);
	glUniformMatrix4fv(locations["viewMatrix"], 1,GL_FALSE, glm::value_ptr(viewMatrix));
	fprintf(stdout, " %f \n  %f \n %f \n %f \n %f \n %f \n \n", viewArray[0], viewArray[1], viewArray[2],viewArray[3], viewArray[4], viewArray[5]);
}

void EntityShader::loadProjectionMatrix(glm::mat4 projectionMatrix)
{
	float *projectionArray = glm::value_ptr(projectionMatrix);
	glUniformMatrix4fv(locations["projectionMatrix"], 1,GL_FALSE,glm::value_ptr(projectionMatrix));
	fprintf(stdout, " %f \n \n", projectionArray[0]);
}

void EntityShader::loadTransformationMatrix(glm::mat4 transformationMatrix)
{
	float *transformArray = glm::value_ptr(transformationMatrix[0]);
	glUniformMatrix4fv(locations["transformationMatrix"], 1,GL_FALSE,glm::value_ptr(transformationMatrix));
	fprintf(stdout, " %f \n \n", transformArray[0]);
}
