#pragma once
#ifndef _FUNCTION_H_

//�Q�[���J�n���̃��b�Z�[�W��\������֐�
void game_start();

//�Q�[����i�s����֐�
int game_progress(int* board, int level);

//�p�X�̗L�����`�F�b�N����֐�(����:�Ֆʂ̏��)
int pass_check(int* board);

//�Δz�u�\�ȍ��W���擾����֐�
void position_check(int* board, POINT* stone_position);

//�΂̔��]�ۂ𔻒肷��֐�(����:�Ֆʂ̏��A�c�̍��W�A���̍��W�A�@�\�����铮��)
int stone_rolling(int* board, POINT COORDINATE, int mode);

//�΂�z�u����֐�
int stone_set(int* board, int active_turn, int not_active_turn);

//���x���ݒ�Ŕz�u�`����ύX����֐�
int CPU_level(POINT* stone_position, int set_count, int level);

//�l����͂���֐�
int number_input();

/** @def
 * ���b�Z�[�W�\���O
 */
#define NON_DISPLAY 0

 /** @def
  * ���b�Z�[�W�\����
  */
#define DISPLAY 1

  /** @def
   * �Δz�u�\
   */
#define STONE_SET_ENABLE 1

   /** @def
    * �Δz�u�s�\
    */
#define STONE_SET_DISABLE 0

    /** @def
     * �Δz�u�ۃ��[�h
     */
#define MODE_STONE_SET_CHECK 0

     /** @def
      * �Δ��]���[�h
      */
#define MODE_STONE_INVERSION 1


#endif // !_FUNCTION_H_