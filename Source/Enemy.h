#ifndef INCLUDE_ENEMY
#define INCLUDE_ENEMY

extern int Enemy_Init();
extern int Enemy_Dpct();
extern int Enemy_Draw();
extern int Enemy_End();


typedef struct {	//構造体
	int x;		//enemyのx座標
	int y;		//enemyのy座標

	int ex;		//enemyのbulletのx座標
	int ey;		//enemyのbulletのy座標
} S_Enemy;

typedef enum {

	E_Drct_Stop,	//とまる	-> 0
	E_Drct_Up,		//上		-> 1
	E_Drct_Right,	//右		-> 2
	E_Drct_Down,	//下		-> 3
	E_Drct_Left,	//左		-> 4

} E_Drct;  //Drct = Direction(向き)

#endif