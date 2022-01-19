#include "keyboard.h"


//*****************************************************************************
//  実体の宣言
//*****************************************************************************
unsigned int Keyboard::held_;
unsigned int Keyboard::pressed_;
unsigned int Keyboard::save_flag_;


//*****************************************************************************
//  更新
//*****************************************************************************
void Keyboard::update()
{
    // フラグ初期化
    held_ = 0U;
    pressed_ = 0U;

    // 各ボタンの押されている入力状況を更新
    if( CheckHitKey( KEY_INPUT_SPACE ) )  held_ |= kSpace;
    if( CheckHitKey( KEY_INPUT_RETURN ) ) held_ |= kEnter;
    if( CheckHitKey( KEY_INPUT_LEFT ) )   held_ |= kLeftArrow;
    if( CheckHitKey( KEY_INPUT_RIGHT ) )  held_ |= kRightArrow;
    if( CheckHitKey( KEY_INPUT_UP ) )     held_ |= kUpArrow;
    if( CheckHitKey( KEY_INPUT_DOWN ) )   held_ |= kDownArrow;
    if( CheckHitKey( KEY_INPUT_Z ) )      held_ |= kZKey;

    // 各ボタンの押されていた入力状況を更新
    isPressed( KEY_INPUT_SPACE, kSpace );
    isPressed( KEY_INPUT_RETURN, kEnter );
    isPressed( KEY_INPUT_LEFT, kLeftArrow );
    isPressed( KEY_INPUT_RIGHT, kRightArrow );
    isPressed( KEY_INPUT_UP, kUpArrow );
    isPressed( KEY_INPUT_DOWN, kDownArrow );
    isPressed( KEY_INPUT_Z, kZKey );
}


//*****************************************************************************
//  押されたボタンを取得
//*****************************************************************************
void Keyboard::isPressed( const int DxKey, const unsigned int KeyFlag )
{
    // 各ボタンの押されていた入力状況を更新
    if( CheckHitKey( DxKey ) )
    {
        // 前回押されていたか
        if( !(save_flag_ & KeyFlag) )
        {
            // 押されていないので押したことにする
            pressed_ |= KeyFlag;
            save_flag_ |= KeyFlag;
        }
    }
    else save_flag_ &= ~KeyFlag;
}