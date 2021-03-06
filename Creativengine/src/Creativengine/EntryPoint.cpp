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
			100.0f, 100.0f, 0.0f, 0.0f,
			200.0f, 100.0f, 1.0f, 0.0f,
			200.0f, 200.0f, 1.0f, 1.0f,
			100.0f, 200.0f, 0.0f, 1.0f
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

		glm::mat4 proj = glm::ortho(0.0f, 960.0f, 0.0f, 540.0f, -1.0f, 1.0f);
		glm::mat4 view = glm::translate(glm::mat4(1.0f), glm::vec3(-100, 0, 0));
		glm::mat4 model = glm::translate(glm::mat4(1.0f), glm::vec3(200, 200, 0));

		glm::mat4 mvp = proj * view * model;

		Shader shader("res/shaders/Basic.shader");
		shader.Bind();

		Texture texture("res/textures/ExampleTexture.png");
		texture.Bind();
		
		shader.SetUniform1i("u_Texture", 0);
		shader.SetUniformMat4f("u_MVP", mvp);

		IMGUI_CHECKVERSION();
		ImGui::CreateContext();
		ImGuiIO& io = ImGui::GetIO();
		io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;
		ImGui_ImplGlfw_InitForOpenGL(window, true);
		ImGui_ImplOpenGL3_Init("#version 130");
		
		ImVec4 skyColor = ImVec4(0.0f, 0.2f, 0.4f, 1.0f);

		StyledImGui sig;
		sig.AddStyle();

		ImGuiDockspace imguidockspace;
		
		AssetViewerPanel assetViewerPanel;
		GameObjectsPanel gameObjectsPanel;
		PropertiesPanel propertiesPanel;
		//ViewportPanel viewportPanel;
		WorldSettingsPanel worldSettingsPanel(skyColor);
		

		while (!glfwWindowShouldClose(window))
		{
			glClear(GL_COLOR_BUFFER_BIT);

			ImGui_ImplGlfw_NewFrame();

			shader.Bind();

			shader.SetUniform4f("u_Color", 1.0f, 1.0f, 0.5f, 1.0f);
			
			GLCall(glBindVertexArray(vao));
			ib.Bind();
			va.Bind();

			GLCall(glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr));

			//GLCall(glClearColor(skyColor.x * skyColor.w, skyColor.y * skyColor.w, skyColor.z * skyColor.w, skyColor.w));

			ImGui_ImplOpenGL3_NewFrame();
			ImGui_ImplGlfw_NewFrame();
			ImGui::NewFrame();

			imguidockspace.Init();

			assetViewerPanel.Init();
			gameObjectsPanel.Init();
			propertiesPanel.Init();
			//viewportPanel.Init();
			worldSettingsPanel.Init();

			ImGui::Render();
			ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

			GLCall(glfwSwapBuffers(window));

			GLCall(glfwPollEvents());
			
			glViewport(0, 0, 1380 + 400, 800);

			glfwSetFramebufferSizeCallback(window, [](GLFWwindow* window, int width, int height) {

				glViewport(0, 0, width + 400, height);

			});
		}

		glfwTerminate();
	}

}