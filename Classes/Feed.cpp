#include"Feed.h"
// _/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/
// �T�v:�G�T�N���X�̃\�[�X�t�@�C��
// 
// �����:2016/11/11
//
// �����:�͖{���G
// _/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/


//============================
// =>�T�v:�G�T�R���X�g���N�^
// 
// =>����:�Ȃ�
//============================
Feed::Feed()
	:m_pos_x(0), m_pos_y(0), m_grp_w(0), m_grp_h(0)
{

}	 

//============================
// =>�T�v:�G�T�f�X�g���N�^
//============================
Feed::~Feed()
{

}

//============================
// =>�T�v:�G�T�A�b�v�f�[�g
// 
// =>����:�v���C�V�[���ւ̃|�C���^�iPlay*�j
// 
// =>�Ԃ�l:�Ȃ�
//============================
void Feed::Update(Play* playObj)
{

	if (WaitTime())
	{
		SetPosition();
		Generater(playObj);
	}
}
//============================
// =>�T�v:�G�T����
// 
// =>����:�v���C�V�[���ւ̃|�C���^�iPlay*�j
// 
// =>�Ԃ�l:�Ȃ�
//============================
void Feed::Generater(Play* playObj)
{
	m_feed_sprite = cocos2d::Sprite::create("heart_tex01.png");
	m_feed_sprite->setScale(0.1f);
	m_feed_sprite->setPosition(cocos2d::Vec2(m_pos_x, m_pos_y));

	playObj->addChild(m_feed_sprite);
}

//============================
// =>�T�v:�����܂ł̃E�F�C�g
// 
// =>����:�Ȃ�
// 
// =>�Ԃ�l:���Ԃ܂ŗ�����
//============================
bool Feed::WaitTime()
{

	static int cnt = 0;
	cnt++;
	if (cnt > 150)
	{
		cnt = 0;
		return true;

	}
	return false;
}

//============================
// =>�T�v:�������W�̌���
// 
// =>����:�Ȃ�
// 
// =>�Ԃ�l:�Ȃ�
//============================
void Feed::SetPosition()
{
	m_pos_x = rand() % 25 *32;
	m_pos_y = rand() % 20 *32;
}
