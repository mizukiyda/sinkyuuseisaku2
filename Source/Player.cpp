#include"DxLib.h"
#include"Player.h"
#include"MAP.h"
#include "Keyboard.h"
#include"Enemy.h"
#include"Scene_Mgr.h"
#include"UI.h"

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

//Enemyの座標を入れる
int enemy_x;
int enemy_y;

//歩数カウント
int count;

//Playerのフラグ
int Move_Flg;			//Playerが動いるいるかどうかのフラグ
int menu_flg;			//メニューを開いているかどうかのフラグ

int Player_Init() {

	//Playerの初期位置(Mapからもらう)
	player.x = MAP_Player_Pos_Init_x();
	player.y = MAP_Player_Pos_Init_y();
	player.nx = player.x;
	player.ny = player.y;

	//画像の取得
	Player[12] = {};
	LoadDivGraph("Resource/Image/Player1.png", 12, 3, 4, 48, 48,Player);  //配列「Player」へ画像を入れる
	None = 1;					//正面を向いている状態
	Player_Animetion = 0;		//何もしていない状態

	//移動
	count_x = 0;
	count_y = 0;
	Move_Flg = false;
	drct = E_Drct_Stop;

	//歩数カウントの初期化
	count = 0;

	//当たり判定

	//めにゅー フラグ
	menu_flg = false;
	return 0;
}

int Player_Dpct() {

	//エネミーの座標を入れる（上記のは仮）
	enemy_x = Enemy_Pos_Init_x();
	enemy_y = Enemy_Pos_Init_y();
	/*for (int i = 0;i <= EnemyCount;i++) {
	enemy_x[i] = Enmey_Pos_Init_x(i);
	enemy_y[i] = Enmey_Pos_Init_y(i);
	}*/

	menu_flg = UI_Flg();

	if (menu_flg == false) {		//メニューを開いていたら歩けない

		if (Move_Flg == false) {
			player.nx = player.x;
			player.ny = player.y;
			//上
			if (Keyboard_Get(KEY_INPUT_UP) == 1)   //↑
			{
				player.ny--;
				drct = E_Drct_Up;
				count++;
			}
			//右
			if (Keyboard_Get(KEY_INPUT_RIGHT) == 1) //→
			{
				player.nx++;
				drct = E_Drct_Right;
				count++;
			}
			//下
			if (Keyboard_Get(KEY_INPUT_DOWN) == 1)  //↓
			{
				player.ny++;
				drct = E_Drct_Down;
				count++;
			}
			//左
			if (Keyboard_Get(KEY_INPUT_LEFT) == 1)  //←
			{
				player.nx--;
				drct = E_Drct_Left;
				count++;
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
	}		



	if (count == 15) {
		Scene_Mgr_ChangeScene(E_Scene_GameScene);
		count = 0;

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
		player.x = player.nx;
		player.y = player.ny;
	
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
			Player_Animetion = count_y / 16 % 3;   //画像のアニメーション用の変数 y
		}
		//左右
		if (drct == E_Drct_Right || drct == E_Drct_Left)
		{
			Player_Animetion = count_x / 16 % 3;   //画像のアニメーション用の変数 x
		}

		//上
		if (drct == E_Drct_Up)
		{
			DrawGraph(player.x * MAP_SIZE + count_x, player.y * MAP_SIZE + count_y, Player[9 + Player_Animetion], TRUE);
			None = 10;
		}
		//右
		if (drct == E_Drct_Right)
		{
			DrawGraph(player.x * MAP_SIZE + count_x, player.y * MAP_SIZE + count_y, Player[6 + Player_Animetion], TRUE);
			None = 7;
		}
		//下
		if (drct == E_Drct_Down)
		{
			DrawGraph(player.x * MAP_SIZE + count_x, player.y * MAP_SIZE + count_y, Player[0 + Player_Animetion], TRUE);
			None = 1;
		}
		//左
		if (drct == E_Drct_Left)
		{
			DrawGraph(player.x * MAP_SIZE + count_x, player.y * MAP_SIZE + count_y, Player[3 + Player_Animetion], TRUE);
			None = 4;
		}
	}


	//デバッグ
	SetFontSize(18);
	DrawFormatString(700, 20, GetColor(255, 0, 0), "1:上 2:右 3:下 4 :左 0:止まる ");
	DrawFormatString(700, 40, GetColor(255, 0, 0), "Drct:%d", drct);
	DrawFormatString(700, 60, GetColor(255, 0, 0), "x = %d   y = %d", player.x,player.y);
	DrawFormatString(700, 80, GetColor(255, 0, 0), "nx = %d   ny = %d", player.nx,player.ny);
	DrawFormatString(700, 100, GetColor(255, 0, 0), "MoveFlg:%d", Move_Flg);
	DrawFormatString(700, 120, GetColor(255, 0, 0), "count_x:%d  count_y:%d", count_x,count_y);
	
	return 0;
}

int Player_Pos_Init_x() {

	return player.x;
}

int Player_Pos_Init_y() {

	return player.y;
}

int Player_End() {
	return 0;
}