#include<stdio.h>
#include<stdlib.h>

#include "OthelloLib.h"
#include "function.h"

//ターンを管理
int turn;

//メッセージ表示フラグ
int message_flag;

//パスフラグ
int pass_flag;

//石の反転個数カウント
int reverse_count;

//座標毎の反転個数
int reverse_stone[20];

int game_progress(int* board, int level)
{
	//パスフラグ
	//int ps = 0;

	//勝者
	int winner = 0;

	//メッセージフラグ
	message_flag = 0;

	//ターンを管理
	//int turn = 0;

	//パス有無入力値
	//int num = 0;

	//石配置可能な座標数
	int set_count = 0;

	//石配置可能な座標
	POINT* stone_position;

	//石を配置する座標
	int set_stone = 0;

	//反転個数
	reverse_count = 0;

	//ターン管理用変数(黒が先手)
	turn = BLACK_STONE;

	//終了フラグ
	int game_end = 60;
	
	//盤面上の黒石数
	int black_stone = 2;
	
	//盤面上の白石数
	int white_stone = 2;

	//ループ終了条件:盤面上に石を配置していない場所がある、黒か白の石が0になる、両プレイヤーがパスする
	while (game_end != 0 && black_stone != NONE_PLAY && white_stone != NONE_PLAY && pass_flag != 2)
	{
		//盤面の石カウント初期化
		game_end = 0;
		black_stone = 0;
		white_stone = 0;
		
		//黒石のターンのとき
		if (turn == BLACK_STONE)
		{
			/* 4.現在のプレイヤーの表示 */
			//現在のプレイヤー表示
			//同一ターンで1回だけ表示
			if (message_flag == NON_DISPLAY)
			{
				printf("現在のプレイヤー:%s\n", BLACK_STONE_STR);
			}
			else
			{
				;
			}
			
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
			turn = stone_set(board, BLACK_STONE, WHITE_STONE);
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
			//配置可能な座標数
			set_count = pass_check(board);

			//ターン開始表示
			printf("現在のプレイヤー:%s\n", WHITE_STONE_STR);

			//パス動作
			if (set_count == 0)
			{
				printf("挟む石がありません。パスします\n");
			}
			else
			{
				//メモリブロック確保
				stone_position = (POINT*)malloc(sizeof(POINT) * set_count);

				//配置可能な座標を取得
				position_check(board, stone_position);

				//レベルに応じたアドレスを取得
				set_stone = CPU_level(stone_position, set_count, level);

				//石の配置
				*(board + ((stone_position + set_stone)->y * HEIGHT) + (stone_position + set_stone)->x) = WHITE_STONE;

				//石の反転
				stone_rolling(board, *(stone_position + set_stone), MODE_STONE_INVERSION);

				/* 10.反転後の盤面表示 */
				//盤面を表示する
				printBoard(board, 64);

				//反転座標と個数の初期化
				reverse_count = 0;

				for (int i = 0; i < set_count; i++)
				{
					reverse_stone[i] = 0;
				}

				//メモリブロックの解放
				free(stone_position);
			}

			//ターンを渡す
			turn = BLACK_STONE;
			
			/* 4.現在のプレイヤーの表示 */
			//現在のプレイヤー表示
			//同一ターンで1回だけ表示
			/*
			if (message_flag == NON_DISPLAY)
			{
				printf("現在のプレイヤー:%s\n", WHITE_STONE_STR);
			}
			else
			{
				;
			}

			//石の配置
			turn = stone_set(board, WHITE_STONE, BLACK_STONE);
			*/
		}
		
		//盤面の未配置の数と石の数を管理
		//ループ終了条件:縦の全てのマスをチェックするまで
		for (int h = 0; h < HEIGHT; h++)
		{
			//ループ終了条件:横の全てのマスをチェックするまで
			for (int w = 0; w < WIDTH; w++)
			{
				//該当マスがコマ未配置のとき
				if (*(board + (h * HEIGHT) + w) == NONE_PLAY)
				{
					game_end++;
				}
				//該当マスが黒石配置済みの場合
				else if (*(board + (h * HEIGHT) + w) == BLACK_STONE)
				{
					black_stone++;
				}
				//該当マスが白石配置済みの場合
				else if (*(board + (h * HEIGHT) + w) == WHITE_STONE)
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

	//勝敗の判定
	//黒が勝利のとき
	if (white_stone < black_stone)
	{
		winner = BLACK_STONE;
	}
	//白が勝利のとき
	else if (black_stone < white_stone)
	{
		winner = WHITE_STONE;
	}
	//引き分けのとき
	else
	{
		winner = NONE_FINISH;
	}

	//勝敗を返す
	return winner;
}

int CPU_level(POINT* stone_position, int set_count, int level)
{
	//石を配置する座標
	int set_stone = 0;

	//反転数が同数になる座標の数
	int tie = 1;

	switch (level)
	{
	case 1:
		//石を配置する座標の決定
		set_stone = rand() % set_count;
		break;
	case 2:
		//要素数-1回繰り返し
		for (int bubble = 0; bubble < set_count - 1; bubble++)
		{
			//反転個数で昇順ソート
			for (int max_reverse = 0; max_reverse + 1 < set_count - bubble; max_reverse++)
			{
				//ソート用一時保管変数
				int sort = 0;
				POINT SORT;

				//石の反転個数の多いほうが配列上位になるようにソート
				if (reverse_stone[max_reverse] < reverse_stone[max_reverse + 1])
				{
					;
				}
				else
				{
					//ソート処理
					sort = reverse_stone[max_reverse + 1];
					SORT.y = stone_position[max_reverse + 1].y;
					SORT.x = stone_position[max_reverse + 1].x;

					reverse_stone[max_reverse + 1] = reverse_stone[max_reverse];
					stone_position[max_reverse + 1].y = stone_position[max_reverse].y;
					stone_position[max_reverse + 1].x = stone_position[max_reverse].x;

					reverse_stone[max_reverse] = sort;
					stone_position[max_reverse].y = SORT.y;
					stone_position[max_reverse].x = SORT.x;
				}
			}
		}

		//石の反転個数の多い座標を保持
		set_stone = set_count - 1;

		//反転個数の最大値に対して同数が複数あるときの処理
		for (int max_num = 0; max_num < set_count - 1; max_num++)
		{
			//反転個数の最大値と反転個数が同じとき
			if (reverse_stone[set_count - 1] == reverse_stone[max_num])
			{
				//最大反転個数の座標の数をカウントアップ
				tie++;
			}
			else
			{
				;
			}
		}

		//同数の座標からランダムで1つ選択する
		set_stone = (set_count - tie) + (rand() % tie);
		break;
	case 3:
		break;
	case 4:
		break;
	case 5:
		break;
	default:
		break;
	}

	return set_stone;
}