#include"Dxlib.h"
#include"stdlib.h"
#include"Enemy.h"
#include"MAP.h"
#include"Player.h"


int Enemyalive;          //�G�̉摜�̕ϐ�(��)
int Enemydeath;          //�G�̉摜�̕ϐ�(��)


int Enemy_x = Enemy_Pos_Init_x();       //
int Enemy_y = Enemy_Pos_Init_y();
int Player_x;
int Player_y;
int E_Rand;
int Enemy_OnActive;

int Enemy_Init() {

	Enemyalive = LoadGraph("resource/Image/Enemyalive.png");
	Enemydeath = LoadGraph("resource/Image/Enemydeath.png");

	Enemy_OnActive = true;		//�������� == �����Ă���

	E_Rand = GetRand(5);

	return 0;
}

int Enemy_Dpct() {
	/*
	if (Enemy_OnActive == false) {
	if (Keyboard_Get(KEY_INPUT_SPACE) == 1)
	{
	Enemy_OnActive = true;
	}
	}
	else
	{
	if (Keyboard_Get(KEY_INPUT_SPACE) == 1)
	{
	Enemy_OnActive = true;
	}
	return 0;
	}

	*/
<<<<<<< HEAD
	//while (0) {                //�������[�v
	switch (E_Rand) {
	case 0:        //��
	Enemy_y--;
	break;
	case 1:      //��
	Enemy_y++;
	break;
	case 2:     //�E
	Enemy_x++;
	break;
	case 3:      //��
	Enemy_x--;
	break;
	case 4:      //�~
	break;
	}
	return 1;
	if (Player_x + Player_y >= Enemy_x && Player_x <= Enemy_x + Enemy_y) {      //�v���C���[�Ƃ̓����蔻��
	Enemy_OnActive = false;                                                 //���������琶�������false�ɂ���
	}
	//break;
	//}
	return 0;
}
//Enemy�̈ړ������֐��ŊǗ�����

int   Enemy_Move0() {
	if (Enemy_x >200) {
		Enemy_y++;
		return 0;
	}
=======
	return  0;
}
//Enemy�̈ړ������֐��ŊǗ�����

int Enemy_Move0() {
	//if()
	return 0;
>>>>>>> yokoyama
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
	Enemy_x = 100;
	return Enemy_x;
}
int Enemy_Pos_Init_y() {
	Enemy_y = 100;
	return Enemy_y;
}
int Enemy_Draw() {
	if (Enemy_OnActive == true)
	{
		DrawGraph(Enemy_x, Enemy_y, Enemyalive, true);
	}
	else
	{
		DrawGraph(Enemy_x, Enemy_y, Enemydeath, true);
	}
	return 0;
}
int Enemy_End() {
	return 0;
}