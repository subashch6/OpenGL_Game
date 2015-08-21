#include "MainGameLoop.h"

const int WIDTH = 800; 



int main()
{

	GLFWwindow* window;

	/* Initialize the library */
	if (!glfwInit())
	{
		fprintf(stderr, "could not init glfw");
		return -1;
	}

	/* Create a windowed mode window and its OpenGL context */
	window = glfwCreateWindow(WIDTH,(int) (.75 * WIDTH), "Super Duper Extreme Alpha", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		fprintf(stderr, "could not init window");
		return -2;
	}
	glfwWindowHint(GLFW_SAMPLES, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 4);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	/* Make the window's context current */
	glfwMakeContextCurrent(window);
	glewExperimental = GL_TRUE;

	if (glewInit() != GLEW_OK)
	{
		fprintf(stderr, "glew did not init");
		glfwTerminate();
		return -4;
	}

	ModelParser parser("../res/box.obj");
	Model *model = Loader::createModel(&parser);
	EntityShader shader("../shaders/TestVert", "../shaders/TestFrag");
	Camera camera(glm::vec3(0,0,20), glm::vec3(0,0,0), glm::vec3(0,1,0), window);
	Renderer renderer(&shader, &camera);
    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
		renderer.render(model);
        /* Swap front and back buffers */
		glfwSwapBuffers(window);	

        /* Poll for and process events */
        glfwPollEvents();
        camera.checkChanges();
    }
    glfwTerminate();
    delete model;
    return 0;
}

