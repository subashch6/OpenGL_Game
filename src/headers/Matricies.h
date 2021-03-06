#ifndef _MATRICIES_H
#define _MATRICIES_H


#include <glm/gtc/matrix_transform.hpp>
#include <glm/mat4x4.hpp>
#include <glm/vec3.hpp>

class Matricies
{
public:
	static glm::mat4 transformationMatrix(glm::vec3 , float , float , float , glm::vec3 );
	static glm::mat4 viewMatrix(glm::vec3, glm::vec3, glm::vec3);
	static glm::mat4 projectionMatrix(float, float, float, float);
private:
};

#endif 