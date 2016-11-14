/********************************************/
/*���@�e�@�v���C���[�N���X�̃w�b�_�[�t�@�C��*/
/*����ҁ@�����x							*/
/*������@2016/11/14						*/
/********************************************/
#pragma once

#include "cocos2d.h"
#include "GameMain.h"

#define MAX_PLAYER (2)
#define PLAYER_SPD (5.0f/60.0f/60.0f)

class Player
{
private:
	OBJECT m_player;					//�v���C���[���
	int m_score;						//�X�R�A
	int m_resurrectionTime;				//�����܂ł̎���
	bool m_shootStock;					//�S�t�̃X�g�b�N

public:
	Player();							//�R���X�g���N�^
	~Player();							//�f�X�g���N�^
	OBJECT GetObj();					//�S�Ă̏���Ԃ�
	cocos2d::Sprite* GetSprite();		//�摜����Ԃ�
	cocos2d::Vec2 GetPos();				//�ʒu��Ԃ�
	cocos2d::Vec2 GetSpd();				//���x��Ԃ�
	int GetState();						//��Ԃ�Ԃ�
	bool GetStockShoot();				//�S�t�̃X�g�b�N
	void Shoot();						//�S�t�𔭎�
	void StockShoot();					//�S�t��ǉ�
	void Damege();						//�S�t���󂯂����̏���
	void Resurrection();				//�����̏���
	void ChangeSpd(cocos2d::Vec2 spd);	//���x�̕ύX
	void Move();						//�ړ�
	void Draw();						//�`��
};