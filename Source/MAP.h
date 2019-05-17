#ifndef INCLUDED_MAP
#define INCLUDED_MAP


#define MAP_SIZE	64			// マップチップ一つのドットサイズ
#define MAP_WIDTH	15			// マップの幅
#define MAP_HEIGHT	10			// マップの縦長さ

#define MAP_MAX 3

extern int MAP_Init();
extern int MAP_Dpct();
extern int MAP_Draw();
extern int MAP_End();





#endif
