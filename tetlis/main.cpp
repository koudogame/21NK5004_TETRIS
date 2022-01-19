//*****************************************************************************
//  Include
//*****************************************************************************
#include "DxLib.h"
#include "common.h"
#include "progress.h"
#include "keyboard.h"
#include "frame.h"


//*****************************************************************************
//  エントリーポイント
//*****************************************************************************
int WINAPI WinMain( _In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpcmdLine, _In_ int nCmdShow )
{
    // log.txtの出力をしない
    SetOutApplicationLogValidFlag( false );

    SetGraphMode( kWindowWidth, kWindowHeight, 32 ); // 画面解像度を変更
    ChangeWindowMode( true );            // ウィンドウモードに設定
    SetBackgroundColor( 255, 255, 255 ); // 背景カラー
    SetMainWindowText( "TETRIS" );       // ウィンドウ名の設定

    // DXライブラリの初期化
    if( DxLib_Init() == -1 ) return 0;

    // 裏画面に描画する
    SetDrawScreen( DX_SCREEN_BACK );

    // シーン管理クラスの宣言
    Progress progress;
    if( !progress.init() )
    {
        // エラー
        DxLib_End();
        return 0;
    }

    // フレームレート管理クラス
    Frame frame( kGameTitle );

    // メインループ
    while( ProcessMessage() != -1 )
    {

        // フレームレートの計測
        frame.update();

        // キー入力更新
        Keyboard::update();

        // 強制終了処理
        if( CheckHitKey( KEY_INPUT_ESCAPE ) )
        {
            break;
        }

        // 更新
        progress.update();

        // 画面初期化
        ClearDrawScreen();

        // 描画
        progress.draw();

        // 裏画面に描画した内容を表に表示する
        ScreenFlip();
        WaitTimer( 16 );
    }

    // DXライブラリの破棄
    DxLib_End();

    return 0;
}