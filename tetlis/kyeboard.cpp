#include "keyboard.h"


//*****************************************************************************
//  ���̂̐錾
//*****************************************************************************
unsigned int Keyboard::held_;
unsigned int Keyboard::pressed_;
unsigned int Keyboard::save_flag_;


//*****************************************************************************
//  �X�V
//*****************************************************************************
void Keyboard::update()
{
    // �t���O������
    held_ = 0U;
    pressed_ = 0U;

    // �e�{�^���̉�����Ă�����͏󋵂��X�V
    if( CheckHitKey( KEY_INPUT_SPACE ) )  held_ |= kSpace;
    if( CheckHitKey( KEY_INPUT_RETURN ) ) held_ |= kEnter;
    if( CheckHitKey( KEY_INPUT_LEFT ) )   held_ |= kLeftArrow;
    if( CheckHitKey( KEY_INPUT_RIGHT ) )  held_ |= kRightArrow;
    if( CheckHitKey( KEY_INPUT_UP ) )     held_ |= kUpArrow;
    if( CheckHitKey( KEY_INPUT_DOWN ) )   held_ |= kDownArrow;
    if( CheckHitKey( KEY_INPUT_Z ) )      held_ |= kZKey;

    // �e�{�^���̉�����Ă������͏󋵂��X�V
    isPressed( KEY_INPUT_SPACE, kSpace );
    isPressed( KEY_INPUT_RETURN, kEnter );
    isPressed( KEY_INPUT_LEFT, kLeftArrow );
    isPressed( KEY_INPUT_RIGHT, kRightArrow );
    isPressed( KEY_INPUT_UP, kUpArrow );
    isPressed( KEY_INPUT_DOWN, kDownArrow );
    isPressed( KEY_INPUT_Z, kZKey );
}


//*****************************************************************************
//  �����ꂽ�{�^�����擾
//*****************************************************************************
void Keyboard::isPressed( const int DxKey, const unsigned int KeyFlag )
{
    // �e�{�^���̉�����Ă������͏󋵂��X�V
    if( CheckHitKey( DxKey ) )
    {
        // �O�񉟂���Ă�����
        if( !(save_flag_ & KeyFlag) )
        {
            // ������Ă��Ȃ��̂ŉ��������Ƃɂ���
            pressed_ |= KeyFlag;
            save_flag_ |= KeyFlag;
        }
    }
    else save_flag_ &= ~KeyFlag;
}