#include "DxLib.h"
#include "UI.h"
#include "Keyboard.h"
#include "Player.h"
//#include "Box.h"
#include "Scene_Mgr.h"
#include "Enemy.h"

#define HISTORY_MAX 256

//ここで変数を宣言（C++を使わないのでグローバル変数）




int UI_Init() {
	//ここで初期化をする

	
	return 0;
}

int UI_Dpct() {
	//ここで計算
	//Dqctは毎フレーム呼ばれる

	return 0;
}

int UI_Draw() {
	//ここで描写
	//こっちも毎フレーム呼ばれますが計算とは別に書きます

	return 0;
}

int UI_End() {
	//無し
	return 0;
}
