#include<stdio.h>

#include "OthelloLib.h"
#include "function.h"

void pass_check(int* b, int x, int y)
{
	//���[�v�I������:�S�Ẵ}�X���`�F�b�N����܂�
	while (x != 0)
	{
		//���[�v�I������:�c�̑S�Ẵ}�X���`�F�b�N����܂�
		for (int h = 0; h < HEIGHT; h++)
		{
			//���[�v�I������:���̑S�Ẵ}�X���`�F�b�N����܂�
			for (int w = 0; w < WIDTH; w++)
			{
				//�Y���}�X���R�}���z�u�̂Ƃ�
				if (*(b + (h * HEIGHT) + w) == 0)
				{
					stone_rolling(b, x, y);
				}
				//�Y���}�X���R�}�z�u�ς݂̏ꍇ
				else
				{
					;
				}
			}
		}
	}
}