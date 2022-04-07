#pragma once

// Include Directories
#include <GL/glew.h>
#include <GLFW/glfw3.h>
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
//

#ifdef CE_ENGINE
#define CREATIVENGINE_API __declspec(dllexport)
#else
#define CREATIVENGINE_API __declspec(dllimport)
#endif