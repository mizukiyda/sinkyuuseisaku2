#include"Dxlib.h"
#include"stdlib.h"
//#include"Enemy.h"
//#include"MAP.h"
//#include"Player.h"


int Enemyalive;          //�G�̉摜�̕ϐ�(��)
int Enemydeath;          //�G�̉摜�̕ϐ�(��)


int Enemy_Init() {
	Enemyalive=LoadGraph("resource/Image/Enemy.png");
	Enemydeath=LoadGraph("resource/Image/Enemydeath.png");
	return 0;
}
int Enemy_Dpct() {
	/*
	switch () {          //�����_���ɓ���
	case E_Up:           //��

	case E_Right:        //�E

	case E_Down:         //��

	case E_Left:         //��

	case E_Stop:         //�~
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