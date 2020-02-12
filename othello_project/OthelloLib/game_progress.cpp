#include<stdio.h>
#include<stdlib.h>

#include "OthelloLib.h"
#include "function.h"

//�^�[�����Ǘ�
int turn;

//���b�Z�[�W�\���t���O
int message_flag;

//�p�X�t���O
int pass_flag;

//�΂̔��]���J�E���g
int reverse_count;

//���W���̔��]��
int reverse_stone[20];

int game_progress(int* board, int level)
{
	//�p�X�t���O
	//int ps = 0;

	//����
	int winner = 0;

	//���b�Z�[�W�t���O
	message_flag = 0;

	//�^�[�����Ǘ�
	//int turn = 0;

	//�p�X�L�����͒l
	//int num = 0;

	//�Δz�u�\�ȍ��W��
	int set_count = 0;

	//�Δz�u�\�ȍ��W
	POINT* stone_position;

	//�΂�z�u������W
	int set_stone = 0;

	//���]��
	reverse_count = 0;

	//�^�[���Ǘ��p�ϐ�(�������)
	turn = BLACK_STONE;

	//�I���t���O
	int game_end = 60;
	
	//�Ֆʏ�̍��ΐ�
	int black_stone = 2;
	
	//�Ֆʏ�̔��ΐ�
	int white_stone = 2;

	//���[�v�I������:�Ֆʏ�ɐ΂�z�u���Ă��Ȃ��ꏊ������A�������̐΂�0�ɂȂ�A���v���C���[���p�X����
	while (game_end != 0 && black_stone != NONE_PLAY && white_stone != NONE_PLAY && pass_flag != 2)
	{
		//�Ֆʂ̐΃J�E���g������
		game_end = 0;
		black_stone = 0;
		white_stone = 0;
		
		//���΂̃^�[���̂Ƃ�
		if (turn == BLACK_STONE)
		{
			/* 4.���݂̃v���C���[�̕\�� */
			//���݂̃v���C���[�\��
			//����^�[����1�񂾂��\��
			if (message_flag == NON_DISPLAY)
			{
				printf("���݂̃v���C���[:%s\n", BLACK_STONE_STR);
			}
			else
			{
				;
			}
			
			//�p�X�̗L������
			//ps = pass_check(b);
			
			//�p�X����
			//if (ps == 1)
			//{
				//printf("���ސ΂�����܂���B�p�X(0:���Ȃ��A1:����)���܂����H\n");
				//num = number_input();

				//�p�X����ꍇ
				//if (num == 1)
				//{
				//	turn = WHITE_STONE;
				//}
				//�p�X���Ȃ��ꍇ
				//else if(num == 0)
				//{
			//�΂̔z�u
			turn = stone_set(board, BLACK_STONE, WHITE_STONE);
				//}
				//���͒l��0��1�ȊO�������Ƃ�
				//else
				//{
				//	printf("0��1����͂��ĉ������B\n");
				//}

			//}
			//�p�X�̂Ȃ��ꍇ
			//else
			//{
				//�΂̔z�u
			//	turn = stone_set(b, BLACK_STONE, WHITE_STONE);
			//}
		}
		//���΂̃^�[���̂Ƃ�
		else
		{
			//�z�u�\�ȍ��W��
			set_count = pass_check(board);

			//�^�[���J�n�\��
			printf("���݂̃v���C���[:%s\n", WHITE_STONE_STR);

			//�p�X����
			if (set_count == 0)
			{
				printf("���ސ΂�����܂���B�p�X���܂�\n");
			}
			else
			{
				//�������u���b�N�m��
				stone_position = (POINT*)malloc(sizeof(POINT) * set_count);

				//�z�u�\�ȍ��W���擾
				position_check(board, stone_position);

				//���x���ɉ������A�h���X���擾
				set_stone = CPU_level(stone_position, set_count, level);

				//�΂̔z�u
				*(board + ((stone_position + set_stone)->y * HEIGHT) + (stone_position + set_stone)->x) = WHITE_STONE;

				//�΂̔��]
				stone_rolling(board, *(stone_position + set_stone), MODE_STONE_INVERSION);

				/* 10.���]��̔Ֆʕ\�� */
				//�Ֆʂ�\������
				printBoard(board, 64);

				//���]���W�ƌ��̏�����
				reverse_count = 0;

				for (int i = 0; i < set_count; i++)
				{
					reverse_stone[i] = 0;
				}

				//�������u���b�N�̉��
				free(stone_position);
			}

			//�^�[����n��
			turn = BLACK_STONE;
			
			/* 4.���݂̃v���C���[�̕\�� */
			//���݂̃v���C���[�\��
			//����^�[����1�񂾂��\��
			/*
			if (message_flag == NON_DISPLAY)
			{
				printf("���݂̃v���C���[:%s\n", WHITE_STONE_STR);
			}
			else
			{
				;
			}

			//�΂̔z�u
			turn = stone_set(board, WHITE_STONE, BLACK_STONE);
			*/
		}
		
		//�Ֆʂ̖��z�u�̐��Ɛ΂̐����Ǘ�
		//���[�v�I������:�c�̑S�Ẵ}�X���`�F�b�N����܂�
		for (int h = 0; h < HEIGHT; h++)
		{
			//���[�v�I������:���̑S�Ẵ}�X���`�F�b�N����܂�
			for (int w = 0; w < WIDTH; w++)
			{
				//�Y���}�X���R�}���z�u�̂Ƃ�
				if (*(board + (h * HEIGHT) + w) == NONE_PLAY)
				{
					game_end++;
				}
				//�Y���}�X�����Δz�u�ς݂̏ꍇ
				else if (*(board + (h * HEIGHT) + w) == BLACK_STONE)
				{
					black_stone++;
				}
				//�Y���}�X�����Δz�u�ς݂̏ꍇ
				else if (*(board + (h * HEIGHT) + w) == WHITE_STONE)
				{
					white_stone++;
				}
				else
				{
					;
				}
			}
		}
	}

	//���s�̔���
	//���������̂Ƃ�
	if (white_stone < black_stone)
	{
		winner = BLACK_STONE;
	}
	//���������̂Ƃ�
	else if (black_stone < white_stone)
	{
		winner = WHITE_STONE;
	}
	//���������̂Ƃ�
	else
	{
		winner = NONE_FINISH;
	}

	//���s��Ԃ�
	return winner;
}

