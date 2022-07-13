/*******************************************************************************
* �^�C�g��:		enemy�v���O����
* �v���O������:	enemy.cpp
* �쐬��:		GP11B132 05 ���E��
* �쐬��:		2022/07/07
*******************************************************************************/


/*******************************************************************************
* �C���N���[�h�t�@�C��
*******************************************************************************/
#include "main.h"
#include "player.h"
#include "enemy.h"
#include "map.h"

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
ENEMY g_Enemy[ENEMY_MAX];

// ����������
void InitEnemy(void){
	for (int i = 0; i < ENEMY_MAX; i++) {
		g_Enemy[i].y = 1 + (rand() % (MAINMAP_H - 10));
		g_Enemy[i].x = 1 + (rand() % (MAINMAP_W - 10));

		g_Enemy[i].hp = 100;
		g_Enemy[i].atk = rand() % 10;
		g_Enemy[i].mp = 20;
		g_Enemy[i].speed  = rand() % 20;
		g_Enemy[i].lucky = rand() % 80;
		g_Enemy[i].critical = (g_Enemy[i].atk) + 20;
		g_Enemy[i].collision = false;
	}
}

// �I������
void UninitEnemy(void) {

}

// �X�V����
void UpdateEnemy(void) {
	for (int i = 0; i < ENEMY_MAX; i++) {
		g_Enemy[i].old_x = g_Enemy[i].x;
		g_Enemy[i].old_y = g_Enemy[i].y;

		// Enemy moving 
		int key = rand() % 4;

		switch (key) {
		case 0:
			g_Enemy[i].x--;
			break;

		case 1:
			g_Enemy[i].x++;
			break;

		case 2:
			g_Enemy[i].y--;
			break;

		case 3:
			g_Enemy[i].y++;
			break;

		default:
			break;
		}

		// map range check
		int answer = CheckMap(g_Enemy[i].y, g_Enemy[i].x);
		switch (answer) {
		case 1:
			g_Enemy[i].y = g_Enemy[i].old_y;
			g_Enemy[i].x = g_Enemy[i].old_x;
			break;

		default:
			break;
		}
	}
}

void DrawEnemy(void) {
	for (int i = 0; i < ENEMY_MAX; i++) {
		SetMap(g_Enemy[i].y, g_Enemy[i].x, 'E');	
	}
}

ENEMY* GetEnemy(void) {
	for (int i = 0; i < ENEMY_MAX; i++) {
		return &g_Enemy[i];
	}
}