#pragma once

typedef struct {	//構造体
	int x, y;  //座標の変数
	//int num;	//画像入れたらコメントアウト解除
	char name[256];     //項目名の変数
} MenuElement_t;


typedef struct {	//画像入れたらコメントアウト解除
	
	int Start;
	int On_Start;
	int End;
	int On_End;

} Image_t;

extern int StartMenu_Init();
extern int StartMenu_Dpct();
extern int StartMenu_Draw();
extern int StartMenu_End();