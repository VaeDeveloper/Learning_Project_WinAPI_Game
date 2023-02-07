#pragma once

#include "Config.h"

//------------------------------------------------------------------------------------------------------------
//						AMop_Indicator
//------------------------------------------------------------------------------------------------------------
class AMop_Indicator : public AGraphics_Object
{
public:
	AMop_Indicator(int x_pos, int y_pos, int time_offset);

	virtual void Act() override;
	virtual void Clear(HDC hdc, RECT& paint_area) override;
	virtual void Draw(HDC hdc, RECT& paint_area) override;
	virtual bool Is_Finished() override;

	void Set_Y_Pos(int y_pos);

private:
	int X_Pos, Y_Pos;
	int Time_Offset;
	const AColor* Current_Color;
	RECT Indicator_Rect;

	static const int Width = 17;
	static const int Height = 5;

	static const int Normal_Timeout = AsConfig::FPS;
};
//------------------------------------------------------------------------------------------------------------