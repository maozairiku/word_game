/*******************************************************************************
* �^�C�g��:		battle�v���O����
* �v���O������:	battle.cpp
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
#include "battle.h"

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
int selection;
bool battleend;

// battle scene
char battlescene[BATTLESCENE_H][BATTLESCENE_W] = {
	"|============================================================================|",
	"|                                                                            |",
	"|                                                                            |",
	"|                                                                            |",
	"|                                                                            |",
	"|                  E         E                                               |",
	"|                 E E       E E                |---------|                   |",
	"|                E   EEEEEEE   E               | GA GA O |                   |",
	"|      H H      E               E     H H      |_________|                   |",
	"|     H H HE   E    |       |    E   EH H H   /                              |",
	"|     E    E  E         |         E E    E                                   |",
	"|      E    E  E       V V       E E    E               |-----------|        |",
	"|       E    E  EE             EE E    E             ---| YA YA YA  |        |",
	"|        E     E  EEEEEEOEEEEEE EE    E                 |___________|        |",
	"|         E     E              E     E                                       |",
	"|          E                        E                                        |",
	"|----------------------------------------------------------------------------|",
	"|    �Ȃ񂩃G�l�~�[�炵���G�l�~�[������܂����I                              |",
	"|    �ǂ����܂��傤�B                                                        |",
	"|                                                                            |",
	"|       1. �키                                                              |",
	"|       2. �a��^����                                                        |",
	"|       3. ������                                                            |",
	"|============================================================================|",
};

char battlewin[BATTLESCENE_H][BATTLESCENE_W] = {
	"|============================================================================|",
	"|                                                                            |",
	"|                                                                            |",
	"|                                                                            |",
	"|                                                                            |",
	"|                                                                            |",
	"|                   Y�@O�@U�@                                                |",
	"|                                                                            |",
	"|                                                                            |",
	"|                                                                            |",
	"|                                                                            |",
	"|                                         W�@I�@N                            |",
	"|                                                                            |",
	"|                                                                            |",
	"|                                                                            |",
	"|                                                                            |",
	"|                                                                            |",
	"|                                                                            |",
	"|                                                                            |",
	"|----------------------------------------------------------------------------|",
	"|                                                                            |",
	"|        �퓬�I�����܂����I                                                  |",
	"|                                                                            |",
	"|============================================================================|",
};

char battlelose[BATTLESCENE_H][BATTLESCENE_W] = {
	"|============================================================================|",
	"|                                                                            |",
	"|                                                                            |",
	"|                                                                            |",
	"|                                                                            |",
	"|                                                                            |",
	"|                                                                            |",
	"|                  Y�@O�@U�@                                                 |",
	"|                                                                            |",
	"|                                                                            |",
	"|                                                                            |",
	"|                                                                            |",
	"|                                                                            |",
	"|                                        L  O  S  E                          |",
	"|                                                                            |",
	"|                                                                            |",
	"|                                                                            |",
	"|                                                                            |",
	"|                                                                            |",
	"|----------------------------------------------------------------------------|",
	"|                                                                            |",
	"|                        -   G A M E    O V E R   -                          |",
	"|                                                                            |",
	"|============================================================================|",
};

char battledie[BATTLESCENE_H][BATTLESCENE_W] = {
	"|============================================================================|",
	"|                                                                            |",
	"|        {/}{/}{/}            {/}      {/}         {/}   {/}{/}{/}           |",
	"|      {/}      {/}        {/}  {/}    {/}{/}   {/}{/}   {/}                 |",
	"|     {/}         {/}     {/}    {/}   {/}  {/}{/} {/}   {/}                 |",
	"|    {/}                 {/}      {/}  {/}   {/}   {/}   {/}{/}{/}           |",
	"|     {/}     {/}{/}     {/}{/}{/}{/}  {/}   {/}   {/}   {/}                 |",
	"|      {/}       {/}     {/}      {/}  {/}   {/}   {/}   {/}                 |",
	"|        {/}{/}{/} {/}   {/}      {/}  {/}         {/}   {/}{/}{/}           |",
	"|                                                                            |",
	"|                                                                            |",
	"|                                                                            |",
	"|           {/}        {/}        {/}  {/}{/}{/}{/}    {/}{/}{/}{/}          |",
	"|        {/}   {/}      {/}      {/}   {/}             {/}         {/}       |",
	"|      {/}      {/}     {/}      {/}   {/}             {/}         {/}       |",
	"|     {/}        {/}    {/}      {/}   {/}             {/}{/}{/}{/}          |",
	"|     {/}        {/}     {/}    {/}    {/}{/}{/}{/}    {/}    {/}            |",
	"|     {/}        {/}     {/}    {/}    {/}             {/}      {/}          |",
	"|     {/}        {/}     {/}    {/}    {/}             {/}       {/}         |",
	"|      {/}      {/}       {/}  {/}     {/}             {/}        {/}        |",
	"|        {/}   {/}         {/}{/}      {/}             {/}         {/}       |",
	"|           {/}             {/}        {/}{/}{/}{/}    {/}          {/}      |",
	"|                                                                            |",
	"|============================================================================|",
};



// ������
void InitBattle(void) {
	for (int i = 0; i < BATTLESCENE_H; i++) {
		printf("%s\n", &battlescene[i][0]);
	}
}

// �I������
void UninitBattle(void) {

}
// �X�V����
void UpdateBattle(void) {
	ENEMY* enemy = GetEnemy();
	PLAYER* player = GetPlayer();

	// player status
	int playerdamage = rand() % 30;
	int playercritical = 20 + (rand() % 25);
	player[0].lucky = rand() % 100;


	// battle select

		scanf("%d", &selection);

		switch (selection) {
		case 1:
			for (int i = 0; i < ENEMY_MAX; i++) {
				if(enemy[i].collision == true ){
					while ((player[0].hp > 0) && (enemy[i].hp > 0)) {
						system("cls");

						// enemy status
						int enemydamage = rand() % 20;
						int enemycritical = 15 + (rand() % 25);
						enemy[i].lucky = rand() % 90;


						if (player[0].lucky < 30) {
							player[0].hp -= enemycritical;
							printf("�N���e�B�J���q�b�g���󂯂܂����Ihp:%d\n", player[0].hp);
							printf("���Ȃ���%d�̃_���[�W���󂯂��c��hp:%d\n", enemydamage, player[0].hp);
							Sleep(500);
						}
						else if (player[0].lucky >= 30) {
							player[0].hp -= enemydamage;
							printf("���Ȃ���%d�̃_���[�W���󂯂��c��hp:%d\n", enemydamage, player[0].hp);
							Sleep(500);
						}
						if (enemy[i].lucky < 30) {
							enemy[i].hp -= playercritical;
							printf("�N���e�B�J���q�b�g���󂯂܂����Ihp:%d\n",enemy[i].hp);
							printf("�G�l�~�[�炵���G�l�~�[��%d�̃_���[�W���󂯂��c��hp:%d\n", playerdamage, enemy[i].hp);
							Sleep(500);
						}
						else if (enemy[i].lucky >= 30) {
							enemy[i].hp -= playerdamage;
							printf("�G�l�~�[�炵���G�l�~�[��%d�̃_���[�W���󂯂��c��hp:%d\n", playerdamage, enemy[i].hp);
							Sleep(500);
						}
					}
				}
			}

			//when HP0 game over
			if (player[0].hp <= 0) {
				for (int i = 0; i < BATTLESCENE_H; i++) {
					printf("%s\n", &battledie[i][0]);
				}
				rewind(stdin);
				_getch();

				SetMode(GAME_END);
			}
			else if (player[0].hp > 0) {
				switch (player[0].mapoint) {
				case GAME_MODE:
					SetMode(GAME_MODE);
					break;

				case GAME_MAP2:
					SetMode(GAME_MAP2);
					break;

				case GAME_MAP3:
					SetMode(GAME_MAP3);
					break;

				case GAME_MAP4:
					SetMode(GAME_MAP4);
					break;
				}
			}
			break;

		case 2:
			while (1) {
				if (player[0].apple == 0) {
					printf("�����S�������Ă��܂���B");
					break;
				}
				else if (player[0].apple != 0) {
					player[0].apple--;
					printf("�����S����^���܂����B\n");
					printf("�G�l�~�[�炵���G�l�~�[�����������ł��B");
					break;
				}
			}
			break;

		case 3:
			player[0].lucky = rand() % 100;
			if (player[0].lucky >= 70) {
				printf("�Ȃ�ƂȂ������o���܂����B");
				Sleep(2000);

				switch (player[0].mapoint) {
				case GAME_MODE:
					SetMode(GAME_MODE);
					break;

				case GAME_MAP2:
					SetMode(GAME_MAP2);
					break;

				case GAME_MAP3:
					SetMode(GAME_MAP3);
					break;

				case GAME_MAP4:
					SetMode(GAME_MAP4);
					break;
				}
				break;
			}
			else if (player[0].lucky < 70) {
				printf("�������Ȃ��ł��B");
			}
			break;
		}
}




// �`�揈��
void DrawBattle(void) {
	ENEMY* enemy = GetEnemy();
	PLAYER* player = GetPlayer();

	if (battleend == true) {
		for (int i = 0; i < ENEMY_MAX;i++) {
			if (enemy[i].collision == true) {
				if ((player[0].hp > enemy[i].hp) && (enemy[i].hp == 0)) {
					for (int i = 0; i < BATTLESCENE_H; i++) {
						printf("%s\n", &battlewin[i][0]);
					}
				}
				else if ((enemy[i].hp > player[0].hp) && (player[0].hp == 0)) {
					for (int i = 0; i < BATTLESCENE_H; i++) {
						printf("%s\n", &battlelose[i][0]);
					}
				}
			}
		}
	}
}
