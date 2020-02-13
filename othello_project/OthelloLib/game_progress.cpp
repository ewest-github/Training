#include<stdio.h>
#include<stdlib.h>

#include "OthelloLib.h"
#include "function.h"

//�I�Z���Ֆʂ̐Δz�u�z��̒�`
extern int* board;

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

int game_progress(int level)
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
			turn = stone_set(BLACK_STONE, WHITE_STONE);
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

				//�p�X�t���O�𗧂Ă�
				pass_flag++;
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

				//�p�X�t���O�̉���
				pass_flag = 0;

				/* 10.���]��̔Ֆʕ\�� */
				//�Ֆʂ�\������
				printBoard(board, 64);

				//���]���W�ƌ��̏�����
				for (int i = 0; i < set_count; i++)
				{
					reverse_stone[i] = 0;
				}

				//�������u���b�N�̉��
				free(stone_position);
			}

			//�^�[����n��
			turn = BLACK_STONE;
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
		//4���̍��W��D�悵�Ĕz�u����
		set_stone = CORNER_stone_put(stone_position, set_count);

		break;
	case 5:
		//����̎��̎���v�Z���Ĕz�u����
		set_stone = onehand_stone_put(stone_position, set_count);

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

	//���W���菈��
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
		else
		{
			;
		}
	}

	//���W���菈��
	//4���ɔz�u�\�ȍ��W����������Ƃ�
	if (1 < corner_put)
	{
		set_stone = MAX_Inversion(stone_position, corner_put);
	}
	//4���ɔz�u�\�ȍ��W��1�݂̂̂Ƃ�
	else if (corner_put == 1)
	{
		set_stone = 0;
	}
	//4���ɔz�u�\�ȍ��W���Ȃ��Ƃ�
	else
	{
		//4�ӂɔz�u�\�ȍ��W����������Ƃ�
		if (1 < side_put)
		{
			set_stone = MAX_Inversion(stone_position, side_put);
		}
		//4�ӂɔz�u�\�ȍ��W��1�݂̂̂Ƃ�
		else if (side_put == 1)
		{
			set_stone = 0;
		}
		//4�ӂɔz�u�\�ȍ��W���Ȃ��Ƃ�
		else
		{
			set_stone = MAX_Inversion(stone_position, set_count);
		}
	}

	//�������u���b�N�̉��
	free(side_address);

	return set_stone;
}

