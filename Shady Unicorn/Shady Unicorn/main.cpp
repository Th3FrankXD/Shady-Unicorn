#include <GLAD/glad.h>
#include <GLFW/glfw3.h>
#include <vector>
#include "ShaderManager.h"
#include "StateManager.h"
#include "MainMenu.h"

void loadShaders()
{
	extern ShaderManager shaderManager;
	shaderManager.LoadShader("shaders/vertexShader.vs", "vs", "vertex");
	shaderManager.LoadShader("shaders/fragmentShader.fs", "fs", "fragment");
}

int main(void)
{
	GLFWwindow* window;

	/* Initialize the library */
	if (!glfwInit())
		return -1;

	/* Create a windowed mode window and its OpenGL context */
	window = glfwCreateWindow(1280, 720, "Shady Unicorn", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	/* Make the window's context current */
	glfwMakeContextCurrent(window);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		std::cout << "Failed to initialize OpenGL context" << std::endl;
		return -1;
	}

	loadShaders();

	extern StateManager stateManager;
	stateManager.SetState(new MainMenu);

	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(window))
	{
		/* Render here */
		stateManager.Update();
		stateManager.Render();

		extern ShaderManager shaderManager;
		std::vector<GLuint> shaders;
		shaders.push_back(shaderManager.GetShader("vertex"));
		shaders.push_back(shaderManager.GetShader("fragment"));
		glUseProgram(shaderManager.CreateProgram(shaders));
		glDeleteProgram(shaderManager.programID);

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		float points[] = {
			0.0f,  0.5f,  0.0f,
			0.5f, -0.5f,  0.0f,
			-0.5f, -0.5f,  0.0f
		};

		//////////////////////////////////
		GLuint vbo = 0;
		glGenBuffers(1, &vbo);
		glBindBuffer(GL_ARRAY_BUFFER, vbo);
		glBufferData(GL_ARRAY_BUFFER, 9 * sizeof(float), points, GL_STATIC_DRAW);

		GLuint vao = 0;
		glGenVertexArrays(1, &vao);
		glBindVertexArray(vao);
		glEnableVertexAttribArray(0);
		glBindBuffer(GL_ARRAY_BUFFER, vbo);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL);
		
		/* Starting from vertex 0; 3 vertices total -> 1 triangle */
		glDrawArrays(GL_TRIANGLES, 0, 3);
		glDisableVertexAttribArray(0);
		/////////////////////////////////////

		/* Swap front and back buffers */
		glfwSwapBuffers(window);

		/* Poll for and process events */
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}