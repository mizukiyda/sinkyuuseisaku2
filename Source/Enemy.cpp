#include"Dxlib.h"
#include"Enemy.h"
#include"MAP.h"
#include"Player.h"

#define Enemy_Max 4						//�G�̍ő吔

S_Enemy enemy[Enemy_Max];					//�G�̔z��

//for���p�Ɏg���ϐ�
int i, j, k;

//�ړ�	
int count_x;						//�}�b�v�T�C�Y���J�E���g ��
int count_y;						//�}�b�v�T�C�Y���J�E���g ��

//����
E_Drct Drct;						//�����̊Ǘ�

//�U���̃t���O�i��ɉ摜�̕`��Ɏg���Ă���j
int Attack_Flg = false;

//player�̍��W
int player_x;						//player��x���W
int player_y;						//player��y���W

//player�ւ̓����蔻��
int Player_Hit_Flg = false;

//�摜
int EnemyGyallaly[12];					//�G�̉摜�̕ϐ�
int EnemyShotGyallaly;					//�G�̒e�̉摜�̕ϐ�
int EnemyMissGyallaly[3];				//�G���|���ꂽ���̉摜

//enemy�ւ̓����蔻��
int Enemy_Hit_Flg = false;

//�����Ă����Ԃ����
int OnActives = true;

int Enemy_Init() {
	//����������

	LoadDivGraph("resource/Image/enemy.png", 12, 3, 4, 48, 48, EnemyGyallaly);									// �G�̉摜�����[�h
	EnemyShotGyallaly = LoadGraph("resource/Image/EnemyShot.png");												//�G�̒e�̉摜�����[�h
	LoadDivGraph("resource/Image/enemymiss.png", 12, 3, 4, 48, 48, EnemyMissGyallaly);							// �G�̉摜�����[�h


	for (i = 0;i < Enemy_Max;i++) {
		enemy[i].x = MAP_Enemy_Pos_Init_x(i);					//MAP����G�l�~�[�̏���x���W�����炤
		enemy[i].y = MAP_Enemy_Pos_Init_y(i);					//MAP����G�l�~�[�̏���y���W�����炤
	}


	return 0;
}

int Enemy_MapDeta(int x, int y) {		
	//enemy��p��Map�f�[�^�����[����

	return 0;
}

