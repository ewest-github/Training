#include<stdio.h>
#include<stdlib.h>
#include "OthelloLib.h"
#include "function.h"

//test

int main() {
	
	//オセロ盤面の石配置配列の定義
	int board[8][8] = {};

	/* 1.石の初期配置 */
	//【提供関数】盤面の石の配置を初期化する(全て未配置ではなくゲーム開始時点の状態)
	initializeBoard(*board, 64);

	/* 2.盤面の表示 */
	//【提供関数】オセロの盤面を描画する(レイアウトから全て描画される)
	printBoard(*board, 64);

	/* 3.ゲーム開始時の表示 */
	game_start();

	/* 4.現在のプレイヤーの表示 */
	//game_progress(*board);

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
