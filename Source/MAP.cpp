// �}�b�v�\����{
#include "DxLib.h"
#include "MAP.h"
#include "Player.h"
#include "Enemy.h"
#include "Scene_Mgr.h"
#include "Keyboard.h"
int FileHandle, y;
static int i = 0, j = 0;
char buf[256];
char c1, c2;				    //MAP��Player,Enemy�Ɏg��char
int MAP[MAP_HEIGHT][MAP_WIDTH]; //�}�b�v
int px, py;				    	//�󂯎��v���C���[�̕ϐ�
int Enemy_Count;				//�󂯎��Enemy�̕ϐ�;
static int Enemy_Pos_x[10];		//�󂯎��Enemy��x���W�ϐ�
static int Enemy_Pos_y[10];		//�󂯎��Enemy��y���W�ϐ�
int lflag;

int Image_Wall = 0;			// ��
int Image_Load = 0;			// �n�ʁA��
int Image_Goal = 0;			// �S�[��

char MAPHandle[256];		// ���ʓI�Ƀ}�b�v���ɂȂ�ϐ�
int Handleflag = 1;			// ���ʂ��J����

//10��define��const�Œ�`���ׂ�
//�ނ���\���̂����ʂ��ׂ�


//�v���C���[�̏���x���W���󂯎��
int MAP_Player_Pos_Init_x(){

	return px;		//�����������v���C���[��x���W��߂�
}

//�v���C���[�̏���y���W���󂯎��
int MAP_Player_Pos_Init_y() {

	return py;		//�����������v���C���[��y���W��߂�
}

//MAP�̍��W
int MAP_Data(int x, int y) {	

	return MAP[y][x];
}

//Enemy�̌����󂯎��
int MAP_Enemy_Count_Init() {

	return Enemy_Count;
}

//Enemy�̏���X���W
int MAP_Enemy_Pos_Init_x(int num) {

	return Enemy_Pos_x[num];
}

//Enemy�̏���Y���W
int MAP_Enemy_Pos_Init_y(int num) {

	return Enemy_Pos_y[num];
}

