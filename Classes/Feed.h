#pragma once

#include"HelloWorldScene.h"
#include"GameMain.h"

#define FEED_MAX 20
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
	OBJECT m_feed[FEED_MAX];
public:
	Feed();
	~Feed();
	void Update(HelloWorld* playObj);
private:
	void Generater(HelloWorld* playObj, int id);
	bool WaitTime();
	void SetPosition(int id);
};