#include<stdio.h>

#include "OthelloLib.h"
#include "function.h"

void game_progress(int* b)
{
	//ターン管理用変数(黒が先手)
	turn = BLACK_STONE;

	//終了フラグ
	int game_end = 60;

	//ループ終了条件:終了フラグが立っていないとき
	while (game_end != 0)
	{
		//黒石のターンのとき
		if (turn == BLACK_STONE)
		{
			//パスの有無判定
			pass_check(b, BLACK_STONE, WHITE_STONE);

			//白石にターンを渡す
			turn = WHITE_STONE;
		}
		//白石のターンのとき
		else
		{
			//黒石にターンを渡す
			turn = BLACK_STONE;
		}
	}
}