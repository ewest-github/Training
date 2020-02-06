#include<stdio.h>

#include "OthelloLib.h"
#include "function.h"

void game_progress(int* b)
{
	//パスフラグ
	int ps = 0;

	//パス有無入力値
	//int num = 0;

	//ターン管理用変数(黒が先手)
	turn = BLACK_STONE;

	//終了フラグ
	int game_end = 60;
	
	//盤面上の黒石数
	int black_stone = 2;
	
	//盤面上の白石数
	int white_stone = 2;

	//ループ終了条件:盤面上に石を配置していない場所がある、黒か白の石が0になる
	while (game_end != 0 && black_stone == 0 && white_stone == 0)
	{
		//盤面の石カウント初期化
		game_end = 0;
		black_stone = 0;
		white_stone = 0;
		
		//黒石のターンのとき
		if (turn == BLACK_STONE)
		{
			//現在のプレイヤー表示
			printf("現在のプレイヤー:%s", BLACK_STONE_STR);
			
			//パスの有無判定
			//ps = pass_check(b);
			
			//パス動作
			//if (ps == 1)
			//{
				//printf("挟む石がありません。パス(0:しない、1:する)しますか？\n");
				//num = number_input();

				//パスする場合
				//if (num == 1)
				//{
				//	turn = WHITE_STONE;
				//}
				//パスしない場合
				//else if(num == 0)
				//{
					//石の配置
					turn = stone_set(b, BLACK_STONE, WHITE_STONE);
				//}
				//入力値が0か1以外だったとき
				//else
				//{
				//	printf("0か1を入力して下さい。\n");
				//}

			//}
			//パスのない場合
			//else
			//{
				//石の配置
			//	turn = stone_set(b, BLACK_STONE, WHITE_STONE);
			//}
		}
		//白石のターンのとき
		else
		{
			//現在のプレイヤー表示
			printf("現在のプレイヤー:%s", WHITE_STONE_STR);
			
			//黒石にターンを渡す
			turn = BLACK_STONE;
		}
		
		//盤面の未配置の数と石の数を管理
		//ループ終了条件:縦の全てのマスをチェックするまで
		for (int h = 0; h < HEIGHT; h++)
		{
			//ループ終了条件:横の全てのマスをチェックするまで
			for (int w = 0; w < WIDTH; w++)
			{
				//該当マスがコマ未配置のとき
				if (*(b + (h * HEIGHT) + w) == 0)
				{
					game_end++;
				}
				//該当マスが黒石配置済みの場合
				else if (*(b + (h * HEIGHT) + w) == BLACK_STONE)
				{
					black_stone++;
				}
				//該当マスが白石配置済みの場合
				else if (*(b + (h * HEIGHT) + w) == WHITE_STONE)
				{
					white_stone++;
				}
				else
				{
					;
				}
			}
		}
	}
}