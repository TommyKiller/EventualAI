#include "Scene.h"



Scenes::Scene::Scene(int width, int height, const char *title, int xpos, int ypos)
{
	window = glfwCreateWindow(width, height, title, nullptr, nullptr);
	glfwSetWindowPos(window, xpos, ypos);
}


void Scenes::Scene::AttachViewport(int xpos, int ypos)
{
	glfwGetFramebufferSize(window, &window_width, &window_height);
	glViewport(xpos, ypos, window_width, window_height);
}


void Scenes::Scene::MakeContextCurrent()
{
	glfwMakeContextCurrent(window);
}
