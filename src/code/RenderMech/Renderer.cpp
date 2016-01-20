#include "Renderer.h"


double Renderer::RED = 0.0, Renderer::GREEN = 0.0, Renderer::BLUE = 0.6, Renderer::ALPHA = 1.0;



Renderer::Renderer(EntityShader *entityShader, Camera *loadCamera)
{
	shader = entityShader;
	camera = loadCamera;
	glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
    //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
}

void Renderer::render(Model *model)
{
	glClearColor((GLclampf)RED, (GLclampf)GREEN, (GLclampf)BLUE, (GLclampf)ALPHA);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	
	glBindVertexArray(model->vao);
	glEnableVertexAttribArray(0);
	shader->startProgram();
	shader->loadProjectionMatrix(Matricies::projectionMatrix(camera->FOV, camera->aspect, camera->near, camera->far));
    shader->loadTransformationMatrix(Matricies::transformationMatrix(glm::vec3(0,0,0),0,0,0,glm::vec3(1,1,1)));
	shader->loadViewMatrix(Matricies::viewMatrix(*(camera->pos), *(camera->lookAt),*(camera->upVec)));	
    //glDrawArrays(GL_TRIANGLES, 0, model->size);
    int modelStuff[model->indicies.size()];
    for(int i = 0; i < model->indicies.size(); i++)
    {
       modelStuff[i] = model->indicies[i]; 
    }
    glDrawElements(GL_TRIANGLES, model->size, GL_UNSIGNED_INT, modelStuff); 
	shader->stopProgram();
	glDisableVertexAttribArray(0);
	glBindVertexArray(0);
}

Renderer::~Renderer()
{

}
