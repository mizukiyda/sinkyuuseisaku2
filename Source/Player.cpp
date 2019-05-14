#include"DxLib.h"
#include"Player.h"
#include"MAP.h"
#include "Keyboard.h"
#include"Enemy.h"

//ループ用
static int i, j, k;

int Gyallaly[12];    //プレイヤー画像の変数(今回は12分割なので12)
int Player;
P_PLAYER player;
E_Drct drct;

int Player_Init() {

	player.x = 50;
	player.y = 50;

	Gyallaly[12] = {};
	LoadDivGraph("Resource/Image/Player.png", 12, 3, 4, 64, 64, Gyallaly);  //配列「Gyallaly」へ画像を入れる
	Player = LoadGraph("Resource/Image/END.png");
	return 0;
}

int Player_Dpct() {
	//上
	if (Keyboard_Get(KEY_INPUT_UP) == 1)   //↑
	{
		player.y--;    
		drct = E_Drct_Up;
	}
	//左
	if (Keyboard_Get(KEY_INPUT_LEFT) == 1)  //←
	{
		player.x--;      
		drct = E_Drct_Left;
	}
	//下
	if (Keyboard_Get(KEY_INPUT_DOWN) == 1)  //↓
	{
		player.y++;      
		drct = E_Drct_Down;
	}
	//右
	if (Keyboard_Get(KEY_INPUT_RIGHT) == 1) //→
	{
		player.x++;      
		drct = E_Drct_Right;
	}

	return 0;
}

int Player_Draw() {

	DrawGraph(player.x * 64, player.y * 64, Gyallaly[7],true);
	DrawFormatString(700, 20, GetColor(255, 0, 0), "0:上 1:右 2:下 3:左 4:通常");
	DrawFormatString(700, 40, GetColor(255, 0, 0), "Drct:%d", drct);
	

	return 0;
}

int Player_End() {

	return 0;
}