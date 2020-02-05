#pragma once
#ifndef _FUNCTION_H_

//ゲーム開始時のメッセージを表示する関数
void game_start();

//ゲームを進行する関数
void game_progress(int* b);

//パスの有無をチェックする関数
void pass_check(int* b, int x, int y);

//石の反転可否を判定する関数
void stone_rolling(int* b, int x, int y);

#endif // !_FUNCTION_H_