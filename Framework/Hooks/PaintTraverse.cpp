#include "../Cheat.h"

PaintTraverseFn oPaintTraverse;
void __stdcall Hooks::PaintTraverse(unsigned int panel, bool forceRepaint, bool allowForce)
{
	oPaintTraverse(panel, forceRepaint, allowForce);

	static unsigned int drawPanel;
	if (!drawPanel)
	{
		const char* panelname = I::VPanel->GetName(panel);

		if (panelname[0] == 'M' && panelname[2] == 't')
			drawPanel = panel;
	}

	if (panel != drawPanel)
		return;

	D::DrawPixel(1, 1, Color(0, 0, 0));
		E::Visuals->Run();

		if (Vars.Misc.Ranks && G::PressedKeys[VK_TAB])
			U::ServerRankRevealAll();

		E::ClantagChanger->BeginFrame();
		E::NameChanger->BeginFrame();
}