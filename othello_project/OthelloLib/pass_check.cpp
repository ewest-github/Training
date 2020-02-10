#include<stdio.h>
#include<stdlib.h>

#include "OthelloLib.h"
#include "function.h"

//アクティブターン
extern int turn;

//メッセージ表示フラグ
extern int message_flag;

//パスフラグ
extern int pass_flag;

int pass_check(int* board)
{
	//石配置可能マス数
	int stone_set_count = 0;

	//コマ配置可能座標
	POINT COORDINATE;

	//ループ終了条件:縦の全てのマスをチェックするまで
	for (int height = 0; height < HEIGHT; height++)
	{
		//ループ終了条件:横の全てのマスをチェックするまで
		for (int width = 0; width < WIDTH; width++)
		{
			//該当マスがコマ未配置のとき
			if (*(board + (height * HEIGHT) + width) == NONE_PLAY)
			{
				//構造体に座標を代入
				COORDINATE.y = height;
				COORDINATE.x = width;

				//石配置可能なとき
				if (0 < stone_rolling(board, COORDINATE, MODE_STONE_SET_CHECK))
				{
					stone_set_count++;
				}
				else
				{
					;
				}
			}
			//該当マスがコマ配置済みの場合
			else
			{
				;
			}
		}
	}

	return stone_set_count;
}

void position_check(int* board, POINT* stone_position)
{
	//石配置可能フラグ
	int stone_set_count = 0;

	//座標格納アドレス
	int position_save = 0;

	//コマ配置可能座標
	POINT COORDINATE;

	//ループ終了条件:縦の全てのマスをチェックするまで
	for (int height = 0; height < HEIGHT; height++)
	{
		//ループ終了条件:横の全てのマスをチェックするまで
		for (int width = 0; width < WIDTH; width++)
		{
			//該当マスがコマ未配置のとき
			if (*(board + (height * HEIGHT) + width) == NONE_PLAY)
			{
				//構造体に座標を代入
				COORDINATE.y = height;
				COORDINATE.x = width;

				stone_set_count = stone_rolling(board, COORDINATE, MODE_STONE_SET_CHECK);

				//石配置可能な座標のとき
				if (0 < stone_set_count)
				{
					//座標の保存
					(stone_position + position_save)->y = height;
					(stone_position + position_save)->x = width;

					//アドレスのカウントアップ
					position_save++;
				}
				else
				{
					;
				}
			}
			//該当マスがコマ配置済みの場合
			else
			{
				;
			}
		}
	}
}

int number_input()
{
	char ss[10];
	int num = 0;

	gets_s(ss);
	num = atoi(ss);

	return num;
}

int stone_set(int* board, int active_turn, int not_active_turn)
{
	//ターンを返す
	int ac_turn = 0;
	
	//パス有無入力値
	int num = 0;

	//石の配置位置入力値
	int width = 0;
	int height = 0;

	//座標の構造体
	POINT COORDINATE;

	/* 5.石の配置位置の入力 */
	//石の配置位置の入力
	if (message_flag == NON_DISPLAY)
	{
		printf("石の位置を入力して下さい。\n");

		//同一ターンに2回以上表示しない
		message_flag = DISPLAY;
	}
	else
	{
		;
	}
	printf("横:");
	COORDINATE.x = number_input();
	printf("縦:");
	COORDINATE.y = number_input();

	//入力値の有効判定
	//盤面の範囲外のとき
	if(COORDINATE.x < BOARD_LINE_INDEX_1 || BOARD_LINE_INDEX_8 < COORDINATE.x || COORDINATE.y < BOARD_LINE_INDEX_1 || BOARD_LINE_INDEX_8 < COORDINATE.y)
	{
		/* 6.石のエラーメッセージ表示 */
		printf("盤面の範囲外です、違う場所を指定してください。\n");
		
		//ターンを渡さない
		ac_turn = active_turn;
	}
	else
	{
		//石が配置済みのとき
		if (*(board + (COORDINATE.y * HEIGHT) + COORDINATE.x) != NONE_PLAY)
		{
			/* 6.石のエラーメッセージ表示 */
			printf("既に石を配置済みなので、違う場所を指定してください。\n");

			//ターンを渡さない
			ac_turn = active_turn;
		}
		else
		{
			//石が配置可能なとき
			if (STONE_SET_DISABLE < stone_rolling(board, COORDINATE, MODE_STONE_SET_CHECK))
			{
				//石の配置動作
				*(board + (COORDINATE.y * HEIGHT) + COORDINATE.x) = active_turn;

				/* 7.石の自動反転 */
				//反転動作
				stone_rolling(board, COORDINATE, MODE_STONE_INVERSION);
			
				//ターンを渡す
				ac_turn = not_active_turn;
				
				/* 10.反転後の盤面表示 */
				//盤面を表示する
				printBoard(board, 64);

				//メッセージ表示フラグの解除
				message_flag = NON_DISPLAY;

				//パスフラグの解除
				pass_flag = 0;
			}
			//石が配置できないとき
			else
			{
				//パス有無の入力待機(ループ終了条件:0か1が入力されるまで)
				do {
					/* 8.パス有無の入力 */
					printf("挟む石がありません。パス(0:しない、1:する)しますか？\n");
					num = number_input();

					//パスする場合
					if (num == PASS)
					{
						//石を配置できる場所があるとき
						if (0 < pass_check(board))
						{
							printf("配置可能な石があるためパスできません。\n");

							//ターンを渡さない
							ac_turn = active_turn;
						}
						//ないとき
						else
						{
							//ターンを渡す
							ac_turn = not_active_turn;

							//パスフラグを立てる
							pass_flag++;

							//メッセージ表示フラグの解除
							message_flag = NON_DISPLAY;
						}
					}
					//パスしない場合
					else if (num == NOT_PASS)
					{
						//ターンを渡さない
						ac_turn = active_turn;
					}
					//入力値が0か1以外だったとき
					else
					{
						/* 9.パス有無のエラーメッセージ表示 */
						printf("0か1を入力して下さい。\n");

						//ターンを渡さない
						ac_turn = active_turn;
					}
				} while (num != NOT_PASS && num != PASS);
			}
		}
	}
	

	//どちらかのターンを返す
	return ac_turn;
}