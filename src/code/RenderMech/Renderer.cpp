#include "Renderer.h"


double Renderer::RED = 0.0, Renderer::GREEN = 0.0, Renderer::BLUE = 0.4, Renderer::ALPHA = 1.0;



Renderer::Renderer(EntityShader *entityShader, Camera *loadCamera)
{
	shader = entityShader;
	camera = loadCamera;
}

void Renderer::render(Model *model)
{
	glEnable(GL_DEPTH_TEST);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	
	glClearColor((GLclampf)RED, (GLclampf)GREEN, (GLclampf)BLUE, (GLclampf)ALPHA);
	shader->startProgram();
	shader->loadProjectionMatrix(Matricies::projectionMatrix(camera->FOV, camera->aspect, camera->near, camera->far));
	shader->loadTransformationMatrix(Matricies::transformationMatrix(glm::vec3(0,0,0),0,0,0,glm::vec3(1,1,1)));
	shader->loadViewMatrix(Matricies::viewMatrix(*(camera->pos), *(camera->lookAt),*(camera->up)));
	glBindVertexArray(model->getVao());
	glEnableVertexAttribArray(0);
	GLenum error = glGetError();
	fprintf(stderr, "Error = %d\n",error);
	glDrawArrays(GL_TRIANGLES, 0, model->getSize());
	GLenum errors = glGetError();
	fprintf(stderr, "Error = %d\n",errors);
	glDisableVertexAttribArray(0);
	glBindVertexArray(0);
	shader->stopProgram();
	camera->checkChanges();
}

Renderer::~Renderer()
{

}
