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

int pass_check(int* b)
{
	//パスフラグ
	int ps = 0;

	//ループ終了条件:縦の全てのマスをチェックするまで
	for (int h = 0; h < HEIGHT; h++)
	{
		//ループ終了条件:横の全てのマスをチェックするまで
		for (int w = 0; w < WIDTH; w++)
		{
			//該当マスがコマ未配置のとき
			if (*(b + (h * HEIGHT) + w) == 0)
			{
				ps = ps + stone_rolling(b, h, w, 0);
			}
			//該当マスがコマ配置済みの場合
			else
			{
				;
			}
		}
	}

	return ps;
}

int number_input()
{
	char ss[10];
	int num = 0;

	gets_s(ss);
	num = atoi(ss);

	return num;
}

int stone_set(int* b, int active_turn, int not_active_turn)
{
	//ターンを返す
	int ac_turn = 0;
	
	//パス有無入力値
	int num = 0;

	//石の配置位置入力値
	int width = 0;
	int height = 0;

	/* 5.石の配置位置の入力 */
	//石の配置位置の入力
	if (message_flag == 0)
	{
		printf("石の位置を入力して下さい。\n");

		//同一ターンに2回以上表示しない
		message_flag = 1;
	}
	else
	{
		;
	}
	printf("横:");
	width = number_input();
	printf("縦:");
	height = number_input();

	//入力値の有効判定
	//盤面の範囲外のとき
	if(width < 0 || 7 < width || height < 0 || 7 < height)
	{
		/* 6.石のエラーメッセージ表示 */
		printf("盤面の範囲外です、違う場所を指定してください。\n");
		
		//ターンを渡さない
		ac_turn = active_turn;
	}
	else
	{
		//石が配置済みのとき
		if (*(b + (height * HEIGHT) + width) != 0)
		{
			/* 6.石のエラーメッセージ表示 */
			printf("既に石を配置済みなので、違う場所を指定してください。\n");

			//ターンを渡さない
			ac_turn = active_turn;
		}
		else
		{
			//石が配置可能なとき
			if (stone_rolling(b, height, width, 0) == 1)
			{
				//石の配置動作
				*(b + (height * HEIGHT) + width) = active_turn;

				/* 7.石の自動反転 */
				//反転動作
				stone_rolling(b, height, width, 1);
			
				//ターンを渡す
				ac_turn = not_active_turn;
				
				/* 10.反転後の盤面表示 */
				//盤面を表示する
				printBoard(b, 64);

				//メッセージ表示フラグの解除
				message_flag = 0;
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
					if (num == 1)
					{
						//石を配置できる場所があるとき
						if (0 < pass_check(b))
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

							//盤面を表示する
							//printBoard(b, 64);

							//パスフラグを立てる
							pass_flag++;

							//メッセージ表示フラグの解除
							message_flag = 0;
						}
					}
					//パスしない場合
					else if (num == 0)
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
				} while (num != 0 && num != 1);
			}
		}
	}
	

	//どちらかのターンを返す
	return ac_turn;
}