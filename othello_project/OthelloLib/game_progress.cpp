#include<stdio.h>

#include "OthelloLib.h"
#include "function.h"

void game_progress(int* b)
{
	//�p�X�t���O
	int ps = 0;

	//�p�X�L�����͒l
	int num = 0;

	//�^�[���Ǘ��p�ϐ�(�������)
	turn = BLACK_STONE;

	//�I���t���O
	int game_end = 60;

	//���[�v�I������:�I���t���O�������Ă��Ȃ��Ƃ�
	while (game_end != 0)
	{
		//���΂̃^�[���̂Ƃ�
		if (turn == BLACK_STONE)
		{
			//�p�X�̗L������
			ps = pass_check(b);
			
			//�p�X����
			if (ps == 1)
			{
				printf("���ސ΂�����܂���B�p�X(0:���Ȃ��A1:����)���܂����H\n");
				num = number_input();

				//�p�X����ꍇ
				if (num == 1)
				{
					turn = WHITE_STONE;
				}
				//�p�X���Ȃ��ꍇ
				else if(num == 0)
				{
					//�΂̔z�u
					turn = stone_set(b, BLACK_STONE, WHITE_STONE);
				}
				//���͒l��0��1�ȊO�������Ƃ�
				else
				{
					printf("0��1����͂��ĉ������B\n");
				}

			}
			//�p�X�̂Ȃ��ꍇ
			else
			{
				//�΂̔z�u
				turn = stone_set(b, BLACK_STONE, WHITE_STONE);
			}
		}
		//���΂̃^�[���̂Ƃ�
		else
		{
			//���΂Ƀ^�[����n��
			turn = BLACK_STONE;
		}
	}
}