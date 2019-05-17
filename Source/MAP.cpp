// マップ表示基本
#include "DxLib.h"
#include "MAP.h"
#include "Enemy.h"
#include "Player.h"
#include "Scene_Mgr.h"

int ImageWall = 0;
int ImageLoad = 0;
int ImageGoal = 0;
int BG;
int i, j;
int px, py;					//受け取るプレイヤーの変数

int MapData[MAP_HEIGHT][MAP_WIDTH] =
{
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,1,1,1,1,1,1,2,1,1,1,1,1,1,0},
{0,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
{0,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
{0,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
{0,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
{0,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
{0,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
{0,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
};
//10はdefineかconstで定義すべき
//むしろ構造体を共通すべき

//プレイヤーの初期x座標を受け取る
int MAP_Player_Pos_Init_x() {

	return px;		//初期化したプレイヤーのx座標を戻す
}

//プレイヤーの初期y座標を受け取る
int MAP_Player_Pos_Init_y() {

	return py;		//初期化したプレイヤーのy座標を戻す
}

int MAP_Data(int x , int y) {
	return MapData[y][x];
}

//初期化
int MAP_Init() {

	//画像の読み込み
	ImageWall = LoadGraph("resource/Image/Wall.png");
	ImageLoad = LoadGraph("resource/Image/Load.png");
	ImageGoal = LoadGraph("resource/Image/Goal.png");

	BG = LoadGraph("resource/Image/BackGround.png");

	px = 5;
	py = 5;
	
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

	// マップを描く
	for (i = 0; i < MAP_HEIGHT; i++)
	{
		for (j = 0; j < MAP_WIDTH; j++)
		{
			if (MapData[i][j] == P_Object_Wall)
			{
				//DrawBox(j * MAP_SIZE, i * MAP_SIZE,j * MAP_SIZE + MAP_SIZE, i * MAP_SIZE + MAP_SIZE,GetColor(0, 230, 0), TRUE);

				DrawGraph(j * MAP_SIZE, i * MAP_SIZE, ImageWall, TRUE);

			}
			if (MapData[i][j] == P_Object_Load)
			{
				//DrawBox(j * MAP_SIZE, i * MAP_SIZE,j * MAP_SIZE + MAP_SIZE, i * MAP_SIZE + MAP_SIZE,GetColor(122, 255, 122), TRUE);

				DrawGraph(j * MAP_SIZE, i * MAP_SIZE, ImageLoad, TRUE);

			}
			if (MapData[i][j] == P_Object_Goal)
			{
				//DrawBox(j * MAP_SIZE, i * MAP_SIZE,j * MAP_SIZE + MAP_SIZE, i * MAP_SIZE + MAP_SIZE,GetColor(122, 122, 255), TRUE);

				DrawGraph(j * MAP_SIZE, i * MAP_SIZE, ImageGoal, TRUE);
			}
		}
	}
	//DrawExtendGraph(0, 0, 1280, 640, BG, true);
	return 0;
}

//終了
int MAP_End() {

	return 0;
}