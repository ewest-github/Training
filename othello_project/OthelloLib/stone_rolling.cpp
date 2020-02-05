#include<stdio.h>
#include<stdlib.h>

#include "OthelloLib.h"
#include "function.h"

//石の反転
int stone_rolling(int* b, int h, int w)
{
	//探索位置の座標
	int h1 = 0;
	int w1 = 0;

	//配置可能な石の数
	int s = 0;

	//探索方向のポインタ
	POINT* p;

	//メモリブロックの確保
	p = (POINT*)malloc(sizeof(POINT) * 8);

	//探索方向の設定
	setDirection(p, 8);

	//ループ終了条件:全方向探索を完了するまで
	for (int f = 0; f < DIRECTION_INDEX::NUM; f++)
	{
		//探索位置の初期化
		h1 = h;
		w1 = w;

		//1方向ずつ探索
		switch (f)
		{
		//左方向
		case 0:
			//マス左端のとき
			if (w == 0)
			{
				;
			}
			else
			{
				while (w1 != 0 && *(b + ((h1 + p[DIRECTION_INDEX::LEFT].y) * HEIGHT) + w1 + p[DIRECTION_INDEX::LEFT].x) != NONE_PLAY && *(b + ((h + p[DIRECTION_INDEX::LEFT].y) * HEIGHT) + w + p[DIRECTION_INDEX::LEFT].x) != turn)
				{
					/*
					//移動終了の判定(盤面端まで到達)
					if (w1 == 0)
					{
						break;
					}
					//移動終了の判定(石未配置のマスまで到達)
					else if (*(b + ((h1 + p[DIRECTION_INDEX::LEFT].y) * HEIGHT) + w1 + p[DIRECTION_INDEX::LEFT].x) == 0)
					{
						break;
					}
					//移動終了の判定(隣が同じ色のコマ)
					else if (*(b + (h * HEIGHT) + w) == *(b + ((h + p[DIRECTION_INDEX::LEFT].y) * HEIGHT) + w + p[DIRECTION_INDEX::LEFT].x))
					{
						break;
					}
					*/

					//座標の移動
					h1 = h1 + p[DIRECTION_INDEX::LEFT].y;
					w1 = w1 + p[DIRECTION_INDEX::LEFT].x;
					//*(b + ((h1 + p[DIRECTION_INDEX::LEFT].y) * HEIGHT) + w1 + p[DIRECTION_INDEX::LEFT].x);
				}
			}
			break;
		case 1:
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			break;
		case 6:
			break;
		case 7:
			break;
		default:
			break;
		}
	}

	return s;
}