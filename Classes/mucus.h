//_/_/_/_/_/_/_/_/_/_/_/_/_/
// �S�t�̃w�b�_�t�@�C��
//
// 2016/11/12
//
// AsakawaTasuku
//_/_/_/_/_/_/_/_/_/_/_/_/_/

#pragma once

#include"HelloWorldScene.h"

// �\���̐錾
//typedef struct tag_object
//{ 
//	float pos_x;					// ���Wx
//	float pos_y;					// ���Wy
//	float spd_x;					// ���xx
//	float spd_y;					// ���xy
//	bool isVisible;					// 1:�\���@0:��\��
//	cocos2d::Sprite* m_pSprite;		// �X�v���C�g
//
//}OBJECT;

// ����
//enum DIRECTION
//{
//	UP,
//	DOWN,
//	RIGHT,
//	LEFT,
//};

// Mucus�N���X
class Mucus
{
	private:
		OBJECT m_mucus;		

	public:
		Mucus();											// �S�t�̃R���X�g���N�^
		~Mucus();											// �S�t�̃f�X�g���N�^
		void initialize_mucus();							// �S�t�̏���������
		void update_mucus(Mucus* m_mucus,HelloWorld* obj,int KeyCode);	// �S�t�̍X�V����
		void render_mucus(HelloWorld* obj);					// �S�t�̕`�揈��
		void finalize_mucus();								// �S�t�̏I������
		void Mucus::move_mucus(Mucus* obj, int direction);			// �S�t�̈ړ�����
		void destract_mucus();								// �S�t���ǂɓ����������̏���
		void Mucus::setoff_mucus();							// �S�t���m�������������̏���
		

};


