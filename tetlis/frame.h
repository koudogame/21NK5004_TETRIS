#pragma once
#ifndef __FRAME_H__ // インクルードガード
#define __FRAME_H__


//*****************************************************************************
//  Class
//*****************************************************************************
class Frame
{
private:
    int counter_;                 // カウンター
    long long timer_;             // 時刻保存用
    char game_name_[ MAX_PATH ];  // ゲームタイトル

public:
    Frame( const char* TitleName ); // コンストラクタ
    void update(); // 更新
};

#endif