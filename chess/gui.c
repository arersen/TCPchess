#include "gui.h"

#define STB_IMAGE_IMPLEMENTATION
#include "../stb_image.h"





void draw_chess_board(){

	float square_size = 2.0f / 8;

	for(int row = 0; row < 8; row++){
		for(int col = 0; col < 8; col++){
			if((row + col) % 2 == 0)
				glColor3f(1.0f, 1.0f, 1.0f);
			else
				glColor3f(0.0f, 0.0f, 0.0f);

			float x = -1.0f + col * square_size;
			float y = 1.0f - (row + 1) * square_size;

			glBegin(GL_QUADS);

			glVertex2f(x, y);
			glVertex2f(x + square_size, y);
			glVertex2f(x + square_size, y + square_size);
			glVertex2f(x, y + square_size);

			glEnd();

		}
	}

}