int Enemy_Dpct(int num) {

	//����Player�̍��W���X�V���邽��
	player_x = ;						//player��x���W�����邽�߂̕ϐ�
	player_y = ;						//player��y���W�����邽�߂̕ϐ�

	enemy[num].ex = enemy[num].x;		//enemy�̒e��Enemy��x���W�Ɋi�[����
	enemy[num].ey = enemy[num].y;		//enemy�̒e��Enemy��y���W�Ɋi�[����

	Enemy_Hit_Flg = ;								//player�����������t���O������ϐ�

	if (Enemy_Hit_Flg == true) {					//�������������Ȃ�				
		Enemy_Hit();							//�����Ă����Ԃ�OFF�ɂ���
	}

	if (count_x == 0 || count_y == 0) {				//�����J�E���g��0�Ȃ�		
		//�ڂ̑O���ǂ��ǂ����̔��ʂ�����ienemy��pMap�����Ĕ��f����) -> �ڂ̑O�����̂Ƃ��@�@�@�@�@-> 0�Ȃ�
		if (Enemy_MapDeta(enemy[num].x, enemy[num].y) == E_Object_Load) {
			Drct = (E_Drct)GetRand(4);					//�i�L���X�g���Z�j0�`4�܂ł̐����Ō����������_���ɑ������
		}
	}															

	/*************************************************  Enemy�̈ړ�����  *********************************************************************/

	switch (Drct)
	{
		//�~�܂�
	case E_Drct_Stop:					//�����Ȃ�

		break;

		//��
	case E_Drct_Up:						//��������Ȃ�(1)
		count_y--;						//�k���k��������
		break;

		//��
	case E_Drct_Left:					//���������Ȃ�(4)
		count_x--;						//�k���k��������
		break;

		//��
	case E_Drct_Down:					//���������Ȃ�(3)
		count_y++;						//�k���k��������
		break;

		//�E
	case E_Drct_Right:					//�������E�Ȃ�(2)
		count_x++;						//�k���k��������
		break;

	}

	//�ڂ̑O���ǂ��ǂ����̔��ʂ�����ienemy��pMap�����Ĕ��f����) -> �ڂ̑O���ǂ̂Ƃ�    -> 1�Ȃ�
	if (Enemy_MapDeta(enemy[num].x, enemy[num].y) == E_Object_Wall) {

		if (E_Drct_Up == true) {
			while (Drct == 1) {								//�ォ�痈������1�����������x��
				Drct = (E_Drct)GetRand(4);					//�i�L���X�g���Z�j0�`4�܂ł̐����Ō����������_���ɑ������
			}
		}

		if (E_Drct_Down == true) {
			while (Drct == 3) {								//�����痈������3�����������x��
				Drct = (E_Drct)GetRand(4);					//�i�L���X�g���Z�j0�`4�܂ł̐����Ō����������_���ɑ������
			}
		}

		if (E_Drct_Left == true) {
			while (Drct == 4) {								//�����痈������4�����������x��
				Drct = (E_Drct)GetRand(4);					//�i�L���X�g���Z�j0�`4�܂ł̐����Ō����������_���ɑ������
			}
		}

		if (E_Drct_Right == true) {
			while (Drct == 2) {								//�E���痈������2�����������x��
				Drct = (E_Drct)GetRand(4);					//�i�L���X�g���Z�j0�`4�܂ł̐����Ō����������_���ɑ������
			}
		}

		if (E_Drct_Stop == true) {
			while (Drct == 0) {								//��~���Ă�������0�����������x��
				Drct = (E_Drct)GetRand(4);					//�i�L���X�g���Z�j0�`4�܂ł̐����Ō����������_���ɑ������
			}
		}
	}

	//count_x/count_y�̂ǂꂩ�̃J�E���g���}64�Ȃ�@>>�@Player.x/y�̍��W�X�V�E�J�E���g�ƃt���O�̏�����
	if (count_x >= MAP_SIZE - 1 || count_y <= -MAP_SIZE + 1 || count_x <= -MAP_SIZE + 1 || count_y >= MAP_SIZE - 1)
	{
		//�J�E���g�̏�����
		count_x = 0;
		count_y = 0;
	}
		/**************************************************enemy�̍U������***********************************************/

	for (i = 0;i < Enemy_Max;i++) {
		if (Drct == E_Drct_Left) {									//����enemy�����������Ă���
			if (enemy[i].x - MAP_SIZE * 5 <= player_x) {			//�Ȃ����G�l�~�[�̍�����v���C���[������Ȃ�
				Enemy_Attack_Left(num);
				Attack_Flg = true;
			}
		}

		if (Drct == E_Drct_Right) {									//����enemy���E�������Ă���
			if (enemy[i].x + MAP_SIZE * 5 >= player_x) {			//�Ȃ����G�l�~�[�̉E����v���C���[������Ȃ�
				Enemy_Attack_Right(num);
				Attack_Flg = true;
			}
		}

		if (Drct == E_Drct_Down) {									//����enemy�����������Ă���
			if (enemy[i].y - MAP_SIZE * 5 <= player_y) {			//�Ȃ����G�l�~�[�̉�����v���C���[������Ȃ�
				Enemy_Attack_Down(num);
				Attack_Flg = true;
			}
		}

		if (Drct == E_Drct_Up) {									//����enemy����������Ă���
			if (enemy[i].y + MAP_SIZE * 5 >= player_y) {			//�Ȃ����G�l�~�[�̏ォ��v���C���[������Ȃ�
				Enemy_Attack_Up(num);
				Attack_Flg = true;
			}
		}
	}
	return 0;
}
/*********************************************      �e��łi��ɍU�����s�������j(�����蔻��)    ***********************************************************/
		
