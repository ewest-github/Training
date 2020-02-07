#include<stdio.h>
#include<stdlib.h>

#include "OthelloLib.h"
#include "function.h"

//�A�N�e�B�u�^�[��
extern int turn;

//�������ɔ��]�ۂ𔻒肷��֐�
int stone_direction(int* board, POINT COORDINATE, int direction, int mode);

//�΂̔��]
int stone_rolling(int* board, POINT COORDINATE, int mode)
{
	//�΂̐ݒu�\�t���O
	int stone_set_flag = 0;

	//���[�v�I������:�S�����T������������܂�
	for (int direction_check = 0; direction_check < DIRECTION_INDEX::NUM; direction_check++)
	{
		//1�������T��
		switch (direction_check)
		{
		//������
		case DIRECTION_INDEX::LEFT:
			//�}�X���[�̂Ƃ�
			if (COORDINATE.x == BOARD_LINE_INDEX_1)
			{
				;
			}
			else
			{
				//�΂̔��]����
				stone_set_flag = stone_set_flag + stone_direction(board, COORDINATE, DIRECTION_INDEX::LEFT, mode);
			}
			break;
		//��������
		case DIRECTION_INDEX::LEFT_BOTTOM:
			//�}�X�����[�̂Ƃ�
			if (COORDINATE.x == BOARD_LINE_INDEX_1)
			{
				;
			}
			//�}�X���ŉ��i�̂Ƃ�
			else if (COORDINATE.y == BOARD_LINE_INDEX_8)
			{
				;
			}
			else
			{
				//�΂̔��]����
				stone_set_flag = stone_set_flag + stone_direction(board, COORDINATE, DIRECTION_INDEX::LEFT_BOTTOM, mode);
			}
			break;
		//������
		case DIRECTION_INDEX::BOTTOM:
			//�}�X���ŉ��i�̂Ƃ�
			if (COORDINATE.y == BOARD_LINE_INDEX_8)
			{
				;
			}
			else
			{
				//�΂̔��]����
				stone_set_flag = stone_set_flag + stone_direction(board, COORDINATE, DIRECTION_INDEX::BOTTOM, mode);
			}
			break;
		//�E������
		case DIRECTION_INDEX::RIGHT_BOTTOM:
			//�}�X���E�[�̂Ƃ�
			if (COORDINATE.x == BOARD_LINE_INDEX_8)
			{
				;
			}
			//�}�X���ŉ��i�̂Ƃ�
			else if (COORDINATE.y == BOARD_LINE_INDEX_8)
			{
				;
			}
			else
			{
				//�΂̔��]����
				stone_set_flag = stone_set_flag + stone_direction(board, COORDINATE, DIRECTION_INDEX::RIGHT_BOTTOM, mode);
			}
			break;
		//�E����
		case DIRECTION_INDEX::RIGHT:
			//�}�X�E�[�̂Ƃ�
			if (COORDINATE.x == BOARD_LINE_INDEX_8)
			{
				;
			}
			else
			{
				//�΂̔��]����
				stone_set_flag = stone_set_flag + stone_direction(board, COORDINATE, DIRECTION_INDEX::RIGHT, mode);
			}
			break;
		//�E�����
		case DIRECTION_INDEX::RIGHT_TOP:
			//�}�X���E�[�̂Ƃ�
			if (COORDINATE.x == BOARD_LINE_INDEX_8)
			{
				;
			}
			//�}�X���ŏ�i�̂Ƃ�
			else if (COORDINATE.y == BOARD_LINE_INDEX_1)
			{
				;
			}
			else
			{
				//�΂̔��]����
				stone_set_flag = stone_set_flag + stone_direction(board, COORDINATE, DIRECTION_INDEX::RIGHT_TOP, mode);
			}
			break;
		//�����
		case DIRECTION_INDEX::TOP:
			//�}�X���ŏ�i�̂Ƃ�
			if (COORDINATE.y == BOARD_LINE_INDEX_1)
			{
				;
			}
			else
			{
				//�΂̔��]����
				stone_set_flag = stone_set_flag + stone_direction(board, COORDINATE, DIRECTION_INDEX::TOP, mode);
			}
			break;
		//�������
		case DIRECTION_INDEX::LEFT_TOP:
			//�}�X�����[�̂Ƃ�
			if (COORDINATE.x == BOARD_LINE_INDEX_1)
			{
				;
			}
			//�}�X���ŏ�i�̂Ƃ�
			else if (COORDINATE.y == BOARD_LINE_INDEX_1)
			{
				;
			}
			else
			{
				//�΂̔��]����
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
	//�T���ʒu�̍��W
	int height_move = COORDINATE.y;
	int width_move = COORDINATE.x;

	//�΂̐ݒu�\�t���O
	int stone_set_flag = 0;

	//�T�������̃|�C���^
	POINT* direction_point;

	//�������u���b�N�̊m��
	direction_point = (POINT*)malloc(sizeof(POINT) * DIRECTION_INDEX::NUM);

	//�T�������̐ݒ�
	setDirection(direction_point, DIRECTION_INDEX::NUM);

	//���[�v�I������:break����܂�
	while (1)
	{
		if (direction == DIRECTION_INDEX::LEFT)
		{
			//�����[�̂Ƃ�
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
			//�����[�̂Ƃ�
			if (width_move == BOARD_LINE_INDEX_1)
			{
				break;
			}
			else
			{
				;
			}
			//�c���[�̂Ƃ�
			if (height_move == BOARD_LINE_INDEX_8)
			{
				break;
			}
		}
		else if (direction == DIRECTION_INDEX::BOTTOM)
		{
			//�c���[�̂Ƃ�
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
			//�����[�̂Ƃ�
			if (width_move == BOARD_LINE_INDEX_8)
			{
				break;
			}
			else
			{
				;
			}
			//�c���[�̂Ƃ�
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
			//�����[�̂Ƃ�
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
			//�����[�̂Ƃ�
			if (width_move == BOARD_LINE_INDEX_8)
			{
				break;
			}
			else
			{
				;
			}
			//�c���[�̂Ƃ�
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
			//�c���[�̂Ƃ�
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
			//�����[�̂Ƃ�
			if (width_move == BOARD_LINE_INDEX_1)
			{
				break;
			}
			else
			{
				;
			}
			//�c���[�̂Ƃ�
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

		//�T�������̃}�X�����z�u�̂Ƃ�
		if (*(board + ((height_move + direction_point[direction].y) * HEIGHT) + width_move + direction_point[direction].x) == NONE_PLAY)
		{
			break;
		}
		else
		{
			;
		}
		//�T�������ׂ̗̃}�X�Ɠ����F�̐΂̂Ƃ�
		if (*(board + ((COORDINATE.y + direction_point[direction].y) * HEIGHT) + COORDINATE.x + direction_point[direction].x) == turn)
		{
			break;
		}
		else
		{
			;
		}

		//���W�̈ړ�
		height_move = height_move + direction_point[direction].y;
		width_move = width_move + direction_point[direction].x;

		if (direction == DIRECTION_INDEX::LEFT)
		{
			//�[�łȂ��Ƃ�
			if (width_move != BOARD_LINE_INDEX_1)
			{
				//�����F�̐΂����������Ƃ�
				if (*(board + ((height_move + direction_point[direction].y) * HEIGHT) + width_move + direction_point[direction].x) == turn)
				{
					//�����Ŗ߂�l�𕪂��ċ@�\�؂�ւ�����
					//�΂̔z�u�\�t���O��߂��Ƃ�
					if (mode == MODE_STONE_SET_CHECK)
					{
						//�Δz�u�\�t���O�𗧂Ă�
						stone_set_flag = STONE_SET_ENABLE;
					}
					//���]������s��
					else if (mode == MODE_STONE_INVERSION)
					{
						//�z�u�ʒu�܂Ő΂𔽓]�����Ƃ�
						while (COORDINATE.y != height_move || COORDINATE.x != width_move)
						{
							//�v���C���[�^�[���̐΂ɕύX����
							*(board + (height_move * HEIGHT) + width_move) = turn;

							//���W�̈ړ�(�z�u�ʒu�Ɍ�����)
							height_move = height_move - direction_point[direction].y;
							width_move = width_move - direction_point[direction].x;
						}
					}
					else
					{
						;
					}

					//���[�v�𔲂���
					break;
				}
				else
				{
					;
				}
			}
			//�[�̂Ƃ�
			else
			{
				;
			}
		}
		else if (direction == DIRECTION_INDEX::LEFT_BOTTOM)
		{
			//�[�łȂ��Ƃ�
			if (width_move != BOARD_LINE_INDEX_1 && height_move != BOARD_LINE_INDEX_8)
			{
				//�����F�̐΂����������Ƃ�
				if (*(board + ((height_move + direction_point[direction].y) * HEIGHT) + width_move + direction_point[direction].x) == turn)
				{
					//�����Ŗ߂�l�𕪂��ċ@�\�؂�ւ�����
					//�΂̔z�u�\�t���O��߂��Ƃ�
					if (mode == MODE_STONE_SET_CHECK)
					{
						//�Δz�u�\�t���O�𗧂Ă�
						stone_set_flag = STONE_SET_ENABLE;
					}
					//���]������s��
					else if (mode == MODE_STONE_INVERSION)
					{
						//�z�u�ʒu�܂Ő΂𔽓]�����Ƃ�
						while (COORDINATE.y != height_move || COORDINATE.x != width_move)
						{
							//�v���C���[�^�[���̐΂ɕύX����
							*(board + (height_move * HEIGHT) + width_move) = turn;

							//���W�̈ړ�(�z�u�ʒu�Ɍ�����)
							height_move = height_move - direction_point[direction].y;
							width_move = width_move - direction_point[direction].x;
						}
					}
					else
					{
						;
					}

					//���[�v�𔲂���
					break;
				}
				else
				{
					;
				}
			}
			//�[�̂Ƃ�
			else
			{
				;
			}
		}
		else if (direction == DIRECTION_INDEX::BOTTOM)
		{
			//�[�łȂ��Ƃ�
			if (height_move != BOARD_LINE_INDEX_8)
			{
				//�����F�̐΂����������Ƃ�
				if (*(board + ((height_move + direction_point[direction].y) * HEIGHT) + width_move + direction_point[direction].x) == turn)
				{
					//�����Ŗ߂�l�𕪂��ċ@�\�؂�ւ�����
					//�΂̔z�u�\�t���O��߂��Ƃ�
					if (mode == MODE_STONE_SET_CHECK)
					{
						//�Δz�u�\�t���O�𗧂Ă�
						stone_set_flag = STONE_SET_ENABLE;
					}
					//���]������s��
					else if (mode == MODE_STONE_INVERSION)
					{
						//�z�u�ʒu�܂Ő΂𔽓]�����Ƃ�
						while (COORDINATE.y != height_move || COORDINATE.x != width_move)
						{
							//�v���C���[�^�[���̐΂ɕύX����
							*(board + (height_move * HEIGHT) + width_move) = turn;

							//���W�̈ړ�(�z�u�ʒu�Ɍ�����)
							height_move = height_move - direction_point[direction].y;
							width_move = width_move - direction_point[direction].x;
						}
					}
					else
					{
						;
					}

					//���[�v�𔲂���
					break;
				}
				else
				{
					;
				}
			}
			//�[�̂Ƃ�
			else
			{
				;
			}
		}
		else if (direction == DIRECTION_INDEX::RIGHT_BOTTOM)
		{
			//�[�łȂ��Ƃ�
			if (width_move != BOARD_LINE_INDEX_8 && height_move != BOARD_LINE_INDEX_8)
			{
				//�����F�̐΂����������Ƃ�
				if (*(board + ((height_move + direction_point[direction].y) * HEIGHT) + width_move + direction_point[direction].x) == turn)
				{
					//�����Ŗ߂�l�𕪂��ċ@�\�؂�ւ�����
					//�΂̔z�u�\�t���O��߂��Ƃ�
					if (mode == MODE_STONE_SET_CHECK)
					{
						//�Δz�u�\�t���O�𗧂Ă�
						stone_set_flag = STONE_SET_ENABLE;
					}
					//���]������s��
					else if (mode == MODE_STONE_INVERSION)
					{
						//�z�u�ʒu�܂Ő΂𔽓]�����Ƃ�
						while (COORDINATE.y != height_move || COORDINATE.x != width_move)
						{
							//�v���C���[�^�[���̐΂ɕύX����
							*(board + (height_move * HEIGHT) + width_move) = turn;

							//���W�̈ړ�(�z�u�ʒu�Ɍ�����)
							height_move = height_move - direction_point[direction].y;
							width_move = width_move - direction_point[direction].x;
						}
					}
					else
					{
						;
					}

					//���[�v�𔲂���
					break;
				}
				else
				{
					;
				}
			}
			//�[�̂Ƃ�
			else
			{
				;
			}
		}
		else if (direction == DIRECTION_INDEX::RIGHT)
		{
			//�[�łȂ��Ƃ�
			if (width_move != BOARD_LINE_INDEX_8)
			{
				//�����F�̐΂����������Ƃ�
				if (*(board + ((height_move + direction_point[direction].y) * HEIGHT) + width_move + direction_point[direction].x) == turn)
				{
					//�����Ŗ߂�l�𕪂��ċ@�\�؂�ւ�����
					//�΂̔z�u�\�t���O��߂��Ƃ�
					if (mode == MODE_STONE_SET_CHECK)
					{
						//�Δz�u�\�t���O�𗧂Ă�
						stone_set_flag = STONE_SET_ENABLE;
					}
					//���]������s��
					else if (mode == MODE_STONE_INVERSION)
					{
						//�z�u�ʒu�܂Ő΂𔽓]�����Ƃ�
						while (COORDINATE.y != height_move || COORDINATE.x != width_move)
						{
							//�v���C���[�^�[���̐΂ɕύX����
							*(board + (height_move * HEIGHT) + width_move) = turn;

							//���W�̈ړ�(�z�u�ʒu�Ɍ�����)
							height_move = height_move - direction_point[direction].y;
							width_move = width_move - direction_point[direction].x;
						}
					}
					else
					{
						;
					}

					//���[�v�𔲂���
					break;
				}
				else
				{
					;
				}
			}
			//�[�̂Ƃ�
			else
			{
				;
			}
		}
		else if (direction == DIRECTION_INDEX::RIGHT_TOP)
		{
			//�[�łȂ��Ƃ�
			if (width_move != BOARD_LINE_INDEX_8 && height_move != BOARD_LINE_INDEX_1)
			{
				//�����F�̐΂����������Ƃ�
				if (*(board + ((height_move + direction_point[direction].y) * HEIGHT) + width_move + direction_point[direction].x) == turn)
				{
					//�����Ŗ߂�l�𕪂��ċ@�\�؂�ւ�����
					//�΂̔z�u�\�t���O��߂��Ƃ�
					if (mode == MODE_STONE_SET_CHECK)
					{
						//�Δz�u�\�t���O�𗧂Ă�
						stone_set_flag = STONE_SET_ENABLE;
					}
					//���]������s��
					else if (mode == MODE_STONE_INVERSION)
					{
						//�z�u�ʒu�܂Ő΂𔽓]�����Ƃ�
						while (COORDINATE.y != height_move || COORDINATE.x != width_move)
						{
							//�v���C���[�^�[���̐΂ɕύX����
							*(board + (height_move * HEIGHT) + width_move) = turn;

							//���W�̈ړ�(�z�u�ʒu�Ɍ�����)
							height_move = height_move - direction_point[direction].y;
							width_move = width_move - direction_point[direction].x;
						}
					}
					else
					{
						;
					}

					//���[�v�𔲂���
					break;
				}
				else
				{
					;
				}
			}
			//�[�̂Ƃ�
			else
			{
				;
			}
		}
		else if (direction == DIRECTION_INDEX::TOP)
		{
			//�[�łȂ��Ƃ�
			if (height_move != BOARD_LINE_INDEX_1)
			{
				//�����F�̐΂����������Ƃ�
				if (*(board + ((height_move + direction_point[direction].y) * HEIGHT) + width_move + direction_point[direction].x) == turn)
				{
					//�����Ŗ߂�l�𕪂��ċ@�\�؂�ւ�����
					//�΂̔z�u�\�t���O��߂��Ƃ�
					if (mode == MODE_STONE_SET_CHECK)
					{
						//�Δz�u�\�t���O�𗧂Ă�
						stone_set_flag = STONE_SET_ENABLE;
					}
					//���]������s��
					else if (mode == MODE_STONE_INVERSION)
					{
						//�z�u�ʒu�܂Ő΂𔽓]�����Ƃ�
						while (COORDINATE.y != height_move || COORDINATE.x != width_move)
						{
							//�v���C���[�^�[���̐΂ɕύX����
							*(board + (height_move * HEIGHT) + width_move) = turn;

							//���W�̈ړ�(�z�u�ʒu�Ɍ�����)
							height_move = height_move - direction_point[direction].y;
							width_move = width_move - direction_point[direction].x;
						}
					}
					else
					{
						;
					}

					//���[�v�𔲂���
					break;
				}
				else
				{
					;
				}
			}
			//�[�̂Ƃ�
			else
			{
				;
			}
		}
		else if (direction == DIRECTION_INDEX::LEFT_TOP)
		{
			//�[�łȂ��Ƃ�
			if (width_move != BOARD_LINE_INDEX_1 && height_move != BOARD_LINE_INDEX_1)
			{
				//�����F�̐΂����������Ƃ�
				if (*(board + ((height_move + direction_point[direction].y) * HEIGHT) + width_move + direction_point[direction].x) == turn)
				{
					//�����Ŗ߂�l�𕪂��ċ@�\�؂�ւ�����
					//�΂̔z�u�\�t���O��߂��Ƃ�
					if (mode == MODE_STONE_SET_CHECK)
					{
						//�Δz�u�\�t���O�𗧂Ă�
						stone_set_flag = STONE_SET_ENABLE;
					}
					//���]������s��
					else if (mode == MODE_STONE_INVERSION)
					{
						//�z�u�ʒu�܂Ő΂𔽓]�����Ƃ�
						while (COORDINATE.y != height_move || COORDINATE.x != width_move)
						{
							//�v���C���[�^�[���̐΂ɕύX����
							*(board + (height_move * HEIGHT) + width_move) = turn;

							//���W�̈ړ�(�z�u�ʒu�Ɍ�����)
							height_move = height_move - direction_point[direction].y;
							width_move = width_move - direction_point[direction].x;
						}
					}
					else
					{
						;
					}

					//���[�v�𔲂���
					break;
				}
				else
				{
					;
				}
			}
			//�[�̂Ƃ�
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

	//�������u���b�N�̉��
	free(direction_point);

	return stone_set_flag;
}