#include<stdio.h>

#include "OthelloLib.h"
#include "function.h"

void game_progress(int* b, int x)
{
	//�^�[���Ǘ��p�ϐ�(�������)
	int turn = BLACK_STONE;

	//�I���t���O
	int game_end = 62;

	//���[�v�I������:�I���t���O�������Ă��Ȃ��Ƃ�
	while (game_end != 0)
	{
		//���΂̃^�[���̂Ƃ�
		if (turn == BLACK_STONE)
		{
			//�p�X�̗L������
			pass_check(b, BLACK_STONE, WHITE_STONE);

			//���΂Ƀ^�[����n��
			turn = WHITE_STONE;
		}
		//���΂̃^�[���̂Ƃ�
		else
		{
			//���΂Ƀ^�[����n��
			turn = BLACK_STONE;
		}
	}
}