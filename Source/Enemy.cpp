#include"Dxlib.h"
#include"stdlib.h"
#include"Enemy.h"
#include"MAP.h"
#include"Player.h"
#include"Keyboard.h"


int Enemyalive;          //“G‚Ì‰æ‘œ‚Ì•Ï”(¶)
int Enemydeath;          //“G‚Ì‰æ‘œ‚Ì•Ï”(€)
int Enemy_OnActive;		 //Enemy‚Ì¶‘¶Šm”F
int Enemy_x =100;
int Enemy_y = 100;
int E_Rand;

int Enemy_Init() {

	Enemyalive = LoadGraph("Resource/Image/Enemyalive.png");
	Enemydeath = LoadGraph("Resource/Image/Enemydeath.png");

	Enemy_OnActive = true;		//¶‚«‚Ä‚¢‚é

	E_Rand = GetRand(5);

	return 0;
}

int Enemy_Dpct() {
	if (Enemy_OnActive == false) {
		if (Keyboard_Get(KEY_INPUT_SPACE) == 1)
		{
			Enemy_OnActive = true;
		}
	}
	else
	{
		if (Keyboard_Get(KEY_INPUT_SPACE) == 1)
		{ 
	}

	return 0;
	while (1) {

		switch (E_Rand) {
		case E_Drct_Up:
			Enemy_y -= 3;
			break;
		case E_Drct_Down:
			Enemy_y += 3;
			break;
		case E_Drct_Right:
			Enemy_x += 3;
			break;
		case E_Drct_Left:
			Enemy_x -= 3;
			break;
		case E_Drct_Stop:
			break;
		}
	}
	return 0;
}
int Enemy_Draw() {
	if (Enemy_OnActive == true) 
	{
		DrawGraph(Enemy_x, Enemy_y, Enemyalive, true);
	}
	else 
	{
		DrawGraph(Enemy_x,Enemy_y, Enemydeath, true);
	}
	return 0;
}
int Enemy_End() {
	return 0;
}