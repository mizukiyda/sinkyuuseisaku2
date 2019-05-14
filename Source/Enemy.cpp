#include"Dxlib.h"
#include"stdlib.h"
#include"Enemy.h"
#include"MAP.h"
#include"Player.h"
#include"Keyboard.h"


int Enemyalive;          //“G‚Ì‰æ‘œ‚Ì•Ï”(¶)
int Enemydeath;          //“G‚Ì‰æ‘œ‚Ì•Ï”(€)


int Enemy_Init() {
	Enemyalive=LoadGraph("Resource/Image/Enemy.png");
	Enemydeath=LoadGraph("Resource/Image/Enemydeath.png");
	return 0;
}

int Enemy_Dpct() {

	if(Keyboard_Get(KEY_INPUT_UP) == 1)   //ª
	{
		DrawFormatString(100, 200, GetColor(255, 0, 0), "“®‚¢‚Ä‚é‚æ‚ñ");
	}
	return 0;
}

int Enemy_Draw() {
	DrawGraph(100, 100, Enemyalive, true);
	return 0;
}
int Enemy_End() {
	return 0;
}