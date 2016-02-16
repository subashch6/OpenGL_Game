#include "Entity.h"

Entity::Entity(Model* thisModel, glm::vec3 positionVector, float rotationx, float rotationy, float rotationz, glm::vec3 entityDialation)
{
    model = thisModel;
	position = positionVector;
	rotx = rotationx;
	roty = rotationy;
	rotz = rotationz;
	scale = entityDialation;
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
glm::vec3 Entity::getScale()
{
	return scale;
}
glm::mat4x4 Entity::getTransform()
{
    return Matricies::transformationMatrix(position,rotx,roty,rotz,scale);
}

Model* Entity::getModel()
{   
    return model;
}
