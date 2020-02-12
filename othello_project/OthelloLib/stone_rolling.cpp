#include<stdio.h>
#include<stdlib.h>

#include "OthelloLib.h"
#include "function.h"

//�A�N�e�B�u�^�[��
extern int turn;

//�΂̔��]��
extern int reverse_count;

//�΂̔��]���v��
extern int reverse_total;

//�������ɔ��]�ۂ̔���Ɛ΂𔽓]����֐�
int stone_direction(int* board, POINT COORDINATE, int direction, int mode);
int stone_coordinate(int* board, POINT COORDINATE, POINT* MOVE, POINT* direction_point, int direction, int mode);

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

				//�΂̔��]���̃J�E���g
				reverse_total = reverse_total + reverse_count;

				//���]���̏�����
				reverse_count = 0;
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

				//�΂̔��]���̃J�E���g
				reverse_total = reverse_total + reverse_count;

				//���]���̏�����
				reverse_count = 0;
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

				//�΂̔��]���̃J�E���g
				reverse_total = reverse_total + reverse_count;

				//���]���̏�����
				reverse_count = 0;
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

				//�΂̔��]���̃J�E���g
				reverse_total = reverse_total + reverse_count;

				//���]���̏�����
				reverse_count = 0;
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

				//�΂̔��]���̃J�E���g
				reverse_total = reverse_total + reverse_count;

				//���]���̏�����
				reverse_count = 0;
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

				//�΂̔��]���̃J�E���g
				reverse_total = reverse_total + reverse_count;

				//���]���̏�����
				reverse_count = 0;
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

				//�΂̔��]���̃J�E���g
				reverse_total = reverse_total + reverse_count;

				//���]���̏�����
				reverse_count = 0;
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

				//�΂̔��]���̃J�E���g
				reverse_total = reverse_total + reverse_count;

				//���]���̏�����
				reverse_count = 0;
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
	//�΂̐ݒu�\�t���O
	int stone_set_flag = 0;

	//�T�������̃|�C���^
	POINT* direction_point;

	//�T�����W�̃|�C���^
	POINT* MOVE;

	//�������u���b�N�̊m��
	direction_point = (POINT*)malloc(sizeof(POINT) * DIRECTION_INDEX::NUM);
	MOVE = (POINT*)malloc(sizeof(POINT));

	//�T�������̐ݒ�
	setDirection(direction_point, DIRECTION_INDEX::NUM);

	//�T���ʒu�̍��W
	MOVE->y = COORDINATE.y;
	MOVE->x = COORDINATE.x;

	//���[�v�I������:break����܂�
	while (1)
	{
		if (direction == DIRECTION_INDEX::LEFT)
		{
			//�����[�̂Ƃ�
			if (MOVE->x == BOARD_LINE_INDEX_1)
			{
				//�΂̔��]��������
				reverse_count = 0;

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
			if (MOVE->x == BOARD_LINE_INDEX_1)
			{
				//�΂̔��]��������
				reverse_count = 0;

				break;
			}
			else
			{
				;
			}
			//�c���[�̂Ƃ�
			if (MOVE->y == BOARD_LINE_INDEX_8)
			{
				//�΂̔��]��������
				reverse_count = 0;

				break;
			}
		}
		else if (direction == DIRECTION_INDEX::BOTTOM)
		{
			//�c���[�̂Ƃ�
			if (MOVE->y == BOARD_LINE_INDEX_8)
			{
				//�΂̔��]��������
				reverse_count = 0;

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
			if (MOVE->x == BOARD_LINE_INDEX_8)
			{
				//�΂̔��]��������
				reverse_count = 0;

				break;
			}
			else
			{
				;
			}
			//�c���[�̂Ƃ�
			if (MOVE->y == BOARD_LINE_INDEX_8)
			{
				//�΂̔��]��������
				reverse_count = 0;

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
			if (MOVE->x == BOARD_LINE_INDEX_8)
			{
				//�΂̔��]��������
				reverse_count = 0;

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
			if (MOVE->x == BOARD_LINE_INDEX_8)
			{
				//�΂̔��]��������
				reverse_count = 0;

				break;
			}
			else
			{
				;
			}
			//�c���[�̂Ƃ�
			if (MOVE->y == BOARD_LINE_INDEX_1)
			{
				//�΂̔��]��������
				reverse_count = 0;

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
			if (MOVE->y == BOARD_LINE_INDEX_1)
			{
				//�΂̔��]��������
				reverse_count = 0;

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
			if (MOVE->x == BOARD_LINE_INDEX_1)
			{
				//�΂̔��]��������
				reverse_count = 0;

				break;
			}
			else
			{
				;
			}
			//�c���[�̂Ƃ�
			if (MOVE->y == BOARD_LINE_INDEX_1)
			{
				//�΂̔��]��������
				reverse_count = 0;

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
		if (*(board + ((MOVE->y + direction_point[direction].y) * HEIGHT) + MOVE->x + direction_point[direction].x) == NONE_PLAY)
		{
			//�΂̔��]��������
			reverse_count = 0;

			break;
		}
		else
		{
			;
		}
		//�T�������ׂ̗̃}�X�Ɠ����F�̐΂̂Ƃ�
		if (*(board + ((COORDINATE.y + direction_point[direction].y) * HEIGHT) + COORDINATE.x + direction_point[direction].x) == turn)
		{
			//�΂̔��]��������
			reverse_count = 0;

			break;
		}
		else
		{
			;
		}

		//���W�̈ړ�
		MOVE->y = MOVE->y + direction_point[direction].y;
		MOVE->x = MOVE->x + direction_point[direction].x;

		if (direction == DIRECTION_INDEX::LEFT)
		{
			//�[�łȂ��Ƃ�
			if (MOVE->x != BOARD_LINE_INDEX_1)
			{
				//�����F�̐΂����������Ƃ�
				if (*(board + ((MOVE->y + direction_point[direction].y) * HEIGHT) + MOVE->x + direction_point[direction].x) == turn)
				{
					//�΂̔z�u�t���O��΂𔽓]����֐�
					stone_set_flag = stone_coordinate(board, COORDINATE, MOVE, direction_point, direction, mode);

					//���[�v�𔲂���
					break;
				}
				else
				{
					//���]���J�E���g�A�b�v
					reverse_count++;
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
			if (MOVE->x != BOARD_LINE_INDEX_1 && MOVE->y != BOARD_LINE_INDEX_8)
			{
				//�����F�̐΂����������Ƃ�
				if (*(board + ((MOVE->y + direction_point[direction].y) * HEIGHT) + MOVE->x + direction_point[direction].x) == turn)
				{
					//�΂̔z�u�t���O��΂𔽓]����֐�
					stone_set_flag = stone_coordinate(board, COORDINATE, MOVE, direction_point, direction, mode);

					//���[�v�𔲂���
					break;
				}
				else
				{
					//���]���J�E���g�A�b�v
					reverse_count++;
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
			if (MOVE->y != BOARD_LINE_INDEX_8)
			{
				//�����F�̐΂����������Ƃ�
				if (*(board + ((MOVE->y + direction_point[direction].y) * HEIGHT) + MOVE->x + direction_point[direction].x) == turn)
				{
					//�΂̔z�u�t���O��΂𔽓]����֐�
					stone_set_flag = stone_coordinate(board, COORDINATE, MOVE, direction_point, direction, mode);

					//���[�v�𔲂���
					break;
				}
				else
				{
					//���]���J�E���g�A�b�v
					reverse_count++;
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
			if (MOVE->x != BOARD_LINE_INDEX_8 && MOVE->y != BOARD_LINE_INDEX_8)
			{
				//�����F�̐΂����������Ƃ�
				if (*(board + ((MOVE->y + direction_point[direction].y) * HEIGHT) + MOVE->x + direction_point[direction].x) == turn)
				{
					//�΂̔z�u�t���O��΂𔽓]����֐�
					stone_set_flag = stone_coordinate(board, COORDINATE, MOVE, direction_point, direction, mode);

					//���[�v�𔲂���
					break;
				}
				else
				{
					//���]���J�E���g�A�b�v
					reverse_count++;
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
			if (MOVE->x != BOARD_LINE_INDEX_8)
			{
				//�����F�̐΂����������Ƃ�
				if (*(board + ((MOVE->y + direction_point[direction].y) * HEIGHT) + MOVE->x + direction_point[direction].x) == turn)
				{
					//�΂̔z�u�t���O��΂𔽓]����֐�
					stone_set_flag = stone_coordinate(board, COORDINATE, MOVE, direction_point, direction, mode);

					//���[�v�𔲂���
					break;
				}
				else
				{
					//���]���J�E���g�A�b�v
					reverse_count++;
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
			if (MOVE->x != BOARD_LINE_INDEX_8 && MOVE->y != BOARD_LINE_INDEX_1)
			{
				//�����F�̐΂����������Ƃ�
				if (*(board + ((MOVE->y + direction_point[direction].y) * HEIGHT) + MOVE->x + direction_point[direction].x) == turn)
				{
					//�΂̔z�u�t���O��΂𔽓]����֐�
					stone_set_flag = stone_coordinate(board, COORDINATE, MOVE, direction_point, direction, mode);

					//���[�v�𔲂���
					break;
				}
				else
				{
					//���]���J�E���g�A�b�v
					reverse_count++;
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
			if (MOVE->y != BOARD_LINE_INDEX_1)
			{
				//�����F�̐΂����������Ƃ�
				if (*(board + ((MOVE->y + direction_point[direction].y) * HEIGHT) + MOVE->x + direction_point[direction].x) == turn)
				{
					//�΂̔z�u�t���O��΂𔽓]����֐�
					stone_set_flag = stone_coordinate(board, COORDINATE, MOVE, direction_point, direction, mode);

					//���[�v�𔲂���
					break;
				}
				else
				{
					//���]���J�E���g�A�b�v
					reverse_count++;
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
			if (MOVE->x != BOARD_LINE_INDEX_1 && MOVE->y != BOARD_LINE_INDEX_1)
			{
				//�����F�̐΂����������Ƃ�
				if (*(board + ((MOVE->y + direction_point[direction].y) * HEIGHT) + MOVE->x + direction_point[direction].x) == turn)
				{
					//�΂̔z�u�t���O��΂𔽓]����֐�
					stone_set_flag = stone_coordinate(board, COORDINATE, MOVE, direction_point, direction, mode);

					//���[�v�𔲂���
					break;
				}
				else
				{
					//���]���J�E���g�A�b�v
					reverse_count++;
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
	free(MOVE);

	return stone_set_flag;
}

int stone_coordinate(int* board, POINT COORDINATE, POINT* MOVE, POINT* direction_point, int direction, int mode)
{
	//�΂̐ݒu�\�t���O
	int stone_set_flag = 0;

	//�����Ŗ߂�l�𕪂��ċ@�\�؂�ւ�����
	//�΂̔z�u�\�t���O��߂��Ƃ�
	if (mode == MODE_STONE_SET_CHECK)
	{
		//�Δz�u�\�t���O�𗧂Ă�
		stone_set_flag = STONE_SET_ENABLE;

		//���]���J�E���g�A�b�v
		reverse_count++;
	}
	//���]������s��
	else if (mode == MODE_STONE_INVERSION)
	{
		//�z�u�ʒu�܂Ő΂𔽓]�����Ƃ�
		while (COORDINATE.y != MOVE->y || COORDINATE.x != MOVE->x)
		{
			//�v���C���[�^�[���̐΂ɕύX����
			*(board + (MOVE->y * HEIGHT) + MOVE->x) = turn;

			//���W�̈ړ�(�z�u�ʒu�Ɍ�����)
			MOVE->y = MOVE->y - direction_point[direction].y;
			MOVE->x = MOVE->x - direction_point[direction].x;
		}
	}
	else
	{
		;
	}

	return stone_set_flag;
}