int onehand_stone_put(POINT* stone_position, int set_count)
{
	//�΂�z�u������W
	int set_stone = 0;

	//����̐Δz�u�s�\�t���O
	int hand_not_stone = 0;

	//4�ӂ̐Δz�u�\�ȃt���O
	int side_count = 0;

	//4���ɐΔz�u�\�ȃt���O
	int corner_count = 0;

	//4�ӂɂ�4���ɂ��Δz�u�s�\�ȃt���O
	int non_side_count = 0;

	//�΂����z�u���邽�߂̔Ֆʏ��
	int* hand_board;

	//�΂̉��z�u��ɐΔz�u�\�ȍ��W
	POINT* hand_stone_position;

	//�΂̉��z�u��ɑ���̎��i�K��������
	int* hand_level;

	//�΂̉��z�u��ɐΔz�u�\��4�ӂ̃A�h���X�Ǘ��t���O
	int* hand_side_address;

	//���̐Δz�u�\�ȍ��W��
	int hand_set_count = 0;

	//�������u���b�N�̊m��
	hand_board = (int*)malloc(sizeof(int) * 64);
	hand_level = (int*)malloc(sizeof(int) * set_count);

	//���̔Ֆʏ���ۑ�
	for (int y = 0; y < 8; y++)
	{
		for (int x = 0; x < 8; x++)
		{
			*(hand_board + (y * HEIGHT) + x) = *(board + (y * HEIGHT) + x);
		}
	}

	//�Ֆʏ�̐Δz�u�ł���ꏊ�S�Ăɐ΂����u������
	for (int provisional = 0; provisional < set_count; provisional++)
	{
		//�΂̉��z�u
		*(hand_board + ((stone_position + provisional)->y * HEIGHT) + (stone_position + provisional)->x) = WHITE_STONE;

		//�΂̉����]
		stone_rolling(hand_board, *(stone_position + provisional), MODE_STONE_INVERSION);

		//�^�[����n��
		turn = BLACK_STONE;

		//�f�o�b�O�p�\��
		/*
		for (int xxx = 0; xxx < 8; xxx++)
		{
			for (int yyy = 0; yyy < 8; yyy++)
			{
				printf("%d", *(hand_board + (xxx * 8) + yyy));
			}
			printf("\n");
		}
		*/

		//�Δz�u�\�ȍ��W������肷��
		hand_set_count = pass_check(hand_board);

		//���肪�Δz�u�ł��Ȃ��Ƃ�
		if (hand_set_count == 0)
		{
			set_stone = provisional;

			//����̐Δz�u�s�\�t���O�𗧂Ă�
			hand_not_stone++;
		}
		else
		{
			//4�ӂɔz�u�ł�����W�̐�
			int side_put = 0;

			//4���ɔz�u�ł�����W�̐�
			int corner_put = 0;

			//�������u���b�N�m��
			hand_stone_position = (POINT*)malloc(sizeof(POINT) * hand_set_count);
			hand_side_address = (int*)malloc(sizeof(int) * hand_set_count);

			//�f�o�b�O�p
			//printBoard(hand_board, 64);

			//�z�u�\�ȍ��W���擾
			position_check(hand_board, hand_stone_position);

			//4�ӂ�4���ɔz�u�\�ȃA�h���X�Ƀt���O������
			SIDE_stone_flag(hand_stone_position, hand_set_count, hand_side_address);

			//4�ӂ�4���ɔz�u�ł�����W���̊m�F
			for (int max_num = 0; max_num < hand_set_count; max_num++)
			{
				//4���̍��W�̂Ƃ�
				if (*(hand_side_address + max_num) == 2)
				{
					//4���ɔz�u�ł��鐔���J�E���g�A�b�v
					corner_put++;
				}
				else if (*(hand_side_address + max_num) == 1)
				{
					//4�ӂɔz�u�ł��鐔���J�E���g�A�b�v
					side_put++;
				}
				else
				{
					;
				}
			}

			//�Δz�u�\�ȍ��W�̃����N�t��
			//4���ɔz�u�\�ȍ��W������Ƃ�
			if (0 < corner_put)
			{
				*(hand_level + provisional) = 2;
			}
			else
			{
				//4�ӂɔz�u�\�ȍ��W������Ƃ�
				if (0 < side_put)
				{
					*(hand_level + provisional) = 1;
				}
				//4�ӂɔz�u�\�ȍ��W���Ȃ��Ƃ�
				else
				{
					*(hand_level + provisional) = 0;
				}
			}


			//�������u���b�N�̉��
			free(hand_stone_position);
			free(hand_side_address);
		}

		//���z�u�����Ֆʏ��̃��Z�b�g
		for (int y = 0; y < 8; y++)
		{
			for (int x = 0; x < 8; x++)
			{
				*(hand_board + (y * HEIGHT) + x) = *(board + (y * HEIGHT) + x);
			}
		}

		//���]���W�ƌ��̏�����
		for (int i = 0; i < hand_set_count; i++)
		{
			reverse_stone[i] = 0;
		}

		//�^�[����߂�
		turn = WHITE_STONE;
	}

	//�Δz�u�s�\�t���O�������Ă���Ƃ�
	if (0 < hand_not_stone)
	{
		;
	}
	else
	{
		//�����N���̍��W�����J�E���g����
		for (int num = 0; num < set_count; num++)
		{
			if (*(hand_level + num) == 2)
			{
				corner_count++;
			}
			else if (*(hand_level + num) == 1)
			{
				side_count++;
			}
			else
			{
				non_side_count++;
			}
		}

		//���W�̃����N�ō~���\�[�g����
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
				if (*(hand_level + (max_reverse - 1)) < *(hand_level + max_reverse))
				{
					//�\�[�g����
					sort = reverse_stone[max_reverse];
					SORT.y = stone_position[max_reverse].y;
					SORT.x = stone_position[max_reverse].x;
					*(side_sort) = *(hand_level + max_reverse);

					reverse_stone[max_reverse] = reverse_stone[max_reverse - 1];
					stone_position[max_reverse].y = stone_position[max_reverse - 1].y;
					stone_position[max_reverse].x = stone_position[max_reverse - 1].x;
					*(hand_level + max_reverse) = *(hand_level + (max_reverse - 1));

					reverse_stone[max_reverse - 1] = sort;
					stone_position[max_reverse - 1].y = SORT.y;
					stone_position[max_reverse - 1].x = SORT.x;
					*(hand_level + (max_reverse - 1)) = *(side_sort);
				}
				else
				{
					;
				}

				//�������u���b�N�̉��
				free(side_sort);
			}
		}

		//4�ӂł�4���ł��Ȃ����W�ɔz�u�\�ȍ��W������Ƃ�
		if (0 < non_side_count)
		{
			set_stone = MAX_Inversion(stone_position, non_side_count);
		}
		//4�ӂł�4���ł��Ȃ����W�ɔz�u�\�ȍ��W���Ȃ��Ƃ�
		else
		{
			//4�ӂɔz�u�\�ȍ��W��1�݂̂̂Ƃ�
			if (side_count == 1)
			{
				set_stone = 0;
			}
			//4�ӂɔz�u�\�ȍ��W����������Ƃ�
			else if (1 < side_count)
			{
				set_stone = MAX_Inversion(stone_position, side_count);
			}
			//4�ӂɔz�u�\�ȍ��W���Ȃ��Ƃ�
			else
			{
				//4���ɔz�u�\�ȍ��W��1�݂̂̂Ƃ�
				if (corner_count == 1)
				{
					set_stone = 0;
				}
				//4���ɔz�u�\�ȍ��W����������Ƃ�
				else if (1 < corner_count)
				{
					set_stone = MAX_Inversion(stone_position, corner_count);
				}
				//4���ɔz�u�\�ȍ��W���Ȃ��Ƃ�(���肦�Ȃ��P�[�X)
				else
				{
					;
				}
			}
		}
	}


	//���]���W�ƌ��̏�����
	for (int i = 0; i < set_count; i++)
	{
		reverse_stone[i] = 0;
	}

	//�������u���b�N�̉��
	free(hand_level);

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