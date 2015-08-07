#ifndef _ENTITY_H
#define _ENTITY_H
#include "glm/vec3.hpp"


class Entity
{
public:
	Entity(glm::vec3, float, float, float, float);
	~Entity();
	glm::vec3 getPosition();
	float getRotationX();
	float getRotationY();
	float getRotationZ();
	float getScale();
private:
	glm::vec3 position;
	float rotx;
	float roty;
	float rotz;
	float scale;

};
#endif 
 