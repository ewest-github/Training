#pragma once
#ifndef _FUNCTION_H_

//�Q�[���J�n���̃��b�Z�[�W��\������֐�
void game_start();

//�Q�[����i�s����֐�
void game_progress(int* b);

//�p�X�̗L�����`�F�b�N����֐�(����:�Ֆʂ̏��)
int pass_check(int* b);

//�΂̔��]�ۂ𔻒肷��֐�(����:�Ֆʂ̏��A�c�̍��W�A���̍��W)
int stone_rolling(int* b, int h, int w, int m);

//�΂�z�u����֐�
int stone_set(int* b, int active_turn, int not_active_turn);

//�l����͂���֐�
int number_input();


//�^�[�����Ǘ�����ϐ�
int turn;


#endif // !_FUNCTION_H_