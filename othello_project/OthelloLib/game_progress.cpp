#include<stdio.h>

#include "OthelloLib.h"
#include "function.h"

//�^�[�����Ǘ�
int turn;

//���b�Z�[�W�\���t���O
int message_flag;

//�p�X�t���O
int pass_flag;

int game_progress(int* b)
{
	//�p�X�t���O
	int ps = 0;

	//����
	int winner = 0;

	//���b�Z�[�W�t���O
	message_flag = 0;

	//�^�[�����Ǘ�
	//int turn = 0;

	//�p�X�L�����͒l
	//int num = 0;

	//�^�[���Ǘ��p�ϐ�(�������)
	turn = BLACK_STONE;

	//�I���t���O
	int game_end = 60;
	
	//�Ֆʏ�̍��ΐ�
	int black_stone = 2;
	
	//�Ֆʏ�̔��ΐ�
	int white_stone = 2;

	//���[�v�I������:�Ֆʏ�ɐ΂�z�u���Ă��Ȃ��ꏊ������A�������̐΂�0�ɂȂ�A���v���C���[���p�X����
	while (game_end != 0 && black_stone != 0 && white_stone != 0 && pass_flag != 2)
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
			if (message_flag == 0)
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
			turn = stone_set(b, BLACK_STONE, WHITE_STONE);
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
			/* 4.���݂̃v���C���[�̕\�� */
			//���݂̃v���C���[�\��
			//����^�[����1�񂾂��\��
			if (message_flag == 0)
			{
				printf("���݂̃v���C���[:%s\n", WHITE_STONE_STR);
			}
			else
			{
				;
			}

			//�΂̔z�u
			turn = stone_set(b, WHITE_STONE, BLACK_STONE);
			
			//���΂Ƀ^�[����n��
			//turn = BLACK_STONE;
		}
		
		//�Ֆʂ̖��z�u�̐��Ɛ΂̐����Ǘ�
		//���[�v�I������:�c�̑S�Ẵ}�X���`�F�b�N����܂�
		for (int h = 0; h < HEIGHT; h++)
		{
			//���[�v�I������:���̑S�Ẵ}�X���`�F�b�N����܂�
			for (int w = 0; w < WIDTH; w++)
			{
				//�Y���}�X���R�}���z�u�̂Ƃ�
				if (*(b + (h * HEIGHT) + w) == 0)
				{
					game_end++;
				}
				//�Y���}�X�����Δz�u�ς݂̏ꍇ
				else if (*(b + (h * HEIGHT) + w) == BLACK_STONE)
				{
					black_stone++;
				}
				//�Y���}�X�����Δz�u�ς݂̏ꍇ
				else if (*(b + (h * HEIGHT) + w) == WHITE_STONE)
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
		winner = 3;
	}

	//���s��Ԃ�
	return winner;
}