#ifndef _ENTITY_H
#define _ENTITY_H
#include "glm/vec3.hpp"
#include "Model.h"
#include "glm/mat4x4.hpp"
#include "Matricies.h"


class Entity
{
public:
	Entity(Model* model, glm::vec3 positionVector, float rotationx, float rotationy,   float rotationz, glm::vec3 entityDialation);
	~Entity();
	glm::vec3 getPosition();
	float getRotationX();
	float getRotationY();
	float getRotationZ();
    glm::vec3 getScale();
    glm::mat4x4 getTransform();
    Model* getModel();
private:
	glm::vec3 position;
	float rotx;
	float roty;
	float rotz;
    glm::vec3 scale;
    glm::mat4 transform;
    Model* model;
};
#endif 
 
