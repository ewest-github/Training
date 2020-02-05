#include<stdio.h>

#include "OthelloLib.h"
#include "function.h"

void game_progress(int* b)
{
	//パスフラグ
	int ps = 0;

	//パス有無入力値
	int num = 0;

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
			ps = pass_check(b);
			
			//パス動作
			if (ps == 1)
			{
				printf("挟む石がありません。パス(0:しない、1:する)しますか？\n");
				num = number_input();

				//パスする場合
				if (num == 1)
				{
					turn = WHITE_STONE;
				}
				//パスしない場合
				else if(num == 0)
				{
					//石の配置
					turn = stone_set(b, BLACK_STONE, WHITE_STONE);
				}
				//入力値が0か1以外だったとき
				else
				{
					printf("0か1を入力して下さい。\n");
				}

			}
			//パスのない場合
			else
			{
				//石の配置
				turn = stone_set(b, BLACK_STONE, WHITE_STONE);
			}
		}
		//白石のターンのとき
		else
		{
			//黒石にターンを渡す
			turn = BLACK_STONE;
		}
	}
}