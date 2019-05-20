#include"DxLib.h"
#include"Player.h"
#include"MAP.h"
#include "Keyboard.h"
#include"Enemy.h"
#include"Scene_Mgr.h"

//���[�v�p
static int i, j, k;

//Player�̉摜
int Player[12];				//�v���C���[�摜�̕ϐ�(�����12�����Ȃ̂�12)
int None;					//�摜�̃X�^���o�C���(�Î~���)
int Player_Animetion;		//Player�̃A�j���[�V����

//Player�̍\���̊֌W
P_PLAYER player;	
E_Drct drct;				//����

//Player�p�̕ϐ�
int count_x;		//Map�T�C�Y�̃J�E���g(x)
int count_y;		//Map�T�C�Y�̃J�E���g(y)

//Player�̃t���O
int Move_Flg;			//Player�������邢�邩�ǂ����̃t���O
int Player_Hit_Flg;		//Player��Enemy�Ɠ����������ǂ����̃t���O

int Player_Init() {

	//Player�̏����ʒu(Map������炤)
	player.x = MAP_Player_Pos_Init_x();
	player.y = MAP_Player_Pos_Init_y();
	player.nx = player.x;
	player.ny = player.y;

	//�摜�̎擾
	Player[12] = {};
	LoadDivGraph("Resource/Image/Player.png", 12, 3, 4, 64, 64,Player);  //�z��uPlayer�v�։摜������
	None = 7;					//���ʂ������Ă�����
	Player_Animetion = 0;		//�������Ă��Ȃ����

	//�ړ�
	count_x = 0;
	count_y = 0;
	Move_Flg = false;
	drct = E_Drct_Stop;

	//�����蔻��
	Player_Hit_Flg = false;

	return 0;
}

int Player_Dpct() {

	

	if (Move_Flg == false) {
		player.nx = player.x;
		player.ny = player.y;
		//��
		if (Keyboard_Get(KEY_INPUT_UP) == 1)   //��
		{
			player.ny--;
			drct = E_Drct_Up;
		}
		//�E
		if (Keyboard_Get(KEY_INPUT_RIGHT) == 1) //��
		{
			player.nx++;
			drct = E_Drct_Right;
		}
		//��
		if (Keyboard_Get(KEY_INPUT_DOWN) == 1)  //��
		{
			player.ny++;
			drct = E_Drct_Down;
		}
		//��
		if (Keyboard_Get(KEY_INPUT_LEFT) == 1)  //��
		{
			player.nx--;
			drct = E_Drct_Left;
		}

		//�G���^�[�L�[����������ResultScene�ցi�f�o�b�O�p�j
		if (Keyboard_Get(KEY_INPUT_RETURN) == 1) //��
		{
			Scene_Mgr_ChangeScene(E_Scene_Result);
		}

		//Player�̈ړ���̃`�F�b�N�i�ǂ������j
		if (drct != E_Drct_Stop)	//�L�[�����͂���Ă���Ȃ�(�~�܂��Ă��Ȃ��Ȃ�)
		{
			Player_Check();
		}

		//�ړ�������
		if (Move_Flg == true) {		//�ړ��悪����������
			Player_Move();
		}
	}
	return 0;
}

int Player_Check() {

	if (MAP_Data(player.nx, player.ny) == P_Object_Load || MAP_Data(player.nx, player.ny) == P_Object_Goal) {
		Move_Flg = true;			//����
	}
	
	if (MAP_Data(player.nx, player.ny) == P_Object_Wall) {
		Move_Flg = false;
		drct = E_Drct_Stop;
	}
	return 0;
}

int Player_Move() {

	//Player���k���k������������
	switch (drct) {

		//��
	case E_Drct_Up:
		count_y--;
		break;
		//�E
	case E_Drct_Right:
		count_x++;
		break;
		//��
	case E_Drct_Down:
		count_y++;
		break;
		//��
	case E_Drct_Left:
		count_x--;
		break;
	}

	//count_x��count_y�̃J�E���g���}64��B�����Ȃ�@
	if (count_x >= MAP_SIZE - 1 || count_y <= -MAP_SIZE + 1 || count_x <= -MAP_SIZE + 1 || count_y >= MAP_SIZE - 1){
		//�v���C���[�̍��W�ɉ��̍��W�������č��W���X�V(�`��̍ۂɎg���̂�player.x,player.y)
		player.y = player.ny;
		player.x = player.nx;

		//�J�E���g�̏�����
		count_x = 0;
		count_y = 0;

		//�t���O�ƌ����̊Ǘ�
		Move_Flg = false;
		drct = E_Drct_Stop;
	}
		return 0;
}

int Player_Draw() {
	//Player�̕\��

	//�~�܂��Ă�����
	if (drct == E_Drct_Stop) {
		DrawGraph(player.x * MAP_SIZE + count_x, player.y * MAP_SIZE + count_y, Player[None], TRUE);
	}
	
	//Player�������Ă���悤�Ɍ����鏈��
	if (Move_Flg == true){

		//�㉺
		if (drct == E_Drct_Up || drct == E_Drct_Down)
		{
			Player_Animetion = count_y / 8 % 3;   //�摜�̃A�j���[�V�����p�̕ϐ� y
		}
		//���E
		if (drct == E_Drct_Right || drct == E_Drct_Left)
		{
			Player_Animetion = count_x / 8 % 3;   //�摜�̃A�j���[�V�����p�̕ϐ� x
		}

		//��
		if (drct == E_Drct_Up)
		{
			DrawGraph(player.x * MAP_SIZE + count_x, player.y * MAP_SIZE + count_y, Player[0 + Player_Animetion], TRUE);
		
		}
		//�E
		if (drct == E_Drct_Right)
		{
			DrawGraph(player.x * MAP_SIZE + count_x, player.y * MAP_SIZE + count_y, Player[3 + Player_Animetion], TRUE);

		
		}
		//��
		if (drct == E_Drct_Down)
		{
			DrawGraph(player.x * MAP_SIZE + count_x, player.y * MAP_SIZE + count_y, Player[6 + Player_Animetion], TRUE);

		
		}
		//��
		if (drct == E_Drct_Left)
		{
			DrawGraph(player.x * MAP_SIZE + count_x, player.y * MAP_SIZE + count_y, Player[9 + Player_Animetion], TRUE);

		
		}
	}

	//�f�o�b�O�p����
	DrawFormatString(700, 20, GetColor(255, 0, 0), "0:�� 1:�E 2:�� 3:�� 4 :�~�܂�");
	DrawFormatString(700, 40, GetColor(255, 0, 0), "Drct:%d", drct);
	DrawFormatString(700, 60, GetColor(255, 0, 0), "x = %d   y = %d", player.x,player.y);
	DrawFormatString(700, 80, GetColor(255, 0, 0), "nx = %d   ny = %d", player.nx,player.ny);
	DrawFormatString(700, 100, GetColor(255, 0, 0), "MoveFlg:%d", Move_Flg);
	DrawFormatString(700, 120, GetColor(255, 0, 0), "count_x:%d  count_y:%d", count_x,count_y);
	
	return 0;
}

int Player_End() {
	return 0;
}