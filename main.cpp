#include <vk.h>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <Window.h>

int main() {
    print("Hello OpenGL!");
    
    Window* window = new Window(640, 480, "Hello OpenGL");

    while(window->IsRunning()) {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        /* Sets the clear color of the screen */
        glClearColor(0.2f, 0.7f, 0.2f, 1.0f);

        window->Update();
    }

    delete window;
    
    return 0;
}