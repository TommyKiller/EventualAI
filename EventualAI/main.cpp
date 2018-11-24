#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>


void key_callback(GLFWwindow *window, int key, int scancode, int action, int mode)
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
			int window_posx, window_posy;
			glfwGetWindowPos(window, &window_posx, &window_posy);
			glfwSetWindowPos(window, window_posx, window_posy - 10);
			break;
		}
		break;

	case GLFW_KEY_DOWN:
		switch (action)
		{
		case GLFW_REPEAT:
			int window_posx, window_posy;
			glfwGetWindowPos(window, &window_posx, &window_posy);
			glfwSetWindowPos(window, window_posx, window_posy + 10);
			break;
		}
		break;

	case GLFW_KEY_LEFT:
		switch (action)
		{
		case GLFW_REPEAT:
			int window_posx, window_posy;
			glfwGetWindowPos(window, &window_posx, &window_posy);
			glfwSetWindowPos(window, window_posx - 10, window_posy);
			break;
		}
		break;

	case GLFW_KEY_RIGHT:
		switch (action)
		{
		case GLFW_REPEAT:
			int window_posx, window_posy;
			glfwGetWindowPos(window, &window_posx, &window_posy);
			glfwSetWindowPos(window, window_posx + 10, window_posy);
			break;
		}
		break;
	}
}


int main()
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 5);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

	GLFWwindow *window = glfwCreateWindow(1360, 768, "World", nullptr, nullptr);
	if (window == nullptr)
	{
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);

	glewExperimental = GL_TRUE;
	if (glewInit() != GLEW_OK)
	{
		return -1;
	}

	/*gladLoadGL();*/


	glfwSetKeyCallback(window, key_callback);

	glfwSetWindowPos(window, 0, 0);
	int window_width, window_height;
	glfwGetFramebufferSize(window, &window_width, &window_height);
	glViewport(0, 0, window_width, window_height);

	while (!glfwWindowShouldClose(window))
	{
		glfwPollEvents();

		glClearColor(0.2f, 0.4f, 0.4f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		glfwSwapBuffers(window);
	}

	glfwTerminate();
	return 0;
}