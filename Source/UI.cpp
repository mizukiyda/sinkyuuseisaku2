#include "DxLib.h"
#include "UI.h"
#include "Keyboard.h"
#include "Player.h"
//#include "Box.h"
#include "Scene_Mgr.h"
#include "Enemy.h"

#define HISTORY_MAX 256

//�����ŕϐ���錾�iC++���g��Ȃ��̂ŃO���[�o���ϐ��j
int ImageMenu = 0;



int UI_Init() {
	//�����ŏ�����������
	//�摜�̓ǂݍ���
	ImageMenu = LoadGraph("resource/Image/STR.png");
	
	return 0;
}

int UI_Dpct() {
	//�����Ōv�Z
	//Dqct�͖��t���[���Ă΂��
	int Key;
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		Key = GetJoypadInputState(DX_INPUT_KEY);
		if (Keyboard_Get(KEY_INPUT_M) == 1) {

		}

	}
	return 0;
}

int UI_Draw() {
	//�����ŕ`��
	//�����������t���[���Ă΂�܂����v�Z�Ƃ͕ʂɏ����܂�
	

	

	return 0;
}

int UI_End() {
	//����
	return 0;
}
