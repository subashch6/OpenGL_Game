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
	window = glfwCreateWindow(WIDTH,(int) (.75 * WIDTH), "This is great", NULL, NULL);
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


	glm::vec3 positions[] =
	   {glm::vec3(-1.0, -1.0f, 0.0f),
		glm::vec3(1.0f, -1.0f, 0.0f),
		glm::vec3(0.0f, 1.0f, 0.0f)};

	glm::vec3 positions2[] =
		{glm::vec3(1.0, 1.0f, 0.0f),
		glm::vec3(-1.0f, 1.0f, 0.0f),
		glm::vec3(0.0f, -1.0f, 0.0f)};

	int length = sizeof(positions) / sizeof(positions[0]);
	int length2 = sizeof(positions2) / sizeof(positions2[0]);
	std::ifstream stream("../shaders/TestVert", std::ios::in);
	if (stream.is_open())
	{
		std::string line;
		while (getline(stream,line))
		{
			std::cout << line << std::endl;
		}
	}
	else
	{
		fprintf(stdout, "hello");
		std::cout << "ello" << std::endl;
	}
	fprintf(stdout, "Hello \n");
	ModelParser parser("../res/test.obj");
	std::vector<glm::vec3> *vecs = parser.getVertices();
	glm::vec3 *arrayVecs = vecs->data();

	/*glm::vec3 *pos = &vecs[0];
	int newLength = sizeof(vecs[0]) * vecs.size();
	*/

	int newLength = vecs->size();
	Loader load(arrayVecs, newLength);
	//load.add(positions2, length2);
	/*GLuint vaoID = 6;	
	glGenVertexArrays(1,&vaoID);
	glBindVertexArray(vaoID);

	static const GLfloat verts[] =
	{ 
		-1.0, -1.0f, 0.0f,
		1.0f, -1.0f, 0.0f,
		0.0f, 1.0f, 0.0f
	};

	GLuint vboID;
	glGenBuffers(1, &vboID);
	glBindBuffer(GL_ARRAY_BUFFER, vboID);
	glBufferData(GL_ARRAY_BUFFER, sizeof(verts), verts, GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
	glDisableVertexAttribArray(0);*/
	EntityShader shader("../shaders/TestVert", "../shaders/TestFrag");
	//GLuint program = loadShader("shaders/TestVert", "shaders/TestFrag");
	//GLuint program = loadShader("shaders\\TestVert", "shaders\\TestFrag");
	//glClearColor(0.0f,0.0f,1.0f,1.0f);
	GLfloat i = 0;
	//GLint moveLocation = glGetUniformLocation(shader.getProgram(), "move");
	Renderer renderer;
    /* Loop until the user closes the window */
   		fprintf(stdout, "MEOW");
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        shader.loadMove(i);
		i += (GLfloat).0001;
		//glUniform1f(moveLocation, i);
		renderer.render(shader.getProgram(), load.getVaoId(), load.getNumElements());
		//renderer.render(program, load2.getVaoId(), load2.getNumElements());
		/*
		glClear(GL_COLOR_BUFFER_BIT);
		glEnableVertexAttribArray(0);
		glUseProgram(program);
		glDrawArrays(GL_TRIANGLES, 0, newLength);
		glDisableVertexAttribArray(0);*/
        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }
    glfwTerminate();
    return 0;
}

