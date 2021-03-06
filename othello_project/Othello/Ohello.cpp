﻿#include<stdio.h>
#include<stdlib.h>

#include "OthelloLib.h"
#include "function.h"

//オセロ盤面の石配置配列の定義
int* board;

int main() {
	
	//オセロ盤面の石配置配列の定義
	int stone_board[8][8] = {};

	//先頭アドレスを格納する
	board = &stone_board[0][0];

	//勝利プレイヤー
	int win_player = 0;

	//対戦相手(CPU)のレベルを管理する変数
	int level = 0;

	//レベル選択
	printf("対戦相手(CPU)のレベルを選択してください。(弱1～強5)\n");
	level = number_input();
	while (level < 1 || 5 < level)
	{
		printf("1から5で入力して下さい。\n");
		level = number_input();
	}

	/* 1.石の初期配置 */
	//【提供関数】盤面の石の配置を初期化する(全て未配置ではなくゲーム開始時点の状態)
	initializeBoard(board, 64);

	/* 2.盤面の表示 */
	//【提供関数】オセロの盤面を描画する(レイアウトから全て描画される)
	printBoard(board, 64);

	/* 3.ゲーム開始時の表示 */
	game_start();

	/* 4.現在のプレイヤーの表示 */
	/* 5.石の配置位置の入力 */
	/* 6.石の配置位置のエラーメッセージ表示 */
	/* 7.石の自動反転 */
	/* 8.パス有無の入力 */
	/* 9.パス有無のエラーメッセージ表示 */
	/* 10.反転後の盤面表示 */
	win_player = game_progress(level);

	/* 11.勝利メッセージの表示 */
	//黒の勝利
	if (win_player == WIN_BLACK_STONE)
	{
		printf("WINNER!!! %s", BLACK_STONE_STR);
	}
	//白の勝利
	else if (win_player == WIN_WHITE_STONE)
	{
		printf("WINNER!!! %s", WHITE_STONE_STR);
	}
	//引き分け
	else
	{
		printf("DROW!!!");
	}

	/*
	for (int i = 0; i < 8; i++)
	{
		for (int v = 0; v < 8; v++)
		{
			printf("%d", board[i][v]);
		}
		printf("\n");
	}
	*/
	return 0;
}
