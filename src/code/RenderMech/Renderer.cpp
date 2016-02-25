#include "Renderer.h"


double Renderer::RED = 0.0, Renderer::GREEN = 0.3, Renderer::BLUE = 0.6, Renderer::ALPHA = 1.0;



Renderer::Renderer(EntityShader *entityShader, Camera *loadCamera)
{
	shader = entityShader;
	camera = loadCamera;
	glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
    //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    loadProjection(entityShader, loadCamera);
}

void Renderer::render(Entity* entity)
{

	glBindVertexArray(entity->getModel()->vao);
	glEnableVertexAttribArray(0);
    shader->loadTransformationMatrix(entity->getTransform());
    printf("%d\n",entity->getModel()->vbos[0]);
    glDrawElements(GL_TRIANGLES, entity->getModel()->size, GL_UNSIGNED_INT, &entity->getModel()->indicies[0]); 
	glDisableVertexAttribArray(0);
	glBindVertexArray(0);
}

Renderer::~Renderer()
{

}



void Renderer::loadProjection(EntityShader* shader, Camera* camera)
{
    shader->startProgram();
	shader->loadProjectionMatrix(Matricies::projectionMatrix(camera->FOV, camera->aspect, camera->near, camera->far));
    shader->stopProgram();
}


void Renderer::renderList(std::vector<Entity*> entityList)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	
	glClearColor((GLclampf)RED, (GLclampf)GREEN, (GLclampf)BLUE, (GLclampf)ALPHA);
	shader->startProgram();
	shader->loadViewMatrix(Matricies::viewMatrix(*(camera->pos), *(camera->lookAt),*(camera->upVec)));	
    for(std::vector<Entity*>::iterator it = entityList.begin(); it!=entityList.end(); it++)
        render(*it);
	shader->stopProgram();
}
