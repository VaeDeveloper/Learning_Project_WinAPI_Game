#pragma once


#include "Label.h"


//------------------------------------------------------------------------------------------------------------
//                                          Level_Title
//------------------------------------------------------------------------------------------------------------
enum class ELevel_Title_State : unsigned char
{
	Missing,
	Showing,
	Hiding
};
//------------------------------------------------------------------------------------------------------------
class AsLevel_Title : public AGraphics_Object 
{
public:
	AsLevel_Title();

	virtual void Act() override;
	virtual void Clear(HDC hdc, RECT& paint_area) override;
	virtual void Draw(HDC hdc, RECT& paint_area) override;
	virtual bool Is_Finished() override;

	void Show(int level_number);
	void Hide();

private:
	//bool Is_Visible;
	ELevel_Title_State Level_Title_State;
	ALabel Level_Name, Level_Number;
	RECT Title_Rect;

	static const int Width = 96;
	static const int Height = 14;
	static const int X_Pos = AsConfig::Max_X_Pos / 2 - Width / 2;
	static const int Y_Pos = 150;
};
//------------------------------------------------------------------------------------------------------------
