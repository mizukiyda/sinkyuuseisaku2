#include "StartMenu.h"
#include "Dxlib.h"
#include "Keyboard.h"
#include "Scene_Mgr.h"

MenuElement_t MenuElement[2] = {
{ 100, 100, "�X�^�[�g" }, // �^�O�̒��g�̏��ԂŊi�[�����Bx��100���Ay��100���Aname��"�Q�[���X�^�[�g"��
{ 100, 200, "�Q�[���I��" },
};

//Image_t Image;	//�摜���ꂽ��R�����g�A�E�g����

static int SelectNum;	//�I�����Ă�ԍ�

int StartMenu_Init() {
	//�����ŏ�����������
	
	 SelectNum = 0; // ���݂̑I��ԍ�

	/*//�摜���ꂽ��R�����g�A�E�g����
	 Image.Start = LoadGraph("Image/Start.png");
    Image.On_Start = LoadGraph("Image/Start2.png");
	 Image.End = LoadGraph("Image/End.png");
	 Image.On_End = LoadGraph("Image/End2.png");
	 */
	return 0;
}

int StartMenu_Dpct() {
	//�����Ōv�Z
	//Dqct�͖��t���[���Ă΂��

	if (Keyboard_Get(KEY_INPUT_UP) == 1) {
		SelectNum = (SelectNum + sizeof(MenuElement) / sizeof*(MenuElement)-1) % 2;	// ���݂̑I�����ڂ����ɂ��炷
	}

	if (Keyboard_Get(KEY_INPUT_DOWN) == 1) {
		SelectNum = (SelectNum + 1) % 2;	// ���݂̑I�����ڂ�����ɂ��炷
	}
	for (int i = 0; i<2; i++) {              // ���j���[���ڐ��ł���5���[�v����
		if (i == SelectNum) {          // ���������Ă���̂��A�I��ԍ��Ɠ����v�f�Ȃ�
			MenuElement[i].x = 80; // ���W��80�ɂ���
			if (Keyboard_Get(KEY_INPUT_SPACE) == 1) {	//���W��80�ɂȂ��Ă��鍀�ڂŃX�y�[�X�L�[��������
														//���̍��ڂ̒��ɓ���
				switch (i) {
				case 0:
					Scene_Mgr_ChangeScene(E_Scene_Game);
					break;
				case 1:
					Scene_Mgr_End();
					DxLib_End(); // DX���C�u�����I������
					exit(0);
					break;
				}
			}
		}
		else {                     // ���������Ă���̂��A�I��ԍ��ȊO�Ȃ�
			MenuElement[i].x = 100;// ���W��100�ɂ���
		}
	}
	return 0;
}


int StartMenu_Draw() {
	//�����ŕ`��
	//�����������t���[���Ă΂�܂����v�Z�Ƃ͕ʂɏ����܂�

	for (int i = 0; i<2; i++) { // ���j���[���ڂ�`��
		DrawFormatString(MenuElement[i].x, MenuElement[i].y, GetColor(255, 255, 255), MenuElement[i].name);
	}
	/*
	switch (SelectNum)	//�摜���ꂽ��R�����g�A�E�g����
	{
	case 0:
		DrawGraph(MenuElement[0].x, MenuElement[0].y, Image.Start, TRUE);
		DrawGraph(MenuElement[1].x, MenuElement[1].y, Image.On_End, TRUE);
		break;
	case 1:
	case -1:
		DrawGraph(MenuElement[0].x, MenuElement[0].y, Image.On_Start, TRUE);
		DrawGraph(MenuElement[1].x, MenuElement[1].y, Image.End, TRUE);

		break;

	}
	*/
	return 0;
}


int StartMenu_End() {
	//NoScript
	return 0;
}
