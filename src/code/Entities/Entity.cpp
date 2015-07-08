#include "Entity.h"

Entity::Entity(glm::vec3 positionVector, float rotationx, float rotationy, float rotationz, float entitydialtion)
{
	position = positionVector;
	rotx = rotationx;
	roty = rotationy;
	rotz = rotationz;
	scale = entitydialtion;
}

Entity::~Entity()
{
	
}

glm::vec3 Entity::getPosition() 
{  
	return position;
}

float Entity::getRotationX()
{
	return rotx;
}

float Entity::getRotationY()
{
	return roty;
}


float Entity::getRotationZ()
{
	return rotz;
}
float Entity::getScale()
{
	return scale;
}