#pragma once

#include"PlayScene.h"

// _/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/
// �T�v:�G�T�N���X�̃w�b�_�[�t�@�C��
// 
// �����:2016/11/11
//
// �����:�͖{���G
// _/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/
class Feed
{
private:
	int m_pos_x;
	int m_pos_y;
	int m_grp_w;
	int m_grp_h;
	cocos2d::Sprite* m_feed_sprite;
public:
	Feed();
	~Feed();
	void Update(Play* playObj);
private:
	void Generater(Play* playObj);
	bool WaitTime();
	void SetPosition();
};