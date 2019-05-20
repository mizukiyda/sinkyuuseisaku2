#include"DxLib.h"
#include"Player.h"
#include"MAP.h"
#include "Keyboard.h"
#include"Enemy.h"
#include"Scene_Mgr.h"

//ループ用
static int i, j, k;

//Playerの画像
int Player[12];				//プレイヤー画像の変数(今回は12分割なので12)
int None;					//画像のスタンバイ状態(静止状態)
int Player_Animetion;		//Playerのアニメーション

//Playerの構造体関係
P_PLAYER player;	
E_Drct drct;				//向き

//Player用の変数
int count_x;		//Mapサイズのカウント(x)
int count_y;		//Mapサイズのカウント(y)

//Playerのフラグ
int Move_Flg;			//Playerが動いるいるかどうかのフラグ
int Player_Hit_Flg;		//PlayerがEnemyと当たったかどうかのフラグ

int Player_Init() {

	//Playerの初期位置(Mapからもらう)
	player.x = MAP_Player_Pos_Init_x();
	player.y = MAP_Player_Pos_Init_y();
	player.nx = player.x;
	player.ny = player.y;

	//画像の取得
	Player[12] = {};
	LoadDivGraph("Resource/Image/Player.png", 12, 3, 4, 64, 64,Player);  //配列「Player」へ画像を入れる
	None = 7;					//正面を向いている状態
	Player_Animetion = 0;		//何もしていない状態

	//移動
	count_x = 0;
	count_y = 0;
	Move_Flg = false;
	drct = E_Drct_Stop;

	//当たり判定
	Player_Hit_Flg = false;

	return 0;
}

int Player_Dpct() {

	

	if (Move_Flg == false) {
		player.nx = player.x;
		player.ny = player.y;
		//上
		if (Keyboard_Get(KEY_INPUT_UP) == 1)   //↑
		{
			player.ny--;
			drct = E_Drct_Up;
		}
		//右
		if (Keyboard_Get(KEY_INPUT_RIGHT) == 1) //→
		{
			player.nx++;
			drct = E_Drct_Right;
		}
		//下
		if (Keyboard_Get(KEY_INPUT_DOWN) == 1)  //↓
		{
			player.ny++;
			drct = E_Drct_Down;
		}
		//左
		if (Keyboard_Get(KEY_INPUT_LEFT) == 1)  //←
		{
			player.nx--;
			drct = E_Drct_Left;
		}

		//エンターキーを押したらResultSceneへ（デバッグ用）
		if (Keyboard_Get(KEY_INPUT_RETURN) == 1) //→
		{
			Scene_Mgr_ChangeScene(E_Scene_Result);
		}

		//Playerの移動先のチェック（壁か道か）
		if (drct != E_Drct_Stop)	//キーが入力されているなら(止まっていないなら)
		{
			Player_Check();
		}

		//移動させる
		if (Move_Flg == true) {		//移動先が道だった時
			Player_Move();
		}
	}
	return 0;
}

int Player_Check() {

	if (MAP_Data(player.nx, player.ny) == P_Object_Load || MAP_Data(player.nx, player.ny) == P_Object_Goal) {
		Move_Flg = true;			//動く
	}
	
	if (MAP_Data(player.nx, player.ny) == P_Object_Wall) {
		Move_Flg = false;
		drct = E_Drct_Stop;
	}
	return 0;
}

int Player_Move() {

	//Playerをヌルヌル動かす処理
	switch (drct) {

		//上
	case E_Drct_Up:
		count_y--;
		break;
		//右
	case E_Drct_Right:
		count_x++;
		break;
		//下
	case E_Drct_Down:
		count_y++;
		break;
		//左
	case E_Drct_Left:
		count_x--;
		break;
	}

	//count_xかcount_yのカウントが±64を達したなら　
	if (count_x >= MAP_SIZE - 1 || count_y <= -MAP_SIZE + 1 || count_x <= -MAP_SIZE + 1 || count_y >= MAP_SIZE - 1){
		//プレイヤーの座標に仮の座標を代入して座標を更新(描画の際に使うのはplayer.x,player.y)
		player.y = player.ny;
		player.x = player.nx;

		//カウントの初期化
		count_x = 0;
		count_y = 0;

		//フラグと向きの管理
		Move_Flg = false;
		drct = E_Drct_Stop;
	}
		return 0;
}

int Player_Draw() {
	//Playerの表示

	//止まっている状態
	if (drct == E_Drct_Stop) {
		DrawGraph(player.x * MAP_SIZE + count_x, player.y * MAP_SIZE + count_y, Player[None], TRUE);
	}
	
	//Playerが歩いているように見せる処理
	if (Move_Flg == true){

		//上下
		if (drct == E_Drct_Up || drct == E_Drct_Down)
		{
			Player_Animetion = count_y / 8 % 3;   //画像のアニメーション用の変数 y
		}
		//左右
		if (drct == E_Drct_Right || drct == E_Drct_Left)
		{
			Player_Animetion = count_x / 8 % 3;   //画像のアニメーション用の変数 x
		}

		//上
		if (drct == E_Drct_Up)
		{
			DrawGraph(player.x * MAP_SIZE + count_x, player.y * MAP_SIZE + count_y, Player[0 + Player_Animetion], TRUE);
		
		}
		//右
		if (drct == E_Drct_Right)
		{
			DrawGraph(player.x * MAP_SIZE + count_x, player.y * MAP_SIZE + count_y, Player[3 + Player_Animetion], TRUE);

		
		}
		//下
		if (drct == E_Drct_Down)
		{
			DrawGraph(player.x * MAP_SIZE + count_x, player.y * MAP_SIZE + count_y, Player[6 + Player_Animetion], TRUE);

		
		}
		//左
		if (drct == E_Drct_Left)
		{
			DrawGraph(player.x * MAP_SIZE + count_x, player.y * MAP_SIZE + count_y, Player[9 + Player_Animetion], TRUE);

		
		}
	}

	//デバッグ用処理
	DrawFormatString(700, 20, GetColor(255, 0, 0), "0:上 1:右 2:下 3:左 4 :止まる");
	DrawFormatString(700, 40, GetColor(255, 0, 0), "Drct:%d", drct);
	DrawFormatString(700, 60, GetColor(255, 0, 0), "x = %d   y = %d", player.x,player.y);
	DrawFormatString(700, 80, GetColor(255, 0, 0), "nx = %d   ny = %d", player.nx,player.ny);
	DrawFormatString(700, 100, GetColor(255, 0, 0), "MoveFlg:%d", Move_Flg);
	DrawFormatString(700, 120, GetColor(255, 0, 0), "count_x:%d  count_y:%d", count_x,count_y);
	
	return 0;
}

int Player_End() {
	return 0;
}