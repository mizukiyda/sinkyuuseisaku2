#pragma once

typedef struct {	//�\����
	int x, y;  //���W�̕ϐ�
	//int num;	//�摜���ꂽ��R�����g�A�E�g����
	char name[256];     //���ږ��̕ϐ�
} MenuElement_t;


typedef struct {	//�摜���ꂽ��R�����g�A�E�g����
	
	int Start;
	int On_Start;
	int End;
	int On_End;

} Image_t;

extern int StartMenu_Init();
extern int StartMenu_Dpct();
extern int StartMenu_Draw();
extern int StartMenu_End();