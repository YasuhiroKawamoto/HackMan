#pragma once

#include"PlayScene.h"

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