#include "Window.h"

Window::Window(int width, int height, string title)
{
    if (glfwInit() == false)
        cerr << "GLFW failed to initialize!" << endl;
    window = glfwCreateWindow(width, height, title, nullptr, nullptr);
    glfwMakeContextCurrent(window);

    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_BLEND);
}

GLFWwindow* Window::getWindow()
{
    return window;
}

Window::~Window()
{
    //dtor
}
