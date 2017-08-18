
#include "glew/include/GL/glew.h"
#include "glfw/include/GLFW/glfw3.h"
#include <math.h>
#include <iostream>
#include <string.h>

#define SCREEN_WIDTH 640
#define SCREEN_HIEGHT 480

void keyCallback( GLFWwindow *window, int key, int scancode, int action, int mods);

static void cursorPositionCallback(GLFWwindow *window, double xPos, double yPos);
void cursorEnterCallback( GLFWwindow *window, int entered);
void mouseButtonCallback( GLFWwindow *window, int button, int action, int mods);
void scrollCallback( GLFWwindow *window, double xOffset, double yOffset);

int main(void)
{
	GLFWwindow *window;

	//initialize the library

	if(!glfwInit())
	{
		return -1;
	}
	//Create a window mode window abd its OpenGL context

		window = glfwCreateWindow( SCREEN_WIDTH, SCREEN_HIEGHT, "Hello World", NULL, NULL);
		glfwSetKeyCallback(window, keyCallback );
		glfwSetInputMode( window, GLFW_STICKY_KEYS, 1);

		glfwSetCursorPosCallback( window, cursorPositionCallback);
		glfwSetInputMode( window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
		glfwSetScrollCallback( window, scrollCallback);
		glfwSetCursorEnterCallback( window, cursorEnterCallback);
		glfwSetMouseButtonCallback( window, mouseButtonCallback);
		glfwSetInputMode( window, GLFW_STICKY_MOUSE_BUTTONS, 1);
		
		int screenWidth, screenHeight;

	glfwGetFramebufferSize( window, &screenWidth, &screenHeight);

	if(! window )
	{
		glfwTerminate ( );
		return -1;

	}

	glfwMakeContextCurrent ( window );

	glViewport( 0.0f, 0.0f, screenWidth, screenHeight ); //drwa the window
	glMatrixMode ( GL_PROJECTION );//camera and view prjects, zoom facto
	glLoadIdentity( );
	glOrtho(0, SCREEN_WIDTH, 0, SCREEN_HIEGHT, 0, 1 ); //Set cordinate system
	glMatrixMode( GL_MODELVIEW ); //objects are transformed, translation, rotation and scalling
	glLoadIdentity( ); //as above


unsigned char pixels[ 16 * 16 * 4];
memset( pixels, 0xff, sizeof(pixels) );
GLFWimage image;
image.width = 16;
image.height = 16;
image.pixels = pixels;
GLFWcursor *cursor = glfwCreateCursor( &image, 0, 0);
glfwSetCursor(window, cursor);

	
double xPos =0; double yPos =0;
//loop untill the user closes the window
	while(! glfwWindowShouldClose( window ))
	{
		glClear( GL_COLOR_BUFFER_BIT);
		//RENDER OPENGL HERE
		
glfwGetCursorPos( window, &xPos, &yPos);

		//Swap front and back buffers

		glfwSwapBuffers( window );

		//Poll for and process events
		glfwPollEvents( );

	}
	glfwTerminate( );

	return 0;
}


void keyCallback( GLFWwindow *window, int key, int scancode, int action, int mods)
{
std::cout << key << std::endl;
if(key == GLFW_KEY_SPACE)
{
switch (action)
{
case GLFW_PRESS:
std::cout << "Space key pressed" << std::endl;
break;
case GLFW_REPEAT:
std::cout << "Space key being held down" << std::endl;
break;
case GLFW_RELEASE:
std::cout << "Space key being release" << std::endl;
}
}
}
static void cursorPositionCallback(GLFWwindow *window, double xPos, double yPos)
{
	std:: cout << xPos << " : " << yPos << std::endl;

}

void cursorEnterCallback( GLFWwindow *window, int entered)
{
	if( entered)
	{

		std::cout << "Enter Window" << std::endl;
	}
	else
	{
		std::cout << "left Window " << std::endl;
	}

}
void mouseButtonCallback( GLFWwindow *window, int button, int action, int mods)
{
	if ( button == GLFW_MOUSE_BUTTON_RIGHT && action == GLFW_PRESS)
	{
		std::cout << "Right button press" << std::endl;
	}
	if ( button == GLFW_MOUSE_BUTTON_RIGHT && action == GLFW_RELEASE)
	{
		std::cout << "Right button released" << std::endl;
	}
}
void scrollCallback( GLFWwindow *window, double xOffset, double yOffset)
{
	std::cout << xOffset << " : " << yOffset << std::endl;
}
