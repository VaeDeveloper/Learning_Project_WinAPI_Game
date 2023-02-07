#pragma once

#include "Falling_Letter.h"
#include "Indicator.h"
#include "Label.h"

//------------------------------------------------------------------------------------------------------------
//									AsInfo_Panel
//------------------------------------------------------------------------------------------------------------
enum class EScore_Event_Type : unsigned char
{
	Hit_Brick,
	Hit_Monster,
	Catch_Latter
};
//------------------------------------------------------------------------------------------------------------
class AsInfo_Panel : public AGame_Object
{
public:
	AsInfo_Panel();

	virtual void Begin_Movement() override;
	virtual void Finish_Movement() override;
	virtual void Advance(double max_speed) override;
	virtual double Get_Speed() override;

	virtual void Act() override;
	virtual void Clear(HDC hdc, RECT& paint_area) override;
	virtual void Draw(HDC hdc, RECT& paint_area) override;
	virtual bool Is_Finished() override;

	void Init();
	void Increase_Life_Count();;
	bool Decrease_Life_Count();
	bool Edit_Player_Name(wchar_t symbol);

	static void Update_Score(EScore_Event_Type event_type, EBrick_Type brick_type = EBrick_Type::None);

	AIndicator Floor_Indicator, Monster_Indicator;

private:
	void Draw_Extra_Life(HDC hdc, int x_pos, int y_pos);
	void Show_Extra_Life(HDC hdc);

	bool Expecting_User_Name;
	int Start_Tick;
	int Extra_Lives_Count;

	AFalling_Letter Letter_P, Letter_G, Letter_M;
	AColor Dark_Blue, Dark_Red;

	ALabel Player_Name_Label, Score_Label;

	static RECT Logo_Rect; // Область логотипа
	static RECT Data_Rect; // Область данных (имени игрока, счета и индикаторов)

	static int Score;

	static const int Logo_X_Pos = 215 ;
	static const int Logo_Y_Pos = 3 ;
	static const int Shadow_X_Offset = 5 ;
	static const int Shadow_Y_Offset = 5 ;


	static const int Score_X = 208;
	static const int Score_Y = 108;
	static const int Score_Width = 110;
	static const int Score_Height = 90;
	static const int Score_Value_Offset = 20;
	static const int Indicator_Y_Offset = 55;
	static const int Bling_Timeout = AsConfig::FPS / 2;
};
//------------------------------------------------------------------------------------------------------------