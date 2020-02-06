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
				ps = ps + stone_rolling(b, h, w, 0);
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
	//�^�[����Ԃ�
	int ac_turn = 0;
	
	//�p�X�L�����͒l
	int num = 0;

	//�΂̔z�u�ʒu���͒l
	int width = 0;
	int height = 0;

	/* 5.�΂̔z�u�ʒu�̓��� */
	//�΂̔z�u�ʒu�̓���
	if (message_flag == 0)
	{
		printf("�΂̈ʒu����͂��ĉ������B\n");

		//����^�[����2��ȏ�\�����Ȃ�
		message_flag = 1;
	}
	else
	{
		;
	}
	printf("��:");
	width = number_input();
	printf("�c:");
	height = number_input();

	//���͒l�̗L������
	//�Ֆʂ͈̔͊O�̂Ƃ�
	if(width < 0 || 7 < width || height < 0 || 7 < height)
	{
		/* 6.�΂̃G���[���b�Z�[�W�\�� */
		printf("�Ֆʂ͈̔͊O�ł��A�Ⴄ�ꏊ���w�肵�Ă��������B\n");
		
		//�^�[����n���Ȃ�
		ac_turn = active_turn;
	}
	else
	{
		//�΂��z�u�ς݂̂Ƃ�
		if (*(b + (height * HEIGHT) + width) != 0)
		{
			/* 6.�΂̃G���[���b�Z�[�W�\�� */
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

				/* 7.�΂̎������] */
				//���]����
				stone_rolling(b, height, width, 1);
			
				//�^�[����n��
				ac_turn = not_active_turn;
				
				/* 10.���]��̔Ֆʕ\�� */
				//�Ֆʂ�\������
				printBoard(b, 64);

				//���b�Z�[�W�\���t���O�̉���
				message_flag = 0;
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
					if (num == 1)
					{
						//�΂�z�u�ł���ꏊ������Ƃ�
						if (0 < pass_check(b))
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

							//�Ֆʂ�\������
							//printBoard(b, 64);

							//�p�X�t���O�𗧂Ă�
							pass_flag++;

							//���b�Z�[�W�\���t���O�̉���
							message_flag = 0;
						}
					}
					//�p�X���Ȃ��ꍇ
					else if (num == 0)
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
				} while (num != 0 && num != 1);
			}
		}
	}
	

	//�ǂ��炩�̃^�[����Ԃ�
	return ac_turn;
}