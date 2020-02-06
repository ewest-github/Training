#include<stdio.h>
#include<stdlib.h>

#include "OthelloLib.h"
#include "function.h"

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
				ps = stone_rolling(b, h, w, 0);
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
	//ターンの管理
	int ac_turn = 0;
	
	//パス有無入力値
	int num = 0;

	//石の配置位置入力値
	int width = 0;
	int height = 0;

	//石の配置位置の入力
	printf("石の位置を入力して下さい。\n");
	printf("横:");
	width = number_input();
	printf("縦:");
	height = number_input();

	//入力値の有効判定
	//盤面の範囲外のとき
	if((width < 0 || 8 < width) && (height < 0 || 8 < height))
	{
		printf("盤面の範囲外です、違う場所を指定してください。\n");
		
		//ターンを渡さない
		ac_turn = active_turn;
	}
	else
	{
		//石が配置済みのとき
		if (*(b + (height * HEIGHT) + width) != 0)
		{
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

				//反転動作
			
				//ターンを渡す
				ac_turn = not_active_turn;
				
				//盤面を表示する
				printBoard(*b, 64);
			}
			//石が配置できないとき
			else
			{
				printf("挟む石がありません。パス(0:しない、1:する)しますか？\n");
				num = number_input();
				
				//パスする場合
				if(num == 1)
				{
					//ターンを渡す
					ac_turn = not_active_turn;
					
					//盤面を表示する
					printBoard(*b, 64);
				}
				//パスしない場合
				else if(num == 0)
				{
					//ターンを渡さない
					ac_turn = active_turn;
				}
				//入力値が0か1以外だったとき
				else
				{
					printf("0か1を入力して下さい。\n");
					
					//ターンを渡さない
					ac_turn = active_turn;
				}
			}
		}
	}
	

	//どちらかのターンを返す
	return ac_turn;
}