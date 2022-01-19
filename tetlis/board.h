#pragma once
#ifndef __BOARD_H__ // インクルードガード
#define __BOARD_H__


//*****************************************************************************
//  Constant
//*****************************************************************************
#include "Common.h"


//*****************************************************************************
//  Constant
//*****************************************************************************
constexpr int kBoardWidth = 10; // 横のマス数
constexpr int kBoardHeight = 22; // 縦のマス数(1マス余分に確保)
constexpr int kMinoSize = 25; // ミノのサイズ

// ブロックの描画開始基準点
constexpr int kSrcX = 688;
constexpr int kSrcY = 957;

// ゲームエリア左上基準点
constexpr int kReferencePointX = 511;
constexpr int kReferencePointY = 173;


//*****************************************************************************
//  Enum
//*****************************************************************************
enum
{
    kNone = -1, // 何もない
    kLightBlue, // 水色
    kOrange,    // 橙
    kGreen,     // 緑
    kRed,       // 赤
    kBlue,      // 青
    kBrown,     // 茶
    kPurple,    // 紫
    kGray,      // 灰
    kLock       // ロックマス
};


//*****************************************************************************
//  Class
//*****************************************************************************
class Board
{
private:
    int texture_; // グラフィックハンドル
    int board_[ kBoardHeight ][ kBoardWidth ]; // ゲームエリア
    int mino_cnt_;
    int width;
public:
    bool init(); // 初期化
    void draw(); // 描画
    void destroy() { SAFE_DELETE_GRAPH( texture_ ); } // 破棄
    void update();

    // 指定要素のデータを取得/設定
    int getMass( const int X, const int Y ) { return board_[ Y ][ X ]; }
    void setMass( const int X, const int Y, const int Value ) { board_[ Y ][ X ] = Value; }
};

#endif