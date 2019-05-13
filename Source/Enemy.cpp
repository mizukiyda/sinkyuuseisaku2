#include"Dxlib.h"
#include"stdlib.h"
//#include"Enemy.h"
//#include"MAP.h"
//#include"Player.h"


int Enemyalive;          //“G‚Ì‰æ‘œ‚Ì•Ï”(¶)
int Enemydeath;          //“G‚Ì‰æ‘œ‚Ì•Ï”(€)


int Enemy_Init() {
	Enemyalive=LoadGraph("resource/Image/Enemy.png");
	Enemydeath=LoadGraph("resource/Image/Enemydeath.png");
	return 0;
}
int Enemy_Dpct() {
	/*
	switch () {          //ƒ‰ƒ“ƒ_ƒ€‚É“®‚­
	case E_Up:           //ã

	case E_Right:        //‰E

	case E_Down:         //‰º

	case E_Left:         //¶

	case E_Stop:         //~
	}
	*/
	return 0;
}
int Enemy_Move() {
	return 0;

}
int Enemy_Draw() {
	DrawGraph(100, 100, Enemyalive, true);
	return 0;
}
int Enemy_End() {
	return 0;
}