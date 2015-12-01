#include "MainGameLoop.h"

const int WIDTH = 800; 

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode)
    {
            // When a user presses the escape key, we set the WindowShouldClose property to true, 
            // closing the application
            if(key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
                glfwSetWindowShouldClose(window, GL_TRUE);
    }   

int main()
{

    std::string input;
    printf("what is your model of choosing? ");
    std::getline(std::cin, input);
    std::string modelPath;
    if(!input.empty())
    {
       modelPath = "../res/" + input + ".obj"; 
    }
    else
    {
        modelPath = "../res/dragon.obj";   
    
    }
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
    
    float vecs[] = {-1.0f, -1.0f, 0.0,
                    1.0f,-1.0f, 0.0f,
                    0.0f, 1.0f, 0.0f};
   
    ModelParser parser(modelPath);
    printf("%d",parser.vertices.size());
    Model *model = Loader::createModel(&parser);
    EntityShader shader("../shaders/TestVert", "../shaders/TestFrag");
    Camera camera(glm::vec3(0,0,10), glm::vec3(0,0,0), glm::vec3(0,1,0), window);
    Renderer renderer(&shader, &camera);
    glfwSetKeyCallback(window, key_callback); 
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
    delete model;
    glfwTerminate();
    exit(EXIT_SUCCESS);
}
