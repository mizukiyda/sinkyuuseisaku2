#include "DxLib.h"
#include "Result.h"
#include "StartMenu.h"
#include "Keyboard.h"
#include "Scene_Mgr.h"

MenuElement_t ResultMenuElement[MENU_ELEMENT_MAX]{
{ 100 , 200 , "Next" },
{ 100 , 300 , "Title" },
{ 100 , 400 , "Exit" }
};

//�����ŕϐ���錾�iC++���g��Ȃ��̂ŃO���[�o���ϐ��j


static int SelectNum;


// Init ������
int Result_Init() {
	//�����ŏ�����������
	//step_count = UI_StepCount();			UI���ł�����R�����g���͂���
	SelectNum = 0;
	return 0;
}

int Result_Dpct() {
	//�����Ōv�Z
	//Dqct�͖��t���[���Ă΂��
	if (Keyboard_Get(KEY_INPUT_UP) == 1) {
		SelectNum = (SelectNum - 1) % 3;	// ���݂̑I�����ڂ����ɂ��炷
	}
	if (SelectNum == -1) {
		SelectNum = MENU_ELEMENT_MAX - 1;
	}

	if (Keyboard_Get(KEY_INPUT_DOWN) == 1) {
		SelectNum = (SelectNum + 1) % 3;	// ���݂̑I�����ڂ�����ɂ��炷
	}
	for (int i = 0; i < MENU_ELEMENT_MAX; i++) {
		if (i == SelectNum) {          // ���������Ă���̂��A�I��ԍ��Ɠ����v�f�Ȃ�
			ResultMenuElement[i].x = 80; // ���W��80�ɂ���
			if (Keyboard_Get(KEY_INPUT_SPACE) == 1) {	//���W��80�ɂȂ��Ă��鍀�ڂŃX�y�[�X�L�[��������
														//���̍��ڂ̒��ɓ���
				int tmp;
				switch (i) {
				/*case 0:
					// ���̃X�e�[�W��
					// ���̃X�e�[�W�̓G�̔z�������

					Scene_Mgr_ChangeScene(E_Scene_Game);




					tmp = MAP_GetHandleflag();
						//Scene_Mgr_ChangeScene(E_Scene_StartMenu);
					else {
						MAP_SetHandleflag(tmp + 1);
						Scene_Mgr_ChangeScene(E_Scene_Game);
					}


					break;	*/
				case 1:
					Scene_Mgr_ChangeScene(E_Scene_StartMenu);
					break;
				case 2:
					Scene_Mgr_End();
					DxLib_End(); // DX���C�u�����I������
					exit(0);
					break;
				}
			}
		}
		else {                     // ���������Ă���̂��A�I��ԍ��ȊO�Ȃ�
			ResultMenuElement[i].x = 100;// ���W��100�ɂ���
		}
	}

	return 0;
}

int Result_Draw() {
	//�����ŕ`��
	//�����������t���[���Ă΂�܂����v�Z�Ƃ͕ʂɏ����܂�

	DrawFormatString(100, 100, GetColor(255, 255, 255), "�肴���");

	for (int i = 0; i<MENU_ELEMENT_MAX; i++) { // ���j���[���ڂ�`��
		DrawFormatString(ResultMenuElement[i].x, ResultMenuElement[i].y, GetColor(255, 255, 255), ResultMenuElement[i].name);
	}

	return 0;
}

int Result_End() {
	//�����ŏI������
	return 0;
}