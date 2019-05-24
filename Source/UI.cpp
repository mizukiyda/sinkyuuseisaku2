#include "DxLib.h"
#include "UI.h"
#include "Keyboard.h"
#include "Player.h"
//#include "Box.h"
#include "Scene_Mgr.h"
#include "Enemy.h"

//ここで変数を宣言（C++を使わないのでグローバル変数）
int ImageMenu = 0;
int Menu_OnActive;
int Menu_x;
int Menu_y;

int UI_Init() {
	//ここで初期化をする
	//画像の読み込み
	ImageMenu = LoadGraph("resource/Image/STR.png");
	Menu_OnActive = false;  //画像非表示

	return 0;
}

int UI_Dpct() {

	//ここで計算
	//Dqctは毎フレーム呼ばれる
	int Key;
	
	if (Menu_OnActive == false) {
		if (Keyboard_Get(KEY_INPUT_M) == 1) {
			Menu_OnActive = true;	//画像表示
		}
	}
	else
	{
		if (Keyboard_Get(KEY_INPUT_M) == 1) {
			Menu_OnActive = false;	//画像表示
		}
	}
	return 0;
}

int UI_Draw() {
	//ここで描写
	//こっちも毎フレーム呼ばれますが計算とは別に書きます
	if (Menu_OnActive == true)
	{
		DrawGraph(Menu_x, Menu_y, ImageMenu, true);
	}

	return 0;
}

int UI_End() {
	//無し
	return 0;
}
