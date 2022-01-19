#pragma once
#ifndef __BOARD_H__ // �C���N���[�h�K�[�h
#define __BOARD_H__


//*****************************************************************************
//  Constant
//*****************************************************************************
#include "Common.h"


//*****************************************************************************
//  Constant
//*****************************************************************************
constexpr int kBoardWidth = 10; // ���̃}�X��
constexpr int kBoardHeight = 22; // �c�̃}�X��(1�}�X�]���Ɋm��)
constexpr int kMinoSize = 25; // �~�m�̃T�C�Y

// �u���b�N�̕`��J�n��_
constexpr int kSrcX = 688;
constexpr int kSrcY = 957;

// �Q�[���G���A�����_
constexpr int kReferencePointX = 511;
constexpr int kReferencePointY = 173;


//*****************************************************************************
//  Enum
//*****************************************************************************
enum
{
    kNone = -1, // �����Ȃ�
    kLightBlue, // ���F
    kOrange,    // ��
    kGreen,     // ��
    kRed,       // ��
    kBlue,      // ��
    kBrown,     // ��
    kPurple,    // ��
    kGray,      // �D
    kLock       // ���b�N�}�X
};


//*****************************************************************************
//  Class
//*****************************************************************************
class Board
{
private:
    int texture_; // �O���t�B�b�N�n���h��
    int board_[ kBoardHeight ][ kBoardWidth ]; // �Q�[���G���A
    int mino_cnt_;
    int width;
public:
    bool init(); // ������
    void draw(); // �`��
    void destroy() { SAFE_DELETE_GRAPH( texture_ ); } // �j��
    void update();

    // �w��v�f�̃f�[�^���擾/�ݒ�
    int getMass( const int X, const int Y ) { return board_[ Y ][ X ]; }
    void setMass( const int X, const int Y, const int Value ) { board_[ Y ][ X ] = Value; }
};

#endif