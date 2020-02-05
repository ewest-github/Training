#include<stdio.h>
#include<stdlib.h>

#include "OthelloLib.h"
#include "function.h"

//石の反転
int stone_rolling(int* b, int h, int w, int m)
{
	//探索位置の座標
	int h1 = 0;
	int w1 = 0;

	//石の設置可能フラグ
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
		case DIRECTION_INDEX::LEFT:
			//マス左端のとき
			if (w == BOARD_LINE_INDEX_1)
			{
				;
			}
			else
			{
				//ループ終了条件:横が端ではなく、探索方向のマスが未配置ではなく、探索方向のマスが同じ色の石にならない
				while (w1 != BOARD_LINE_INDEX_1 &&
					*(b + ((h1 + p[DIRECTION_INDEX::LEFT].y) * HEIGHT) + w1 + p[DIRECTION_INDEX::LEFT].x) != NONE_PLAY && 
					*(b + ((h + p[DIRECTION_INDEX::LEFT].y) * HEIGHT) + w + p[DIRECTION_INDEX::LEFT].x) != turn)
				{
					//座標の移動
					h1 = h1 + p[DIRECTION_INDEX::LEFT].y;
					w1 = w1 + p[DIRECTION_INDEX::LEFT].x;

					//同じ色の石が見つかったとき
					if (*(b + ((h1 + p[DIRECTION_INDEX::LEFT].y) * HEIGHT) + w1 + p[DIRECTION_INDEX::LEFT].x) == turn)
					{
						//石配置可能フラグを立てる
						s = 1;

						//ループを抜ける
						break;
					}
					else
					{
						;
					}
				}
			}
			break;
		//左下方向
		case DIRECTION_INDEX::LEFT_BOTTOM:
			//マスが左端のとき
			if (w == BOARD_LINE_INDEX_1)
			{
				;
			}
			//マスが最下段のとき
			else if (h == BOARD_LINE_INDEX_8)
			{
				;
			}
			else
			{
				//ループ終了条件:横が端ではなく、縦が端ではなく、探索方向のマスが未配置ではなく、探索方向のマスが同じ色の石にならない
				while (w1 != BOARD_LINE_INDEX_1 &&
					h1 != BOARD_LINE_INDEX_8 &&
					*(b + ((h1 + p[DIRECTION_INDEX::LEFT].y) * HEIGHT) + w1 + p[DIRECTION_INDEX::LEFT].x) != NONE_PLAY &&
					*(b + ((h + p[DIRECTION_INDEX::LEFT].y) * HEIGHT) + w + p[DIRECTION_INDEX::LEFT].x) != turn)
				{
					//座標の移動
					h1 = h1 + p[DIRECTION_INDEX::LEFT].y;
					w1 = w1 + p[DIRECTION_INDEX::LEFT].x;

					//同じ色の石が見つかったとき
					if (*(b + ((h1 + p[DIRECTION_INDEX::LEFT].y) * HEIGHT) + w1 + p[DIRECTION_INDEX::LEFT].x) == turn)
					{
						//引数で戻り値を分けて機能切り替えする
						//石の配置可能フラグを戻すとき
						if (m == 0)
						{
							//石配置可能フラグを立てる
							s = 1;
						}
						//
						else
						{
							;
						}

						//ループを抜ける
						break;
					}
					else
					{
						;
					}
				}
			}
			break;
		//下方向
		case DIRECTION_INDEX::BOTTOM:
			//マスが最下段のとき
			if (h == BOARD_LINE_INDEX_8)
			{
				;
			}
			else
			{
				//ループ終了条件:縦が端ではなく、探索方向のマスが未配置ではなく、探索方向のマスが同じ色の石にならない
				while (h1 != BOARD_LINE_INDEX_8 &&
					*(b + ((h1 + p[DIRECTION_INDEX::LEFT].y) * HEIGHT) + w1 + p[DIRECTION_INDEX::LEFT].x) != NONE_PLAY &&
					*(b + ((h + p[DIRECTION_INDEX::LEFT].y) * HEIGHT) + w + p[DIRECTION_INDEX::LEFT].x) != turn)
				{
					//座標の移動
					h1 = h1 + p[DIRECTION_INDEX::LEFT].y;
					w1 = w1 + p[DIRECTION_INDEX::LEFT].x;

					//同じ色の石が見つかったとき
					if (*(b + ((h1 + p[DIRECTION_INDEX::LEFT].y) * HEIGHT) + w1 + p[DIRECTION_INDEX::LEFT].x) == turn)
					{
						//石配置可能フラグを立てる
						s = 1;

						//ループを抜ける
						break;
					}
					else
					{
						;
					}
				}
			}
			break;
		//右下方向
		case DIRECTION_INDEX::RIGHT_BOTTOM:
			//マスが右端のとき
			if (w == BOARD_LINE_INDEX_8)
			{
				;
			}
			//マスが最下段のとき
			else if (h == BOARD_LINE_INDEX_8)
			{
				;
			}
			else
			{
				//ループ終了条件:横が端ではなく、縦が端ではなく、探索方向のマスが未配置ではなく、探索方向のマスが同じ色の石にならない
				while (w1 != BOARD_LINE_INDEX_8 &&
					h1 != BOARD_LINE_INDEX_8 &&
					*(b + ((h1 + p[DIRECTION_INDEX::LEFT].y) * HEIGHT) + w1 + p[DIRECTION_INDEX::LEFT].x) != NONE_PLAY &&
					*(b + ((h + p[DIRECTION_INDEX::LEFT].y) * HEIGHT) + w + p[DIRECTION_INDEX::LEFT].x) != turn)
				{
					//座標の移動
					h1 = h1 + p[DIRECTION_INDEX::LEFT].y;
					w1 = w1 + p[DIRECTION_INDEX::LEFT].x;

					//同じ色の石が見つかったとき
					if (*(b + ((h1 + p[DIRECTION_INDEX::LEFT].y) * HEIGHT) + w1 + p[DIRECTION_INDEX::LEFT].x) == turn)
					{
						//石配置可能フラグを立てる
						s = 1;

						//ループを抜ける
						break;
					}
					else
					{
						;
					}
				}
			}
			break;
		//右方向
		case DIRECTION_INDEX::RIGHT:
			//マス右端のとき
			if (w == BOARD_LINE_INDEX_8)
			{
				;
			}
			else
			{
				//ループ終了条件:横が端ではなく、探索方向のマスが未配置ではなく、探索方向のマスが同じ色の石にならない
				while (w1 != BOARD_LINE_INDEX_8 &&
					*(b + ((h1 + p[DIRECTION_INDEX::LEFT].y) * HEIGHT) + w1 + p[DIRECTION_INDEX::LEFT].x) != NONE_PLAY &&
					*(b + ((h + p[DIRECTION_INDEX::LEFT].y) * HEIGHT) + w + p[DIRECTION_INDEX::LEFT].x) != turn)
				{
					//座標の移動
					h1 = h1 + p[DIRECTION_INDEX::LEFT].y;
					w1 = w1 + p[DIRECTION_INDEX::LEFT].x;

					//同じ色の石が見つかったとき
					if (*(b + ((h1 + p[DIRECTION_INDEX::LEFT].y) * HEIGHT) + w1 + p[DIRECTION_INDEX::LEFT].x) == turn)
					{
						//石配置可能フラグを立てる
						s = 1;

						//ループを抜ける
						break;
					}
					else
					{
						;
					}
				}
			}
			break;
		//右上方向
		case DIRECTION_INDEX::RIGHT_TOP:
			//マスが右端のとき
			if (w == BOARD_LINE_INDEX_8)
			{
				;
			}
			//マスが最上段のとき
			else if (h == BOARD_LINE_INDEX_1)
			{
				;
			}
			else
			{
				//ループ終了条件:横が端ではなく、縦が端ではなく、探索方向のマスが未配置ではなく、探索方向のマスが同じ色の石にならない
				while (w1 != BOARD_LINE_INDEX_8 &&
					h1 != BOARD_LINE_INDEX_1 &&
					*(b + ((h1 + p[DIRECTION_INDEX::LEFT].y) * HEIGHT) + w1 + p[DIRECTION_INDEX::LEFT].x) != NONE_PLAY &&
					*(b + ((h + p[DIRECTION_INDEX::LEFT].y) * HEIGHT) + w + p[DIRECTION_INDEX::LEFT].x) != turn)
				{
					//座標の移動
					h1 = h1 + p[DIRECTION_INDEX::LEFT].y;
					w1 = w1 + p[DIRECTION_INDEX::LEFT].x;

					//同じ色の石が見つかったとき
					if (*(b + ((h1 + p[DIRECTION_INDEX::LEFT].y) * HEIGHT) + w1 + p[DIRECTION_INDEX::LEFT].x) == turn)
					{
						//石配置可能フラグを立てる
						s = 1;

						//ループを抜ける
						break;
					}
					else
					{
						;
					}
				}
			}
			break;
		//上方向
		case DIRECTION_INDEX::TOP:
			//マスが最上段のとき
			if (h == BOARD_LINE_INDEX_1)
			{
				;
			}
			else
			{
				//ループ終了条件:縦が端ではなく、探索方向のマスが未配置ではなく、探索方向のマスが同じ色の石にならない
				while (h1 != BOARD_LINE_INDEX_1 &&
					*(b + ((h1 + p[DIRECTION_INDEX::LEFT].y) * HEIGHT) + w1 + p[DIRECTION_INDEX::LEFT].x) != NONE_PLAY &&
					*(b + ((h + p[DIRECTION_INDEX::LEFT].y) * HEIGHT) + w + p[DIRECTION_INDEX::LEFT].x) != turn)
				{
					//座標の移動
					h1 = h1 + p[DIRECTION_INDEX::LEFT].y;
					w1 = w1 + p[DIRECTION_INDEX::LEFT].x;

					//同じ色の石が見つかったとき
					if (*(b + ((h1 + p[DIRECTION_INDEX::LEFT].y) * HEIGHT) + w1 + p[DIRECTION_INDEX::LEFT].x) == turn)
					{
						//石配置可能フラグを立てる
						s = 1;

						//ループを抜ける
						break;
					}
					else
					{
						;
					}
				}
			}
			break;
		//左上方向
		case DIRECTION_INDEX::LEFT_TOP:
			//マスが左端のとき
			if (w == BOARD_LINE_INDEX_1)
			{
				;
			}
			//マスが最上段のとき
			else if (h == BOARD_LINE_INDEX_1)
			{
				;
			}
			else
			{
				//ループ終了条件:横が端ではなく、縦が端ではなく、探索方向のマスが未配置ではなく、探索方向のマスが同じ色の石にならない
				while (w1 != BOARD_LINE_INDEX_1 &&
					h1 != BOARD_LINE_INDEX_1 &&
					*(b + ((h1 + p[DIRECTION_INDEX::LEFT].y) * HEIGHT) + w1 + p[DIRECTION_INDEX::LEFT].x) != NONE_PLAY &&
					*(b + ((h + p[DIRECTION_INDEX::LEFT].y) * HEIGHT) + w + p[DIRECTION_INDEX::LEFT].x) != turn)
				{
					//座標の移動
					h1 = h1 + p[DIRECTION_INDEX::LEFT].y;
					w1 = w1 + p[DIRECTION_INDEX::LEFT].x;

					//同じ色の石が見つかったとき
					if (*(b + ((h1 + p[DIRECTION_INDEX::LEFT].y) * HEIGHT) + w1 + p[DIRECTION_INDEX::LEFT].x) == turn)
					{
						//石配置可能フラグを立てる
						s = 1;

						//ループを抜ける
						break;
					}
					else
					{
						;
					}
				}
			}
			break;
		default:
			break;
		}
	}

	return s;
}