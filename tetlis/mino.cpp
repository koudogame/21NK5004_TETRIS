#include "mino.h"
#include "Common.h"
#include "keyboard.h"
#include "mino_shape_.h"



//*****************************************************************************
//  Constant
//*****************************************************************************
constexpr int kBlockWidthNum = 10;  // 横に並んでいるブロックエリアの数
constexpr int kBlockHeightNum = 21; // 縦に並んでいるブロックエリアの数
constexpr int kFallSpeed = 6;      // 落下速度




//*****************************************************************************
//  コンストラクタ
//*****************************************************************************
Mino::Mino() : x_( 4 ), y_( 0 ), texture_( 0 ), fall_counter_( 0 )
{
    for(  i = 0; i < 4; i++ )
    {
        for(  j = 0; j < 4; j++ )
        {
            Tetris_[ i ][ j ] = 0;
        }
    }
    tetris_color_ = -1;//テトリスカラー

    rand_ = 0;

}


//*****************************************************************************
//  デストラクタ
//*****************************************************************************
Mino::~Mino()
{
    destroy();
}


//*****************************************************************************
//  初期化
//*****************************************************************************
bool Mino::init()
{
    // テクスチャの読み込み
    texture_ = LoadGraph( "Tetris11_SingleT.png" );
    if( texture_ == -1 )
    {
        // エラー
        return false;
    }
    for( i = 0; i < 4; i++ )
    {
        for( j = 0; j < 4; j++ )
        {
            Tetris_[ i ][ j ] = 0;
        }
    }

    tetris_color_ = -1;//テトリスカラー

    return true;
}


//*****************************************************************************
//  更新
//*****************************************************************************
bool Mino::update( Board* pBoard )
{
    // 入力取得
    unsigned int pressed_key = Keyboard::getPressed();

    if( y_ == 0 ) {

        tetris_color_ = GetRand( 7 );

    }
    

    for( int i = 0; i < 4; i++ )
    {
        for( int j = 0; j < 4; j++ )
        {
            Tetris_[ i ][ j ] = tetris_mino_shape[ tetris_color_ ].tetris_shape[ i ][ j ];
        }
    }

    // 下左右移動
    if( pressed_key & kRightArrow )
    {
        ++x_;

        if( x_ > kBlockWidthNum - 1 )
        {
            x_ = kBlockWidthNum - 1;

        }
    }
    else if( pressed_key & kLeftArrow )
    {
        --x_;
        if( x_ < 0 ) {
            x_ = 0;
        }
    }
    else if( pressed_key & kDownArrow )
    {
        // 落下処理を強制動作させる
        fall_counter_ = kFallSpeed;
    }

    // 落下処理
    if( ++fall_counter_ > kFallSpeed )
    {
        ++y_;              // 落下
        fall_counter_ = 0; // カウンター初期化

        // 下段まで到達したら戻す
        if( y_ >= kBlockHeightNum )
        {
            // ブロックを書き込む(下げる前の位置)
            // 第三引数で渡す列挙値を変えれば自動的に描画範囲を計算するようにしている
            pBoard->setMass( x_, y_ - 1, tetris_color_ );

            x_ = 4; // ブロック位置を中央付近にする
            y_ = 0; // 一番上へ
        }

        // 一つ下にブロックがあるなら書き込んで上へ戻す
        if( pBoard->getMass( x_, y_ ) != -1 )
        {
            // ブロックを書き込む(下げる前の位置)
            pBoard->setMass( x_, y_ - 1, tetris_color_ );

            x_ = 4; // ブロック位置を中央付近にする
            y_ = 0; // 一番上へ
        }
    }


    return true;
}


//*****************************************************************************
//  描画
//*****************************************************************************
void Mino::draw()
{
    // ミノの描画(今回は水色のみにしている）
    // データは添え字で管理して描画座標は計算で求める
    // (ミノの添え字番号は後々使えるところが多い）

    for( i = 0; i < 4; i++ )
    {
        for( j = 0; j < 4; j++ )
        {
            if( Tetris_[ i ][ j ] > 0 )
            {
                DrawRectGraph(
                    kReferencePointX + (x_ * kMinoSize) + (j * kMinoSize),
                    kReferencePointY + (y_ * kMinoSize) + (i * kMinoSize),
                    kSrcX + (tetris_color_ * kMinoSize), kSrcY, kMinoSize, kMinoSize, texture_, true );
            }
   
        }
    }
    
}



//*****************************************************************************
//  破棄
//*****************************************************************************
void Mino::destroy()
{
    // グラフィックハンドルの解放
    SAFE_DELETE_GRAPH( texture_ );
}