int CPU_level(POINT* stone_position, int set_count, int level)
{
	//�΂�z�u������W
	int set_stone = 0;

	//4�ӂɔz�u�ł�����W�̐�
	int side_put = 0;

	switch (level)
	{
	case 1:
		//�΂�z�u������W�̌���
		set_stone = rand() % set_count;
		break;
	case 2:
		//���]�ł���΂̑������W�ɔz�u����
		set_stone = MAX_Inversion(stone_position, set_count);

		break;
	case 3:
		//4�ӂ̍��W��D�悵�Ĕz�u����
		set_stone = SIDE_stone_put(stone_position, set_count);

		break;
	case 4:
		break;
	case 5:
		break;
	default:
		break;
	}

	return set_stone;
}

int MAX_Inversion(POINT* stone_position, int set_count)
{
	//�΂�z�u������W
	int set_stone = 0;

	//���]���������ɂȂ���W�̐�
	int tie = 1;

	//�v�f��-1��J��Ԃ�
	for (int bubble = 0; bubble < set_count - 1; bubble++)
	{
		//���]���ŏ����\�[�g
		for (int max_reverse = 0; max_reverse + 1 < set_count - bubble; max_reverse++)
		{
			//�\�[�g�p�ꎞ�ۊǕϐ�
			int sort = 0;
			POINT SORT;

			//�΂̔��]���̑����ق����z���ʂɂȂ�悤�Ƀ\�[�g
			if (reverse_stone[max_reverse] < reverse_stone[max_reverse + 1])
			{
				;
			}
			else
			{
				//�\�[�g����
				sort = reverse_stone[max_reverse + 1];
				SORT.y = stone_position[max_reverse + 1].y;
				SORT.x = stone_position[max_reverse + 1].x;

				reverse_stone[max_reverse + 1] = reverse_stone[max_reverse];
				stone_position[max_reverse + 1].y = stone_position[max_reverse].y;
				stone_position[max_reverse + 1].x = stone_position[max_reverse].x;

				reverse_stone[max_reverse] = sort;
				stone_position[max_reverse].y = SORT.y;
				stone_position[max_reverse].x = SORT.x;
			}
		}
	}

	//�΂̔��]���̑������W��ێ�
	//set_stone = set_count - 1;

	//���]���̍ő�l�ɑ΂��ē�������������Ƃ��̏���
	for (int max_num = 0; max_num < set_count - 1; max_num++)
	{
		//���]���̍ő�l�Ɣ��]���������Ƃ�
		if (reverse_stone[set_count - 1] == reverse_stone[max_num])
		{
			//�ő唽�]���̍��W�̐����J�E���g�A�b�v
			tie++;
		}
		else
		{
			;
		}
	}

	//�����̍��W���烉���_����1�I������
	set_stone = (set_count - tie) + (rand() % tie);

	return set_stone;
}

