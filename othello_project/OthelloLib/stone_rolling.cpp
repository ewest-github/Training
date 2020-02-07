#include<stdio.h>
#include<stdlib.h>

#include "OthelloLib.h"
#include "function.h"

//アクティブターン
extern int turn;

//方向毎に反転可否を判定する関数
int stone_direction(int* board, POINT COORDINATE, int direction, int mode);

//石の反転
int stone_rolling(int* board, POINT COORDINATE, int mode)
{
	//石の設置可能フラグ
	int stone_set_flag = 0;

	//ループ終了条件:全方向探索を完了するまで
	for (int direction_check = 0; direction_check < DIRECTION_INDEX::NUM; direction_check++)
	{
		//1方向ずつ探索
		switch (direction_check)
		{
		//左方向
		case DIRECTION_INDEX::LEFT:
			//マス左端のとき
			if (COORDINATE.x == BOARD_LINE_INDEX_1)
			{
				;
			}
			else
			{
				//石の反転動作
				stone_set_flag = stone_set_flag + stone_direction(board, COORDINATE, DIRECTION_INDEX::LEFT, mode);
			}
			break;
		//左下方向
		case DIRECTION_INDEX::LEFT_BOTTOM:
			//マスが左端のとき
			if (COORDINATE.x == BOARD_LINE_INDEX_1)
			{
				;
			}
			//マスが最下段のとき
			else if (COORDINATE.y == BOARD_LINE_INDEX_8)
			{
				;
			}
			else
			{
				//石の反転動作
				stone_set_flag = stone_set_flag + stone_direction(board, COORDINATE, DIRECTION_INDEX::LEFT_BOTTOM, mode);
			}
			break;
		//下方向
		case DIRECTION_INDEX::BOTTOM:
			//マスが最下段のとき
			if (COORDINATE.y == BOARD_LINE_INDEX_8)
			{
				;
			}
			else
			{
				//石の反転動作
				stone_set_flag = stone_set_flag + stone_direction(board, COORDINATE, DIRECTION_INDEX::BOTTOM, mode);
			}
			break;
		//右下方向
		case DIRECTION_INDEX::RIGHT_BOTTOM:
			//マスが右端のとき
			if (COORDINATE.x == BOARD_LINE_INDEX_8)
			{
				;
			}
			//マスが最下段のとき
			else if (COORDINATE.y == BOARD_LINE_INDEX_8)
			{
				;
			}
			else
			{
				//石の反転動作
				stone_set_flag = stone_set_flag + stone_direction(board, COORDINATE, DIRECTION_INDEX::RIGHT_BOTTOM, mode);
			}
			break;
		//右方向
		case DIRECTION_INDEX::RIGHT:
			//マス右端のとき
			if (COORDINATE.x == BOARD_LINE_INDEX_8)
			{
				;
			}
			else
			{
				//石の反転動作
				stone_set_flag = stone_set_flag + stone_direction(board, COORDINATE, DIRECTION_INDEX::RIGHT, mode);
			}
			break;
		//右上方向
		case DIRECTION_INDEX::RIGHT_TOP:
			//マスが右端のとき
			if (COORDINATE.x == BOARD_LINE_INDEX_8)
			{
				;
			}
			//マスが最上段のとき
			else if (COORDINATE.y == BOARD_LINE_INDEX_1)
			{
				;
			}
			else
			{
				//石の反転動作
				stone_set_flag = stone_set_flag + stone_direction(board, COORDINATE, DIRECTION_INDEX::RIGHT_TOP, mode);
			}
			break;
		//上方向
		case DIRECTION_INDEX::TOP:
			//マスが最上段のとき
			if (COORDINATE.y == BOARD_LINE_INDEX_1)
			{
				;
			}
			else
			{
				//石の反転動作
				stone_set_flag = stone_set_flag + stone_direction(board, COORDINATE, DIRECTION_INDEX::TOP, mode);
			}
			break;
		//左上方向
		case DIRECTION_INDEX::LEFT_TOP:
			//マスが左端のとき
			if (COORDINATE.x == BOARD_LINE_INDEX_1)
			{
				;
			}
			//マスが最上段のとき
			else if (COORDINATE.y == BOARD_LINE_INDEX_1)
			{
				;
			}
			else
			{
				//石の反転動作
				stone_set_flag = stone_set_flag + stone_direction(board, COORDINATE, DIRECTION_INDEX::LEFT_TOP, mode);
			}
			break;
		default:
			break;
		}
	}

	return stone_set_flag;
}

