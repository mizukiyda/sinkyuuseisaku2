// マップ表示基本
#include "DxLib.h"
#include "MAP.h"
#include "Enemy.h"
#include "Player.h"
#include "Scene_Mgr.h"

int ImageWall = 0;
int ImageLoad = 0;
int ImageGoal = 0;

//10はdefineかconstで定義すべき
//むしろ構造体を共通すべき


//初期化
int MAP_Init() {

	//画像の読み込み
	ImageWall = LoadGraph("Image/Wall.png");
	ImageLoad = LoadGraph("Image/Load.png");
	ImageGoal = LoadGraph("Image/Goal.png");

	return 0;

}

//計算
int MAP_Dpct() {
	//Dpctは毎フレーム呼ばれる

	return 0;
}

//描写
int MAP_Draw() {
	//こっちも毎フレーム呼ばれるが計算とは別に書きます


	return 0;
}

//終了
int MAP_End() {

	return 0;
}