int SIDE_stone_put(POINT* stone_position, int set_count)
{
	//�΂�z�u������W
	int set_stone = 0;

	//4�ӂɔz�u�ł�����W�̐�
	int side_put = 0;

	//�Δz�u�\��4�ӂ̃A�h���X
	int* side_address;

	//�������u���b�N�̊m��
	side_address = (int*)malloc(sizeof(int) * set_count);

	//4�ӂɔz�u�\�ȃA�h���X�Ƀt���O������
	SIDE_stone_flag(stone_position, set_count, side_address);
	/*
	//�A�h���X���̒l�̏�����
	for (int Initialize = 0; Initialize < set_count; Initialize++)
	{
		*(side_address + Initialize) = 0;
	}

	//�Δz�u�\�ȍ��W����4�ӂ̍��W���J�E���g����
	for (int side_count = 0; side_count < set_count; side_count++)
	{
		if (stone_position[side_count].y == BOARD_LINE_INDEX_1)
		{
			*(side_address + side_count) = *(side_address + side_count) + 1;
		}
		else
		{
			;
		}
		if (stone_position[side_count].y == BOARD_LINE_INDEX_8)
		{
			*(side_address + side_count) = *(side_address + side_count) + 1;
		}
		else
		{
			;
		}
		if (stone_position[side_count].x == BOARD_LINE_INDEX_1)
		{
			*(side_address + side_count) = *(side_address + side_count) + 1;
		}
		else
		{
			;
		}
		if (stone_position[side_count].x == BOARD_LINE_INDEX_8)
		{
			*(side_address + side_count) = *(side_address + side_count) + 1;
		}
		else
		{
			;
		}
	}

	//4�ӂ̔z�u�ۂō~���\�[�g����
	//�v�f��-1��J��Ԃ�
	for (int bubble = 0; bubble <= set_count - 1; bubble++)
	{
		//4�ӂ̔z�u�ۂō~���\�[�g
		for (int max_reverse = set_count - 1; bubble <= max_reverse - 1; max_reverse--)
		{
			//�\�[�g�p�ꎞ�ۊǕϐ�
			int sort = 0;
			POINT SORT;
			int* side_sort;

			//�������u���b�N�̊m��
			side_sort = (int*)malloc(sizeof(int));

			//4�ӂɔz�u�ł���z�񂪍~���ɂȂ�悤�Ƀ\�[�g
			if (*(side_address + (max_reverse - 1)) < *(side_address + max_reverse))
			{
				//�\�[�g����
				sort = reverse_stone[max_reverse];
				SORT.y = stone_position[max_reverse].y;
				SORT.x = stone_position[max_reverse].x;
				*(side_sort) = *(side_address + max_reverse);

				reverse_stone[max_reverse] = reverse_stone[max_reverse - 1];
				stone_position[max_reverse].y = stone_position[max_reverse - 1].y;
				stone_position[max_reverse].x = stone_position[max_reverse - 1].x;
				*(side_address + max_reverse) = *(side_address + (max_reverse - 1));

				reverse_stone[max_reverse - 1] = sort;
				stone_position[max_reverse - 1].y = SORT.y;
				stone_position[max_reverse - 1].x = SORT.x;
				*(side_address + (max_reverse - 1)) = *(side_sort);
			}
			else
			{
				;
			}

			//�������u���b�N�̉��
			free(side_sort);
		}
	}
	*/
	//4�ӂɔz�u�ł�����W���̊m�F
	for (int max_num = 0; max_num < set_count; max_num++)
	{
		//4�ӂ̍��W�̂Ƃ�
		if (0 < *(side_address + max_num))
		{
			//�ő唽�]���̍��W�̐����J�E���g�A�b�v
			side_put++;
		}
		else
		{
			;
		}
	}

	//4�ӂɔz�u�ł�����W����0�̂Ƃ�
	if (side_put == 0)
	{
		set_stone = MAX_Inversion(stone_position, set_count);
	}
	//4�ӂɔz�u�ł�����W����1�̂Ƃ�
	else if (side_put == 1)
	{
		set_stone = 0;
	}
	//4�ӂɔz�u�ł�����W����2�ȏ�̂Ƃ�
	else
	{
		set_stone = MAX_Inversion(stone_position, side_put);
	}

	//�������u���b�N�̉��
	free(side_address);

	return set_stone;
}

