#pragma once

#include <GLAD/glad.h>
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "Shader.h"

class ShaderManager
{
public:
	ShaderManager();
	~ShaderManager();
	void LoadShader(const char* filePath, std::string shaderType, std::string name);
	GLuint CreateProgram(std::vector<GLuint> shaders);
	GLuint GetShader(std::string name);
	std::vector<Shader*> shaders;
	GLuint programID;
private:
};