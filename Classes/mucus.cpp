//_/_/_/_/_/_/_/_/_/_/_/_/_/
// 粘液のソースファイル
//
// 2016/11/12
//
// AsakawaTasuku
//_/_/_/_/_/_/_/_/_/_/_/_/_/

#include "mucus.h"
#include "HelloWorldScene.h"
#include "GameMain.h"

using namespace std;

#define SCREEN_W		(960)		// 画面の幅
#define SCREEN_H		(640)		// 画面の高さ
#define MUCUS_SPEED		(5.0f)		// 粘液の速さ



//_/_/_/_/_/_/_/_/_/_/_/_/_/
// 粘液のコンストラクタ
//_/_/_/_/_/_/_/_/_/_/_/_/_/
Mucus::Mucus()
{
}

//_/_/_/_/_/_/_/_/_/_/_/_/_/
// 粘液デストラクタ
//_/_/_/_/_/_/_/_/_/_/_/_/_/
Mucus::~Mucus()
{

}

//_/_/_/_/_/_/_/_/_/_/_/_/_/
// 粘液の初期化処理
//
// 引数: なし
//
// 戻り値:なし
//_/_/_/_/_/_/_/_/_/_/_/_/_/
void Mucus::initialize_mucus()
{
	// 粘液の初期化
	m_mucus.pos = 0;
	m_mucus.spd = 0;
	m_mucus.state = 0;
}

//_/_/_/_/_/_/_/_/_/_/_/_/_/
// 粘液の更新処理
//
// 引数:あり(HelloWorld*)
//
// 戻り値:なし
//_/_/_/_/_/_/_/_/_/_/_/_/_/
void Mucus::update_mucus(Mucus* m_mucus, HelloWorld* obj,int direction)
{
	// 粘液の描画
	render_mucus(obj);
	
	// 粘液の移動
	move_mucus(m_mucus, direction);

}

//_/_/_/_/_/_/_/_/_/_/_/_/_/
// 粘液の描画処理
//
// 引数:あり(HelloWorld*)
//
// 戻り値:なし
//_/_/_/_/_/_/_/_/_/_/_/_/_/
void Mucus::render_mucus(HelloWorld* obj)
{
	m_mucus.sprite = cocos2d::Sprite::create("daiyou.png");
	m_mucus.sprite->setPosition(cocos2d::Vec2(SCREEN_W / 2, SCREEN_H / 2));
	obj->addChild(m_mucus.sprite);
	
}

//_/_/_/_/_/_/_/_/_/_/_/_/_/
// 粘液の終了処理
//
// 引数:なし
//
// 戻り値:なし
//_/_/_/_/_/_/_/_/_/_/_/_/_/
void Mucus::finalize_mucus()
{

}

//_/_/_/_/_/_/_/_/_/_/_/_/_/
// 粘液の移動処理
//
// 引数:あり(Mucus*,int)
//
// 戻り値:なし
//_/_/_/_/_/_/_/_/_/_/_/_/_/
void Mucus::move_mucus(Mucus* obj, int direction)
{
	m_mucus.pos = obj->m_mucus.pos;
	m_mucus.state = 1;

	// 向いている方向
	switch (direction)
	{
		case UP:
			obj->m_mucus.spd = cocos2d::Vec2(0, MUCUS_SPEED);
			break;
		case DOWN:
			obj->m_mucus.spd = cocos2d::Vec2(0, -MUCUS_SPEED);
			break;
		case LEFT:
			obj->m_mucus.spd = cocos2d::Vec2(-MUCUS_SPEED,0);
			break;
		case RIGHT:
			obj->m_mucus.spd = cocos2d::Vec2(MUCUS_SPEED, 0);
			break;
	}

	// 粘液の移動計算
	if (m_mucus.state == 1)
	{
		m_mucus.pos += m_mucus.spd;
	}
}


//_/_/_/_/_/_/_/_/_/_/_/_/_/
// 粘液が壁に当たった時の処理
//
// 引数:なし
//
// 戻り値:なし
//_/_/_/_/_/_/_/_/_/_/_/_/_/
void Mucus::destract_mucus()
{
	// 壁に当たった時
	if (m_mucus.state == true)
	{
		m_mucus.state = false;
	}
}

//_/_/_/_/_/_/_/_/_/_/_/_/_/
// 粘液同士が当たった時の処理
//
// 引数:なし
//
// 戻り値:なし
//_/_/_/_/_/_/_/_/_/_/_/_/_/
void Mucus::setoff_mucus()
{
	if (m_mucus.state== true && m_mucus.state == true)
	{
		m_mucus.state = false;
	}
}