//������
int MAP_Init() {
	memset(MAP, -1, sizeof(MAP));
	Enemy_Count = 1;	//�󂯎����Enemy�̐��̏�����
	i = 0; j = 0;

	//�摜�̓ǂݍ���
	Image_Wall = LoadGraph("resource/Image/Player.png");	// �ǂ̉摜�ƃp�X
	Image_Load = LoadGraph("resource/Image/Player.png");	// �n�ʂ̉摜�ƃp�X
	Image_Goal = LoadGraph("resource/Image/Player.png");	// �S�[���̉摜�ƃp�X
	
	char Handletmp[256];	// ���ʓI�ɂ��̖��O�̃p�X�Ńt�@�C�����J��
	char flagtmp[256];		// MAP_�Z�c�Z�̕���

	strcpy_s(MAPHandle, "resauce/MAP/MAP_");	// MAPHandle�ɌŒ蕶���R�s�[

	sprintf_s(flagtmp, "%d", Handleflag);		// falgtmp��MAP_SetHandleflag���琔��������

	strcpy_s(Handletmp, MAPHandle);			    // MAPHandle�ɃR�s�[�����̂��R�s�[

	strcat_s(Handletmp, flagtmp);				// flagtmp�ɃR�s�[�����̂��R�s�[

	strcat_s(Handletmp, ".csv");				// �Ō��.csv���R�s�[

	// resauce/MAP/MAP_ / %d / .csv	�ŋ�敪�����Ă���

	// MAP�̓ǂݍ���
	FileHandle = FileRead_open( Handletmp );	// ��s�ǂݍ���
													// �t�@�C���̏I�[������܂ŕ\������
	if (FileHandle == 0) {

//		WaitKey();
		Scene_Mgr_ChangeScene(E_Scene_StartMenu);
		return -1;
	}

	while (FileRead_eof(FileHandle) == 0) {			// ��s�ǂݍ���

		//c1 = MAP��char
		c1 = FileRead_getc(FileHandle);		//1�����ǂݍ���
		if ('0' <= c1 && c1 <= '9') {		//����0�`9��������
			MAP[i][j] = c1 - '0';				//MAP�ɑ��
		}
		else if (c1 == ',') {				//����","��ǂݍ��񂾂�
			j++;							//�E�̐�����ǂݍ���
		}
		else if (c1 == '\n') {					//����"\n"��ǂݍ��񂾂�
			j = 0;							//�E�ɍs���̂���߂�
			i++;							//���̍s�ɍs��
		}
	} 

	// �t�@�C�������
	FileRead_close(FileHandle);

	// Player��Enemy�̓ǂݍ���
	strcpy_s(Handletmp, MAPHandle);

	strcat_s(Handletmp, flagtmp);

	strcat_s(Handletmp, ".txt");

	
	// Player�̍��W�ǂݍ���
	FileHandle = FileRead_open( Handletmp );	//1�s�ǂݍ���
													// �t�@�C���̏I�[������܂ŕ\������
	if (FileHandle == 0) {
//		WaitKey();
		Scene_Mgr_ChangeScene(E_Scene_StartMenu);
		return -1;
	}

	//c2 = Player��Enemy��char
	
	c2 = FileRead_getc(FileHandle);		//1�����ǂݍ���	
	px = c2 - '0';				    //Player��X���W�ɑ��
	
	FileRead_getc(FileHandle);

	c2 = FileRead_getc(FileHandle);						//�E�̐�����ǂݍ���
	py = c2 - '0';

	FileRead_getc(FileHandle);

	
	Enemy_Count = 0;

	
	while (1) {
		FileRead_getc(FileHandle);
		if (c2 == EOF)break;
		c2 = FileRead_getc(FileHandle);
		if (c2 == EOF)break;
		Enemy_Pos_x[Enemy_Count] = c2 - '0';
		
		FileRead_getc(FileHandle);
		if (c2 == EOF)break;
		c2 = FileRead_getc(FileHandle);
		if (c2 == EOF)break;
		Enemy_Pos_y[Enemy_Count] = c2 - '0';
		FileRead_getc(FileHandle);
		if (c2 == EOF)break;
		Enemy_Count++;
	}
	
	// �t�@�C�������
	FileRead_close(FileHandle);

	return 0;

}



//�v�Z
int MAP_Dpct() {
	//Dpct�͖��t���[���Ă΂��
	if (Keyboard_Get(KEY_INPUT_SPACE) == 1) {	//���W��80�ɂȂ��Ă��鍀�ڂŃX�y�[�X�L�[��������
		Scene_Mgr_ChangeScene(E_Scene_Result);
	}
	return 0;
}


//�`��
int MAP_Draw() {
	//�����������t���[���Ă΂�邪�v�Z�Ƃ͕ʂɏ����܂�
	
	// �}�b�v��`��
	for (i = 0; i < MAP_HEIGHT; i++)
	{
		for (j = 0; j < MAP_WIDTH; j++)
		{
			if (MAP[i][j] == P_Object_Wall)		// �ǂ̕`�揈��
			{
				DrawGraph(i * MAP_SIZE, j * MAP_SIZE, Image_Wall, TRUE);
			}
			if (MAP[i][j] == P_Object_Load)		// ���̕`�揈��
			{
				DrawGraph(j * MAP_SIZE, i * MAP_SIZE, Image_Load, TRUE);
			}
			if (MAP[i][j] == P_Object_Goal)		// �S�[���̕`�揈��
			{
				DrawGraph(j * MAP_SIZE, i * MAP_SIZE, Image_Goal, TRUE);
			}
		}
	}

	DrawFormatString(100, 200, GetColor(255, 255, 255), "MAP Draw�����Ă���");
	return 0;
}


void MAP_SetHandleflag(int num) {
	Handleflag = num;
}

int MAP_GetHandleflag() {
	return Handleflag;
}

//�I��
int MAP_End() {
	DeleteGraph(Image_Wall);
	DeleteGraph(Image_Load);
	DeleteGraph(Image_Goal);

	return 0;
}