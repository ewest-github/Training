#pragma once
#ifndef _FUNCTION_H_

//�Q�[���J�n���̃��b�Z�[�W��\������֐�
void game_start();

//�Q�[����i�s����֐�
void game_progress(int* b);

//�p�X�̗L�����`�F�b�N����֐�(����:�Ֆʂ̏��,�A�N�e�B�u�v���C���[�̐�,��A�N�e�B�u�v���C���[�̐�)
void pass_check(int* b, int x, int y);

//�΂̔��]�ۂ𔻒肷��֐�
int stone_rolling(int* b, int h, int w);

#endif // !_FUNCTION_H_