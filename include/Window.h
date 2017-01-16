#ifndef WINDOW_H
#define WINDOW_H

#include <string>
#include <iostream>

#include <GLFW/glfw3.h>

using namespace std;


class Window
{
    public:
        Window(int width, int height, string title);
        ~Window();

        GLFWwindow* getWindow();

    protected:
        GLFWwindow* window;

    private:
};

#endif // WINDOW_H
