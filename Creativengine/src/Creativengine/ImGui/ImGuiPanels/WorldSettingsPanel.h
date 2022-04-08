#pragma once

#include <Creativengine.h>

namespace Creativengine {

	class WorldSettingsPanel
	{
	public:

		WorldSettingsPanel(ImVec4 SkyColor);
		~WorldSettingsPanel();

		void Init();

	private:
		ImVec4 m_SkyColor;
	};

}