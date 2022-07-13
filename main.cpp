/*******************************************************************************
* タイトル:		mainプログラム
* プログラム名:	main.cpp
* 作成者:		GP11B132 05 王ウ華
* 作成日:		2022/07/07
*******************************************************************************/


/*******************************************************************************
* インクルードファイル
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
int g_mode = GAME_TITLE;

/*******************************************************************************
 関数名:	int main( void )
 引数:	void
 戻り値:	正常終了: int型の 0
 説明:	メイン関数
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

// 初期化処理
void Init(void) {
	srand((unsigned)time(NULL));

	//InitTitle();
	InitPlayer();
	//InitEnemy();
	//InitBattle();
	//InitField();
	//InitMap();
}

// 終了処理
void Uninit(void) {
	rewind(stdin);
	_getch();

}

// 更新処理
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

// 描画処理
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

// ゲームモード取得
int GetMode(void) {
	return g_mode;
}

// ゲームモード変更
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