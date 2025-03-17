#include "gui.h"

#define STB_IMAGE_IMPLEMENTATION
#include "../stb_image.h"




void loadTexture(Texture* texture, const char* filename) {
	glGenTextures(1, &texture->textureID);
	glBindTexture(GL_TEXTURE_2D, texture->textureID);

	int width, height, channels;
	unsigned char* image = stbi_load(filename, &width, &height, &channels, 4);
	if (!image) {
		printf("Failed to load texture: %s\n", filename);
		return;
	}

	texture->imgWidth = width;
	texture->imgHeight = height;


	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	stbi_image_free(image);
}

void drawSprite(Texture texture, float x, float y, float spriteWidth, float spriteHeight, int sx, int sy, int sw, int sh) {
	float u0 = (float)sx / texture.imgWidth;
	float v0 = (float)sy / texture.imgHeight;
	float u1 = (float)(sx + sw) / texture.imgWidth;
	float v1 = (float)(sy + sh) / texture.imgHeight;

	glBindTexture(GL_TEXTURE_2D, texture.textureID);
	glEnable(GL_TEXTURE_2D);

	glBegin(GL_QUADS);
	glTexCoord2f(u0, v0); glVertex2f(x, y);
	glTexCoord2f(u1, v0); glVertex2f(x + spriteWidth, y);
	glTexCoord2f(u1, v1); glVertex2f(x + spriteWidth, y + spriteHeight);
	glTexCoord2f(u0, v1); glVertex2f(x, y + spriteHeight);
	glEnd();
}


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
