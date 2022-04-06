#pragma once

// Include Directories
#include <GLFW/glfw3.h>
#include "Creativengine/Logger/Log.h"
//

#ifdef CE_ENGINE
#define CREATIVENGINE_API __declspec(dllexport)
#else
#define CREATIVENGINE_API __declspec(dllimport)
#endif