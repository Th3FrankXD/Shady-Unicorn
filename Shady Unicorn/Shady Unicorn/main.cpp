#include <GLAD/glad.h>
#include <GLFW/glfw3.h>
#include <glm/vec2.hpp>
#include <vector>
#include "ShaderManager.h"
#include "StateManager.h"
#include "MainMenu.h"

void loadShaders()
{
	extern ShaderManager shaderManager;
	shaderManager.LoadShader("shaders/vertexShader.vs", "vs", "mapvs");
	shaderManager.LoadShader("shaders/fragmentShader.fs", "fs", "mapfs");
}

glm::vec2 getScreenSize()
{
	const GLFWvidmode * mode = glfwGetVideoMode(glfwGetPrimaryMonitor());
	return glm::vec2(mode->width, mode->height);
}

glm::vec2 pixToCoord(float x, float y)
{
	int screenWidth = getScreenSize().x;
	int screenHeight = getScreenSize().y;

	float newX = 2.0 / screenWidth * x - 1;
	float newY = 2.0 / screenHeight * y - 1;

	return glm::vec2(newX, newY);
}

void RenderWorld(ShaderManager shaderManager, GLuint vao, GLuint vbo)
{
	std::vector<GLuint> shaders;
	shaders.push_back(shaderManager.GetShader("mapvs"));
	shaders.push_back(shaderManager.GetShader("mapfs"));

	glUseProgram(shaderManager.CreateProgram(shaders));

	GLuint modelMatIdx = glGetUniformLocation(shaderManager.programID, "modelMat");
	GLuint viewMatIdx = glGetUniformLocation(shaderManager.programID, "viewMat");
	GLuint projMatIdx = glGetUniformLocation(shaderManager.programID, "projMat");

	int screenWidth = getScreenSize().x;
	int screenHeight = getScreenSize().y;
	int tileSize = 16;

	std::vector<glm::vec2> vertices;
	for (float y = 0; y < screenHeight / tileSize + 1; y++)
	{
		for (float x = 0; x < screenWidth / tileSize + 1; x++)
		{
			vertices.push_back(pixToCoord(x * tileSize, y * tileSize));
		}
	}

	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(glm::vec2) * vertices.size(), &vertices[0], GL_DYNAMIC_DRAW);

	glBindVertexArray(vao);
	//glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, NULL);

	glEnable(GL_VERTEX_PROGRAM_POINT_SIZE);

	glDrawArrays(GL_POINTS, 0, vertices.size());
	glDisableVertexAttribArray(0);

	glDeleteProgram(shaderManager.programID);
}

int main(void)
{
	GLFWwindow* window;

	if (!glfwInit())
		return -1;

	window = glfwCreateWindow(1280, 720, "Shady Unicorn", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		std::cout << "Failed to initialize OpenGL context" << std::endl;
		return -1;
	}

	loadShaders();

	extern StateManager stateManager;
	stateManager.SetState(new MainMenu);

	GLuint vbo = 0;
	glGenBuffers(1, &vbo);

	GLuint vao = 0;
	glGenVertexArrays(1, &vao);

	while (!glfwWindowShouldClose(window))
	{
		stateManager.Update();
		stateManager.Render();

		extern ShaderManager shaderManager;

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		RenderWorld(shaderManager, vao, vbo);

		glfwSwapBuffers(window);

		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}