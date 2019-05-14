#include"Dxlib.h"
#include"stdlib.h"
#include"Enemy.h"
#include"MAP.h"
#include"Player.h"
#include"Keyboard.h"


int Enemyalive;          //“G‚Ì‰æ‘œ‚Ì•Ï”(¶)
int Enemydeath;          //“G‚Ì‰æ‘œ‚Ì•Ï”(€)
int Enemy_OnActive;		//Enemy‚Ì¶‘¶Šm”F

int Enemy_Init() {
	Enemyalive = LoadGraph("Resource/Image/Enemyalive.png");
	Enemydeath = LoadGraph("Resource/Image/Enemydeath.png");

	Enemy_OnActive = true;		//¶‚«‚Ä‚¢‚é
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
			Enemy_OnActive = false;
		}
	}
	
	return 0;
}

int Enemy_Draw() {
	if (Enemy_OnActive == true) 
	{
		DrawGraph(100, 100, Enemyalive, true);
	}
	else 
	{
		DrawGraph(100, 100, Enemydeath, true);
	}
	return 0;
}
int Enemy_End() {
	return 0;
}