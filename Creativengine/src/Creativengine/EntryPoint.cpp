#include "EntryPoint.h"

namespace Creativengine {

	void Run()
	{
		// Run At Start Here
		Creativengine::Log::PrintLine("Creativengine Loaded Successfully!", MessageType::success);
		
        GLFWwindow* window;

        /* Initialize the library */
        if (!glfwInit())
            Creativengine::Log::PrintLine("Failed to Initialize GLFW!", MessageType::criticalError);

        glewInit();

        /* Create a windowed mode window and its OpenGL context */
        window = glfwCreateWindow(1380, 800, "Creativengine", NULL, NULL);
        if (!window)
        {
            glfwTerminate();
            Creativengine::Log::PrintLine("Failed to Initialize GLFW Window!", MessageType::criticalError);
        }

        /* Make the window's context current */
        glfwMakeContextCurrent(window);

        /* Loop until the user closes the window */
        while (!glfwWindowShouldClose(window))
        {
            /* Render here */
            glClear(GL_COLOR_BUFFER_BIT);

            glClearColor(0.0f, 0.2f, 0.4f, 1.0f);

            /* Swap front and back buffers */
            glfwSwapBuffers(window);

            /* Poll for and process events */
            glfwPollEvents();

            glfwSetFramebufferSizeCallback(window, [](GLFWwindow* window, int width, int height) {

                glViewport(0, 0, width, height);

            });
        }

        glfwTerminate();

		while (true);
	}

}