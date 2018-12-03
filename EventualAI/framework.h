#ifndef FRAMEWORK_H
#define FRAMEWORK_H


#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <string>
#include <fstream>
#include <exception>
#include <unordered_map>
#include <vector>
#include <algorithm>


namespace Graphics
{
	GLFWwindow *Initialize(int window_width, int window_height, const char *window_title);

	GLuint InitializeVertexBuffer(GLenum usage, float data[]);

	GLuint CreateShader(GLenum shaderType, std::string fileName);

	GLuint InitializeProgram(std::unordered_map<std::string, GLenum> shaderSourcesList);

	GLuint CreateProgram(std::vector<GLuint> shaderList);

	void Reshape(GLint xpos, GLint ypos, GLsizei width, GLsizei height);
}


#endif
