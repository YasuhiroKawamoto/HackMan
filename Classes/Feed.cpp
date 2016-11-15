#include"Feed.h"

// _/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/
// 概要:エサクラスのソースファイル
// 
// 制作日:2016/11/11
//
// 制作者:河本恭宏
// _/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/


//============================
// =>概要:エサコンストラクタ
// 
// =>引数:なし
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
// =>概要:エサデストラクタ
//============================
Feed::~Feed()
{

}

//============================
// =>概要:エサアップデート
// 
// =>引数:プレイシーンへのポインタ（Play*）
// 
// =>返り値:なし
//============================
void Feed::Update(HelloWorld* playObj)
{
	// 一定時間経過後
	if (WaitTime())
	{
		// 使われていないエサを探索
		for (int i = 0; i < FEED_MAX; i++)
		{
			// エサが未使用なら
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
// =>概要:エサ生成
// 
// =>引数:プレイシーンへのポインタ（Play*）
// 
// =>返り値:なし
//============================
void Feed::Generater(HelloWorld* playObj, int id)
{
	m_feed[id].sprite->setPosition(cocos2d::Vec2(m_feed[id].pos.x, m_feed[id].pos.y));

	playObj->addChild(m_feed[id].sprite);
}

//============================
// =>概要:生成までのウェイト
// 
// =>引数:なし
// 
// =>返り値:時間まで来たか
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
// =>概要:生成座標の決定
// 
// =>引数:なし
// 
// =>返り値:なし
//============================
void Feed::SetPosition(int id)
{
	m_feed[id].pos.x = (rand() % 12 )*64;
	m_feed[id].pos.y = (rand() % 10 )*64;
}
