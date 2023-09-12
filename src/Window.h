#include <cstdint>

struct GLFWwindow;

class Window {
public:
    Window(uint32_t width, uint32_t height, const char* title);
    ~Window();

    void Update() const;

    bool IsRunning() const;
private:
    void CreateWindow(uint32_t width, uint32_t height, const char* title);
private:
    GLFWwindow* m_WindowHandle;
};