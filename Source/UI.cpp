#include "DxLib.h"
#include "UI.h"
#include "Keyboard.h"
#include "Player.h"
//#include "Box.h"
#include "Scene_Mgr.h"
#include "Enemy.h"


<<<<<<< HEAD



int UI_Init() {

=======
//�����ŕϐ���錾�iC++���g��Ȃ��̂ŃO���[�o���ϐ��j
int ImageMenu = 0;
int Menyu_OnActive;
int Menyu_x;
int Menyu_y;

int UI_Init() {
	//�����ŏ�����������
	//�摜�̓ǂݍ���
	ImageMenu = LoadGraph("resource/Image/STR.png");
	Menyu_OnActive = false;  //�摜��\��
>>>>>>> origin/misima
	return 0;
}

int UI_Dpct() {
<<<<<<< HEAD
=======
	//�����Ōv�Z
	//Dqct�͖��t���[���Ă΂��
	int Key;
	
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		Key = GetJoypadInputState(DX_INPUT_KEY);
		if (Keyboard_Get(KEY_INPUT_M) == 1) {
			Menyu_OnActive = true;	//�摜�\��
		}
>>>>>>> origin/misima

	return 0;
}

int UI_Draw() {
	//�����ŕ`��
	//�����������t���[���Ă΂�܂����v�Z�Ƃ͕ʂɏ����܂�
	if (Menyu_OnActive == true)
	{
		DrawGraph(Menyu_x, Menyu_y, ImageMenu, true);
	}

	return 0;
}

int UI_End() {
	//����
	return 0;
}
