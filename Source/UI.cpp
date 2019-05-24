#include "DxLib.h"
#include "UI.h"
#include "Keyboard.h"
#include "Player.h"
//#include "Box.h"
#include "Scene_Mgr.h"
#include "Enemy.h"


<<<<<<< HEAD



int UI_Init() {

=======
//ここで変数を宣言（C++を使わないのでグローバル変数）
int ImageMenu = 0;
int Menyu_OnActive;
int Menyu_x;
int Menyu_y;

int UI_Init() {
	//ここで初期化をする
	//画像の読み込み
	ImageMenu = LoadGraph("resource/Image/STR.png");
	Menyu_OnActive = false;  //画像非表示
>>>>>>> origin/misima
	return 0;
}

int UI_Dpct() {
<<<<<<< HEAD
=======
	//ここで計算
	//Dqctは毎フレーム呼ばれる
	int Key;
	
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		Key = GetJoypadInputState(DX_INPUT_KEY);
		if (Keyboard_Get(KEY_INPUT_M) == 1) {
			Menyu_OnActive = true;	//画像表示
		}
>>>>>>> origin/misima

	return 0;
}

int UI_Draw() {
	//ここで描写
	//こっちも毎フレーム呼ばれますが計算とは別に書きます
	if (Menyu_OnActive == true)
	{
		DrawGraph(Menyu_x, Menyu_y, ImageMenu, true);
	}

	return 0;
}

int UI_End() {
	//無し
	return 0;
}
