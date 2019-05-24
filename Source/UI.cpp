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
	
		// �`�悷�镶����̃T�C�Y��ݒ�
		SetFontSize(34);
		DrawFormatString(1000, 20, GetColor(255, 0, 0), "HP:200");
		DrawFormatString(1000, 120, GetColor(255, 0, 0), "MP:100");

		//HP�̃o�[
		DrawBox(1000, 60,1200,100 ,GetColor(255, 255, 255), true);
		DrawBox(1010, 70, 1190, 90, GetColor(0, 255, 0), true);
		//MP�̃o�[
		DrawBox(1000, 160, 1200, 200, GetColor(255, 255, 255), true);
		DrawBox(1010, 170, 1190, 190, GetColor(0, 0, 255), true);

	return 0;
}

int UI_End() {
	//����
	return 0;
}
