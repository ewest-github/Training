#include<stdio.h>
#include<stdlib.h>

#include "OthelloLib.h"
#include "function.h"

//�΂̔��]
int stone_rolling(int* b, int h, int w)
{
	//�T���ʒu�̍��W
	int h1 = 0;
	int w1 = 0;

	//�z�u�\�Ȑ΂̐�
	int s = 0;

	//�T�������̃|�C���^
	POINT* p;

	//�������u���b�N�̊m��
	p = (POINT*)malloc(sizeof(POINT) * 8);

	//�T�������̐ݒ�
	setDirection(p, 8);

	//���[�v�I������:�S�����T������������܂�
	for (int f = 0; f < DIRECTION_INDEX::NUM; f++)
	{
		//�T���ʒu�̏�����
		h1 = h;
		w1 = w;

		//1�������T��
		switch (f)
		{
		//������
		case 0:
			//�}�X���[�̂Ƃ�
			if (w == 0)
			{
				;
			}
			else
			{
				while (w1 != 0 && *(b + ((h1 + p[DIRECTION_INDEX::LEFT].y) * HEIGHT) + w1 + p[DIRECTION_INDEX::LEFT].x) != NONE_PLAY && *(b + ((h + p[DIRECTION_INDEX::LEFT].y) * HEIGHT) + w + p[DIRECTION_INDEX::LEFT].x) != turn)
				{
					/*
					//�ړ��I���̔���(�Ֆʒ[�܂œ��B)
					if (w1 == 0)
					{
						break;
					}
					//�ړ��I���̔���(�Ζ��z�u�̃}�X�܂œ��B)
					else if (*(b + ((h1 + p[DIRECTION_INDEX::LEFT].y) * HEIGHT) + w1 + p[DIRECTION_INDEX::LEFT].x) == 0)
					{
						break;
					}
					//�ړ��I���̔���(�ׂ������F�̃R�})
					else if (*(b + (h * HEIGHT) + w) == *(b + ((h + p[DIRECTION_INDEX::LEFT].y) * HEIGHT) + w + p[DIRECTION_INDEX::LEFT].x))
					{
						break;
					}
					*/

					//���W�̈ړ�
					h1 = h1 + p[DIRECTION_INDEX::LEFT].y;
					w1 = w1 + p[DIRECTION_INDEX::LEFT].x;
					//*(b + ((h1 + p[DIRECTION_INDEX::LEFT].y) * HEIGHT) + w1 + p[DIRECTION_INDEX::LEFT].x);
				}
			}
			break;
		case 1:
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			break;
		case 6:
			break;
		case 7:
			break;
		default:
			break;
		}
	}

	return s;
}