#pragma once
#ifndef __FIELD_H__ // �C���N���[�h�K�[�h
#define __FIELD_H__


//*****************************************************************************
//  Class
//*****************************************************************************
class Field
{
private:
    int texture_; // �O���t�B�b�N�n���h��

public:
    Field();        // �R���X�g���N�^
    ~Field();       // �f�X�g���N�^

    bool init();    // ������
    bool update();  // �X�V
    void draw();    // �`��
    void destroy(); // �j��
};

#endif