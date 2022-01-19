//*****************************************************************************
//  Include
//*****************************************************************************
#include "DxLib.h"
#include "frame.h"


//*****************************************************************************
//  コンストラクタ
//*****************************************************************************
Frame::Frame( const char* TitleName ) : counter_( 0 ), timer_( 0LL )
{
    // ゲームタイトルをコピー
    strcpy( game_name_, TitleName );
}


//*****************************************************************************
//  更新
//*****************************************************************************
void Frame::update()
{
    // 現在の経過時間を取得
    long long now = GetNowHiPerformanceCount();

    // 1秒経過したか
    ++counter_;
    if( now - timer_ > 1000000 )
    {
        char str[ MAX_PATH ] = "";
        sprintf( str, "%s ｜ FPS：%d", game_name_, counter_ );
        SetMainWindowText( str );

        counter_ = 0; // カウンター初期化
        timer_ = now; // 現在の経過時間を保存
    }
}