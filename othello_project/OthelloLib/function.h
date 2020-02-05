#pragma once
#ifndef _FUNCTION_H_

//ゲーム開始時のメッセージを表示する関数
void game_start();

//ゲームを進行する関数
void game_progress(int* b);

//パスの有無をチェックする関数(引数:盤面の情報)
int pass_check(int* b);

//石の反転可否を判定する関数(引数:盤面の情報、縦の座標、横の座標)
int stone_rolling(int* b, int h, int w, int m);

//石を配置する関数
int stone_set(int* b, int active_turn, int not_active_turn);

//値を入力する関数
int number_input();


//ターンを管理する変数
int turn;


#endif // !_FUNCTION_H_