int Enemy_Attack_Left(int num) {		//���ɒe��ł�

	enemy[num].ex -= 5;

	if (enemy[num].ex == player_x && enemy[num].ey == player_y) {			//����player�ɓ���������t���O��ON�ɂ��āAPlayer�ɓ����蔻���n��
		Player_Hit_Flg = true;
		Attack_Flg = false;																//����player�e�ƃG�l�~�[�e��������������ł���
	}

	if (enemy[num].ex >= enemy[num].x - MAP_SIZE * 5) {						//����enemy�̒e��enemy��x���W�𒆐S��3�}�X�𒴂�����A���ł���B
		Attack_Flg = false;
	}

	return Player_Hit_Flg;
}

int Enemy_Attack_Right(int num) {		//�E�ɒe��ł�

	enemy[num].ex += 5;

	if (enemy[num].ex == player_x && enemy[num].ey == player_y) {			//����player�ɓ���������t���O��ON�ɂ��āAPlayer�ɓ����蔻���n��
		Player_Hit_Flg = true;
		Attack_Flg = false;																//����player�e�ƃG�l�~�[�e��������������ł���
	}

	if (enemy[num].ex >= enemy[num].x + MAP_SIZE * 5) {						//����enemy�̒e��enemy��x���W�𒆐S��3�}�X�𒴂�����A���ł���B
		Attack_Flg = false;
	}

	return Player_Hit_Flg;
}

int Enemy_Attack_Down(int num) {		//���ɒe��ł�

	enemy[num].ey -= 5;

	if (enemy[num].ex == player_x && enemy[num].ey == player_y) {			//����player�ɓ���������t���O��ON�ɂ��āAPlayer�ɓ����蔻���n��
		Player_Hit_Flg = true;
		Attack_Flg = false;																//����player�e�ƃG�l�~�[�e��������������ł���
	}

	if (enemy[num].ey >= enemy[num].y - MAP_SIZE * 5) {						//����enemy�̒e��enemy��y���W�𒆐S��3�}�X�𒴂�����A���ł���B
		Attack_Flg = false;
	}

	return Player_Hit_Flg;
}

int Enemy_Attack_Up(int num) {			//��ɒe��ł�

	enemy[num].ey += 5;

	if (enemy[num].ex == player_x && enemy[num].ey == player_y) {			//����player�ɓ���������t���O��ON�ɂ��āAPlayer�ɓ����蔻���n��
		Player_Hit_Flg = true;
		Attack_Flg = false;																//����player�e�ƃG�l�~�[�e��������������ł���
	}

	if (enemy[num].ey >= enemy[num].y + MAP_SIZE * 5) {						//����enemy�̒e��enemy��y���W�𒆐S��3�}�X�𒴂�����A���ł���B
		Attack_Flg = false;
	}

	return Player_Hit_Flg;
}

/********************************************************   Enemy�ւ̓����蔻���̏����@�@**********************************************************************/
int Enemy_Hit() {
	OnActives = false;

	return 0;
}

int Enemy_Draw() {
	//�`�揈��
	
	for (i = 0;i < Enemy_Max;i++) {
		if (OnActives == true) {																										//����enemy�������Ă���̂Ȃ�
			if (Drct == E_Drct_Stop) {																									//�~�܂��Ă����ԁi���͓r���ł����Ȃ���������ɂȂ��Ă���j
				DrawGraph(enemy[i].x * MAP_SIZE + count_x, enemy[i].y * MAP_SIZE + count_y, EnemyGyallaly[0], true);					//enemy�̕`��
			}

			if (Attack_Flg = true) {																									//�����U����ԂȂ�
				DrawGraph(enemy[i].ex, enemy[i].ey, EnemyShotGyallaly, true);															//�U���̕`��								
			}
		}
		else																															//����enemy�������Ă��Ȃ��̂Ȃ�
		{
			DrawGraph(enemy[i].x * MAP_SIZE + count_x, enemy[i].y * MAP_SIZE + count_y, EnemyMissGyallaly[0], true);					//enemy�����񂾂Ƃ��̕`��
		}
	}
	return 0;
}

int Enemy_Pos_Init_x(int num) {

	return enemy[num].x;
}

int Enemy_Pos_Init_y(int num) {

	return enemy[num].y;
}

int Enemy_End() {
	//�I������

	return 0;
}
