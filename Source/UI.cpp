#include "DxLib.h"
#include "UI.h"
#include "Keyboard.h"
#include "Player.h"
//#include "Box.h"
#include "Scene_Mgr.h"
#include "Enemy.h"

#define HISTORY_MAX 256

//�����ŕϐ���錾�iC++���g��Ȃ��̂ŃO���[�o���ϐ��j
S_History History[HISTORY_MAX];
int StepCount;


int UI_Init() {
	//�����ŏ�����������

	
	return 0;
}

int UI_Dpct() {
	//�����Ōv�Z
	//Dqct�͖��t���[���Ă΂��

	return 0;
}

int UI_Draw() {
	//�����ŕ`��
	//�����������t���[���Ă΂�܂����v�Z�Ƃ͕ʂɏ����܂�



#ifdef _DEBUG


#endif
	return 0;
}

//�v���C���[����
int UI_Player_Move_History() {
	return 0;
}

//�{�b�N�X����
int UI_Box_Move_History() {
	return 0;
}

//�����J�E���g�ǉ�
int UI_StepCount_MoveOn() {
	StepCount++;
	return 0;
}

//�����J�E���g�̒�
int UI_StepCount() {
	return StepCount;
}


int UI_End() {
	//����
	return 0;
}
