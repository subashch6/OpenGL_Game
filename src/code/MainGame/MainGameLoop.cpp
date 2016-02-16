#include "MainGameLoop.h"

const int WIDTH = 800; 

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode)
    {
        if(key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
                glfwSetWindowShouldClose(window, GL_TRUE);
    }   

int main()
{
    std::string input;
    printf("what is your model of choosing? (defaults=dragon)  ");
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
    ModelParser modelParser;
    Model model1 = modelParser.createModel(modelPath);
    Model model2 = modelParser.createModel("../res/bunny.obj");
    EntityShader shader("../shaders/TestVert", "../shaders/TestFrag");
    Camera camera(glm::vec3(0,0,20), glm::vec3(0,0,0), glm::vec3(0,1,0), window);
    Renderer renderer(&shader, &camera);
    glfwSetKeyCallback(window, key_callback); 
    Entity entity1(&model1, glm::vec3(0,0,0),0,0,0,glm::vec3(.2,.2,.2));
    Entity entity2(&model2, glm::vec3(20,0,0),0,0,0, glm::vec3(.2,.2,.2));
    std::vector<Entity*> entityList;
    entityList.push_back(&entity1);
    entityList.push_back(&entity2);
    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        renderer.renderList(entityList);
        
        /* Swap front and back buffers */
        glfwSwapBuffers(window);    

        /* Poll for and process events */
        glfwPollEvents();
        camera.checkChanges();
    }
    glfwTerminate();
    exit(EXIT_SUCCESS);
}


