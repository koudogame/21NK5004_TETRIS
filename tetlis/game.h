#pragma once

#ifndef __GAME_H__ // �C���N���[�h�K�[�h
#define __GAME_H__


//*****************************************************************************
//  Include
//*****************************************************************************
#include "mino.h"
#include "field.h"
#include "board.h"


//*****************************************************************************
//  Class
//*****************************************************************************
class Game
{
private:
    Mino  mino_;  // �e�g���~�m�N���X
    Field field_; // �t�B�[���h�N���X
    Board board_; // �ՖʃN���X

public:
    Game();        // �R���X�g���N�^
    ~Game();       // �f�X�g���N�^

    bool init();    // ������
    bool update();  // �X�V
    void draw();    // �`��
    void destroy(); // �j��
};

#endif
