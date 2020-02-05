#include<stdio.h>

#include "OthelloLib.h"
#include "function.h"

void pass_check(int* b, int x, int y)
{
	//ループ終了条件:全てのマスをチェックするまで
	while (x != 0)
	{
		//ループ終了条件:縦の全てのマスをチェックするまで
		for (int h = 0; h < HEIGHT; h++)
		{
			//ループ終了条件:横の全てのマスをチェックするまで
			for (int w = 0; w < WIDTH; w++)
			{
				//該当マスがコマ未配置のとき
				if (*(b + (h * HEIGHT) + w) == 0)
				{
					stone_rolling(b, x, y);
				}
				//該当マスがコマ配置済みの場合
				else
				{
					;
				}
			}
		}
	}
}