#pragma once

#include "Explosion.h"
#include "Gate.h"
#include "Level.h"

//------------------------------------------------------------------------------------------------------------
enum class EEye_State : unsigned char
{
	Closed,
	Opening,
	Staring,
	Closing
};
//------------------------------------------------------------------------------------------------------------
enum class EMonster_State : unsigned char
{
	Missing,
	Emitting,
	Alive,
	Destroing
};
//------------------------------------------------------------------------------------------------------------
class AMonster :public AHit_Checker, public AGame_Object, public AExplosion
{
public:
	virtual ~AMonster();

	AMonster();

	virtual bool Check_Hit(double next_x_pos, double next_y_pos, ABall_Object* ball) override;
	virtual bool Check_Hit(double next_x_pos, double next_y_pos) override;
	virtual bool Check_Hit(RECT& rect) override;

	virtual void Begin_Movement() override;
	virtual void Finish_Movement() override;
	virtual void Advance(double max_speed) override;
	virtual double Get_Speed() override;

	virtual void Act() override;
	virtual void Clear(HDC hdc, RECT& paint_area) override;
	virtual void Draw(HDC hdc, RECT& paint_area) override;
	virtual bool Is_Finished() override;

	void Activate(double x_pos, double y_pos, bool moving_right);
	void Destroy();
	void Set_Freeze_State(bool freeze);

	static const int Width = 16;
	static const int Height = 16;

protected:
	virtual void Draw_Alive(HDC hdc) = 0;
	virtual void Act_Alive() = 0;
	virtual void On_Activation() = 0;


	EMonster_State Monster_State;
	RECT Monster_Rect, Prev_Monster_Rect;

	double Direction;
	double X_Pos, Y_Pos;
	int Next_Direction_Switch_Tick;
	int Alive_Timer_Tick;

private:
	void Act_Destroing();
	void Get_Monster_Rect(double x_pos, double y_pos, RECT& rect);
	void Redraw_Monster();
	void Change_Direction();

	double Speed, Prev_Speed;
	bool Need_To_Freeze;


};
//------------------------------------------------------------------------------------------------------------
class AMonster_Eye :public AMonster
{
public:
	AMonster_Eye();

private:
	virtual void Draw_Alive(HDC hdc) override;
	virtual void Act_Alive() override;
	virtual void On_Activation() override;

	EEye_State Eye_State;
	double Cornea_Height;
	int Start_Blink_Timeout, Total_Animation_Timeout;

	std::vector<int> Blink_Ticks;

	static const int Blink_Stages_Count = 7;
	static const double Max_Cornea_Height;
	static const double Blink_Timeouts[Blink_Stages_Count];
	static const EEye_State Blink_States[Blink_Stages_Count];

};
//------------------------------------------------------------------------------------------------------------
class AMonster_Comet :public AMonster
{
public:
	AMonster_Comet();

private:
	virtual void Clear(HDC hdc, RECT& paint_area) override;

	virtual void Draw_Alive(HDC hdc) override;
	virtual void Act_Alive() override;
	virtual void On_Activation() override;

	double Current_Angle;
	int Ticks_Per_Rotation;

	static const int Min_Ticks_Per_Rotation = AsConfig::FPS * 2;
	static const int Max_Ticks_Per_Rotation = AsConfig::FPS * 4;

};
//------------------------------------------------------------------------------------------------------------
