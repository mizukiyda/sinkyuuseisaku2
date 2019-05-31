#ifndef INCLUDE_PLAYER		//ヘッダファイルは多重インクルード防止のマクロを定義する
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
	int x;		//現在位置
	int y;		//現在位置
	int nx;
	int ny;
}P_PLAYER;	//Pos_Player
	
typedef enum {
	P_Object_Wall,      //行けない場所
	P_Object_Load,      //歩ける場所
	P_Object_Goal,      //ゴール
}P_Object;	//物体


#endif
