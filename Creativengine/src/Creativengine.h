#pragma once

// Include Directories
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <stb_image.h>
#include <glm/gtc/matrix_transform.hpp>
#include <ImGuiLibraries/imgui.h>
#include <ImGuiLibraries/imgui_impl_glfw.h>
#include <ImGuiLibraries/imgui_impl_opengl3.h>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

#include "Creativengine/Logger/Log.h"
#include "Creativengine/OpenGL/Renderer.h"
#include "Creativengine/OpenGL/VertexBuffer.h"
#include "Creativengine/OpenGL/IndexBuffer.h"
#include "Creativengine/OpenGL/VertexArray.h"
#include "Creativengine/OpenGL/VertexBufferLayout.h"
#include "Creativengine/OpenGL/Shader.h"
#include "Creativengine/OpenGL/Texture.h"
#include "Creativengine/ImGui/StyledImGui.h"
#include "Creativengine/ImGui/ImGuiDockspace.h"

#include "Creativengine/ImGui/ImGuiPanels/AssetViewerPanel.h"
#include "Creativengine/ImGui/ImGuiPanels/GameObjectsPanel.h"
#include "Creativengine/ImGui/ImGuiPanels/PropertiesPanel.h"
#include "Creativengine/ImGui/ImGuiPanels/WorldSettingsPanel.h"
#include "Creativengine/ImGui/ImGuiPanels/ViewportPanel.h"
//

#ifdef CE_ENGINE
#define CREATIVENGINE_API __declspec(dllexport)
#else
#define CREATIVENGINE_API __declspec(dllimport)
#endif