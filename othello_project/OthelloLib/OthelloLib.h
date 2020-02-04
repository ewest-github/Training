#pragma once

#include <stdio.h>

/** @def
 * �Ֆʂ̉��T�C�Y
 */
#define WIDTH           8

 /** @def
  * �Ֆʂ̏c�T�C�Y
  */
#define HEIGHT          8

/** @def
 * �Ֆʏ�̖��z�u�̒l
 */
#define NONE_PLAY       0

/** @def
 * �Ֆʏ�̔��΂̒l
 */
#define WHITE_STONE     1

/** @def
 * �Ֆʏ�̍��΂̒l
 */
#define BLACK_STONE     2

/** @def
 * ���΂̕\��������
 */
#define WHITE_STONE_STR "��"

/** @def
 * ���΂̕\��������
 */
#define BLACK_STONE_STR "�Z"

/** @def
 * ������
 */
#define NONE_FINISH 0

/** @def
 * ���΃v���C���[�̏���
 */
#define WIN_WHITE_STONE 1

/** @def
 * ���΃v���C���[�̏���
 */
#define WIN_BLACK_STONE 2

/** @def
 * �p�X���Ȃ�
 */
#define NOT_PASS 0

/** @def
 * �p�X����
 */
#define PASS 1

/** @def
 * �Ղ̏����ʒu�P x���W
 */
#define INIT_BOARD_FIRST_X 3

/** @def
 * �Ղ̏����ʒu�P y���W
 */
#define INIT_BOARD_FIRST_Y 3

/** @def
 * �Ղ̏����ʒu�P ��
 */
#define INIT_BOARD_FIRST_STONE WHITE_STONE

/** @def
 * �Ղ̏����ʒu�Q x���W
 */
#define INIT_BOARD_SECOND_X 3

/** @def
 * �Ղ̏����ʒu�Q y���W
 */
#define INIT_BOARD_SECOND_Y 4

/** @def
 * �Ղ̏����ʒu�Q ��
 */
#define INIT_BOARD_SECOND_STONE BLACK_STONE

/** @def
 * �Ղ̏����ʒu�R x���W
 */
#define INIT_BOARD_THIRD_X 4

/** @def
 * �Ղ̏����ʒu�R y���W
 */
#define INIT_BOARD_THIRD_Y 3

/** @def
 * �Ղ̏����ʒu�R ��
 */
#define INIT_BOARD_THIRD_STONE BLACK_STONE

/** @def
 * �Ղ̏����ʒu�S x���W
 */
#define INIT_BOARD_FOURTH_X 4

/** @def
 * �Ղ̏����ʒu�S y���W
 */
#define INIT_BOARD_FOURTH_Y 4

/** @def
 * �Ղ̏����ʒu�S ��
 */
#define INIT_BOARD_FOURTH_STONE WHITE_STONE

/** @def
 * �Ղ̍s�E��C���f�b�N�X�P
 */
#define BOARD_LINE_INDEX_1 0

/** @def
 * �Ղ̍s�E��C���f�b�N�X�Q
 */
#define BOARD_LINE_INDEX_2 1

/** @def
 * �Ղ̍s�E��C���f�b�N�X�R
 */
#define BOARD_LINE_INDEX_3 2

/** @def
 * �Ղ̍s�E��C���f�b�N�X�S
 */
#define BOARD_LINE_INDEX_4 3

/** @def
 * �Ղ̍s�E��C���f�b�N�X�T
 */
#define BOARD_LINE_INDEX_5 4

/** @def
 * �Ղ̍s�E��C���f�b�N�X�U
 */
#define BOARD_LINE_INDEX_6 5

/** @def
 * �Ղ̍s�E��C���f�b�N�X�V
 */
#define BOARD_LINE_INDEX_7 6

/** @def
 * �Ղ̍s�E��C���f�b�N�X�W
 */
#define BOARD_LINE_INDEX_8 7

/** @def
 * �Ղ̍s�E�񕶎���P
 */
#define BOARD_LINE_STR_1 "�O"

/** @def
 * �Ղ̍s�E�񕶎���Q
 */
#define BOARD_LINE_STR_2 "�P"

/** @def
 * �Ղ̍s�E�񕶎���R
 */
#define BOARD_LINE_STR_3 "�Q"

/** @def
 * �Ղ̍s�E�񕶎���S
 */
#define BOARD_LINE_STR_4 "�R"

/** @def
 * �Ղ̍s�E�񕶎���T
 */
#define BOARD_LINE_STR_5 "�S"

/** @def
 * �Ղ̍s�E�񕶎���U
 */
#define BOARD_LINE_STR_6 "�T"

/** @def
 * �Ղ̍s�E�񕶎���V
 */
#define BOARD_LINE_STR_7 "�U"

/** @def
 * �Ղ̍s�E�񕶎���W
 */
#define BOARD_LINE_STR_8 "�V"

/** @enum DIRECTION_INDEX
 * �����z��̃C���f�b�N�Xnum��`
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

	// �C���f�b�N�X���v
	NUM
};

/** @struct POINT
 * ���W�\����
 */
struct POINT
{
	int x;
	int y;
};

/**
 * @fn printBoard(int*)
 * �Ֆʂ��R���\�[����ɏo�͂���B
 * @param board �Ֆʂ̔z��|�C���^
 * @param size  �z��̃T�C�Y
 */
void printBoard(int* board, size_t size);

/**
 * @fn initializeBoard(int*)
 * �Ֆʂ̏����z�u���s���B
 * @param board �Ֆʂ̔z��|�C���^(�o��)
 * @param size  �z��̃T�C�Y
 */
void initializeBoard(int* board, size_t size);

/**
 * @fn setDirection(POINT*)
 * �����̏d�ݔz��̐ݒ���s���B
 * @param directions �����̏d�ݔz��̃|�C���^(�o��)
 * @param size       �z��̃T�C�Y
 */
void setDirection(POINT* direction, size_t size);
