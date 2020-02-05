#include<stdio.h>
#include<stdlib.h>

#include "OthelloLib.h"
#include "function.h"

int pass_check(int* b)
{
	//�p�X�t���O
	int ps = 0;

	//���[�v�I������:�c�̑S�Ẵ}�X���`�F�b�N����܂�
	for (int h = 0; h < HEIGHT; h++)
	{
		//���[�v�I������:���̑S�Ẵ}�X���`�F�b�N����܂�
		for (int w = 0; w < WIDTH; w++)
		{
			//�Y���}�X���R�}���z�u�̂Ƃ�
			if (*(b + (h * HEIGHT) + w) == 0)
			{
				ps = stone_rolling(b, h, w, 0);
			}
			//�Y���}�X���R�}�z�u�ς݂̏ꍇ
			else
			{
				;
			}
		}
	}

	return ps;
}

int number_input()
{
	char ss[10];
	int num = 0;

	gets_s(ss);
	num = atoi(ss);

	return num;
}

int stone_set(int* b, int active_turn, int not_active_turn)
{
	//�^�[���̊Ǘ�
	int ac_turn = 0;

	//�΂̔z�u�ʒu���͒l
	int width = 0;
	int height = 0;

	//�΂̔z�u�ʒu�̓���
	printf("�΂̈ʒu����͂��ĉ������B\n");
	printf("��:");
	width = number_input();
	printf("�c:");
	height = number_input();

	//���͒l�̗L������
	//�΂��z�u�ł��Ȃ��Ƃ�
	if (*(b + (height * HEIGHT) + width) != 0)
	{
		printf("���ɐ΂�z�u�ς݂Ȃ̂ŁA�Ⴄ�ꏊ���w�肵�Ă��������B\n");

		//�^�[����n���Ȃ�
		ac_turn = active_turn;
	}
	else
	{
		//�΂��z�u�\�ȂƂ�
		if (stone_rolling(b, height, width, 0) == 1)
		{
			//�΂̔z�u����
			*(b + (height * HEIGHT) + width) = active_turn;

			//���]����
			
			//�^�[����n��
			ac_turn = not_active_turn;
		}
		//�΂��z�u�ł��Ȃ��Ƃ�
		else
		{
			printf("���߂�΂�����܂���B\n");

			//�^�[����n���Ȃ�
			ac_turn = active_turn;
		}
	}

	//�ǂ��炩�̃^�[����Ԃ�
	return ac_turn;
}