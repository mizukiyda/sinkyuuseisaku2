#ifndef INCLUDED_MAP
#define INCLUDED_MAP


#define MAP_SIZE	48			// �}�b�v�`�b�v��̃h�b�g�T�C�Y
#define MAP_WIDTH	10			// �}�b�v�̕�
#define MAP_HEIGHT	8			// �}�b�v�̏c����

#define MAP_MAX 10				// MAP�̍ő吔

extern int MAP_Init();
extern int MAP_Dpct();
extern int MAP_Draw();
extern int MAP_End();

int MAP_Data(int, int);        //�}�b�v�̔z��  Map_data[][]

int MAP_Player_Pos_Init_x();   //�v���C���[�̏���x���W
int MAP_Player_Pos_Init_y();   //�v���C���[�̏���y���W
int MAP_Enemy_Count_Init();      //Enemy�̌�
int MAP_Enemy_Pos_Init_x(int);   //Enemy�̏���X���W
int MAP_Enemy_Pos_Init_y(int);   //Enemy�̏���Y���W

int MAP_GetHandleflag();
void MAP_SetHandleflag(int);

#endif
