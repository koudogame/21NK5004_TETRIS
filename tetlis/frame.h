#pragma once
#ifndef __FRAME_H__ // �C���N���[�h�K�[�h
#define __FRAME_H__


//*****************************************************************************
//  Class
//*****************************************************************************
class Frame
{
private:
    int counter_;                 // �J�E���^�[
    long long timer_;             // �����ۑ��p
    char game_name_[ MAX_PATH ];  // �Q�[���^�C�g��

public:
    Frame( const char* TitleName ); // �R���X�g���N�^
    void update(); // �X�V
};

#endif