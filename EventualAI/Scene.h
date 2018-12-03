#ifndef SCENE_H
#define SCENE_H



#include <GL/glew.h>
#include <GLFW/glfw3.h>


namespace Scenes
{
	class Scene
	{
	protected:
		GLFWwindow *window;
		int window_width, window_height;

		virtual void SetCallBacks() = 0;

	public:
		Scene(int width, int height, const char *title, int xpos, int ypos);

		Scene(Scene &) = delete;

		Scene & operator==(Scene &) = delete;

		virtual void StartLoop(GLuint VAO, GLuint shaderProgram) = 0;

		void AttachViewport(int xpos, int ypos);

		void MakeContextCurrent();
	};

}


#endif
