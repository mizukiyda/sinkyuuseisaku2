#include"Dxlib.h"
#include"stdlib.h"
#include"Enemy.h"
#include"MAP.h"
#include"Player.h"
#include"Keyboard.h"


int Enemyalive;          //�G�̉摜�̕ϐ�(��)
int Enemydeath;          //�G�̉摜�̕ϐ�(��)
int Enemy_OnActive;		 //Enemy�̐����m�F

int Enemy_x = 100;       //
int Enemy_y = 100;
int player_x;
int player_y;
int E_Rand;

int Enemy_Init() {

	Enemyalive = LoadGraph("Resource/Image/Enemyalive.png");
	Enemydeath = LoadGraph("Resource/Image/Enemydeath.png");

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
	while(1){
		switch (E_Rand) {
		case E_Drct_Up:
			Enemy_y --;
			break;
		case E_Drct_Down:
			Enemy_y ++;
			break;
		case E_Drct_Right:
			Enemy_x ++;
			break;
		case E_Drct_Left:
			Enemy_x --;
			break;
		case E_Drct_Stop:
			break;
		}
	return 0;
}
	*/
	while (1) {                //�������[�v
		switch (E_Rand) {      
		case E_Drct_Up:        //��
			Enemy_y--;
			break;
		case E_Drct_Down:      //��
			Enemy_y++;
			break;
		case E_Drct_Right:     //�E
			Enemy_x++;
			break;
		case E_Drct_Left:      //��
			Enemy_x--;
			break;
		case E_Drct_Stop:      //�~
			break;
		}
		return 0;
		if (player_x + player_y >= Enemy_x && player_x <= Enemy_x + Enemy_y) {      //�v���C���[�Ƃ̓����蔻��
			Enemy_OnActive = false;                                                 //���������琶�������false�ɂ���
		}
		break;
	}
}
	/*
	else
	{
		Enemy_OnActive = false;
	}
	*/

int Enemy_Draw() {
	if (Enemy_OnActive == true) 
	{
		DrawGraph(Enemy_x, Enemy_y, Enemyalive, true);
	}
	else 
	{
		DrawGraph(Enemy_x,Enemy_y, Enemydeath, true);
	}
	return 0;
}
int Enemy_End() {
	return 0;
}