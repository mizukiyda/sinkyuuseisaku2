#ifndef INCLUDE_ENEMY
#define INCLUDE_ENEMY

extern int Enemy_Init();
extern int Enemy_Dpct(int);
extern int Enemy_Draw();
extern int Enemy_End();

extern int Enemy_MapDeta(int, int);

extern int Enemy_Attack_Down(int);
extern int Enemy_Attack_Up(int);
extern int Enemy_Attack_Right(int);
extern int Enemy_Attack_Left(int);
extern int Enemy_Hit();
extern int Enemy_Pos_Init_x(int);
extern int Enemy_Pos_Init_y(int);


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

 //�I�u�W�F�N�g�̓����蔻��p
typedef enum {

	E_Object_Load,      //������ꏊ      -> 0
	E_Object_Wall,      //�s���Ȃ��ꏊ    -> 1

}E_Object;

#endif