#include "window.h"

void framebuffer_size_callback(GLFWwindow* window, int width, int height){
	glViewport(0, 0, width, height);
}
void init_window(GLFWwindow** window, int width, int height){
	if(!glfwInit()){
		fprintf(stderr, "Can`t initialize GLFW\n");
		return;
	}
	
	*window = glfwCreateWindow(width, height, "TCPchess", NULL, NULL);

	if(!*window){
		glfwTerminate();
		fprintf(stderr, "Can`t create OpenGL window.\n");
		return;
	}

	glfwMakeContextCurrent(*window);
	glfwSetFramebufferSizeCallback(*window, framebuffer_size_callback);
	glfwSwapInterval(1);

	if(glewInit() != GLEW_OK){
		fprintf(stderr, "Can't initialize GLEW.\n");
		return;

	}

}
