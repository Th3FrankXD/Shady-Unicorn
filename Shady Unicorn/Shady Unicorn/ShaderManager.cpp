#include "ShaderManager.h"

ShaderManager shaderManager = ShaderManager();

ShaderManager::ShaderManager()
{
}

ShaderManager::~ShaderManager()
{
}

GLuint ShaderManager::GetShader(std::string name)
{
	for (int i = 0; i < this->shaders.size(); i++)
	{
		if (name == this->shaders[i]->name)
		{
			return this->shaders[i]->shaderID;
		}
	}
	std::cout << "no shaders with the name " << name << " found";
	return -1;
}

void compileShader(Shader* shader)
{
	GLuint shaderID = 0;
	if (shader->shaderType == "vs") {
		shader->shaderID = glCreateShader(GL_VERTEX_SHADER);
	}
	else if (shader->shaderType == "fs") {
		shader->shaderID = glCreateShader(GL_FRAGMENT_SHADER);
	}
	else if (shader->shaderType == "gs") {
		shader->shaderID = glCreateShader(GL_GEOMETRY_SHADER);
	}
	else {
		std::cout << "invalid shaderType\n";
		return;
	}

	std::cout << "compiling shader: " << shader->name << "\n";
	char const * sourcePointer = shader->shaderCode.c_str();
	glShaderSource(shader->shaderID, 1, &sourcePointer, NULL);
	glCompileShader(shader->shaderID);
}

bool checkShader(Shader* shader)
{
	GLint result = GL_FALSE;
	int infoLogLength;

	glGetShaderiv(shader->shaderID, GL_COMPILE_STATUS, &result);
	glGetShaderiv(shader->shaderID, GL_INFO_LOG_LENGTH, &infoLogLength);
	if (infoLogLength > 0) {
		std::vector<char> shaderErrorMessage(infoLogLength + 1);
		glGetShaderInfoLog(shader->shaderID, infoLogLength, NULL, &shaderErrorMessage[0]);
		std::cout << "\n" << &shaderErrorMessage[0];
		return false;
	}
	return true;
}

void ShaderManager::LoadShader(const char* filePath, std::string shaderType, std::string name)
{
	std::string shaderCode;
	std::ifstream shaderStream(filePath, std::ios::in);
	if (shaderStream.is_open()) {
		std::string Line = "";
		while (std::getline(shaderStream, Line))
			shaderCode += "\n" + Line;
		shaderStream.close();
	}
	else {
		std::cout << "unable to open %s\n" << filePath;
		return;
	}

	Shader* shader = new Shader;

	shader->name = name;
	shader->shaderType = shaderType;
	shader->shaderCode = shaderCode;

	compileShader(shader);
	if (!checkShader(shader)){return;}

	this->shaders.push_back(shader);
}

GLuint ShaderManager::CreateProgram(std::vector<GLuint> shaders)
{
	GLint result = GL_FALSE;
	int infoLogLength;

	GLuint programID = glCreateProgram();

	for (int i = 0; i < shaders.size(); i++)
	{
		glAttachShader(programID, shaders[i]);
	}

	glLinkProgram(programID);
	glGetProgramiv(programID, GL_LINK_STATUS, &result);
	glGetProgramiv(programID, GL_INFO_LOG_LENGTH, &infoLogLength);
	if (infoLogLength > 0) {
		std::vector<char> programErrorMessage(infoLogLength + 1);
		glGetProgramInfoLog(programID, infoLogLength, NULL, &programErrorMessage[0]);
		std::cout << "\n" << &programErrorMessage[0];
	}

	for (int i = 0; i < shaders.size(); i++)
	{
		glDetachShader(programID, shaders[i]);
	}

	this->programID = programID;
	return programID;
}