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

/*typedef enum {

	E_Drct_Up,     //��
	E_Drct_Right,  //�E
	E_Drct_Down,   //��
	E_Drct_Left,   //��

	E_Drct_None
} E_Drct;  //Drct = Direction(����)*/
	
typedef enum {
	P_Object_Wall,      //�s���Ȃ��ꏊ
	P_Object_Load,      //������ꏊ
	P_Object_Goal,      //�S�[��
}P_Object;	//����


#endif 
