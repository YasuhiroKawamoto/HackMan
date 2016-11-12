/********************************************/
/*���@�e�@�I�u�W�F�N�g�̃w�b�_�[�t�@�C��	*/
/*����ҁ@�����x							*/
/*������@2016/11/11						*/
/********************************************/
// ���d�C���N���[�h�̖h�~ ==================================================
#pragma once

#include "cocos2d.h"



// �萔�̒�` ==============================================================

// �Q�[�����
#define SCREEN_WIDTH  960   // ��[pixel]
#define SCREEN_HEIGHT 640   // ����[pixel]

/*-----[�}�b�v�̃T�C�Y]-----*/
#define MAP_W (SCREEN_WIDTH/32)		// �X�e�[�W�@��
#define MAP_H (SCREEN_HEIGHT/32)	// �X�e�[�W�@����

//�摜�T�C�Y�\����
typedef struct tag_grp
{
	int x;
	int y;
	int w;
	int h;

}GRP;

//�I�u�W�F�N�g�\����
typedef struct tag_object
{
							
	cocos2d::Sprite* sprite;//�摜�̏��
	GRP  grp;				//�摜�̕��ƍ���

	cocos2d::Vec2 pos;		//�ʒu
	cocos2d::Vec2 spd;		//���x

	int state;				//��ԁ@�Q�F���C�@�@
							//		�P�F�S�t�������
							//		�O�F���S

}OBJECT;			//�I�u�W�F�N�g�p


