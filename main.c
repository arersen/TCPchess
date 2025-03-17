#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <stdio.h>

#include "window/window.h"

GLFWwindow* window;


__attribute__((constructor)) void init(){
	init_window(&window, 1024, 1024);
}
int main(void){

	while(!glfwWindowShouldClose(window)){
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		glfwSwapBuffers(window);
		
		glfwPollEvents();

	}


	return 0;
}
__attribute__((destructor)) void destroy_window(){
	glfwDestroyWindow(window);
	glfwTerminate();
}
