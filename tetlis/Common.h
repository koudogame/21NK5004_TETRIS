#pragma once
#ifndef __COMMON_H__
#define __COMMON_H__

#include"DxLib.h"

constexpr int kWindowWidth = 1280; // ウィンドウ横幅
constexpr int kWindowHeight = 720;  // ウィンドウ縦幅
constexpr char kGameTitle[ MAX_PATH ] = "TETRIS"; // ゲームタイトル


//*****************************************************************************
//  関数形式マクロ
//*****************************************************************************
// グラフィックハンドルの解放短縮版
#define SAFE_DELETE_GRAPH(x)  { if( x != -1 ) { DeleteGraph( x ); x = -1; } }

// フォントハンドルの解放短縮版
#define SAFE_DELETE_FONT(x)  { if( x != -1 ) { DeleteFontToHandle( x ); x = -1; } }

#endif