#ifndef INCLUDE_PLAYER		//�w�b�_�t�@�C���͑��d�C���N���[�h�h�~�̃}�N�����`����
#define INCLUDE_PLAYER

extern int Player_Init();
extern int Player_Dpct();
extern int Player_Draw();
extern int Player_End();

 int Player_Check();
 int Player_Move();
 int Player_Pos_Init_x();
 int Player_Pos_Init_y();

typedef struct {
	int x;		//���݈ʒu
	int y;		//���݈ʒu
	int nx;
	int ny;
}P_PLAYER;	//Pos_Player
	
typedef enum {
	P_Object_Wall,      //�s���Ȃ��ꏊ
	P_Object_Load,      //������ꏊ
	P_Object_Goal,      //�S�[��
}P_Object;	//����


#endif
