/*******************************************************************************
* �^�C�g��:		Player�v���O����
* �v���O������:	player.cpp
* �쐬��:		GP11B132 05 ���E��
* �쐬��:		2022/07/07
*******************************************************************************/

/*******************************************************************************
* �C���N���[�h�t�@�C��
*******************************************************************************/
#include "main.h"
#include "player.h"
#include "field.h"
#include "enemy.h"
#include "map.h"
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
PLAYER g_Player;

// collision judge easing
int xdistance;
int ydistance;

// ������
void InitPlayer(void) {
	g_Player.y = 2;
	g_Player.x = 2;

	g_Player.hp =  160;
	//g_Player.atk = rand() % 20;
	//g_Player.lucky = rand() % 90;
	//g_Player.critical = (g_Player.atk) + 20;

	g_Player.apple = 10;
}

// �I������
void UninitPlayer(void) {

}

// �X�V����
void UpdatePlayer(void) {
	g_Player.mapoint = GetMode();

	g_Player.old_x = g_Player.x;
	g_Player.old_y = g_Player.y;


	int key = _getch();
	if ((key == 0) || (key == 224)) {
		key = _getch();
	}

	switch (key) {
		case'a':		//��
		case 0x4b:
			g_Player.x--;
			break;

		case'd':		//��
		case 0x4d:
			g_Player.x++;
			break;

		case'w':		//��
		case 0x50:
			g_Player.y++;
			break;

		case's':		//��
		case 0x48:
			g_Player.y--;
			break;

		default:
			break;
	}


	int answer = CheckMap(g_Player.y, g_Player.x);
	switch (answer) {
	case 1:
		g_Player.y = g_Player.old_y;
		g_Player.x = g_Player.old_x;
		break;

	default:
		break;
	}

	// when hit on enemy
	ENEMY* enemy = GetEnemy();

	for (int i = 0; i < ENEMY_MAX; i++) {
		if ((abs(enemy[i].x-g_Player.x) <= 1) && ((abs(enemy[i].y-g_Player.y))<=1)) {
			enemy[i].collision = true;
			SetMode(GAME_BATTLE);
		}
	}

	//when hit on NPC
	NPC* npc = GetNpc();

	for (int i = 0; i < NPC_MAX; i++) {
		if ((abs(g_Player.x - npc[i].x) <= 1) && ((abs(g_Player.y - npc[i].y)) <= 1)) {
			printf("���l�ł��ˁB���ꂮ��C�����Ă��������B\n");
			Sleep(500);
		}
	}

	// change map
	if (g_Player.y == 22) {
		switch (GetMode()) {
		case GAME_MODE:
			SetMode(GAME_MAP2);
			break;

		case GAME_MAP2:
			SetMode(GAME_MAP3);
			break;

		case GAME_MAP3:
			SetMode(GAME_MAP4);
			break;

		case GAME_MAP4:
			SetMode(GAME_MODE);
			break;
		}
	}
}


void DrawPlayer(void) {
	SetMap(g_Player.y, g_Player.x, 'P');

}

PLAYER* GetPlayer(void) {
	return &g_Player;
}


