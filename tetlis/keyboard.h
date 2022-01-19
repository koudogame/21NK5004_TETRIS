#pragma once
#ifndef __KEYBOARD_H__ // �C���N���[�h�K�[�h
#define __KEYBOARD_H__


//*****************************************************************************
//  Input
//*****************************************************************************
#include "DxLib.h"


//*****************************************************************************
//  Constant
//*****************************************************************************
// �L�[�Ċ��蓖��(4Byte�^�Ȃ̂ōő�32�� �g����������`)
constexpr unsigned int kSpace = 1;                // �X�y�[�X
constexpr unsigned int kEnter = kSpace << 1; // �G���^�[
constexpr unsigned int kUpArrow = kEnter << 1; // ��
constexpr unsigned int kDownArrow = kUpArrow << 1; // ��
constexpr unsigned int kLeftArrow = kDownArrow << 1; // ��
constexpr unsigned int kRightArrow = kLeftArrow << 1; // ��
constexpr unsigned int kZKey = kRightArrow << 1; // Z�L�[


//*****************************************************************************
//  Class
//*****************************************************************************
class Keyboard
{
private:
    static unsigned int held_;      // ������Ă���L�[�t���O
    static unsigned int pressed_;   // �����ꂽ�L�[�t���O
    static unsigned int save_flag_; // �O�񉟂���Ă������L������t���O

    // �P�������͂��擾����
    static void isPressed( const int DxKey, const unsigned int keyFlag );

public:
    static void update(); // �X�V

    // ���̓t���O��Ԃ�
    static unsigned int getHeld() { return held_; }
    static unsigned int getPressed() { return pressed_; }
};

#endif