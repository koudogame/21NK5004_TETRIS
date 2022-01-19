//*****************************************************************************
//  Include
//*****************************************************************************
#include "DxLib.h"
#include "common.h"
#include "progress.h"
#include "keyboard.h"
#include "frame.h"


//*****************************************************************************
//  �G���g���[�|�C���g
//*****************************************************************************
int WINAPI WinMain( _In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpcmdLine, _In_ int nCmdShow )
{
    // log.txt�̏o�͂����Ȃ�
    SetOutApplicationLogValidFlag( false );

    SetGraphMode( kWindowWidth, kWindowHeight, 32 ); // ��ʉ𑜓x��ύX
    ChangeWindowMode( true );            // �E�B���h�E���[�h�ɐݒ�
    SetBackgroundColor( 255, 255, 255 ); // �w�i�J���[
    SetMainWindowText( "TETRIS" );       // �E�B���h�E���̐ݒ�

    // DX���C�u�����̏�����
    if( DxLib_Init() == -1 ) return 0;

    // ����ʂɕ`�悷��
    SetDrawScreen( DX_SCREEN_BACK );

    // �V�[���Ǘ��N���X�̐錾
    Progress progress;
    if( !progress.init() )
    {
        // �G���[
        DxLib_End();
        return 0;
    }

    // �t���[�����[�g�Ǘ��N���X
    Frame frame( kGameTitle );

    // ���C�����[�v
    while( ProcessMessage() != -1 )
    {

        // �t���[�����[�g�̌v��
        frame.update();

        // �L�[���͍X�V
        Keyboard::update();

        // �����I������
        if( CheckHitKey( KEY_INPUT_ESCAPE ) )
        {
            break;
        }

        // �X�V
        progress.update();

        // ��ʏ�����
        ClearDrawScreen();

        // �`��
        progress.draw();

        // ����ʂɕ`�悵�����e��\�ɕ\������
        ScreenFlip();
        WaitTimer( 16 );
    }

    // DX���C�u�����̔j��
    DxLib_End();

    return 0;
}