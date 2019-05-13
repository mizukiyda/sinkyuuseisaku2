#ifndef PLAYER_DEFENCE
#define PLAYER_DEFENCE

extern int Player_Init();
extern int Player_Dpct();
extern int Player_Draw();
extern int Player_End();

typedef struct {
	int x;		//現在位置
	int y;		//現在位置
	int nx;		//移動先
	int ny;		//移動先
}P_PLAYER;	//Pos_Player

/*typedef enum {

	E_Drct_Up,     //上
	E_Drct_Right,  //右
	E_Drct_Down,   //下
	E_Drct_Left,   //左

	E_Drct_None
} E_Drct;  //Drct = Direction(向き)*/
	
typedef enum {
	P_Object_Wall,      //行けない場所
	P_Object_Load,      //歩ける場所
	P_Object_Goal,      //ゴール
}P_Object;	//物体


#endif 
