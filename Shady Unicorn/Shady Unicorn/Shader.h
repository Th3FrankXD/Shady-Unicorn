#pragma once

#include <GLFW/glfw3.h>
#include <iostream>

class Shader
{
public:
	GLuint shaderID;
	std::string name;
	std::string shaderType;
	std::string shaderCode;
private:
};