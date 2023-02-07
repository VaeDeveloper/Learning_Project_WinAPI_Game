#pragma once

#include "Active_Brick.h"

//------------------------------------------------------------------------------------------------------------
//										AFalling_Letter
//------------------------------------------------------------------------------------------------------------
enum class ELetter_Type : unsigned char
{
	O,   // Отмена
	I,   // Инверсия
	C,   // Скорость
	M,   // Монстры
	G,   // Жизнь
	K,   // Клей
	W,   // Шире

	T,   // Три
	L,   // Лазер 
	P,   // Пол

	Plus, // переход на след уровень 

	Max
};
//------------------------------------------------------------------------------------------------------------
enum class EFalling_Letter_State : unsigned char
{
	Normal,
	Finalizing, // начинаем удалять объект
	Finished    // объект можно удалять 
};
class AFalling_Letter : public AGraphics_Object
{
public:
	AFalling_Letter(EBrick_Type brick_type, ELetter_Type letter_type, int x, int y);

	virtual void Act() override;
	virtual void Clear(HDC hdc, RECT& paint_area) override;
	virtual void Draw(HDC hdc, RECT& paint_area) override;
	virtual bool Is_Finished() override;

	void Get_Letter_Cell(RECT& rect);
	void Finalize();
	void Show_Full_Size();
	void Test_Draw_All_Step(HDC hdc);

	static void Init();
	static ELetter_Type Get_Random_Letter_Type();

	const EBrick_Type Brick_Type;
	const ELetter_Type Letter_Type;


private:
	void Set_Brick_Letter_Colors(bool is_switch_color, const AColor** front_color, const AColor** back_color);
	void Draw_Brick_Letter(HDC hdc);
	void Draw_Line(HDC hdc, int x_1, int y_1, int x_2, int y_2);
	void Draw_Line_To(HDC hdc, int x, int y);
	void Draw_C(HDC hdc);

	EFalling_Letter_State Falling_Letter_State;

	int X, Y;
	int Rotation_Step;
	int Next_Rotation_Tick;
	RECT Letter_Cell, Prev_Letter_Cell;

	static const int Ticks_Per_Step = 4;
	static const int Max_Rotation_Step = 16;
	static const int Brick_Half_Height = AsConfig::Brick_Height * AsConfig::Global_Scale / 2;

	static int All_Letters_Popularity;
	static int Letters_Popularity[(int)ELetter_Type::Max]; // редкость (вес) каждой буквы
};
//------------------------------------------------------------------------------------------------------------