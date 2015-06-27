#include "Renderer.h"


double Renderer::RED = 0.0, Renderer::GREEN = 0.0, Renderer::BLUE = 0.4, Renderer::ALPHA = 1.0;



Renderer::Renderer()
{
	glClearColor((GLclampf)RED, (GLclampf)GREEN, (GLclampf)BLUE, (GLclampf)ALPHA);
	glDisableVertexAttribArray(0);
	glBindVertexArray(0);
}

void Renderer::readyUp(GLuint Program, GLuint Vao, int indexCount)
{
	//only use glClearColor(RED,GREEN,BLUE,ALPHA); if using one renderer for all rendering
	indexes = indexCount;
	program = Program;
	vao = Vao;
	glUseProgram(program);
	glBindVertexArray(0);
	glBindVertexArray(vao);
	glEnableVertexAttribArray(0);

}

void Renderer::render(GLuint Program, GLuint Vao, int indexCount)
{
	readyUp( Program,  Vao,  indexCount);
	glDrawArrays(GL_TRIANGLES, 0, indexes);
	coolDown();
}

void Renderer::coolDown()
{
	glDisableVertexAttribArray(0);
	glBindVertexArray(0);
}
Renderer::~Renderer()
{

}
