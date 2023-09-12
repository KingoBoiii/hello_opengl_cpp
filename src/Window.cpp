#include "Window.h"

#include <vk.h>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

Window::Window(uint32_t width, uint32_t height, const char *title)
{
    CreateWindow(width, height, title);
}

Window::~Window()
{
    glfwDestroyWindow(m_WindowHandle);
    glfwTerminate();
}

void Window::Update() const
{
    /* Swap front and back buffers */
    glfwSwapBuffers(m_WindowHandle);

    /* Poll for and process events */
    glfwPollEvents();
}

bool Window::IsRunning() const
{
    return !glfwWindowShouldClose(m_WindowHandle);
}

void Window::CreateWindow(uint32_t width, uint32_t height, const char *title)
{
    /* Initialize the library */
    if (!glfwInit()) {
        print("Failed to initialize GLFW library");
        return;
    }

    /* Create a windowed mode window and its OpenGL context */
    m_WindowHandle = glfwCreateWindow((int)width, (int)height, title, NULL, NULL);
    if (!m_WindowHandle)
    {
        print("Failed to initialize GLFW window");
        glfwTerminate();
        return;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(m_WindowHandle);

    /* Setup GLAD */
    if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        print("Failed to initialize GLAD");
        return;
    }
}
