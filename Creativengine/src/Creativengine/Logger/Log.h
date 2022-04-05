#pragma once

#include "Creativengine.h"

#include <iostream>
#include <ctime>
#include <Windows.h>

namespace Creativengine {

	enum MessageType
	{
		info,
		success,
		warning,
		error,
		criticalError
	};

	class Log
	{
	public:
		Log();
		~Log();

		static void PrintLine(const char* message, MessageType type);
	};

}