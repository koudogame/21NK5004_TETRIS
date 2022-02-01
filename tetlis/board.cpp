//*****************************************************************************
//  Include
//*****************************************************************************
#include "board.h"


//*****************************************************************************
//  ������
//*****************************************************************************
bool Board::init()
{
    mino_cnt_ = 0;
    width = 0;
    r = rand() % 10 + 1;
    // ���ׂĂ̗v�f��-1�ŏ�����
    for( int i = 0; i < kBoardHeight; ++i )
    {
        for( int j = 0; j < kBoardWidth; ++j )
        {
            board_[ i ][ j ] = -1;
        }
    }

    // �e�N�X�`���̓ǂݍ���
    texture_ = LoadGraph( "Tetris11_SingleT.png" );
    if( texture_ == -1 )
    {
        // �G���[
        return false;
    }

    return true;
}

//*****************************************************************************
//  �`��
//*****************************************************************************
void Board::draw()
{
    for( int i = 0; i < kBoardHeight; ++i )
    {
        for( int j = 0; j < kBoardWidth; ++j )
        {
            // -1�Ȃ�`�悵�Ȃ�
            if( board_[ i ][ j ] == -1 ) continue;

            // �`��
            DrawRectGraph(
                kReferencePointX + (j * kMinoSize),
                kReferencePointY + (i * kMinoSize),
                kSrcX + (board_[ i ][ j ] * kMinoSize),
                kSrcY, kMinoSize, kMinoSize, texture_, true );
        }
    }
}

//�X�V
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

                for( int b = i; b > 0; b-- )//�c
                {
                    for( int c = 0; c < kBoardWidth; c++ )//��
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
