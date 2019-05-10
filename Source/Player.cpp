#include"DxLib.h"
#include"Player.h"
#include"MAP.h"


/************************************************
*												*
*												*
*												*
************************************************/

//ÉãÅ[Évóp
static int i, j, k;

P_PLAYER player;
P_DRCT drct;
//E_Object obj;

int PGHandle;

int Player_Init() {
	player.x = MAP_Player_Pos_Init_x();
	player.y = MAP_Player_Pos_Init_y();
	//LoadDivGraph("", 0);
	return 0;
}

int Player_Drct() {

	return 0;
}

int Player_Move() {

	return 0;
}

int Player_Object() {

	return 0;
}

int Player_Draw() {
	return 0;
}