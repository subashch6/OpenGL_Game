#include "Renderer.h"


double Renderer::RED = 0.0, Renderer::GREEN = 0.0, Renderer::BLUE = 0.0, Renderer::ALPHA = 1.0;



Renderer::Renderer(EntityShader *entityShader, Camera *loadCamera)
{
	glClearColor((GLclampf)RED, (GLclampf)GREEN, (GLclampf)BLUE, (GLclampf)ALPHA);
	shader = entityShader;
	camera = loadCamera;
	shader->startProgram();
	shader->loadProjectionMatrix(Matricies::projectionMatrix(camera->FOV, camera->aspect, camera->near, camera->far));
	shader->loadTransformationMatrix(Matricies::transformationMatrix(glm::vec3(0,0,0),0,0,0,glm::vec3(1,1,1)));
}

void Renderer::render(Loader load)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	shader->startProgram();
	shader->loadViewMatrix(Matricies::viewMatrix(*(camera->pos), *(camera->lookAt),*(camera->up)));
	glBindVertexArray(load.getVaoId());
	glEnableVertexAttribArray(0);
	fprintf(stderr, "HELP!");
	glDrawArrays(GL_TRIANGLES, 0, load.getNumElements());
	fprintf(stderr, "HELP!");
	camera->checkChanges();
	coolDown();
}

void Renderer::coolDown()
{
	glDisableVertexAttribArray(0);
	glBindVertexArray(0);
	fprintf(stderr, "HELP!");
}
Renderer::~Renderer()
{

}
