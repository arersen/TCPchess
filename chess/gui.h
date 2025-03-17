#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <stdint.h>

typedef struct{
    GLuint textureID;
    int imgWidth, imgHeight;
} Texture;
void draw_chess_board();
void drawSprite(Texture texture, float x, float y, float spriteWidth, float spriteHeight, int sx, int sy, int sw, int sh);
void loadTexture(Texture* texture, const char* filename);
