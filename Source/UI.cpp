#include "DxLib.h"
#include "UI.h"
#include "Keyboard.h"
#include "Player.h"
//#include "Box.h"
#include "Scene_Mgr.h"
#include "Enemy.h"

#define HISTORY_MAX 256

//ここで変数を宣言（C++を使わないのでグローバル変数）
S_History History[HISTORY_MAX];
int StepCount;


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



#ifdef _DEBUG


#endif
	return 0;
}

//プレイヤー履歴
int UI_Player_Move_History() {
	return 0;
}

//ボックス履歴
int UI_Box_Move_History() {
	return 0;
}

//歩数カウント追加
int UI_StepCount_MoveOn() {
	StepCount++;
	return 0;
}

//歩数カウントの提示
int UI_StepCount() {
	return StepCount;
}


int UI_End() {
	//無し
	return 0;
}
