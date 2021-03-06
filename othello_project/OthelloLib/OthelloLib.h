#pragma once

#include <stdio.h>

/** @def
 * ÕÊÌ¡TCY
 */
#define WIDTH           8

 /** @def
  * ÕÊÌcTCY
  */
#define HEIGHT          8

/** @def
 * ÕÊãÌ¢zuÌl
 */
#define NONE_PLAY       0

/** @def
 * ÕÊãÌÎÌl
 */
#define WHITE_STONE     1

/** @def
 * ÕÊãÌÎÌl
 */
#define BLACK_STONE     2

/** @def
 * ÎÌ\¦¶ñ
 */
#define WHITE_STONE_STR ""

/** @def
 * ÎÌ\¦¶ñ
 */
#define BLACK_STONE_STR "Z"

/** @def
 * ¢
 */
#define NONE_FINISH 0

/** @def
 * ÎvC[Ì
 */
#define WIN_WHITE_STONE 1

/** @def
 * ÎvC[Ì
 */
#define WIN_BLACK_STONE 2

/** @def
 * pXµÈ¢
 */
#define NOT_PASS 0

/** @def
 * pX·é
 */
#define PASS 1

/** @def
 * ÕÌúÊuP xÀW
 */
#define INIT_BOARD_FIRST_X 3

/** @def
 * ÕÌúÊuP yÀW
 */
#define INIT_BOARD_FIRST_Y 3

/** @def
 * ÕÌúÊuP Î
 */
#define INIT_BOARD_FIRST_STONE WHITE_STONE

/** @def
 * ÕÌúÊuQ xÀW
 */
#define INIT_BOARD_SECOND_X 3

/** @def
 * ÕÌúÊuQ yÀW
 */
#define INIT_BOARD_SECOND_Y 4

/** @def
 * ÕÌúÊuQ Î
 */
#define INIT_BOARD_SECOND_STONE BLACK_STONE

/** @def
 * ÕÌúÊuR xÀW
 */
#define INIT_BOARD_THIRD_X 4

/** @def
 * ÕÌúÊuR yÀW
 */
#define INIT_BOARD_THIRD_Y 3

/** @def
 * ÕÌúÊuR Î
 */
#define INIT_BOARD_THIRD_STONE BLACK_STONE

/** @def
 * ÕÌúÊuS xÀW
 */
#define INIT_BOARD_FOURTH_X 4

/** @def
 * ÕÌúÊuS yÀW
 */
#define INIT_BOARD_FOURTH_Y 4

/** @def
 * ÕÌúÊuS Î
 */
#define INIT_BOARD_FOURTH_STONE WHITE_STONE

/** @def
 * ÕÌsEñCfbNXP
 */
#define BOARD_LINE_INDEX_1 0

/** @def
 * ÕÌsEñCfbNXQ
 */
#define BOARD_LINE_INDEX_2 1

/** @def
 * ÕÌsEñCfbNXR
 */
#define BOARD_LINE_INDEX_3 2

/** @def
 * ÕÌsEñCfbNXS
 */
#define BOARD_LINE_INDEX_4 3

/** @def
 * ÕÌsEñCfbNXT
 */
#define BOARD_LINE_INDEX_5 4

/** @def
 * ÕÌsEñCfbNXU
 */
#define BOARD_LINE_INDEX_6 5

/** @def
 * ÕÌsEñCfbNXV
 */
#define BOARD_LINE_INDEX_7 6

/** @def
 * ÕÌsEñCfbNXW
 */
#define BOARD_LINE_INDEX_8 7

/** @def
 * ÕÌsEñ¶ñP
 */
#define BOARD_LINE_STR_1 "O"

/** @def
 * ÕÌsEñ¶ñQ
 */
#define BOARD_LINE_STR_2 "P"

/** @def
 * ÕÌsEñ¶ñR
 */
#define BOARD_LINE_STR_3 "Q"

/** @def
 * ÕÌsEñ¶ñS
 */
#define BOARD_LINE_STR_4 "R"

/** @def
 * ÕÌsEñ¶ñT
 */
#define BOARD_LINE_STR_5 "S"

/** @def
 * ÕÌsEñ¶ñU
 */
#define BOARD_LINE_STR_6 "T"

/** @def
 * ÕÌsEñ¶ñV
 */
#define BOARD_LINE_STR_7 "U"

/** @def
 * ÕÌsEñ¶ñW
 */
#define BOARD_LINE_STR_8 "V"

/** @enum DIRECTION_INDEX
 * ûüzñÌCfbNXnumè`
 */
enum DIRECTION_INDEX {
	LEFT = 0,
	LEFT_BOTTOM,
	BOTTOM,
	RIGHT_BOTTOM,
	RIGHT,
	RIGHT_TOP,
	TOP,
	LEFT_TOP,

	// CfbNXv
	NUM
};

/** @struct POINT
 * ÀW\¢Ì
 */
struct POINT
{
	int x;
	int y;
};

/**
 * @fn printBoard(int*)
 * ÕÊðR\[ãÉoÍ·éB
 * @param board ÕÊÌzñ|C^
 * @param size  zñÌTCY
 */
void printBoard(int* board, size_t size);

/**
 * @fn initializeBoard(int*)
 * ÕÊÌúzuðs¤B
 * @param board ÕÊÌzñ|C^(oÍ)
 * @param size  zñÌTCY
 */
void initializeBoard(int* board, size_t size);

/**
 * @fn setDirection(POINT*)
 * ûüÌdÝzñÌÝèðs¤B
 * @param directions ûüÌdÝzñÌ|C^(oÍ)
 * @param size       zñÌTCY
 */
void setDirection(POINT* direction, size_t size);
