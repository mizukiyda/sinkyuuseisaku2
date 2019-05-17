// �}�b�v�\����{
#include "DxLib.h"
#include "MAP.h"
#include "Enemy.h"
#include "Player.h"
#include "Scene_Mgr.h"

int ImageWall = 0;
int ImageLoad = 0;
int ImageGoal = 0;
int BG;
int i, j;
int px, py;					//�󂯎��v���C���[�̕ϐ�

int MapData[MAP_HEIGHT][MAP_WIDTH] =
{
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,1,1,1,1,1,1,2,1,1,1,1,1,1,0},
{0,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
{0,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
{0,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
{0,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
{0,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
{0,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
{0,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
};
//10��define��const�Œ�`���ׂ�
//�ނ���\���̂����ʂ��ׂ�

//�v���C���[�̏���x���W���󂯎��
int MAP_Player_Pos_Init_x() {

	return px;		//�����������v���C���[��x���W��߂�
}

//�v���C���[�̏���y���W���󂯎��
int MAP_Player_Pos_Init_y() {

	return py;		//�����������v���C���[��y���W��߂�
}

int MAP_Data(int x , int y) {
	return MapData[y][x];
}

//������
int MAP_Init() {

	//�摜�̓ǂݍ���
	ImageWall = LoadGraph("resource/Image/Wall.png");
	ImageLoad = LoadGraph("resource/Image/Load.png");
	ImageGoal = LoadGraph("resource/Image/Goal.png");

	BG = LoadGraph("resource/Image/BackGround.png");

	px = 5;
	py = 5;
	
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

	// �}�b�v��`��
	for (i = 0; i < MAP_HEIGHT; i++)
	{
		for (j = 0; j < MAP_WIDTH; j++)
		{
			if (MapData[i][j] == P_Object_Wall)
			{
				//DrawBox(j * MAP_SIZE, i * MAP_SIZE,j * MAP_SIZE + MAP_SIZE, i * MAP_SIZE + MAP_SIZE,GetColor(0, 230, 0), TRUE);

				DrawGraph(j * MAP_SIZE, i * MAP_SIZE, ImageWall, TRUE);

			}
			if (MapData[i][j] == P_Object_Load)
			{
				//DrawBox(j * MAP_SIZE, i * MAP_SIZE,j * MAP_SIZE + MAP_SIZE, i * MAP_SIZE + MAP_SIZE,GetColor(122, 255, 122), TRUE);

				DrawGraph(j * MAP_SIZE, i * MAP_SIZE, ImageLoad, TRUE);

			}
			if (MapData[i][j] == P_Object_Goal)
			{
				//DrawBox(j * MAP_SIZE, i * MAP_SIZE,j * MAP_SIZE + MAP_SIZE, i * MAP_SIZE + MAP_SIZE,GetColor(122, 122, 255), TRUE);

				DrawGraph(j * MAP_SIZE, i * MAP_SIZE, ImageGoal, TRUE);
			}
		}
	}
	//DrawExtendGraph(0, 0, 1280, 640, BG, true);
	return 0;
}

//�I��
int MAP_End() {

	return 0;
}