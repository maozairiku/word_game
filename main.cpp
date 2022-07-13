/*******************************************************************************
* �^�C�g��:		main�v���O����
* �v���O������:	main.cpp
* �쐬��:		GP11B132 05 ���E��
* �쐬��:		2022/07/07
*******************************************************************************/


/*******************************************************************************
* �C���N���[�h�t�@�C��
*******************************************************************************/
#include "main.h"
#include "title.h"
#include "player.h"
#include "enemy.h"
#include "field.h"
#include "map.h"
#include "battle.h"
#include "npc.h"

/*******************************************************************************
* �}�N����`
*******************************************************************************/


/*******************************************************************************
* �\���̒�`
*******************************************************************************/


/*******************************************************************************
* �v���g�^�C�v�錾
*******************************************************************************/


/*******************************************************************************
* �O���[�o���ϐ�
*******************************************************************************/
int g_mode = GAME_TITLE;

/*******************************************************************************
 �֐���:	int main( void )
 ����:	void
 �߂�l:	����I��: int�^�� 0
 ����:	���C���֐�
*******************************************************************************/
int main(void) {
	Init();
	while (GetMode() < GAME_END) {
		Update();
		Draw();
	}
	
	Uninit();
	return 0;

}

// ����������
void Init(void) {
	srand((unsigned)time(NULL));

	//InitTitle();
	InitPlayer();
	//InitEnemy();
	//InitBattle();
	//InitField();
	//InitMap();
}

// �I������
void Uninit(void) {
	rewind(stdin);
	_getch();

}

// �X�V����
void Update(void) {
	switch (GetMode()) {
	case GAME_TITLE:
		UpdateTitle();
		break;

	case GAME_MODE:
		UpdateEnemy();
		UpdateNpc();
		UpdatePlayer();
		//UpdateField();
		UpdateMap();
		break;

	case GAME_MAP2:
		UpdateEnemy();
		UpdateNpc();
		UpdatePlayer();
		//UpdateField();
		UpdateMap();
		break;

	case GAME_MAP3:
		UpdateEnemy();
		UpdateNpc();
		UpdatePlayer();
		//UpdateField();
		UpdateMap();
		break;

	case GAME_MAP4:
		UpdateEnemy();
		UpdateNpc();
		UpdatePlayer();
		//UpdateField();
		UpdateMap();
		break;

	case GAME_BATTLE:
		UpdateBattle();
		break;
	}
}

// �`�揈��
void Draw(void) {
	switch (GetMode()) {
	case GAME_TITLE:
		DrawTitle();
		break;

	case GAME_MODE:
		DrawEnemy();
		DrawPlayer();
		DrawNpc();
		//DrawField();
		DrawMap();
		break;

	case GAME_MAP2:
		DrawEnemy();
		DrawPlayer();
		DrawNpc();
		//DrawField();
		DrawMap();
		break;

	case GAME_MAP3:
		DrawEnemy();
		DrawPlayer();
		DrawNpc();
		//DrawField();
		DrawMap();
		break;

	case GAME_MAP4:
		DrawEnemy();
		DrawPlayer();
		DrawNpc();
		//DrawField();
		DrawMap();
		break;

	case GAME_BATTLE:
		DrawBattle();
		break;
	}
}

// �Q�[�����[�h�擾
int GetMode(void) {
	return g_mode;
}

// �Q�[�����[�h�ύX
void SetMode(int mode) {
	g_mode = mode;

	UninitTitle();
	UninitPlayer();
	UninitEnemy();
	UninitNpc();
	UninitBattle();
	//UninitField();
	UninitMap();

	switch (mode) {
	case GAME_TITLE:
		InitTitle();
		break;

	case GAME_MODE:
		//InitPlayer();
		InitEnemy();
		InitNpc();
		//InitField();
		InitMap();
		break;

	case GAME_MAP2:
		//InitPlayer();
		InitEnemy();
		InitNpc();
		//InitField();
		InitMap();
		break;

	case GAME_MAP3:
		//InitPlayer();
		InitEnemy();
		InitNpc();
		//InitField();
		InitMap();
		break;

	case GAME_MAP4:
		//InitPlayer();
		InitEnemy();
		InitNpc();
		//InitField();
		InitMap();
		break;

	case GAME_BATTLE:
		InitBattle();
		break;
	}
}