#ifndef PLAYER_DEFENCE
#define PLAYER_DEFENCE

extern int Player_Init();
extern int Player_Dpct();
extern int Player_Draw();
extern int Player_End();

typedef struct {
	int x;		//���݈ʒu
	int y;		//���݈ʒu
	int nx;		//�ړ���
	int ny;		//�ړ���
}P_PLAYER;	//Pos_Player
	
typedef enum {
	P_Object_Wall,      //�s���Ȃ��ꏊ
	P_Object_Load,      //������ꏊ
	P_Object_Goal,      //�S�[��
}P_Object;	//����


#endif 
