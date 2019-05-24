#ifndef INCLUDE_ENEMY
#define INCLUDE_ENEMY
#define  EnemyCount 1
extern int Enemy_Pos_Init_x();
extern int Enemy_Pos_Init_y();
/*extern int Enemy_Move0();
extern int Enemy_Move1();
extern int Enemy_Move2();
extern int Enemy_Move3();
extern int Enemy_Move4();*/
extern int Enemy_Init();
extern int Enemy_Dpct();
extern int Enemy_Draw();
extern int Enemy_End();


typedef struct {	//�\����
	int Move_x;		//enemy��x���W
	int Move_y;		//enemy��y���W
	int Type;   //�G�̃^�C�v(���)
	int Enemy_OnActive;		 //Enemy�̐����m�F
} S_Enemy;

typedef enum {

	E_Drct_Stop,	//�Ƃ܂�	-> 0
	E_Drct_Up,		//��		-> 1
	E_Drct_Right,	//�E		-> 2
	E_Drct_Down,	//��		-> 3
	E_Drct_Left,	//��		-> 4

} E_Drct;  //Drct = Direction(����)

#endif