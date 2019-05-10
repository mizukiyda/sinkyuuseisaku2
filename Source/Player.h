#ifndef PLAYER_DEFENCE
#define PLAYER_DEFENCE

typedef struct {
	int x;		//���݈ʒu
	int y;		//���݈ʒu
	int nx;		//�ړ���
	int ny;		//�ړ���
}P_PLAYER;	//Pos_Player

typedef struct {
	bool RIGHT;
	bool LEFT;
	bool UP;
	bool DOWN;
	bool NONE;
}P_DRCT;	//�v���C���[�̌���  Player_Direction
	
typedef enum {
	P_Object_Wall,      //�s���Ȃ��ꏊ
	P_Object_Load,      //������ꏊ
	P_Object_Goal,      //�S�[��
}P_Object;	//����


#endif 
