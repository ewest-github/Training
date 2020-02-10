#pragma once
#ifndef _FUNCTION_H_

//ゲーム開始時のメッセージを表示する関数
void game_start();

//ゲームを進行する関数
int game_progress(int* board);

//パスの有無をチェックする関数(引数:盤面の情報)
int pass_check(int* board);

//石配置可能な座標を取得する関数
void position_check(int* board, POINT* stone_position);

//石の反転可否を判定する関数(引数:盤面の情報、縦の座標、横の座標、機能させる動作)
int stone_rolling(int* board, POINT COORDINATE, int mode);

//石を配置する関数
int stone_set(int* board, int active_turn, int not_active_turn);

//値を入力する関数
int number_input();

/** @def
 * メッセージ表示前
 */
#define NON_DISPLAY 0

 /** @def
  * メッセージ表示後
  */
#define DISPLAY 1

  /** @def
   * 石配置可能
   */
#define STONE_SET_ENABLE 1

   /** @def
    * 石配置不可能
    */
#define STONE_SET_DISABLE 0

    /** @def
     * 石配置可否モード
     */
#define MODE_STONE_SET_CHECK 0

     /** @def
      * 石反転モード
      */
#define MODE_STONE_INVERSION 1


#endif // !_FUNCTION_H_