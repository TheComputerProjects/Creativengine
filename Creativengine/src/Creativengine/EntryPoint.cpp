#include "EntryPoint.h"

namespace Creativengine {

	void Run()
	{
		GLFWwindow* window;

		if (!glfwInit()) {
			Log::PrintLine("Failed initializing GLFW!", MessageType::criticalError);

		}

		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_COMPAT_PROFILE);

		window = glfwCreateWindow(1380, 800, "Creativengine", NULL, NULL);

		glfwMakeContextCurrent(window);

		if (glewInit() != GLEW_OK) {
			Log::PrintLine("Failed initializing GLEW!", MessageType::criticalError);

		}
		else {
			Log::PrintLine("Creativengine loaded successfully!", MessageType::success);
		}

		if (!window)
		{
			glfwTerminate();
			return;
		}

		float positions[] = {
			-0.5f, -0.5f, 0.0f, 0.0f,
			 0.5f, -0.5f, 1.0f, 0.0f,
			 0.5f,  0.5f, 1.0f, 1.0f,
			-0.5f,  0.5f, 0.0f, 1.0f
		};

		unsigned int indices[] = {
			0, 1, 2,
			2, 3, 0
		};

		GLCall(glEnable(GL_BLEND));
		GLCall(glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA));

		unsigned int vao;
		GLCall(glGenVertexArrays(1, &vao));
		GLCall(glBindVertexArray(vao));

		VertexArray va;
		VertexBuffer vb(positions, 4 * 4 * sizeof(float));

		VertexBufferLayout layout;
		layout.Push<float>(2);
		layout.Push<float>(2);
		va.AddBuffer(vb, layout);

		IndexBuffer ib(indices, 6);

		Shader shader("res/shaders/Basic.shader");
		shader.Bind();

		Texture texture("res/textures/ExampleTexture.png");
		texture.Bind();
		shader.SetUniform1i("u_Texture", 0);

		while (!glfwWindowShouldClose(window))
		{
			glClear(GL_COLOR_BUFFER_BIT);

			shader.Bind();

			shader.SetUniform4f("u_Color", 1.0f, 1.0f, 0.5f, 1.0f);
			
			GLCall(glBindVertexArray(vao));
			ib.Bind();
			va.Bind();

			GLCall(glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr));

			GLCall(glClearColor(0.0f, 0.2f, 0.4f, 1.0f));

			/* Swap front and back buffers */
			GLCall(glfwSwapBuffers(window));

			/* Poll for and process events */
			GLCall(glfwPollEvents());

			glfwSetFramebufferSizeCallback(window, [](GLFWwindow* window, int width, int height) {

				glViewport(0, 0, width, height);

			});
		}

		glfwTerminate();
	}

}