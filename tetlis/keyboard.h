#pragma once
#ifndef __KEYBOARD_H__ // インクルードガード
#define __KEYBOARD_H__


//*****************************************************************************
//  Input
//*****************************************************************************
#include "DxLib.h"


//*****************************************************************************
//  Constant
//*****************************************************************************
// キー再割り当て(4Byte型なので最大32個 使う分だけ定義)
constexpr unsigned int kSpace = 1;                // スペース
constexpr unsigned int kEnter = kSpace << 1; // エンター
constexpr unsigned int kUpArrow = kEnter << 1; // ↑
constexpr unsigned int kDownArrow = kUpArrow << 1; // ↓
constexpr unsigned int kLeftArrow = kDownArrow << 1; // ←
constexpr unsigned int kRightArrow = kLeftArrow << 1; // →
constexpr unsigned int kZKey = kRightArrow << 1; // Zキー


//*****************************************************************************
//  Class
//*****************************************************************************
class Keyboard
{
private:
    static unsigned int held_;      // 押されているキーフラグ
    static unsigned int pressed_;   // 押されたキーフラグ
    static unsigned int save_flag_; // 前回押されていたか記憶するフラグ

    // １だけ入力を取得する
    static void isPressed( const int DxKey, const unsigned int keyFlag );

public:
    static void update(); // 更新

    // 入力フラグを返す
    static unsigned int getHeld() { return held_; }
    static unsigned int getPressed() { return pressed_; }
};

#endif