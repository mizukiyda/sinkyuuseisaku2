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

int Menu_Flg;

int UI_Init() {
	//ここで初期化をする
	//画像の読み込み
	ImageMenu = LoadGraph("resource/Image/STR.png");
	Menu_OnActive = false;  //画像非表示

	Menu_Flg = false;
	return 0;
}

int UI_Dpct() {

	//ここで計算
	//Dqctは毎フレーム呼ばれる
	int Key;
	
	if (Menu_OnActive == false) {
		if (Keyboard_Get(KEY_INPUT_M) == 1) {
			Menu_OnActive = true;	//画像表示
			Menu_Flg = true;
		}
	}
	else
	{
		if (Keyboard_Get(KEY_INPUT_M) == 1) {
			Menu_OnActive = false;	//画像表示
			Menu_Flg = false;
		}
	}

	return 0;
}

int UI_Flg() {

	return Menu_Flg;
}
int UI_Draw() {
	//ここで描写
	//こっちも毎フレーム呼ばれますが計算とは別に書きます
	if (Menu_OnActive == true)
	{
		DrawGraph(Menu_x, Menu_y, ImageMenu, true);


		// 描画する文字列のサイズを設定
		SetFontSize(34);
		DrawFormatString(1000, 520, GetColor(255, 0, 0), "HP:200");
		DrawFormatString(1000, 620, GetColor(255, 0, 0), "MP:100");

		//HPのバー
		DrawBox(1000, 560, 1200, 600, GetColor(255, 255, 255), true);
		DrawBox(1010, 570, 1190, 590, GetColor(0, 255, 0), true);
		//MPのバー
		DrawBox(1000, 660, 1200, 700, GetColor(255, 255, 255), true);
		DrawBox(1010, 670, 1190, 690, GetColor(0, 0, 255), true);
	}
	return 0;
}

int UI_End() {
	//無し
	return 0;
}
