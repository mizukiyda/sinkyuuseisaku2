#include "DxLib.h"
#include "UI.h"
#include "Keyboard.h"
#include "Player.h"
//#include "Box.h"
#include "Scene_Mgr.h"
#include "Enemy.h"

//�����ŕϐ���錾�iC++���g��Ȃ��̂ŃO���[�o���ϐ��j
int ImageMenu = 0;
int Menu_OnActive;
int Menu_x;
int Menu_y;

int UI_Init() {
	//�����ŏ�����������
	//�摜�̓ǂݍ���
	ImageMenu = LoadGraph("resource/Image/STR.png");
	Menu_OnActive = false;  //�摜��\��

	return 0;
}

int UI_Dpct() {

	//�����Ōv�Z
	//Dqct�͖��t���[���Ă΂��
	int Key;
	
	if (Menu_OnActive == false) {
		if (Keyboard_Get(KEY_INPUT_M) == 1) {
			Menu_OnActive = true;	//�摜�\��
		}
	}
	else
	{
		if (Keyboard_Get(KEY_INPUT_M) == 1) {
			Menu_OnActive = false;	//�摜�\��
		}
	}
	return 0;
}

int UI_Draw() {
	//�����ŕ`��
	//�����������t���[���Ă΂�܂����v�Z�Ƃ͕ʂɏ����܂�
	if (Menu_OnActive == true)
	{
		DrawGraph(Menu_x, Menu_y, ImageMenu, true);
	}

	return 0;
}

int UI_End() {
	//����
	return 0;
}
