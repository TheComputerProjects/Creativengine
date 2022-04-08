#include "WorldSettingsPanel.h"

namespace Creativengine {

	WorldSettingsPanel::WorldSettingsPanel(ImVec4 skyColor)
		: m_SkyColor(skyColor)
	{
	}

	WorldSettingsPanel::~WorldSettingsPanel()
	{
	}

	void WorldSettingsPanel::Init()
	{
		ImGui::Begin("World Settings");

		ImGui::ColorEdit3("Sky Color", (float*)&m_SkyColor);

		ImGui::End();

		glClearColor(m_SkyColor.x * m_SkyColor.w, m_SkyColor.y * m_SkyColor.w, m_SkyColor.z * m_SkyColor.w, m_SkyColor.w);
	}

}