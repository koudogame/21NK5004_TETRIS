#pragma once
#ifndef __MINO_H__ // �C���N���[�h�K�[�h
#define __MINO_H__


//*****************************************************************************
//  Include
//*****************************************************************************
#include "board.h"


//*****************************************************************************
//  Class
//*****************************************************************************
class Mino
{
private:
    int x_, y_;        // �e�g���~�m�̓Y����([ y ][ x ])
    int texture_;      // �O���t�B�b�N�n���h��
    int fall_counter_; // �����J�E���^�[
    int Tetris_[ 4 ][ 4 ];
    int tetris_color_;//�e�g���X�J���[�irand�̎󂯎��j
    int rand_;
    int tetris_shape_;
    int i ;
    int j ;

public:
    Mino();        // �R���X�g���N�^
    ~Mino();       // �f�X�g���N�^

    bool init();    // ������
    bool update( Board* pBoard );  // �X�V
    void draw();    // �`��
    void destroy(); // �j��
};

#endif