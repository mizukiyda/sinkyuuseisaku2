#include"Dxlib.h"
#include"Enemy.h"
#include"MAP.h"
#include"Player.h"
#include"Keyboard.h"

int Enemyalive;          //�G�̉摜�̕ϐ�(��)
int Enemydeath;          //�G�̉摜�̕ϐ�(��)

//����
int Drct;

//�J�E���g
int Count_x;
int Count_y;

//enemy�̍��W
int Enemy_x;
int Enemy_y;
int Enemy_nx;
int Enemy_ny;

//player�̍��W
int Player_x;
int Player_y;

int E_Rand;
int Enemy_OnActive;

int E_Move_Flg;

int Enemy_Init() {

	Enemyalive = LoadGraph("resource/Image/Enemyalive.png");
	Enemydeath = LoadGraph("resource/Image/Enemydeath.png");

	Enemy_OnActive = true;		//�������� == �����Ă���

	E_Move_Flg = false;
	return 0;
}

int Enemy_Dpct() {
	Enemy_x = MAP_Enemy_Pos_Init_x();
	Enemy_y = MAP_Enemy_Pos_Init_y();

	Player_x = Player_Pos_Init_x();
	Player_y = Player_Pos_Init_y();

	if (Enemy_OnActive == true) {
		if (E_Move_Flg == false) {
			if (MAP_Data(Enemy_x, Enemy_y) == P_Object_Load) {
				Drct = (E_Drct)GetRand(4);			//����
				E_Move_Flg = true;
			}
		}


		/*************************************************  Enemy�̈ړ�����  *********************************************************************/

		if (E_Move_Flg == true) {
			switch (Drct)
			{
				//��
			case E_Drct_Up:						//��������Ȃ�(1)
				Count_y--;						//�k���k��������
				break;
				//��
			case E_Drct_Left:					//���������Ȃ�(4)
				Count_x--;						//�k���k��������
				break;

				//��
			case E_Drct_Down:					//���������Ȃ�(3)
				Count_y++;						//�k���k��������
				break;

				//�E
			case E_Drct_Right:					//�������E�Ȃ�(2)
				Count_x++;						//�k���k��������
				break;

				//�~�܂�
			case E_Drct_Stop:					//�����Ȃ�

				break;

			}
			if (Drct == E_Drct_Up) {
				Enemy_ny--;
			}
			if (Drct == E_Drct_Down) {
				Enemy_ny++;
			}
			if (Drct == E_Drct_Right) {
				Enemy_nx++;
			}
			if (Drct == E_Drct_Left) {
				Enemy_nx--;
			}
			//Count_x��Count_y�̃J�E���g���}64��B�����Ȃ�@
			if (Count_x >= MAP_SIZE - 1 || Count_y <= -MAP_SIZE + 1 || Count_x <= -MAP_SIZE + 1 || Count_y >= MAP_SIZE - 1) {
				Count_x = 0;
				Count_y = 0;

				Enemy_x = Enemy_nx;
				Enemy_y = Enemy_ny;

				E_Move_Flg = false;
				//Drct = E_Drct_Stop;
			}
		}
		if (E_Move_Flg == false) {
			//�ڂ̑O���ǂ��ǂ����̔��ʂ�����ienemy��pMap�����Ĕ��f����) -> �ڂ̑O���ǂ̂Ƃ�    -> 1�Ȃ�
			if (MAP_Data(Enemy_x, Enemy_y) == P_Object_Wall) {

				/*if (E_Drct_Up == true) {
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
				}*/
				E_Move_Flg = false;
			}
		}
	}
	return 0;
}

//Enemy�̈ړ������֐��ŊǗ�����
int Enemy_Move() {
	//if()
	return 0;

}
int  Enemy_Move1() {
	return 0;
}
int  Enemy_Move2() {
	return 0;
}
int  Enemy_Move3() {
	return 0;
}
int  Enemy_Move4() {
	return 0;
}
//	switch (E_Rand) {
int Enemy_Pos_Init_x() {

	return Enemy_x;
}
int Enemy_Pos_Init_y() {

	return Enemy_y;
}

int Enemy_Draw() {
	if (Enemy_OnActive == true)
	{
		DrawGraph(Enemy_x * MAP_SIZE  + Count_x, Enemy_y * MAP_SIZE + Count_y, Enemyalive, true);
	}
	
	return 0;
}

int Enemy_End() {
	return 0;
}