#include <glad/glad.h>
#include <glfw/glfw3.h>
#include "gl2d/gl2d.h"
#include "headers/player.h"

int main()
{
	// Initialize GLFW
	glfwInit();
	GLFWwindow *window = glfwCreateWindow(1200, 800, "Window", nullptr, nullptr);
	glfwMakeContextCurrent(window);
	gladLoadGLLoader((GLADloadproc)(glfwGetProcAddress));
	glfwSwapInterval(1);


	// Initialize gl2d
	gl2d::init();

	Player player;
	player.init();

	gl2d::Renderer2D renderer;
	renderer.create();

	// Load resources example
	//gl2d::Font font(RESOURCES_PATH "roboto_black.ttf");


	// Main loop
	while (!glfwWindowShouldClose(window))
	{
		//very important, don't forget to call renderer.updateWindowMetrics, 
		//this is probably the thing that I forget most often
		int w = 0; int h = 0;
		glfwGetWindowSize(window, &w, &h);
		renderer.updateWindowMetrics(w, h);

		// Set DeltaTime
		currentFrame = glfwGetTime();
		deltaTime = currentFrame - lastFrame;


		// Handle input and update
		player.update(window);

		// Clear screen
		renderer.clearScreen({1.0, 1.0, 1.0, 1});

		// Render objects
		player.draw(&renderer);
		
		// Flush renderer (dump your rendering into the screen)
		renderer.flush();

		// Swap buffers and poll events
		glfwSwapBuffers(window);
		glfwPollEvents();
	} 

	//cleanup if you want, no need for it here tho.
	return 0;
}