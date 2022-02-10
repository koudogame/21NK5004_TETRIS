//*****************************************************************************
//  Include
//*****************************************************************************
#include "board.h"


//*****************************************************************************
//  初期化
//*****************************************************************************
bool Board::init()
{
    mino_cnt_ = 0;
    width = 0;
    // すべての要素を-1で初期化
    for( int i = 0; i < kBoardHeight; ++i )
    {
        for( int j = 0; j < kBoardWidth; ++j )
        {
            board_[ i ][ j ] = -1;
        }
    }

    // テクスチャの読み込み
    texture_ = LoadGraph( "Tetris11_SingleT.png" );
    if( texture_ == -1 )
    {
        // エラー
        return false;
    }

    return true;
}

//*****************************************************************************
//  描画
//*****************************************************************************
void Board::draw()
{
    for( int i = 0; i < kBoardHeight; ++i )
    {
        for( int j = 0; j < kBoardWidth; ++j )
        {
            // -1なら描画しない
            if( board_[ i ][ j ] == -1 ) continue;

            // 描画
            DrawRectGraph(
                kReferencePointX + (j * kMinoSize),
                kReferencePointY + (i * kMinoSize),
                kSrcX + (board_[ i ][ j ] * kMinoSize),
                kSrcY, kMinoSize, kMinoSize, texture_, true );
        }
    }
}

//更新
void Board::update()
{
    for( int i = 0; i < kBoardHeight; i++ )
    {
        for( int j = 0; j < kBoardWidth; j++ )
        {
            if( board_[ i ][ j ] != -1 )
            {
                mino_cnt_++;
            }

            if( mino_cnt_ == 10 )
            {
                for( int a = 0; a < kBoardWidth; a++ )
                {
                    board_[ i ][ a ] = -1;
                }

                for( int b = i; b > 0; b-- )//縦
                {
                    for( int c = 0; c < kBoardWidth; c++ )//横
                    {
                        board_[ b ][ c ] = board_[ b - 1 ][ c ];
                        board_[ b - 1 ][ c ] = -1;
                    }
                }
            }
        }
        mino_cnt_ = 0;
    }


}