int CORNER_stone_put(POINT* stone_position, int set_count)
{
	//�΂�z�u������W
	int set_stone = 0;

	//4�ӂɔz�u�ł�����W�̐�
	int side_put = 0;

	//4���ɔz�u�ł�����W�̐�
	int corner_put = 0;

	//�Δz�u�\��4�ӂ̃A�h���X
	int* side_address;

	//�������u���b�N�̊m��
	side_address = (int*)malloc(sizeof(int) * set_count);

	//4�ӂ�4���ɔz�u�\�ȃA�h���X�Ƀt���O������
	SIDE_stone_flag(stone_position, set_count, side_address);

	//4�ӂ�4���ɔz�u�ł�����W���̊m�F
	for (int max_num = 0; max_num < set_count; max_num++)
	{
		//4���̍��W�̂Ƃ�
		if (*(side_address + max_num) == 2)
		{
			//4���ɔz�u�ł��鐔���J�E���g�A�b�v
			corner_put++;
		}
		else if(*(side_address + max_num) == 1)
		{
			//4�ӂɔz�u�ł��鐔���J�E���g�A�b�v
			side_put++;
		}
	}

	//�������u���b�N�̉��
	free(side_address);

	return set_stone;
}

void SIDE_stone_flag(POINT* stone_position, int set_count, int* side_address)
{
	//�A�h���X���̒l�̏�����
	for (int Initialize = 0; Initialize < set_count; Initialize++)
	{
		*(side_address + Initialize) = 0;
	}

	//�Δz�u�\�ȍ��W����4�ӂ̍��W���J�E���g����
	for (int side_count = 0; side_count < set_count; side_count++)
	{
		if (stone_position[side_count].y == BOARD_LINE_INDEX_1)
		{
			*(side_address + side_count) = *(side_address + side_count) + 1;
		}
		else
		{
			;
		}
		if (stone_position[side_count].y == BOARD_LINE_INDEX_8)
		{
			*(side_address + side_count) = *(side_address + side_count) + 1;
		}
		else
		{
			;
		}
		if (stone_position[side_count].x == BOARD_LINE_INDEX_1)
		{
			*(side_address + side_count) = *(side_address + side_count) + 1;
		}
		else
		{
			;
		}
		if (stone_position[side_count].x == BOARD_LINE_INDEX_8)
		{
			*(side_address + side_count) = *(side_address + side_count) + 1;
		}
		else
		{
			;
		}
	}

	//4�ӂ̔z�u�ۂō~���\�[�g����
	//�v�f��-1��J��Ԃ�
	for (int bubble = 0; bubble <= set_count - 1; bubble++)
	{
		//4�ӂ̔z�u�ۂō~���\�[�g
		for (int max_reverse = set_count - 1; bubble <= max_reverse - 1; max_reverse--)
		{
			//�\�[�g�p�ꎞ�ۊǕϐ�
			int sort = 0;
			POINT SORT;
			int* side_sort;

			//�������u���b�N�̊m��
			side_sort = (int*)malloc(sizeof(int));

			//4�ӂɔz�u�ł���z�񂪍~���ɂȂ�悤�Ƀ\�[�g
			if (*(side_address + (max_reverse - 1)) < *(side_address + max_reverse))
			{
				//�\�[�g����
				sort = reverse_stone[max_reverse];
				SORT.y = stone_position[max_reverse].y;
				SORT.x = stone_position[max_reverse].x;
				*(side_sort) = *(side_address + max_reverse);

				reverse_stone[max_reverse] = reverse_stone[max_reverse - 1];
				stone_position[max_reverse].y = stone_position[max_reverse - 1].y;
				stone_position[max_reverse].x = stone_position[max_reverse - 1].x;
				*(side_address + max_reverse) = *(side_address + (max_reverse - 1));

				reverse_stone[max_reverse - 1] = sort;
				stone_position[max_reverse - 1].y = SORT.y;
				stone_position[max_reverse - 1].x = SORT.x;
				*(side_address + (max_reverse - 1)) = *(side_sort);
			}
			else
			{
				;
			}

			//�������u���b�N�̉��
			free(side_sort);
		}
	}
}