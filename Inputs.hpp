
#ifndef INPUTS_HPP
# define INPUTS_HPP

#include "glew/include/GL/glew.h"
#include "glfw/include/GLFW/glfw3.h"
#include <math.h>
#include <iostream>
#include <string.h>

#define SCREEN_WIDTH 640
#define SCREEN_HIEGHT 480


class Keys
{

public:
    
    void keyCallback( GLFWwindow *window, int key, int scancode, int action, int mods);
    
    static void cursorPositionCallback(GLFWwindow *window, double xPos, double yPos);
    void cursorEnterCallback( GLFWwindow *window, int entered);
    void mouseButtonCallback( GLFWwindow *window, int button, int action, int mods);
    void scrollCallback( GLFWwindow *window, double xOffset, double yOffset);
    


};

#endif


//g++ main.cpp -L glew/lib -L glfw/lib -I glew/include -I glfw/include -lGLEW  -lglfw -framework OpenGL
