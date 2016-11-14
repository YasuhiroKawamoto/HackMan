//_/_/_/_/_/_/_/_/_/_/_/_/_/
// ”S‰t‚Ìƒ\[ƒXƒtƒ@ƒCƒ‹
//
// 2016/11/12
//
// AsakawaTasuku
//_/_/_/_/_/_/_/_/_/_/_/_/_/

#include "mucus.h"
#include "HelloWorldScene.h"
#include "GameMain.h"

using namespace std;

#define SCREEN_W		(960)		// ‰æ–Ê‚Ì•
#define SCREEN_H		(640)		// ‰æ–Ê‚Ì‚‚³
#define MUCUS_SPEED		(5.0f)		// ”S‰t‚Ì‘¬‚³



//_/_/_/_/_/_/_/_/_/_/_/_/_/
// ”S‰t‚ÌƒRƒ“ƒXƒgƒ‰ƒNƒ^
//_/_/_/_/_/_/_/_/_/_/_/_/_/
Mucus::Mucus()
{
}

//_/_/_/_/_/_/_/_/_/_/_/_/_/
// ”S‰tƒfƒXƒgƒ‰ƒNƒ^
//_/_/_/_/_/_/_/_/_/_/_/_/_/
Mucus::~Mucus()
{

}

//_/_/_/_/_/_/_/_/_/_/_/_/_/
// ”S‰t‚Ì‰Šú‰»ˆ—
//
// ˆø”: ‚È‚µ
//
// –ß‚è’l:‚È‚µ
//_/_/_/_/_/_/_/_/_/_/_/_/_/
void Mucus::initialize_mucus()
{
	// ”S‰t‚Ì‰Šú‰»
	m_mucus.pos = 0;
	m_mucus.spd = 0;
	m_mucus.state = 0;
}

//_/_/_/_/_/_/_/_/_/_/_/_/_/
// ”S‰t‚ÌXVˆ—
//
// ˆø”:‚ ‚è(HelloWorld*)
//
// –ß‚è’l:‚È‚µ
//_/_/_/_/_/_/_/_/_/_/_/_/_/
void Mucus::update_mucus(Mucus* m_mucus, HelloWorld* obj,int direction)
{
	// ”S‰t‚Ì•`‰æ
	render_mucus(obj);
	
	// ”S‰t‚ÌˆÚ“®
	move_mucus(m_mucus, direction);

}

//_/_/_/_/_/_/_/_/_/_/_/_/_/
// ”S‰t‚Ì•`‰æˆ—
//
// ˆø”:‚ ‚è(HelloWorld*)
//
// –ß‚è’l:‚È‚µ
//_/_/_/_/_/_/_/_/_/_/_/_/_/
void Mucus::render_mucus(HelloWorld* obj)
{
	m_mucus.sprite = cocos2d::Sprite::create("daiyou.png");
	m_mucus.sprite->setPosition(cocos2d::Vec2(SCREEN_W / 2, SCREEN_H / 2));
	obj->addChild(m_mucus.sprite);
	
}

//_/_/_/_/_/_/_/_/_/_/_/_/_/
// ”S‰t‚ÌI—¹ˆ—
//
// ˆø”:‚È‚µ
//
// –ß‚è’l:‚È‚µ
//_/_/_/_/_/_/_/_/_/_/_/_/_/
void Mucus::finalize_mucus()
{

}

//_/_/_/_/_/_/_/_/_/_/_/_/_/
// ”S‰t‚ÌˆÚ“®ˆ—
//
// ˆø”:‚ ‚è(Mucus*,int)
//
// –ß‚è’l:‚È‚µ
//_/_/_/_/_/_/_/_/_/_/_/_/_/
void Mucus::move_mucus(Mucus* obj, int direction)
{
	m_mucus.pos = obj->m_mucus.pos;
	m_mucus.state = 1;

	// Œü‚¢‚Ä‚¢‚é•ûŒü
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

	// ”S‰t‚ÌˆÚ“®ŒvZ
	if (m_mucus.state == 1)
	{
		m_mucus.pos += m_mucus.spd;
	}
}


//_/_/_/_/_/_/_/_/_/_/_/_/_/
// ”S‰t‚ª•Ç‚É“–‚½‚Á‚½‚Ìˆ—
//
// ˆø”:‚È‚µ
//
// –ß‚è’l:‚È‚µ
//_/_/_/_/_/_/_/_/_/_/_/_/_/
void Mucus::destract_mucus()
{
	// •Ç‚É“–‚½‚Á‚½
	if (m_mucus.state == true)
	{
		m_mucus.state = false;
	}
}

//_/_/_/_/_/_/_/_/_/_/_/_/_/
// ”S‰t“¯m‚ª“–‚½‚Á‚½‚Ìˆ—
//
// ˆø”:‚È‚µ
//
// –ß‚è’l:‚È‚µ
//_/_/_/_/_/_/_/_/_/_/_/_/_/
void Mucus::setoff_mucus()
{
	if (m_mucus.state== true && m_mucus.state == true)
	{
		m_mucus.state = false;
	}
}


