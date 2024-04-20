#ifndef PLAYER_H
#define PLAYER_H
#include "gl2d/gl2d.h"
#include <GLFW/glfw3.h>

class Player
{
public:
	float x, y;
	float velocityX, velocityY;
	float moveSpeed;
	int moveDir;

	void init();
	void update(GLFWwindow *win);
	void draw(gl2d::Renderer2D *renderer);
};

#endif