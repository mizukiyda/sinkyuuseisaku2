#ifndef PLAYER_DEFENCE
#define PLAYER_DEFENCE

typedef struct {
	int x;		//現在位置
	int y;		//現在位置
	int nx;		//移動先
	int ny;		//移動先
}P_PLAYER;	//Pos_Player

typedef struct {
	bool RIGHT;
	bool LEFT;
	bool UP;
	bool DOWN;
	bool NONE;
}P_DRCT;	//プレイヤーの向き  Player_Direction
	
typedef enum {
	P_Object_Wall,      //行けない場所
	P_Object_Load,      //歩ける場所
	P_Object_Goal,      //ゴール
}P_Object;	//物体


#endif 
