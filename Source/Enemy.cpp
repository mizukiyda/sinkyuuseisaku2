#include"Dxlib.h"
#include"Enemy.h"
#include"MAP.h"
#include"Player.h"
#include"Keyboard.h"

int Enemyalive;          //敵の画像の変数(生)
int Enemydeath;          //敵の画像の変数(死)

//向き
int Drct;

//カウント
int Count_x;
int Count_y;

//enemyの座標
int Enemy_x;
int Enemy_y;
int Enemy_nx;
int Enemy_ny;

//playerの座標
int Player_x;
int Player_y;

int E_Rand;
int Enemy_OnActive;

int E_Move_Flg;

int Enemy_Init() {

	Enemyalive = LoadGraph("resource/Image/Enemyalive.png");
	Enemydeath = LoadGraph("resource/Image/Enemydeath.png");

	Enemy_OnActive = true;		//生死判定 == 生きている

	E_Move_Flg = false;
	return 0;
}

int Enemy_Dpct() {
	Enemy_x = MAP_Enemy_Pos_Init_x();
	Enemy_y = MAP_Enemy_Pos_Init_y();

	Player_x = Player_Pos_Init_x();
	Player_y = Player_Pos_Init_y();

	if (Enemy_OnActive == true) {
		if (E_Move_Flg == false) {
			if (MAP_Data(Enemy_x, Enemy_y) == P_Object_Load) {
				Drct = (E_Drct)GetRand(4);			//動く
				E_Move_Flg = true;
			}
		}


		/*************************************************  Enemyの移動制御  *********************************************************************/

		if (E_Move_Flg == true) {
			switch (Drct)
			{
				//上
			case E_Drct_Up:						//向きが上なら(1)
				Count_y--;						//ヌルヌル動かす
				break;
				//左
			case E_Drct_Left:					//向きが左なら(4)
				Count_x--;						//ヌルヌル動かす
				break;

				//下
			case E_Drct_Down:					//向きが下なら(3)
				Count_y++;						//ヌルヌル動かす
				break;

				//右
			case E_Drct_Right:					//向きが右なら(2)
				Count_x++;						//ヌルヌル動かす
				break;

				//止まる
			case E_Drct_Stop:					//動かない

				break;

			}
			if (Drct == E_Drct_Up) {
				Enemy_ny--;
			}
			if (Drct == E_Drct_Down) {
				Enemy_ny++;
			}
			if (Drct == E_Drct_Right) {
				Enemy_nx++;
			}
			if (Drct == E_Drct_Left) {
				Enemy_nx--;
			}
			//Count_xかCount_yのカウントが±64を達したなら　
			if (Count_x >= MAP_SIZE - 1 || Count_y <= -MAP_SIZE + 1 || Count_x <= -MAP_SIZE + 1 || Count_y >= MAP_SIZE - 1) {
				Count_x = 0;
				Count_y = 0;

				Enemy_x = Enemy_nx;
				Enemy_y = Enemy_ny;

				E_Move_Flg = false;
				//Drct = E_Drct_Stop;
			}
		}
		if (E_Move_Flg == false) {
			//目の前が壁かどうかの判別をする（enemy専用Mapを見て判断する) -> 目の前が壁のとき    -> 1なら
			if (MAP_Data(Enemy_x, Enemy_y) == P_Object_Wall) {

				/*if (E_Drct_Up == true) {
					while (Drct == 1) {								//上から来たから1が来たらも一度回す
						Drct = (E_Drct)GetRand(4);					//（キャスト演算）0～4までの数字で向きをランダムに代入する
					}
				}

				if (E_Drct_Down == true) {
					while (Drct == 3) {								//下から来たから3が来たらも一度回す
						Drct = (E_Drct)GetRand(4);					//（キャスト演算）0～4までの数字で向きをランダムに代入する
					}
				}

				if (E_Drct_Left == true) {
					while (Drct == 4) {								//左から来たから4が来たらも一度回す
						Drct = (E_Drct)GetRand(4);					//（キャスト演算）0～4までの数字で向きをランダムに代入する
					}
				}

				if (E_Drct_Right == true) {
					while (Drct == 2) {								//右から来たから2が来たらも一度回す
						Drct = (E_Drct)GetRand(4);					//（キャスト演算）0～4までの数字で向きをランダムに代入する
					}
				}

				if (E_Drct_Stop == true) {
					while (Drct == 0) {								//停止していたから0が来たらも一度回す
						Drct = (E_Drct)GetRand(4);					//（キャスト演算）0～4までの数字で向きをランダムに代入する
					}
				}*/
				E_Move_Flg = false;
			}
		}
	}
	return 0;
}

//Enemyの移動を一つ一つ関数で管理する
int Enemy_Move() {
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
		DrawGraph(Enemy_x * MAP_SIZE  + Count_x, Enemy_y * MAP_SIZE + Count_y, Enemyalive, true);
	}
	
	return 0;
}

int Enemy_End() {
	return 0;
}