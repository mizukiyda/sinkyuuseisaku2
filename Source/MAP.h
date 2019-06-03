#ifndef INCLUDED_MAP
#define INCLUDED_MAP


#define MAP_SIZE	48			// マップチップ一つのドットサイズ
#define MAP_WIDTH	23			// マップの幅
#define MAP_HEIGHT	15			// マップの縦長さ

#define MAP_MAX 3

extern int MAP_Init();
extern int MAP_Dpct();
extern int MAP_Draw();
extern int MAP_End();

int MAP_Data(int ,int );
int MAP_Player_Pos_Init_x();
int MAP_Player_Pos_Init_y();
int MAP_Enemy_Pos_Init_x();
int MAP_Enemy_Pos_Init_y();

#endif
