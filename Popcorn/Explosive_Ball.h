#pragma once

#include "Config.h"
//------------------------------------------------------------------------------------------------------------
//									AExplosion_Ball
//------------------------------------------------------------------------------------------------------------
enum class EExplosive_Ball_State : unsigned char
{
	Idle,
	Charging,
	Expanding,
	Fading
};
//------------------------------------------------------------------------------------------------------------
class AExplosion_Ball : public AGraphics_Object
{
public:
	AExplosion_Ball();

	virtual void Act() override;
	virtual void Clear(HDC hdc, RECT& paint_area) override;
	virtual void Draw(HDC hdc, RECT& paint_area) override;
	virtual bool Is_Finished() override;

	void Explode(int x_pos, int y_pos, int size, bool is_red, int time_offset, int step_count);


private:
	void Update_Ball_Rect();

	EExplosive_Ball_State Explosive_Ball_State;
	bool Is_Red;
	int X_Pos, Y_Pos;
	int Step_Count;
	int Start_Expanding_Tick, Start_Fading_Tick;
	int Time_Offset;

	double Max_Size, Size, Size_Step;
	RECT Ball_Rect;

	static const int Fading_Timeout = AsConfig::FPS;
};
//------------------------------------------------------------------------------------------------------------