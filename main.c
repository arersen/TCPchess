#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <stdio.h>

#include "window/window.h"
#include "chess/gui.h"

GLFWwindow* window;
Texture texture;

__attribute__((constructor)) void init(){
	init_window(&window, 1024, 1024);
	loadTexture(&texture, "chess/Chess_Pieces_Sprite.png");
	glDisable(GL_DEPTH_TEST);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}
int main(void){

	while(!glfwWindowShouldClose(window)){
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


		draw_chess_board();
		drawSprite(texture, -0.5f, -0.5f, 1.0f, 1.0f, 32, 32, 64, 64);

		glfwSwapBuffers(window);
		
		glfwPollEvents();

	}


	return 0;
}
__attribute__((destructor)) void destroy_window(){
	glfwDestroyWindow(window);
	glfwTerminate();
}
