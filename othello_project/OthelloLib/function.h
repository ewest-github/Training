#pragma once
#ifndef _FUNCTION_H_

//�Q�[���J�n���̃��b�Z�[�W��\������֐�
void game_start();

//�Q�[����i�s����֐�
void game_progress(int* b);

//�p�X�̗L�����`�F�b�N����֐�
void pass_check(int* b, int x, int y);

//�΂̔��]�ۂ𔻒肷��֐�
void stone_rolling(int* b, int x, int y);

#endif // !_FUNCTION_H_