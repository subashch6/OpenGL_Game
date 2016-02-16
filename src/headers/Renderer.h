#ifndef _RENDERER_H
#define _RENDERER_H

#include "GL/glew.h"
#include "Loader.h"
#include "EntityShader.h"
#include "Camera.h"
#include "Matricies.h"
#include "Entity.h"



class Renderer
{
	
public:
	Renderer(EntityShader* shader, Camera* camera);
	~Renderer();
    void renderList(std::vector<Entity*> entityList);
private:
	void render(Entity* entity);
	EntityShader *shader;
	Camera *camera;
	int indexes = 0;
	GLuint program;
	GLuint vao;
	static double RED, GREEN, BLUE, ALPHA;
    static void loadProjection(EntityShader* shader, Camera* camera);
};

#endif 
