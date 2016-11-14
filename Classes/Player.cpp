/********************************************/
/*内　容　プレイヤークラスのソースファイル	*/
/*制作者　加藤駿							*/
/*制作日　2016/11/12						*/
/********************************************/
#include "cocos2d.h"
#include"Player.h"
#include "GameMain.h"

//＋ーーーーーーーーーーーー
//｜機　能:プレイヤーのコンストラクタ
//｜引　数:なし(void)
//＋ーーーーーーーーーーーー
Player::Player()
{
	m_player.sprite = cocos2d::Sprite::create("Player.png");
	m_player.grp.x = 0;
	m_player.grp.y = 0;
	m_player.grp.w = MAP_CHIP_W;
	m_player.grp.h = MAP_CHIP_H;
	m_player.pos.x = 100.0f;
	m_player.pos.y = 100.0f;
	m_player.spd.x = 0.0f;
	m_player.spd.y = 0.0f;
	m_player.state = 2;

	m_player.sprite->setScale(MAP_CHIP_H / 32.0f);
}


//＋ーーーーーーーーーーーー
//｜機　能:プレイヤーのデストラクタ
//＋ーーーーーーーーーーーー
Player::~Player()
{

}


//＋ーーーーーーーーーーーー
//｜機　能:プレイヤーの画像情報を返す
//｜引　数:なし(void)
//｜返り値:画像情報(Sprite*)
//＋ーーーーーーーーーーーー
cocos2d::Sprite * Player::GetSprite()
{
	return m_player.sprite;
}

//＋ーーーーーーーーーーーー
//｜機　能:プレイヤーの位置を返す
//｜引　数:なし(void)
//｜返り値:位置(Vec2)
//＋ーーーーーーーーーーーー
cocos2d::Vec2 Player::GetPos()
{
	return m_player.pos;
}

//＋ーーーーーーーーーーーー
//｜機　能:プレイヤーの速度を返す
//｜引　数:なし(void)
//｜返り値:速度(Vec2)
//＋ーーーーーーーーーーーー
cocos2d::Vec2 Player::GetSpd()
{
	return m_player.spd;
}

//＋ーーーーーーーーーーーー
//｜機　能:プレイヤーの状態を返す
//｜引　数:なし(void)
//｜返り値:状態(int)
//＋ーーーーーーーーーーーー
int Player::GetState()
{
	return m_player.state;
}

//＋ーーーーーーーーーーーー
//｜機　能:プレイヤーの速度を変更
//｜引　数:速度(Vec2)
//｜返り値:なし(void)
//＋ーーーーーーーーーーーー
void Player::ChangeSpd(cocos2d::Vec2 spd)
{
	m_player.spd = spd;
}

//＋ーーーーーーーーーーーー
//｜機　能:プレイヤーの移動
//｜引　数:なし(void)
//｜返り値:なし(void)
//＋ーーーーーーーーーーーー
void Player::Move()
{
	m_player.pos += m_player.spd;
}

//＋ーーーーーーーーーーーー
//｜機　能:プレイヤーの描画
//｜引　数:なし(void)
//｜返り値:なし(void)
//＋ーーーーーーーーーーーー
void Player::Draw()
{
	m_player.sprite->setPosition(m_player.pos);
}

