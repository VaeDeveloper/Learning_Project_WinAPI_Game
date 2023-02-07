#pragma once

#include "Explosion.h"


//------------------------------------------------------------------------------------------------------------
enum class EFinal_Letter_State : unsigned char
{
	Show_Letter,
	Hide_Letter,
	Explosing,
	Color_Letter,
	Finish
};
//------------------------------------------------------------------------------------------------------------
class AFinal_Letter : public AGraphics_Object,public AExplosion
{
public:
	AFinal_Letter(double x_pos, double y_pos, const wchar_t letter, int width = 36, int height = 36);

	virtual void Act() override;
	virtual void Clear(HDC hdc, RECT& paint_area) override;
	virtual void Draw(HDC hdc, RECT& paint_area) override;
	virtual bool Is_Finished() override;

	void Destroy();
	void Set_Color(unsigned char r, unsigned char g, unsigned char b);

	double X_Pos, Y_Pos;

private:
	void Draw_Letter(HDC hdc, bool in_color);
	void Setup_Letter_Rect();
	//bool Explosing, Finished;
	bool Got_Letter_Size;
	wchar_t Letter;
	int Width, Height;
	EFinal_Letter_State Final_Letter_State;

	RECT Letter_Rect;
	AColor Color;
};
//------------------------------------------------------------------------------------------------------------
