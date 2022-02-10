#pragma once
#ifndef __MINO_H__ // インクルードガード
#define __MINO_H__


//*****************************************************************************
//  Include
//*****************************************************************************
#include "board.h"


//*****************************************************************************
//  Class
//*****************************************************************************
class Mino
{
private:
    int x_, y_;        // テトリミノの添え字([ y ][ x ])
    int texture_;      // グラフィックハンドル
    int fall_counter_; // 落下カウンター
    int Tetris_[ 4 ][ 4 ];
    int tetris_color_;//テトリスカラー（randの受け取り）
    int rand_;
    int tetris_shape_;
    int i ;
    int j ;

public:
    Mino();        // コンストラクタ
    ~Mino();       // デストラクタ

    bool init();    // 初期化
    bool update( Board* pBoard );  // 更新
    void draw();    // 描画
    void destroy(); // 破棄
};

#endif