int stone_direction(int* board, POINT COORDINATE, int direction, int mode)
{
	//探索位置の座標
	int height_move = COORDINATE.y;
	int width_move = COORDINATE.x;

	//石の設置可能フラグ
	int stone_set_flag = 0;

	//探索方向のポインタ
	POINT* direction_point;

	//メモリブロックの確保
	direction_point = (POINT*)malloc(sizeof(POINT) * DIRECTION_INDEX::NUM);

	//探索方向の設定
	setDirection(direction_point, DIRECTION_INDEX::NUM);

	//ループ終了条件:breakするまで
	while (1)
	{
		if (direction == DIRECTION_INDEX::LEFT)
		{
			//横が端のとき
			if (width_move == BOARD_LINE_INDEX_1)
			{
				break;
			}
			else
			{
				;
			}
		}
		else if (direction == DIRECTION_INDEX::LEFT_BOTTOM)
		{
			//横が端のとき
			if (width_move == BOARD_LINE_INDEX_1)
			{
				break;
			}
			else
			{
				;
			}
			//縦が端のとき
			if (height_move == BOARD_LINE_INDEX_8)
			{
				break;
			}
		}
		else if (direction == DIRECTION_INDEX::BOTTOM)
		{
			//縦が端のとき
			if (height_move == BOARD_LINE_INDEX_8)
			{
				break;
			}
			else
			{
				;
			}
		}
		else if (direction == DIRECTION_INDEX::RIGHT_BOTTOM)
		{
			//横が端のとき
			if (width_move == BOARD_LINE_INDEX_8)
			{
				break;
			}
			else
			{
				;
			}
			//縦が端のとき
			if (height_move == BOARD_LINE_INDEX_8)
			{
				break;
			}
			else
			{
				;
			}
		}
		else if(direction == DIRECTION_INDEX::RIGHT)
		{
			//横が端のとき
			if (width_move == BOARD_LINE_INDEX_8)
			{
				break;
			}
			else
			{
				;
			}
		}
		else if(direction == DIRECTION_INDEX::RIGHT_TOP)
		{
			//横が端のとき
			if (width_move == BOARD_LINE_INDEX_8)
			{
				break;
			}
			else
			{
				;
			}
			//縦が端のとき
			if (height_move == BOARD_LINE_INDEX_1)
			{
				break;
			}
			else
			{
				;
			}
		}
		else if (direction == DIRECTION_INDEX::TOP)
		{
			//縦が端のとき
			if (height_move == BOARD_LINE_INDEX_1)
			{
				break;
			}
			else
			{
				;
			}
		}
		else if (direction == DIRECTION_INDEX::LEFT_TOP)
		{
			//横が端のとき
			if (width_move == BOARD_LINE_INDEX_1)
			{
				break;
			}
			else
			{
				;
			}
			//縦が端のとき
			if (height_move == BOARD_LINE_INDEX_1)
			{
				break;
			}
			else
			{
				;
			}
		}
		else
		{
			;
		}

		//探索方向のマスが未配置のとき
		if (*(board + ((height_move + direction_point[direction].y) * HEIGHT) + width_move + direction_point[direction].x) == NONE_PLAY)
		{
			break;
		}
		else
		{
			;
		}
		//探索方向の隣のマスと同じ色の石のとき
		if (*(board + ((COORDINATE.y + direction_point[direction].y) * HEIGHT) + COORDINATE.x + direction_point[direction].x) == turn)
		{
			break;
		}
		else
		{
			;
		}

		//座標の移動
		height_move = height_move + direction_point[direction].y;
		width_move = width_move + direction_point[direction].x;

		if (direction == DIRECTION_INDEX::LEFT)
		{
			//端でないとき
			if (width_move != BOARD_LINE_INDEX_1)
			{
				//同じ色の石が見つかったとき
				if (*(board + ((height_move + direction_point[direction].y) * HEIGHT) + width_move + direction_point[direction].x) == turn)
				{
					//引数で戻り値を分けて機能切り替えする
					//石の配置可能フラグを戻すとき
					if (mode == MODE_STONE_SET_CHECK)
					{
						//石配置可能フラグを立てる
						stone_set_flag = STONE_SET_ENABLE;
					}
					//反転動作を行う
					else if (mode == MODE_STONE_INVERSION)
					{
						//配置位置まで石を反転したとき
						while (COORDINATE.y != height_move || COORDINATE.x != width_move)
						{
							//プレイヤーターンの石に変更する
							*(board + (height_move * HEIGHT) + width_move) = turn;

							//座標の移動(配置位置に向かう)
							height_move = height_move - direction_point[direction].y;
							width_move = width_move - direction_point[direction].x;
						}
					}
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
			//端のとき
			else
			{
				;
			}
		}
		else if (direction == DIRECTION_INDEX::LEFT_BOTTOM)
		{
			//端でないとき
			if (width_move != BOARD_LINE_INDEX_1 && height_move != BOARD_LINE_INDEX_8)
			{
				//同じ色の石が見つかったとき
				if (*(board + ((height_move + direction_point[direction].y) * HEIGHT) + width_move + direction_point[direction].x) == turn)
				{
					//引数で戻り値を分けて機能切り替えする
					//石の配置可能フラグを戻すとき
					if (mode == MODE_STONE_SET_CHECK)
					{
						//石配置可能フラグを立てる
						stone_set_flag = STONE_SET_ENABLE;
					}
					//反転動作を行う
					else if (mode == MODE_STONE_INVERSION)
					{
						//配置位置まで石を反転したとき
						while (COORDINATE.y != height_move || COORDINATE.x != width_move)
						{
							//プレイヤーターンの石に変更する
							*(board + (height_move * HEIGHT) + width_move) = turn;

							//座標の移動(配置位置に向かう)
							height_move = height_move - direction_point[direction].y;
							width_move = width_move - direction_point[direction].x;
						}
					}
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
			//端のとき
			else
			{
				;
			}
		}
		else if (direction == DIRECTION_INDEX::BOTTOM)
		{
			//端でないとき
			if (height_move != BOARD_LINE_INDEX_8)
			{
				//同じ色の石が見つかったとき
				if (*(board + ((height_move + direction_point[direction].y) * HEIGHT) + width_move + direction_point[direction].x) == turn)
				{
					//引数で戻り値を分けて機能切り替えする
					//石の配置可能フラグを戻すとき
					if (mode == MODE_STONE_SET_CHECK)
					{
						//石配置可能フラグを立てる
						stone_set_flag = STONE_SET_ENABLE;
					}
					//反転動作を行う
					else if (mode == MODE_STONE_INVERSION)
					{
						//配置位置まで石を反転したとき
						while (COORDINATE.y != height_move || COORDINATE.x != width_move)
						{
							//プレイヤーターンの石に変更する
							*(board + (height_move * HEIGHT) + width_move) = turn;

							//座標の移動(配置位置に向かう)
							height_move = height_move - direction_point[direction].y;
							width_move = width_move - direction_point[direction].x;
						}
					}
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
			//端のとき
			else
			{
				;
			}
		}
		else if (direction == DIRECTION_INDEX::RIGHT_BOTTOM)
		{
			//端でないとき
			if (width_move != BOARD_LINE_INDEX_8 && height_move != BOARD_LINE_INDEX_8)
			{
				//同じ色の石が見つかったとき
				if (*(board + ((height_move + direction_point[direction].y) * HEIGHT) + width_move + direction_point[direction].x) == turn)
				{
					//引数で戻り値を分けて機能切り替えする
					//石の配置可能フラグを戻すとき
					if (mode == MODE_STONE_SET_CHECK)
					{
						//石配置可能フラグを立てる
						stone_set_flag = STONE_SET_ENABLE;
					}
					//反転動作を行う
					else if (mode == MODE_STONE_INVERSION)
					{
						//配置位置まで石を反転したとき
						while (COORDINATE.y != height_move || COORDINATE.x != width_move)
						{
							//プレイヤーターンの石に変更する
							*(board + (height_move * HEIGHT) + width_move) = turn;

							//座標の移動(配置位置に向かう)
							height_move = height_move - direction_point[direction].y;
							width_move = width_move - direction_point[direction].x;
						}
					}
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
			//端のとき
			else
			{
				;
			}
		}
		else if (direction == DIRECTION_INDEX::RIGHT)
		{
			//端でないとき
			if (width_move != BOARD_LINE_INDEX_8)
			{
				//同じ色の石が見つかったとき
				if (*(board + ((height_move + direction_point[direction].y) * HEIGHT) + width_move + direction_point[direction].x) == turn)
				{
					//引数で戻り値を分けて機能切り替えする
					//石の配置可能フラグを戻すとき
					if (mode == MODE_STONE_SET_CHECK)
					{
						//石配置可能フラグを立てる
						stone_set_flag = STONE_SET_ENABLE;
					}
					//反転動作を行う
					else if (mode == MODE_STONE_INVERSION)
					{
						//配置位置まで石を反転したとき
						while (COORDINATE.y != height_move || COORDINATE.x != width_move)
						{
							//プレイヤーターンの石に変更する
							*(board + (height_move * HEIGHT) + width_move) = turn;

							//座標の移動(配置位置に向かう)
							height_move = height_move - direction_point[direction].y;
							width_move = width_move - direction_point[direction].x;
						}
					}
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
			//端のとき
			else
			{
				;
			}
		}
		else if (direction == DIRECTION_INDEX::RIGHT_TOP)
		{
			//端でないとき
			if (width_move != BOARD_LINE_INDEX_8 && height_move != BOARD_LINE_INDEX_1)
			{
				//同じ色の石が見つかったとき
				if (*(board + ((height_move + direction_point[direction].y) * HEIGHT) + width_move + direction_point[direction].x) == turn)
				{
					//引数で戻り値を分けて機能切り替えする
					//石の配置可能フラグを戻すとき
					if (mode == MODE_STONE_SET_CHECK)
					{
						//石配置可能フラグを立てる
						stone_set_flag = STONE_SET_ENABLE;
					}
					//反転動作を行う
					else if (mode == MODE_STONE_INVERSION)
					{
						//配置位置まで石を反転したとき
						while (COORDINATE.y != height_move || COORDINATE.x != width_move)
						{
							//プレイヤーターンの石に変更する
							*(board + (height_move * HEIGHT) + width_move) = turn;

							//座標の移動(配置位置に向かう)
							height_move = height_move - direction_point[direction].y;
							width_move = width_move - direction_point[direction].x;
						}
					}
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
			//端のとき
			else
			{
				;
			}
		}
		else if (direction == DIRECTION_INDEX::TOP)
		{
			//端でないとき
			if (height_move != BOARD_LINE_INDEX_1)
			{
				//同じ色の石が見つかったとき
				if (*(board + ((height_move + direction_point[direction].y) * HEIGHT) + width_move + direction_point[direction].x) == turn)
				{
					//引数で戻り値を分けて機能切り替えする
					//石の配置可能フラグを戻すとき
					if (mode == MODE_STONE_SET_CHECK)
					{
						//石配置可能フラグを立てる
						stone_set_flag = STONE_SET_ENABLE;
					}
					//反転動作を行う
					else if (mode == MODE_STONE_INVERSION)
					{
						//配置位置まで石を反転したとき
						while (COORDINATE.y != height_move || COORDINATE.x != width_move)
						{
							//プレイヤーターンの石に変更する
							*(board + (height_move * HEIGHT) + width_move) = turn;

							//座標の移動(配置位置に向かう)
							height_move = height_move - direction_point[direction].y;
							width_move = width_move - direction_point[direction].x;
						}
					}
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
			//端のとき
			else
			{
				;
			}
		}
		else if (direction == DIRECTION_INDEX::LEFT_TOP)
		{
			//端でないとき
			if (width_move != BOARD_LINE_INDEX_1 && height_move != BOARD_LINE_INDEX_1)
			{
				//同じ色の石が見つかったとき
				if (*(board + ((height_move + direction_point[direction].y) * HEIGHT) + width_move + direction_point[direction].x) == turn)
				{
					//引数で戻り値を分けて機能切り替えする
					//石の配置可能フラグを戻すとき
					if (mode == MODE_STONE_SET_CHECK)
					{
						//石配置可能フラグを立てる
						stone_set_flag = STONE_SET_ENABLE;
					}
					//反転動作を行う
					else if (mode == MODE_STONE_INVERSION)
					{
						//配置位置まで石を反転したとき
						while (COORDINATE.y != height_move || COORDINATE.x != width_move)
						{
							//プレイヤーターンの石に変更する
							*(board + (height_move * HEIGHT) + width_move) = turn;

							//座標の移動(配置位置に向かう)
							height_move = height_move - direction_point[direction].y;
							width_move = width_move - direction_point[direction].x;
						}
					}
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
			//端のとき
			else
			{
				;
			}
		}
		else
		{
			;
		}
	}

	//メモリブロックの解放
	free(direction_point);

	return stone_set_flag;
}