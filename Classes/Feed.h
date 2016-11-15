#pragma once

#include"HelloWorldScene.h"
#include"GameMain.h"

#define FEED_MAX 20
// _/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/
// 概要:エサクラスのヘッダーファイル
// 
// 制作日:2016/11/11
//
// 制作者:河本恭宏
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