#include "../headers/player.h"


void Player::init()
{
	x = 100;
	y = 700;
	velocityX = 0;
	velocityY = 0;
	moveDir = 0;
	moveSpeed = 3.14;
}

void Player::draw(gl2d::Renderer2D *renderer)
{
	renderer->renderRectangle({ x ,y, 30, 50 }, Colors_Blue, { 0, 0 }, 0.0f);
}

void Player::update(GLFWwindow* win)
{
	if (glfwGetKey(win, GLFW_KEY_RIGHT) == GLFW_PRESS)
	{
		moveDir = 1;
	}
	else if (glfwGetKey(win, GLFW_KEY_LEFT) == GLFW_PRESS)
	{
		moveDir = -1;
	}
	else
	{
		moveDir = 0;
	}

	velocityX = moveDir * moveSpeed;

	x += velocityX;
}