#include"DxLib.h"
#include"Player.h"
#include"MAP.h"
#include "Keyboard.h"
#include"Enemy.h"

//���[�v�p
static int i, j, k;

//Player�̉摜
int Player[12];    //�v���C���[�摜�̕ϐ�(�����12�����Ȃ̂�12)

//Player�̍\���̊֌W
P_PLAYER player;	
E_Drct drct;

int Player_Init() {

	//Player�̏����ʒu
	player.x = 100;
	player.y = 150;

	//�摜�̎擾
	Player[12] = {};
	LoadDivGraph("Resource/Image/Player.png", 12, 3, 4, 200, 200,Player);  //�z��uPlayer�v�։摜������
	return 0;
}

int Player_Dpct() {
	//��
	if (Keyboard_Get(KEY_INPUT_UP) == 1)   //��
	{
		player.y--;    
		drct = E_Drct_Up;
	}
	//��
	if (Keyboard_Get(KEY_INPUT_LEFT) == 1)  //��
	{
		player.x--;      
		drct = E_Drct_Left;
	}
	//��
	if (Keyboard_Get(KEY_INPUT_DOWN) == 1)  //��
	{
		player.y++;      
		drct = E_Drct_Down;
	}
	//�E
	if (Keyboard_Get(KEY_INPUT_RIGHT) == 1) //��
	{
		player.x++;      
		drct = E_Drct_Right;
	}

	return 0;
}

int Player_Draw() {

	//Player�̕\��
	//��
	if (drct == E_Drct_Up)
	{
		DrawGraph(player.x, player.y, Player[0], TRUE);
	}
	//��
	if (drct == E_Drct_Left)
	{
		DrawGraph(player.x, player.y, Player[9], TRUE);
	
	}
	//��
	if (drct == E_Drct_Down)
	{
		DrawGraph(player.x , player.y, Player[6], TRUE);
		
	}
	//�E
	if (drct == E_Drct_Right)
	{
		DrawGraph(player.x , player.y, Player[3], TRUE);
		
	}

	//�f�o�b�O�p����
	DrawFormatString(700, 20, GetColor(255, 0, 0), "1:�� 2:�E 3:�� 4:��");
	DrawFormatString(700, 40, GetColor(255, 0, 0), "Drct:%d", drct);
	DrawFormatString(700, 60, GetColor(255, 0, 0), "x = %d  \n y = %d", player.x,player.y);


	return 0;
}

int Player_End() {

	return 0;
}