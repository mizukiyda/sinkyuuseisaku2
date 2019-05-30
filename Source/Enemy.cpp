#include"Dxlib.h"
//#include"stdlib.h"
#include"Enemy.h"
#include"MAP.h"
#include"Player.h"
#include"Keyboard.h"

int Enemyalive;          //敵の画像の変数(生)
int Enemydeath;          //敵の画像の変数(死)

int Enemy_x;
int Enemy_y;
int Player_x;
int Player_y;
int E_Rand;
int Enemy_OnActive;

int Enemy_Init() {

	Enemyalive = LoadGraph("resource/Image/Enemyalive.png");
	Enemydeath = LoadGraph("resource/Image/Enemydeath.png");

	Enemy_OnActive = true;		//生死判定 == 生きている

	return 0;
}

int Enemy_Dpct() {
	Enemy_x = MAP_Enemy_Pos_Init_x();
	Enemy_y = MAP_Enemy_Pos_Init_y();

	Player_x = Player_Pos_Init_x();
	Player_y = Player_Pos_Init_y();
	if (Enemy_OnActive == true) {
		if (Keyboard_Get(KEY_INPUT_SPACE) == 1)
		{
			Enemy_OnActive = false;
		}
	}

	else
	{
		if (Keyboard_Get(KEY_INPUT_SPACE) == 1)
		{
			Enemy_OnActive = true;
		}
	}
	//E_Rand = GetRand(4);
	/*
	if (Enemy_OnActive == true) {
	if (Keyboard_Get(KEY_INPUT_SPACE) == 1)
	{
	Enemy_OnActive = false;
	}
	}

	else
	{
	if (Keyboard_Get(KEY_INPUT_SPACE) == 1)
	{
	Enemy_OnActive = true;
	}
	}
	*/

	//while (0) {                //無限ループ
	/*switch (E_Rand) {
	case 0:        //上
	Enemy_y--;
	break;

	case 1:      //下
	Enemy_y++;
	break;

	case 2:     //右
	Enemy_x++;
	break;

	case 3:      //左
	Enemy_x--;
	break;

	case 4:      //止
	break;
	}*/
	//return 1;
	if (Player_x + Player_y >= Enemy_x && Player_x <= Enemy_x + Enemy_y) {      //プレイヤーとの当たり判定
		Enemy_OnActive = false;                                                 //当たったら生死判定をfalseにする
		E_Rand = GetRand(4);

		while (1) {                //無限ループ
			switch (E_Rand) {
			case 0:        //上
				Enemy_y -= 64;
				break;

			case 1:      //下
				Enemy_y += 64;
				break;

			case 2:     //右
				Enemy_x += 64;
				break;

			case 3:      //左
				Enemy_x -= 64;
				break;

			case 4:      //止
				break;
			}
			return E_Rand;
		}
	}
}
//Enemyの移動を一つ一つ関数で管理する


//Enemyの移動を一つ一つ関数で管理する

int Enemy_Move0() {
	//if()
	return 0;

}
int  Enemy_Move1() {
	return 0;
}
int  Enemy_Move2() {
	return 0;
}
int  Enemy_Move3() {
	return 0;
}
int  Enemy_Move4() {
	return 0;
}
//	switch (E_Rand) {
int Enemy_Pos_Init_x() {

	return Enemy_x;
}
int Enemy_Pos_Init_y() {

	return Enemy_y;
}

int Enemy_Draw() {
	if (Enemy_OnActive == true)
	{
		DrawGraph(Enemy_x*MAP_SIZE, Enemy_y*MAP_SIZE, Enemyalive, true);
	}
	else
	{
		DrawGraph(Enemy_x*MAP_SIZE, Enemy_y*MAP_SIZE, Enemydeath, true);
	}
	return 0;
}

int Enemy_End() {
	return 0;
}