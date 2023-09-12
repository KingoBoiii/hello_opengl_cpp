#include <vk.h>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

int main() {
    print("Hello OpenGL!");
    
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit()) {
        print("Failed to initialize GLFW library");
        return -1;
    }

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(640, 480, "Hello OpenGL", NULL, NULL);
    if (!window)
    {
        print("Failed to initialize GLFW window");
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        print("Failed to initialize GLAD");
        return -1;
    }

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        /* Clears the screen buffer */
        glClearColor(0.2f, 0.7f, 0.2f, 1.0f);

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}