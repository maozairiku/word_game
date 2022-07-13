/*******************************************************************************
* タイトル:		battleプログラム
* プログラム名:	battle.cpp
* 作成者:		GP11B132 05 王ウ華
* 作成日:		2022/07/07
*******************************************************************************/

/*******************************************************************************
* インクルードファイル
*******************************************************************************/
#include "main.h"
#include "player.h"
#include "enemy.h"
#include "map.h"
#include "battle.h"

/*******************************************************************************
* マクロ定義
*******************************************************************************/


/*******************************************************************************
* 構造体定義
*******************************************************************************/


/*******************************************************************************
* プロトタイプ宣言
*******************************************************************************/



/*******************************************************************************
* グローバル変数
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
	"|    なんかエネミーらしいエネミーが現れました！                              |",
	"|    どうしましょう。                                                        |",
	"|                                                                            |",
	"|       1. 戦う                                                              |",
	"|       2. 餌を与える                                                        |",
	"|       3. 逃げる                                                            |",
	"|============================================================================|",
};

char battlewin[BATTLESCENE_H][BATTLESCENE_W] = {
	"|============================================================================|",
	"|                                                                            |",
	"|                                                                            |",
	"|                                                                            |",
	"|                                                                            |",
	"|                                                                            |",
	"|                   Y　O　U　                                                |",
	"|                                                                            |",
	"|                                                                            |",
	"|                                                                            |",
	"|                                                                            |",
	"|                                         W　I　N                            |",
	"|                                                                            |",
	"|                                                                            |",
	"|                                                                            |",
	"|                                                                            |",
	"|                                                                            |",
	"|                                                                            |",
	"|                                                                            |",
	"|----------------------------------------------------------------------------|",
	"|                                                                            |",
	"|        戦闘終了しました！                                                  |",
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
	"|                  Y　O　U　                                                 |",
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



// 初期化
void InitBattle(void) {
	for (int i = 0; i < BATTLESCENE_H; i++) {
		printf("%s\n", &battlescene[i][0]);
	}
}

// 終了処理
void UninitBattle(void) {

}
// 更新処理
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
							printf("クリティカルヒットが受けました！hp:%d\n", player[0].hp);
							printf("あなたが%dのダメージを受けた残りhp:%d\n", enemydamage, player[0].hp);
							Sleep(500);
						}
						else if (player[0].lucky >= 30) {
							player[0].hp -= enemydamage;
							printf("あなたが%dのダメージを受けた残りhp:%d\n", enemydamage, player[0].hp);
							Sleep(500);
						}
						if (enemy[i].lucky < 30) {
							enemy[i].hp -= playercritical;
							printf("クリティカルヒットが受けました！hp:%d\n",enemy[i].hp);
							printf("エネミーらしいエネミーが%dのダメージを受けた残りhp:%d\n", playerdamage, enemy[i].hp);
							Sleep(500);
						}
						else if (enemy[i].lucky >= 30) {
							enemy[i].hp -= playerdamage;
							printf("エネミーらしいエネミーが%dのダメージを受けた残りhp:%d\n", playerdamage, enemy[i].hp);
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
					printf("リンゴが持っていません。");
					break;
				}
				else if (player[0].apple != 0) {
					player[0].apple--;
					printf("リンゴを一つ与えました。\n");
					printf("エネミーらしいエネミーが嬉しそうです。");
					break;
				}
			}
			break;

		case 3:
			player[0].lucky = rand() % 100;
			if (player[0].lucky >= 70) {
				printf("なんとなく逃げ出しました。");
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
				printf("逃げられないです。");
			}
			break;
		}
}




// 描画処理
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
