#pragma once

#include "Explosive_Ball.h"
//------------------------------------------------------------------------------------------------------------
//									AExplosion
//------------------------------------------------------------------------------------------------------------
class AExplosion
{
protected:
	AExplosion();

	void Start_Explosion(RECT& area_rect);
	bool Act_Explosion();
	void Draw_Explosion(HDC hdc, RECT& paint_area);

private:
	std::vector<AExplosion_Ball> Explosive_Balls;
	static const int Explosive_Balls_Count = 20;
};
//------------------------------------------------------------------------------------------------------------
