#include<stdio.h>

#include "OthelloLib.h"
#include "function.h"

void game_progress(int* b)
{
	//�p�X�t���O
	int ps = 0;

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

	//���[�v�I������:�Ֆʏ�ɐ΂�z�u���Ă��Ȃ��ꏊ������A�������̐΂�0�ɂȂ�
	while (game_end != 0 && black_stone == 0 && white_stone == 0)
	{
		//�Ֆʂ̐΃J�E���g������
		game_end = 0;
		black_stone = 0;
		white_stone = 0;
		
		//���΂̃^�[���̂Ƃ�
		if (turn == BLACK_STONE)
		{
			//���݂̃v���C���[�\��
			printf("���݂̃v���C���[:%s", BLACK_STONE_STR);
			
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
			//���݂̃v���C���[�\��
			printf("���݂̃v���C���[:%s", WHITE_STONE_STR);
			
			//���΂Ƀ^�[����n��
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
}