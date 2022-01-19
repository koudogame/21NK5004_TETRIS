#pragma once
#ifndef __COMMON_H__
#define __COMMON_H__

#include"DxLib.h"

constexpr int kWindowWidth = 1280; // �E�B���h�E����
constexpr int kWindowHeight = 720;  // �E�B���h�E�c��
constexpr char kGameTitle[ MAX_PATH ] = "TETRIS"; // �Q�[���^�C�g��


//*****************************************************************************
//  �֐��`���}�N��
//*****************************************************************************
// �O���t�B�b�N�n���h���̉���Z�k��
#define SAFE_DELETE_GRAPH(x)  { if( x != -1 ) { DeleteGraph( x ); x = -1; } }

// �t�H���g�n���h���̉���Z�k��
#define SAFE_DELETE_FONT(x)  { if( x != -1 ) { DeleteFontToHandle( x ); x = -1; } }

#endif