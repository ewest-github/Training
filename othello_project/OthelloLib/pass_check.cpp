#include<stdio.h>
#include<stdlib.h>

#include "OthelloLib.h"
#include "function.h"

//�A�N�e�B�u�^�[��
extern int turn;

//���b�Z�[�W�\���t���O
extern int message_flag;

//�p�X�t���O
extern int pass_flag;

int pass_check(int* board)
{
	//�Δz�u�\�}�X��
	int stone_set_count = 0;

	//�R�}�z�u�\���W
	POINT COORDINATE;

	//���[�v�I������:�c�̑S�Ẵ}�X���`�F�b�N����܂�
	for (int height = 0; height < HEIGHT; height++)
	{
		//���[�v�I������:���̑S�Ẵ}�X���`�F�b�N����܂�
		for (int width = 0; width < WIDTH; width++)
		{
			//�Y���}�X���R�}���z�u�̂Ƃ�
			if (*(board + (height * HEIGHT) + width) == NONE_PLAY)
			{
				//�\���̂ɍ��W����
				COORDINATE.y = height;
				COORDINATE.x = width;

				//�Δz�u�\�ȂƂ�
				if (0 < stone_rolling(board, COORDINATE, MODE_STONE_SET_CHECK))
				{
					stone_set_count++;
				}
				else
				{
					;
				}
			}
			//�Y���}�X���R�}�z�u�ς݂̏ꍇ
			else
			{
				;
			}
		}
	}

	return stone_set_count;
}

void position_check(int* board, POINT* stone_position)
{
	//�Δz�u�\�t���O
	int stone_set_count = 0;

	//���W�i�[�A�h���X
	int position_save = 0;

	//�R�}�z�u�\���W
	POINT COORDINATE;

	//���[�v�I������:�c�̑S�Ẵ}�X���`�F�b�N����܂�
	for (int height = 0; height < HEIGHT; height++)
	{
		//���[�v�I������:���̑S�Ẵ}�X���`�F�b�N����܂�
		for (int width = 0; width < WIDTH; width++)
		{
			//�Y���}�X���R�}���z�u�̂Ƃ�
			if (*(board + (height * HEIGHT) + width) == NONE_PLAY)
			{
				//�\���̂ɍ��W����
				COORDINATE.y = height;
				COORDINATE.x = width;

				stone_set_count = stone_rolling(board, COORDINATE, MODE_STONE_SET_CHECK);

				//�Δz�u�\�ȍ��W�̂Ƃ�
				if (0 < stone_set_count)
				{
					//���W�̕ۑ�
					(stone_position + position_save)->y = height;
					(stone_position + position_save)->x = width;

					//�A�h���X�̃J�E���g�A�b�v
					position_save++;
				}
				else
				{
					;
				}
			}
			//�Y���}�X���R�}�z�u�ς݂̏ꍇ
			else
			{
				;
			}
		}
	}
}

int number_input()
{
	char ss[10];
	int num = 0;

	gets_s(ss);
	num = atoi(ss);

	return num;
}

int stone_set(int* board, int active_turn, int not_active_turn)
{
	//�^�[����Ԃ�
	int ac_turn = 0;
	
	//�p�X�L�����͒l
	int num = 0;

	//�΂̔z�u�ʒu���͒l
	int width = 0;
	int height = 0;

	//���W�̍\����
	POINT COORDINATE;

	/* 5.�΂̔z�u�ʒu�̓��� */
	//�΂̔z�u�ʒu�̓���
	if (message_flag == NON_DISPLAY)
	{
		printf("�΂̈ʒu����͂��ĉ������B\n");

		//����^�[����2��ȏ�\�����Ȃ�
		message_flag = DISPLAY;
	}
	else
	{
		;
	}
	printf("��:");
	COORDINATE.x = number_input();
	printf("�c:");
	COORDINATE.y = number_input();

	//���͒l�̗L������
	//�Ֆʂ͈̔͊O�̂Ƃ�
	if(COORDINATE.x < BOARD_LINE_INDEX_1 || BOARD_LINE_INDEX_8 < COORDINATE.x || COORDINATE.y < BOARD_LINE_INDEX_1 || BOARD_LINE_INDEX_8 < COORDINATE.y)
	{
		/* 6.�΂̃G���[���b�Z�[�W�\�� */
		printf("�Ֆʂ͈̔͊O�ł��A�Ⴄ�ꏊ���w�肵�Ă��������B\n");
		
		//�^�[����n���Ȃ�
		ac_turn = active_turn;
	}
	else
	{
		//�΂��z�u�ς݂̂Ƃ�
		if (*(board + (COORDINATE.y * HEIGHT) + COORDINATE.x) != NONE_PLAY)
		{
			/* 6.�΂̃G���[���b�Z�[�W�\�� */
			printf("���ɐ΂�z�u�ς݂Ȃ̂ŁA�Ⴄ�ꏊ���w�肵�Ă��������B\n");

			//�^�[����n���Ȃ�
			ac_turn = active_turn;
		}
		else
		{
			//�΂��z�u�\�ȂƂ�
			if (STONE_SET_DISABLE < stone_rolling(board, COORDINATE, MODE_STONE_SET_CHECK))
			{
				//�΂̔z�u����
				*(board + (COORDINATE.y * HEIGHT) + COORDINATE.x) = active_turn;

				/* 7.�΂̎������] */
				//���]����
				stone_rolling(board, COORDINATE, MODE_STONE_INVERSION);
			
				//�^�[����n��
				ac_turn = not_active_turn;
				
				/* 10.���]��̔Ֆʕ\�� */
				//�Ֆʂ�\������
				printBoard(board, 64);

				//���b�Z�[�W�\���t���O�̉���
				message_flag = NON_DISPLAY;

				//�p�X�t���O�̉���
				pass_flag = 0;
			}
			//�΂��z�u�ł��Ȃ��Ƃ�
			else
			{
				//�p�X�L���̓��͑ҋ@(���[�v�I������:0��1�����͂����܂�)
				do {
					/* 8.�p�X�L���̓��� */
					printf("���ސ΂�����܂���B�p�X(0:���Ȃ��A1:����)���܂����H\n");
					num = number_input();

					//�p�X����ꍇ
					if (num == PASS)
					{
						//�΂�z�u�ł���ꏊ������Ƃ�
						if (0 < pass_check(board))
						{
							printf("�z�u�\�Ȑ΂����邽�߃p�X�ł��܂���B\n");

							//�^�[����n���Ȃ�
							ac_turn = active_turn;
						}
						//�Ȃ��Ƃ�
						else
						{
							//�^�[����n��
							ac_turn = not_active_turn;

							//�p�X�t���O�𗧂Ă�
							pass_flag++;

							//���b�Z�[�W�\���t���O�̉���
							message_flag = NON_DISPLAY;
						}
					}
					//�p�X���Ȃ��ꍇ
					else if (num == NOT_PASS)
					{
						//�^�[����n���Ȃ�
						ac_turn = active_turn;
					}
					//���͒l��0��1�ȊO�������Ƃ�
					else
					{
						/* 9.�p�X�L���̃G���[���b�Z�[�W�\�� */
						printf("0��1����͂��ĉ������B\n");

						//�^�[����n���Ȃ�
						ac_turn = active_turn;
					}
				} while (num != NOT_PASS && num != PASS);
			}
		}
	}
	

	//�ǂ��炩�̃^�[����Ԃ�
	return ac_turn;
}