#include"DxLib.h"
#include"Keyboard.h"

static int Key_State[256];	//�L�[�{�[�h�̏��

void Keyboard_Update() {
	char tmpKey[256];			//���݂̃L�[���͂��󂯎��
	GetHitKeyStateAll(tmpKey);	//�S�ẴL�[���͂�tmpKey�Ɋi�[�B

	for (int i = 0; i < 256; i++) {
		if (tmpKey[i] != 0) {	//�L�[���������ƁAi�Ԃ�tmpKey�Ɋi�[����邽�߁A0�ɂȂ�Ȃ��B
			Key_State[i]++;
		}
		else {					//������ĂȂ���ԂȂ�A0�ɖ߂��B
			Key_State[i] = 0;
		}
	}
}

//
int Keyboard_Get(int KeyCode) {
	return Key_State[KeyCode];
}