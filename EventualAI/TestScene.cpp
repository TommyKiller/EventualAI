#include "TestScene.h"



Scenes::TestScene::TestScene(int width, int height, const char *title, int xpos, int ypos)
	: Scene(width, height, title, xpos, ypos)
{
	SetCallBacks();
}


void Scenes::TestScene::SetCallBacks()
{
	glfwSetKeyCallback(window, Scenes::test_scene_key_callback);
}


void Scenes::TestScene::StartLoop(GLuint VAO, GLuint shaderProgram)
{
	while (!glfwWindowShouldClose(window))
	{
		// Calling CallBack functions //
		glfwPollEvents();

		// Paint algorithm //

		// Clearing the window //
		glClearColor(0.2f, 0.4f, 0.4f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		// Painting the triangle //
		glUseProgram(shaderProgram);
		glBindVertexArray(VAO);
		glDrawArrays(GL_TRIANGLES, 0, 3);
		glBindVertexArray(0);

		// Swap current buffer and newly-painted //
		glfwSwapBuffers(window);
	}
}

// CallBack functions //

void Scenes::test_scene_key_callback(GLFWwindow * window, int key, int scancode, int action, int mode)
{
	switch (key)
	{
	case GLFW_KEY_ESCAPE:
		switch (action)
		{
		case GLFW_PRESS:
			glfwSetWindowShouldClose(window, GL_TRUE);
			break;
		}
		break;

	case GLFW_KEY_UP:
		switch (action)
		{
		case GLFW_REPEAT:

			break;
		}
		break;

	case GLFW_KEY_DOWN:
		switch (action)
		{
		case GLFW_REPEAT:
			break;
		}
		break;

	case GLFW_KEY_LEFT:
		switch (action)
		{
		case GLFW_REPEAT:
			break;
		}
		break;

	case GLFW_KEY_RIGHT:
		switch (action)
		{
		case GLFW_REPEAT:
			break;
		}
		break;
	}
}
