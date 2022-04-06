#include "Renderer.h"

#include <Creativengine.h>

namespace Creativengine {

	void GLClearError()
	{
		while (glGetError() != GL_NO_ERROR);
	}

	bool GLLogCall()
	{
		while (GLenum error = glGetError())
		{
			//const char* formattedError = "[OpenGL Error]" + error;

			Log::PrintLine("An OpenGL error occurred!", MessageType::criticalError);

			return false;
		}
		return true;
	}

}