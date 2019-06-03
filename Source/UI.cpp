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

int Menu_Flg;

int UI_Init() {
	//�����ŏ�����������
	//�摜�̓ǂݍ���
	ImageMenu = LoadGraph("resource/Image/STR.png");
	Menu_OnActive = false;  //�摜��\��

	Menu_Flg = false;
	return 0;
}

int UI_Dpct() {

	//�����Ōv�Z
	//Dqct�͖��t���[���Ă΂��
	int Key;
	
	if (Menu_OnActive == false) {
		if (Keyboard_Get(KEY_INPUT_M) == 1) {
			Menu_OnActive = true;	//�摜�\��
			Menu_Flg = true;
		}
	}
	else
	{
		if (Keyboard_Get(KEY_INPUT_M) == 1) {
			Menu_OnActive = false;	//�摜�\��
			Menu_Flg = false;
		}
	}

	return 0;
}

int UI_Flg() {

	return Menu_Flg;
}
int UI_Draw() {
	//�����ŕ`��
	//�����������t���[���Ă΂�܂����v�Z�Ƃ͕ʂɏ����܂�
	if (Menu_OnActive == true)
	{
		DrawGraph(Menu_x, Menu_y, ImageMenu, true);


		// �`�悷�镶����̃T�C�Y��ݒ�
		SetFontSize(34);
		DrawFormatString(1000, 520, GetColor(255, 0, 0), "HP:200");
		DrawFormatString(1000, 620, GetColor(255, 0, 0), "MP:100");

		//HP�̃o�[
		DrawBox(1000, 560, 1200, 600, GetColor(255, 255, 255), true);
		DrawBox(1010, 570, 1190, 590, GetColor(0, 255, 0), true);
		//MP�̃o�[
		DrawBox(1000, 660, 1200, 700, GetColor(255, 255, 255), true);
		DrawBox(1010, 670, 1190, 690, GetColor(0, 0, 255), true);
	}
	return 0;
}

int UI_End() {
	//����
	return 0;
}
