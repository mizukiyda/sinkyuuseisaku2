#ifndef INCLUDE_ENEMY
#define INCLUDE_ENEMY
#define  EnemyCount 1
extern int Enemy_Pos_Init_x();
extern int Enemy_Pos_Init_y();
extern int Enemy_Init();
extern int Enemy_Dpct();
extern int Enemy_Draw();
extern int Enemy_End();


typedef struct {	//�\����
	int x;		//enemy��x���W
	int y;		//enemy��y���W
	int type;   //�G�̃^�C�v(���)
} S_Enemy;

typedef enum {

	E_Drct_Stop,	//�Ƃ܂�	-> 0
	E_Drct_Up,		//��		-> 1
	E_Drct_Right,	//�E		-> 2
	E_Drct_Down,	//��		-> 3
	E_Drct_Left,	//��		-> 4

} E_Drct;  //Drct = Direction(����)

#endif