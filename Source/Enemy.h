#ifndef INCLUDE_ENEMY
#define INCLUDE_ENEMY

extern int Enemy_Init();
extern int Enemy_Dpct();
extern int Enemy_Draw();
extern int Enemy_End();


typedef struct {	//�\����
	int x;		//enemy��x���W
	int y;		//enemy��y���W

	int ex;		//enemy��bullet��x���W
	int ey;		//enemy��bullet��y���W
} S_Enemy;

typedef enum {

	E_Drct_Stop,	//�Ƃ܂�	-> 0
	E_Drct_Up,		//��		-> 1
	E_Drct_Right,	//�E		-> 2
	E_Drct_Down,	//��		-> 3
	E_Drct_Left,	//��		-> 4

} E_Drct;  //Drct = Direction(����)

#endif