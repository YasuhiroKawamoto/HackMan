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
{
	for(int i = 0; i < FEED_MAX; i++)
	{
		m_feed[i].pos.x = 0, m_feed[i].pos.y = 0, m_feed[i].grp.w = 0, m_feed[i].grp.h = 0;
		m_feed[i].isUsed = false;
		m_feed[i].sprite = cocos2d::Sprite::create("feed.png");
	}
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
void Feed::Update(HelloWorld* playObj)
{
	// ��莞�Ԍo�ߌ�
	if (WaitTime())
	{
		// �g���Ă��Ȃ��G�T��T��
		for (int i = 0; i < FEED_MAX; i++)
		{
			// �G�T�����g�p�Ȃ�
			if (m_feed[i].isUsed == false)
			{
				SetPosition(i);
				Generater(playObj, i);
				m_feed[i].isUsed = true;
				break;
			}
		}
	}
}
//============================
// =>�T�v:�G�T����
// 
// =>����:�v���C�V�[���ւ̃|�C���^�iPlay*�j
// 
// =>�Ԃ�l:�Ȃ�
//============================
void Feed::Generater(HelloWorld* playObj, int id)
{
	m_feed[id].sprite->setPosition(cocos2d::Vec2(m_feed[id].pos.x, m_feed[id].pos.y));

	playObj->addChild(m_feed[id].sprite);
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
void Feed::SetPosition(int id)
{
	m_feed[id].pos.x = (rand() % 12 )*64;
	m_feed[id].pos.y = (rand() % 10 )*64;
}
