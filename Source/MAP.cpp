// �}�b�v�\����{
#include "DxLib.h"
#include "MAP.h"
#include "Enemy.h"
#include "Player.h"
#include "Scene_Mgr.h"

int ImageWall = 0;
int ImageLoad = 0;
int ImageGoal = 0;

//10��define��const�Œ�`���ׂ�
//�ނ���\���̂����ʂ��ׂ�


//������
int MAP_Init() {

	//�摜�̓ǂݍ���
	ImageWall = LoadGraph("Image/Wall.png");
	ImageLoad = LoadGraph("Image/Load.png");
	ImageGoal = LoadGraph("Image/Goal.png");

	return 0;

}

//�v�Z
int MAP_Dpct() {
	//Dpct�͖��t���[���Ă΂��

	return 0;
}

//�`��
int MAP_Draw() {
	//�����������t���[���Ă΂�邪�v�Z�Ƃ͕ʂɏ����܂�


	return 0;
}

//�I��
int MAP_End() {

	return 0;
}