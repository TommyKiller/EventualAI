#ifndef TESTSCENE_H
#define TESTSCENE_H



#include "Scene.h"



namespace Scenes
{
	class TestScene : public Scenes::Scene
	{
	private:
		void SetCallBacks() override;

	public:
		TestScene(int width, int height, const char *title, int xpos, int ypos);

		TestScene(TestScene &) = delete;

		TestScene & operator==(TestScene &) = delete;

		void StartLoop(GLuint VAO, GLuint shaderProgram) override;
	};

	// CallBack functions //

	void test_scene_key_callback(GLFWwindow *window, int key, int scancode, int action, int mode);
}


#endif
