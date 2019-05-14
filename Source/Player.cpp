#include"DxLib.h"
#include"Player.h"
#include"MAP.h"
#include "Keyboard.h"
#include"Enemy.h"

//ループ用
static int i, j, k;

//Playerの画像
int Player[12];    //プレイヤー画像の変数(今回は12分割なので12)

//Playerの構造体関係
P_PLAYER player;	
E_Drct drct;

int Player_Init() {

	//Playerの初期位置
	player.x = 100;
	player.y = 150;

	//画像の取得
	Player[12] = {};
	LoadDivGraph("Resource/Image/Player.png", 12, 3, 4, 200, 200,Player);  //配列「Player」へ画像を入れる
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

	//Playerの表示
	//上
	if (drct == E_Drct_Up)
	{
		DrawGraph(player.x, player.y, Player[0], TRUE);
	}
	//左
	if (drct == E_Drct_Left)
	{
		DrawGraph(player.x, player.y, Player[9], TRUE);
	
	}
	//下
	if (drct == E_Drct_Down)
	{
		DrawGraph(player.x , player.y, Player[6], TRUE);
		
	}
	//右
	if (drct == E_Drct_Right)
	{
		DrawGraph(player.x , player.y, Player[3], TRUE);
		
	}

	//デバッグ用処理
	DrawFormatString(700, 20, GetColor(255, 0, 0), "1:上 2:右 3:下 4:左");
	DrawFormatString(700, 40, GetColor(255, 0, 0), "Drct:%d", drct);
	DrawFormatString(700, 60, GetColor(255, 0, 0), "x = %d  \n y = %d", player.x,player.y);


	return 0;
}

int Player_End() {

	return 0;
}