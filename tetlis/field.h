#pragma once
#ifndef __FIELD_H__ // インクルードガード
#define __FIELD_H__


//*****************************************************************************
//  Class
//*****************************************************************************
class Field
{
private:
    int texture_; // グラフィックハンドル

public:
    Field();        // コンストラクタ
    ~Field();       // デストラクタ

    bool init();    // 初期化
    bool update();  // 更新
    void draw();    // 描画
    void destroy(); // 破棄
};

#endif