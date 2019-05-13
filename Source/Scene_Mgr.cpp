#include "DxLib.h"
#include "Scene_Mgr.h"
#include "StartMenu.h"
#include "Result.h"
#include "Player.h"
#include "Enemy.h"
#include "MAP.h"
//#include "UI.h"
//#include "Sound.h"

static E_Scene Sceneflag = E_Scene_StartMenu;		//���̃V�[��
static E_Scene n_Sceneflag = E_Scene_None;			//���̃V�[��

static void Scene_Mgr_Init_Module(E_Scene scene);	//�w�胂�W���[��������������
static void Scene_Mgr_End_Module(E_Scene scene);	//�w�胂�W���[���̏I���������s��


													//init ������
void Scene_Mgr_Init() {
	Scene_Mgr_Init_Module(Sceneflag);
}

//Dpct �v�Z
void Scene_Mgr_Dpct() {
	if (n_Sceneflag != E_Scene_None) {		//���̃V�[�����Z�b�g����Ă�����
		Scene_Mgr_End_Module(Sceneflag);	    //���݂̃V�[���̏I�����������s
		Sceneflag = n_Sceneflag;			//���̃V�[�������݂̃V�[���ɃZ�b�g
		n_Sceneflag = E_Scene_None;			//���̃V�[�������N���A
		Scene_Mgr_Init_Module(Sceneflag);	//���݂̃V�[����������
	}

	switch (Sceneflag) {
	case E_Scene_StartMenu:
		//�X�^�[�g���j���[
		StartMenu_Dpct();
		break;

	case E_Scene_Game:
		//�Q�[�����		
		MAP_Dpct();
	    //Enemy_Dpct();
		Player_Dpct();
		break;

	case E_Scene_Result:
		//Result_Dpct();
		break;

	case E_Scene_GameMenu:
		//�Q�[�����j���[
		break;
	}
}

//Drow �`��
void Scene_Mgr_Draw() {
	switch (Sceneflag) {
	case E_Scene_StartMenu:
		//�X�^�[�g���j���[
		StartMenu_Draw();
		DrawFormatString(0, 00, GetColor(255, 255, 255), "�X�^�[�g���j���[");
		break;
	case E_Scene_Game:
		//�Q�[�����
		MAP_Draw();
		Enemy_Draw();
		//Player_Draw();
		DrawFormatString(0, 00, GetColor(255, 255, 255), "�Q�[�����");
		break;
	case E_Scene_Result:
		Result_Draw();
		break;
	case E_Scene_GameMenu:
		//�Q�[�����j���[
		DrawFormatString(0, 00, GetColor(255, 255, 255), "�Q�[�����j���[");
		break;
	}
}

//End
void Scene_Mgr_End() {
	Scene_Mgr_End_Module(Sceneflag);
}

void Scene_Mgr_ChangeScene(E_Scene NextScene) {
	n_Sceneflag = NextScene;
}

//�w�胂�W���[���̏�����������
static void Scene_Mgr_Init_Module(E_Scene scene) {
	switch (scene) {
	case E_Scene_StartMenu:
		//�X�^�[�g���j���[
		StartMenu_Init();
		break;
	case E_Scene_Game:
		//�Q�[�����
		Enemy_Init();
		//Player_Init();
		MAP_Init();
		break;
	case E_Scene_Result:
		Result_Init();
		break;
	case E_Scene_GameMenu:
		//�Q�[�����j���[
		break;
	}
}

//�w�胂�W���[���̏I���������s��
static void Scene_Mgr_End_Module(E_Scene scene) {
	switch (scene) {
	case E_Scene_StartMenu:
		//�X�^�[�g���j���[
		StartMenu_End();
		break;
	case E_Scene_Game:
		//�Q�[�����
		Enemy_End();
		//Player_End();
		MAP_End();
		break;
	case E_Scene_Result:
		Result_End();
		break;
	case E_Scene_GameMenu:
		//�Q�[�����j���[
		break;
	}
}
