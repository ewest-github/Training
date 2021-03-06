#pragma once
#ifndef _FUNCTION_H_

//ゲーム開始時のメッセージを表示する関数
void game_start();

//ゲームを進行する関数
int game_progress(int level);

//パスの有無をチェックする関数(引数:盤面の情報)
int pass_check(int* board);

//石配置可能な座標を取得する関数
void position_check(int* board, POINT* stone_position);

//石の反転可否を判定する関数(引数:盤面の情報、縦の座標、横の座標、機能させる動作)
int stone_rolling(int* board, POINT COORDINATE, int mode);

//石を配置する関数
int stone_set(int active_turn, int not_active_turn);

//レベル設定で配置形式を変更する関数
int CPU_level(POINT* stone_position, int set_count, int level);

//石を多く反転できるアドレスを取得する関数
int MAX_Inversion(POINT* stone_position, int set_count);

//4辺に配置できるフラグを取得する関数
void SIDE_stone_flag(POINT* stone_position, int set_count, int* side_address);

//4辺を優先して取得する関数
int SIDE_stone_put(POINT* stone_position, int set_count);

//4隅を優先して取得する関数
int CORNER_stone_put(POINT* stone_position, int set_count);

//相手の1手先を計算して取得する関数
int onehand_stone_put(POINT * stone_position, int set_count);

//値を入力する関数
int number_input();

//CPUレベル
enum mode_select_level
{
    level2,
    level3,
    level4,
    level5,
};

//選択したレベルの関数を動作させる関数ポインタ
int (*levelselect[])(POINT* stone_position, int set_count);

//選択したレベルの値を変換する関数
int level_conversion(mode_select_level lv, POINT* stone_position, int set_count);

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