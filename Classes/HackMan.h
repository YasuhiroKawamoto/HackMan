/********************************************/
/*���@�e�@�Q�[���N���X�̃w�b�_�[�t�@�C��	*/
/*����ҁ@�����x							*/
/*������@2016/11/14						*/
/********************************************/
#include "cocos2d.h"
#include "GameMain.h"
#include"Player.h"

#pragma once

//�Q�[���̐�������
#define PLAY_TIME (60*60)
#define A_LITTLE (2)

/*--�Q�[���N���X--*/
class HackMan
{
private:
	Player* m_player[MAX_PLAYER];			//�v���C���[���
	int m_map[MAP_H][MAP_W];				//�}�b�v���

public:
	HackMan();								//�R���X�g���N�^
	~HackMan();								//�f�X�g���N�^
	void Play();							//�Q�[���{��
	void RegisterPlayer(Player player[]);	//�v���C���[�̓o�^

private:
	bool isFinished(int playTime);			//�Q�[���̏I������
	
	//�~�̓����蔻��
	bool collision(const OBJECT* A,const OBJECT* B);

};
