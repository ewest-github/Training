#include<stdio.h>
#include<stdlib.h>

#include "OthelloLib.h"
#include "function.h"

//�A�N�e�B�u�^�[��
extern int turn;

//�΂̔��]
int stone_rolling(int* b, int h, int w, int m)
{
	//�T���ʒu�̍��W
	int h1 = 0;
	int w1 = 0;

	//�΂̐ݒu�\�t���O
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
		case DIRECTION_INDEX::LEFT:
			//�}�X���[�̂Ƃ�
			if (w == BOARD_LINE_INDEX_1)
			{
				;
			}
			else
			{
				//���[�v�I������:�����[�ł͂Ȃ��A�T�������̃}�X�����z�u�ł͂Ȃ��A�T�������̃}�X�������F�̐΂ɂȂ�Ȃ�
				while (w1 != BOARD_LINE_INDEX_1 &&
					*(b + ((h1 + p[DIRECTION_INDEX::LEFT].y) * HEIGHT) + w1 + p[DIRECTION_INDEX::LEFT].x) != NONE_PLAY &&
					*(b + ((h + p[DIRECTION_INDEX::LEFT].y) * HEIGHT) + w + p[DIRECTION_INDEX::LEFT].x) != turn)
				{
					//���W�̈ړ�
					h1 = h1 + p[DIRECTION_INDEX::LEFT].y;
					w1 = w1 + p[DIRECTION_INDEX::LEFT].x;

					//�[�łȂ��Ƃ�
					if (w1 != BOARD_LINE_INDEX_1)
					{
						//�����F�̐΂����������Ƃ�
						if (*(b + ((h1 + p[DIRECTION_INDEX::LEFT].y) * HEIGHT) + w1 + p[DIRECTION_INDEX::LEFT].x) == turn)
						{
							//�����Ŗ߂�l�𕪂��ċ@�\�؂�ւ�����
							//�΂̔z�u�\�t���O��߂��Ƃ�
							if (m == 0)
							{
								//�Δz�u�\�t���O�𗧂Ă�
								s = 1;
							}
							//���]������s��
							else if (m == 1)
							{
								//�z�u�ʒu�܂Ő΂𔽓]�����Ƃ�
								while (h != h1 || w != w1)
								{
									//�v���C���[�^�[���̐΂ɕύX����
									*(b + (h1 * HEIGHT) + w1) = turn;

									//���W�̈ړ�(�z�u�ʒu�Ɍ�����)
									h1 = h1 - p[DIRECTION_INDEX::LEFT].y;
									w1 = w1 - p[DIRECTION_INDEX::LEFT].x;
								}
							}
							else
							{
								;
							}

							//���[�v�𔲂���
							break;
						}
						else
						{
							;
						}
					}
					//�[�̂Ƃ�
					else
					{
						;
					}
				}
			}
			break;
		//��������
		case DIRECTION_INDEX::LEFT_BOTTOM:
			//�}�X�����[�̂Ƃ�
			if (w == BOARD_LINE_INDEX_1)
			{
				;
			}
			//�}�X���ŉ��i�̂Ƃ�
			else if (h == BOARD_LINE_INDEX_8)
			{
				;
			}
			else
			{
				//���[�v�I������:�����[�ł͂Ȃ��A�c���[�ł͂Ȃ��A�T�������̃}�X�����z�u�ł͂Ȃ��A�T�������̃}�X�������F�̐΂ɂȂ�Ȃ�
				while (w1 != BOARD_LINE_INDEX_1 &&
					h1 != BOARD_LINE_INDEX_8 &&
					*(b + ((h1 + p[DIRECTION_INDEX::LEFT_BOTTOM].y) * HEIGHT) + w1 + p[DIRECTION_INDEX::LEFT_BOTTOM].x) != NONE_PLAY &&
					*(b + ((h + p[DIRECTION_INDEX::LEFT_BOTTOM].y) * HEIGHT) + w + p[DIRECTION_INDEX::LEFT_BOTTOM].x) != turn)
				{
					//���W�̈ړ�
					h1 = h1 + p[DIRECTION_INDEX::LEFT_BOTTOM].y;
					w1 = w1 + p[DIRECTION_INDEX::LEFT_BOTTOM].x;

					//�[�łȂ��Ƃ�
					if (w1 != BOARD_LINE_INDEX_1 && h1 != BOARD_LINE_INDEX_8)
					{
						//�����F�̐΂����������Ƃ�
						if (*(b + ((h1 + p[DIRECTION_INDEX::LEFT_BOTTOM].y) * HEIGHT) + w1 + p[DIRECTION_INDEX::LEFT_BOTTOM].x) == turn)
						{
							//�����Ŗ߂�l�𕪂��ċ@�\�؂�ւ�����
							//�΂̔z�u�\�t���O��߂��Ƃ�
							if (m == 0)
							{
								//�Δz�u�\�t���O�𗧂Ă�
								s = 1;
							}
							//���]������s��
							else if (m == 1)
							{
								//�z�u�ʒu�܂Ő΂𔽓]�����Ƃ�
								while (h != h1 || w != w1)
								{
									//�v���C���[�^�[���̐΂ɕύX����
									*(b + (h1 * HEIGHT) + w1) = turn;

									//���W�̈ړ�(�z�u�ʒu�Ɍ�����)
									h1 = h1 - p[DIRECTION_INDEX::LEFT_BOTTOM].y;
									w1 = w1 - p[DIRECTION_INDEX::LEFT_BOTTOM].x;
								}
							}
							else
							{
								;
							}

							//���[�v�𔲂���
							break;
						}
						else
						{
							;
						}
					}
					//�[�̂Ƃ�
					else
					{
						;
					}
				}
			}
			break;
		//������
		case DIRECTION_INDEX::BOTTOM:
			//�}�X���ŉ��i�̂Ƃ�
			if (h == BOARD_LINE_INDEX_8)
			{
				;
			}
			else
			{
				//���[�v�I������:�c���[�ł͂Ȃ��A�T�������̃}�X�����z�u�ł͂Ȃ��A�T�������̃}�X�������F�̐΂ɂȂ�Ȃ�
				while (h1 != BOARD_LINE_INDEX_8 &&
					*(b + ((h1 + p[DIRECTION_INDEX::BOTTOM].y) * HEIGHT) + w1 + p[DIRECTION_INDEX::BOTTOM].x) != NONE_PLAY &&
					*(b + ((h + p[DIRECTION_INDEX::BOTTOM].y) * HEIGHT) + w + p[DIRECTION_INDEX::BOTTOM].x) != turn)
				{
					//���W�̈ړ�
					h1 = h1 + p[DIRECTION_INDEX::BOTTOM].y;
					w1 = w1 + p[DIRECTION_INDEX::BOTTOM].x;

					//�[�łȂ��Ƃ�
					if (h1 != BOARD_LINE_INDEX_8)
					{
						//�����F�̐΂����������Ƃ�
						if (*(b + ((h1 + p[DIRECTION_INDEX::BOTTOM].y) * HEIGHT) + w1 + p[DIRECTION_INDEX::BOTTOM].x) == turn)
						{
							//�����Ŗ߂�l�𕪂��ċ@�\�؂�ւ�����
							//�΂̔z�u�\�t���O��߂��Ƃ�
							if (m == 0)
							{
								//�Δz�u�\�t���O�𗧂Ă�
								s = 1;
							}
							//���]������s��
							else if (m == 1)
							{
								//�z�u�ʒu�܂Ő΂𔽓]�����Ƃ�
								while (h != h1 || w != w1)
								{
									//�v���C���[�^�[���̐΂ɕύX����
									*(b + (h1 * HEIGHT) + w1) = turn;

									//���W�̈ړ�(�z�u�ʒu�Ɍ�����)
									h1 = h1 - p[DIRECTION_INDEX::BOTTOM].y;
									w1 = w1 - p[DIRECTION_INDEX::BOTTOM].x;
								}
							}
							else
							{
								;
							}

							//���[�v�𔲂���
							break;
						}
						else
						{
							;
						}
					}
					//�[�̂Ƃ�
					else
					{
						;
					}
				}
			}
			break;
		//�E������
		case DIRECTION_INDEX::RIGHT_BOTTOM:
			//�}�X���E�[�̂Ƃ�
			if (w == BOARD_LINE_INDEX_8)
			{
				;
			}
			//�}�X���ŉ��i�̂Ƃ�
			else if (h == BOARD_LINE_INDEX_8)
			{
				;
			}
			else
			{
				//���[�v�I������:�����[�ł͂Ȃ��A�c���[�ł͂Ȃ��A�T�������̃}�X�����z�u�ł͂Ȃ��A�T�������̃}�X�������F�̐΂ɂȂ�Ȃ�
				while (w1 != BOARD_LINE_INDEX_8 &&
					h1 != BOARD_LINE_INDEX_8 &&
					*(b + ((h1 + p[DIRECTION_INDEX::RIGHT_BOTTOM].y) * HEIGHT) + w1 + p[DIRECTION_INDEX::RIGHT_BOTTOM].x) != NONE_PLAY &&
					*(b + ((h + p[DIRECTION_INDEX::RIGHT_BOTTOM].y) * HEIGHT) + w + p[DIRECTION_INDEX::RIGHT_BOTTOM].x) != turn)
				{
					//���W�̈ړ�
					h1 = h1 + p[DIRECTION_INDEX::RIGHT_BOTTOM].y;
					w1 = w1 + p[DIRECTION_INDEX::RIGHT_BOTTOM].x;

					//�[�łȂ��Ƃ�
					if (w1 != BOARD_LINE_INDEX_8 && h1 != BOARD_LINE_INDEX_8)
					{
						//�����F�̐΂����������Ƃ�
						if (*(b + ((h1 + p[DIRECTION_INDEX::RIGHT_BOTTOM].y) * HEIGHT) + w1 + p[DIRECTION_INDEX::RIGHT_BOTTOM].x) == turn)
						{
							//�����Ŗ߂�l�𕪂��ċ@�\�؂�ւ�����
							//�΂̔z�u�\�t���O��߂��Ƃ�
							if (m == 0)
							{
								//�Δz�u�\�t���O�𗧂Ă�
								s = 1;
							}
							//���]������s��
							else if (m == 1)
							{
								//�z�u�ʒu�܂Ő΂𔽓]�����Ƃ�
								while (h != h1 || w != w1)
								{
									//�v���C���[�^�[���̐΂ɕύX����
									*(b + (h1 * HEIGHT) + w1) = turn;

									//���W�̈ړ�(�z�u�ʒu�Ɍ�����)
									h1 = h1 - p[DIRECTION_INDEX::RIGHT_BOTTOM].y;
									w1 = w1 - p[DIRECTION_INDEX::RIGHT_BOTTOM].x;
								}
							}
							else
							{
								;
							}

							//���[�v�𔲂���
							break;
						}
						else
						{
							;
						}
					}
					//�[�̂Ƃ�
					else
					{
						;
					}
				}
			}
			break;
		//�E����
		case DIRECTION_INDEX::RIGHT:
			//�}�X�E�[�̂Ƃ�
			if (w == BOARD_LINE_INDEX_8)
			{
				;
			}
			else
			{
				//���[�v�I������:�����[�ł͂Ȃ��A�T�������̃}�X�����z�u�ł͂Ȃ��A�T�������̃}�X�������F�̐΂ɂȂ�Ȃ�
				while (w1 != BOARD_LINE_INDEX_8 &&
					*(b + ((h1 + p[DIRECTION_INDEX::RIGHT].y) * HEIGHT) + w1 + p[DIRECTION_INDEX::RIGHT].x) != NONE_PLAY &&
					*(b + ((h + p[DIRECTION_INDEX::RIGHT].y) * HEIGHT) + w + p[DIRECTION_INDEX::RIGHT].x) != turn)
				{
					//���W�̈ړ�
					h1 = h1 + p[DIRECTION_INDEX::RIGHT].y;
					w1 = w1 + p[DIRECTION_INDEX::RIGHT].x;

					//�[�łȂ��Ƃ�
					if (w1 != BOARD_LINE_INDEX_8)
					{
						//�����F�̐΂����������Ƃ�
						if (*(b + ((h1 + p[DIRECTION_INDEX::RIGHT].y) * HEIGHT) + w1 + p[DIRECTION_INDEX::RIGHT].x) == turn)
						{
							//�����Ŗ߂�l�𕪂��ċ@�\�؂�ւ�����
							//�΂̔z�u�\�t���O��߂��Ƃ�
							if (m == 0)
							{
								//�Δz�u�\�t���O�𗧂Ă�
								s = 1;
							}
							//���]������s��
							else if (m == 1)
							{
								//�z�u�ʒu�܂Ő΂𔽓]�����Ƃ�
								while (h != h1 || w != w1)
								{
									//�v���C���[�^�[���̐΂ɕύX����
									*(b + (h1 * HEIGHT) + w1) = turn;

									//���W�̈ړ�(�z�u�ʒu�Ɍ�����)
									h1 = h1 - p[DIRECTION_INDEX::RIGHT].y;
									w1 = w1 - p[DIRECTION_INDEX::RIGHT].x;
								}
							}
							else
							{
								;
							}

							//���[�v�𔲂���
							break;
						}
						else
						{
							;
						}
					}
					//�[�̂Ƃ�
					else
					{
						;
					}
				}
			}
			break;
		//�E�����
		case DIRECTION_INDEX::RIGHT_TOP:
			//�}�X���E�[�̂Ƃ�
			if (w == BOARD_LINE_INDEX_8)
			{
				;
			}
			//�}�X���ŏ�i�̂Ƃ�
			else if (h == BOARD_LINE_INDEX_1)
			{
				;
			}
			else
			{
				//���[�v�I������:�����[�ł͂Ȃ��A�c���[�ł͂Ȃ��A�T�������̃}�X�����z�u�ł͂Ȃ��A�T�������̃}�X�������F�̐΂ɂȂ�Ȃ�
				while (w1 != BOARD_LINE_INDEX_8 &&
					h1 != BOARD_LINE_INDEX_1 &&
					*(b + ((h1 + p[DIRECTION_INDEX::RIGHT_TOP].y) * HEIGHT) + w1 + p[DIRECTION_INDEX::RIGHT_TOP].x) != NONE_PLAY &&
					*(b + ((h + p[DIRECTION_INDEX::RIGHT_TOP].y) * HEIGHT) + w + p[DIRECTION_INDEX::RIGHT_TOP].x) != turn)
				{
					//���W�̈ړ�
					h1 = h1 + p[DIRECTION_INDEX::RIGHT_TOP].y;
					w1 = w1 + p[DIRECTION_INDEX::RIGHT_TOP].x;

					//�[�łȂ��Ƃ�
					if (w1 != BOARD_LINE_INDEX_8 && h1 != BOARD_LINE_INDEX_1)
					{
						//�����F�̐΂����������Ƃ�
						if (*(b + ((h1 + p[DIRECTION_INDEX::RIGHT_TOP].y) * HEIGHT) + w1 + p[DIRECTION_INDEX::RIGHT_TOP].x) == turn)
						{
							//�����Ŗ߂�l�𕪂��ċ@�\�؂�ւ�����
							//�΂̔z�u�\�t���O��߂��Ƃ�
							if (m == 0)
							{
								//�Δz�u�\�t���O�𗧂Ă�
								s = 1;
							}
							//���]������s��
							else if (m == 1)
							{
								//�z�u�ʒu�܂Ő΂𔽓]�����Ƃ�
								while (h != h1 || w != w1)
								{
									//�v���C���[�^�[���̐΂ɕύX����
									*(b + (h1 * HEIGHT) + w1) = turn;

									//���W�̈ړ�(�z�u�ʒu�Ɍ�����)
									h1 = h1 - p[DIRECTION_INDEX::RIGHT_TOP].y;
									w1 = w1 - p[DIRECTION_INDEX::RIGHT_TOP].x;
								}
							}
							else
							{
								;
							}

							//���[�v�𔲂���
							break;
						}
						else
						{
							;
						}
					}
					//�[�̂Ƃ�
					else
					{
						;
					}
				}
			}
			break;
		//�����
		case DIRECTION_INDEX::TOP:
			//�}�X���ŏ�i�̂Ƃ�
			if (h == BOARD_LINE_INDEX_1)
			{
				;
			}
			else
			{
				//���[�v�I������:�c���[�ł͂Ȃ��A�T�������̃}�X�����z�u�ł͂Ȃ��A�T�������̃}�X�������F�̐΂ɂȂ�Ȃ�
				while (h1 != BOARD_LINE_INDEX_1 &&
					*(b + ((h1 + p[DIRECTION_INDEX::TOP].y) * HEIGHT) + w1 + p[DIRECTION_INDEX::TOP].x) != NONE_PLAY &&
					*(b + ((h + p[DIRECTION_INDEX::TOP].y) * HEIGHT) + w + p[DIRECTION_INDEX::TOP].x) != turn)
				{
					//���W�̈ړ�
					h1 = h1 + p[DIRECTION_INDEX::TOP].y;
					w1 = w1 + p[DIRECTION_INDEX::TOP].x;

					//�[�łȂ��Ƃ�
					if (h1 != BOARD_LINE_INDEX_1)
					{
						//�����F�̐΂����������Ƃ�
						if (*(b + ((h1 + p[DIRECTION_INDEX::TOP].y) * HEIGHT) + w1 + p[DIRECTION_INDEX::TOP].x) == turn)
						{
							//�����Ŗ߂�l�𕪂��ċ@�\�؂�ւ�����
							//�΂̔z�u�\�t���O��߂��Ƃ�
							if (m == 0)
							{
								//�Δz�u�\�t���O�𗧂Ă�
								s = 1;
							}
							//���]������s��
							else if (m == 1)
							{
								//�z�u�ʒu�܂Ő΂𔽓]�����Ƃ�
								while (h != h1 || w != w1)
								{
									//�v���C���[�^�[���̐΂ɕύX����
									*(b + (h1 * HEIGHT) + w1) = turn;

									//���W�̈ړ�(�z�u�ʒu�Ɍ�����)
									h1 = h1 - p[DIRECTION_INDEX::TOP].y;
									w1 = w1 - p[DIRECTION_INDEX::TOP].x;
								}
							}
							else
							{
								;
							}

							//���[�v�𔲂���
							break;
						}
						else
						{
							;
						}
					}
					//�[�̂Ƃ�
					else
					{
						;
					}
				}
			}
			break;
		//�������
		case DIRECTION_INDEX::LEFT_TOP:
			//�}�X�����[�̂Ƃ�
			if (w == BOARD_LINE_INDEX_1)
			{
				;
			}
			//�}�X���ŏ�i�̂Ƃ�
			else if (h == BOARD_LINE_INDEX_1)
			{
				;
			}
			else
			{
				//���[�v�I������:�����[�ł͂Ȃ��A�c���[�ł͂Ȃ��A�T�������̃}�X�����z�u�ł͂Ȃ��A�T�������̃}�X�������F�̐΂ɂȂ�Ȃ�
				while (w1 != BOARD_LINE_INDEX_1 &&
					h1 != BOARD_LINE_INDEX_1 &&
					*(b + ((h1 + p[DIRECTION_INDEX::LEFT_TOP].y) * HEIGHT) + w1 + p[DIRECTION_INDEX::LEFT_TOP].x) != NONE_PLAY &&
					*(b + ((h + p[DIRECTION_INDEX::LEFT_TOP].y) * HEIGHT) + w + p[DIRECTION_INDEX::LEFT_TOP].x) != turn)
				{
					//���W�̈ړ�
					h1 = h1 + p[DIRECTION_INDEX::LEFT_TOP].y;
					w1 = w1 + p[DIRECTION_INDEX::LEFT_TOP].x;

					//�[�łȂ��Ƃ�
					if (w1 != BOARD_LINE_INDEX_1 && h1 != BOARD_LINE_INDEX_1)
					{
						//�����F�̐΂����������Ƃ�
						if (*(b + ((h1 + p[DIRECTION_INDEX::LEFT_TOP].y) * HEIGHT) + w1 + p[DIRECTION_INDEX::LEFT_TOP].x) == turn)
						{
							//�����Ŗ߂�l�𕪂��ċ@�\�؂�ւ�����
							//�΂̔z�u�\�t���O��߂��Ƃ�
							if (m == 0)
							{
								//�Δz�u�\�t���O�𗧂Ă�
								s = 1;
							}
							//���]������s��
							else if (m == 1)
							{
								//�z�u�ʒu�܂Ő΂𔽓]�����Ƃ�
								while (h != h1 || w != w1)
								{
									//�v���C���[�^�[���̐΂ɕύX����
									*(b + (h1 * HEIGHT) + w1) = turn;

									//���W�̈ړ�(�z�u�ʒu�Ɍ�����)
									h1 = h1 - p[DIRECTION_INDEX::LEFT_TOP].y;
									w1 = w1 - p[DIRECTION_INDEX::LEFT_TOP].x;
								}
							}
							else
							{
								;
							}

							//���[�v�𔲂���
							break;
						}
						else
						{
							;
						}
					}
					//�[�̂Ƃ�
					else
					{
						;
					}
				}
			}
			break;
		default:
			break;
		}
	}

	free(p);

	return s;
}