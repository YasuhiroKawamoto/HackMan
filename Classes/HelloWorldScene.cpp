#include "HelloWorldScene.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include"HackMan.h"
#include"Player.h"
#include "mucus.h"

USING_NS_CC;

using namespace cocostudio::timeline;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    auto rootNode = CSLoader::createNode("MainScene.csb");

    addChild(rootNode);

	/****************/
	/*ここから追加分*/
	/****************/

	/*--パッド画像読み込み--*/
	m_sPad = Sprite::create("Pad1.png");
	m_sPadRight = Sprite::create("PadRight.png");
	m_sPadLeft = Sprite::create("PadLeft.png");
	m_sPadUp = Sprite::create("PadUp.png");
	m_sPadDown = Sprite::create("PadDown.png");

	/*--パッドを非表示--*/
	m_sPad->setVisible(false);
	m_sPadRight->setVisible(false);
	m_sPadLeft->setVisible(false);
	m_sPadUp->setVisible(false);
	m_sPadDown->setVisible(false);

	/*--パッド画像をシーンにつなぐ--*/
	this->addChild(m_sPad);
	this->addChild(m_sPadRight);
	this->addChild(m_sPadLeft);
	this->addChild(m_sPadUp);
	this->addChild(m_sPadDown);

	//プレイヤー画像をシーンにつなぐ
	for (int i = 0; i < MAX_PLAYER; i++)
	{
		this->addChild(m_player[i].GetSprite());
	}

	//プレイヤーの色を変更
	m_player[1].GetSprite()->setColor(Color3B(255, 0, 255));

	/*--タッチの設定--*/
	EventListenerTouchOneByOne* listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = CC_CALLBACK_2(HelloWorld::onTouchBegan, this);
	listener->onTouchMoved = CC_CALLBACK_2(HelloWorld::onTouchMoved, this);
	listener->onTouchEnded = CC_CALLBACK_2(HelloWorld::onTouchEnded, this);
	listener->onTouchCancelled = CC_CALLBACK_2(HelloWorld::onTouchCancelled, this);
	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);
	

	/*--キーボード入力--*/
	auto keyboardListener = cocos2d::EventListenerKeyboard::create();
	keyboardListener->onKeyPressed = CC_CALLBACK_2(HelloWorld::onKeyPressed, this);
	keyboardListener->onKeyReleased = CC_CALLBACK_2(HelloWorld::onKeyReleased, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(keyboardListener, this);


	//更新処理
	this->scheduleUpdate();

    return true;
}


//毎フレームの更新処理
void HelloWorld::update(float delta)
{

	HackMan hackMan;

	hackMan.RegisterPlayer(m_player);

	hackMan.Play();
}

/*--タッチ開始時の関数--*/
bool HelloWorld::onTouchBegan(Touch* touch, Event* unused_event)
{
	//タッチした箇所の座標を取得
	touchPos = touch->getLocation();

	/*--画面の左側をタッチした場合--*/
	if (touchPos.x < SCREEN_WIDTH / 2)
	{
		/*--パッドの位置を設定--*/
		m_sPad->setPosition(touchPos);
		m_sPadRight->setPosition(touchPos);
		m_sPadLeft->setPosition(touchPos);
		m_sPadUp->setPosition(touchPos);
		m_sPadDown->setPosition(touchPos);

		//パッドを表示
		m_sPad->setVisible(true);
	}
	else
	{
		/*--画面の右側をタッチした場合--*/
		if (m_player[0].GetStockShoot())
		{
			/*--粘液があれば--*/

			//粘液の発射
		}		
	}

	return true;
}


/*--タッチ中の関数--*/
void HelloWorld::onTouchMoved(Touch* touch, Event* unused_event)
{
	/*--一度非表示にする--*/
	m_sPadRight->setVisible(false);
	m_sPadLeft->setVisible(false);
	m_sPadUp->setVisible(false);
	m_sPadDown->setVisible(false);

	//パッドの中央の空白の幅
	int center = 30;

	//矢印の長さ
	int arrowSize = 120;

	//現在の座標を取得
	Vec2 pos = touch->getLocation();

	/*--画面の左側をタッチした場合--*/
	if (touchPos.x < SCREEN_WIDTH / 2)
	{
		/*--縦が横矢印の範囲内かどうかの判定--*/
		if (pos.y < touchPos.y + center &&pos.y > touchPos.y - center)
		{
			/*--右方向の判定--*/
			if (pos.x > touchPos.x + center &&pos.x < touchPos.x + center + arrowSize)
			{
				m_sPadRight->setVisible(true);
				m_player[0].ChangeSpd(Vec2(PLAYER_SPD, 0.0f));
				m_player[0].GetSprite()->setRotation(180.0f);
			}
			else
			{
				m_sPadRight->setVisible(false);
			}

			/*--左方向の判定--*/
			if (pos.x < touchPos.x - center&&pos.x > touchPos.x - center - arrowSize)
			{
				m_sPadLeft->setVisible(true);
				m_player[0].ChangeSpd(Vec2(-PLAYER_SPD, 0.0f));
				m_player[0].GetSprite()->setRotation(0.0f);
			}
			else
			{
				m_sPadLeft->setVisible(false);
			}
		}
		else if (pos.x < touchPos.x + center &&pos.x > touchPos.x - center)
		{
			/*--横が縦矢印の範囲内かどうかの判定--*/
			/*--上方向の判定--*/
			if (pos.y > touchPos.y + center&&pos.y < touchPos.y + center + arrowSize)
			{
				m_sPadUp->setVisible(true);
				m_player[0].ChangeSpd(Vec2(0.0f, PLAYER_SPD));
				m_player[0].GetSprite()->setRotation(90.0f);
			}
			else
			{
				m_sPadUp->setVisible(false);
			}

			/*--下方向の判定--*/
			if (pos.y < touchPos.y - center&&pos.y > touchPos.y - center - arrowSize)
			{
				m_sPadDown->setVisible(true);
				m_player[0].ChangeSpd(Vec2(0.0f, -PLAYER_SPD));
				m_player[0].GetSprite()->setRotation(-90.0f);
			}
			else
			{
				m_sPadDown->setVisible(false);
			}
		}
		else
		{
			m_player[0].ChangeSpd(Vec2(0.0f, 0.0f));
		}
	}
}


/*--タッチ終了時の関数--*/
void HelloWorld::onTouchEnded(Touch* touch, Event* unused_event)
{
	/*--パッドを非表示--*/
	m_sPad->setVisible(false);
	m_sPadRight->setVisible(false);
	m_sPadLeft->setVisible(false);
	m_sPadUp->setVisible(false);
	m_sPadDown->setVisible(false);

	m_player[0].ChangeSpd(Vec2(0.0f, 0.0f));
}


/*--タッチキャンセル時の関数--*/
void HelloWorld::onTouchCancelled(Touch* touch, Event* unused_event)
{

}


/*--キーボード入力時の関数--*/
void HelloWorld::onKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event * event)
{
	if (keyCode == EventKeyboard::KeyCode::KEY_UP_ARROW)
	{
		/*--上移動--*/
		m_player[1].ChangeSpd(Vec2(0.0f, PLAYER_SPD));
		m_player[1].GetSprite()->setRotation(90.0f);
		direction = UP;
	}
	else if (keyCode == EventKeyboard::KeyCode::KEY_DOWN_ARROW)
	{
		/*--下移動--*/
		m_player[1].ChangeSpd(Vec2(0.0f, -PLAYER_SPD));
		m_player[1].GetSprite()->setRotation(-90.0f);
		direction = DOWN;
	}
	else if (keyCode == EventKeyboard::KeyCode::KEY_RIGHT_ARROW)
	{
		/*--右移動--*/
		m_player[1].ChangeSpd(Vec2(PLAYER_SPD, 0.0f));
		m_player[1].GetSprite()->setRotation(180.0f);
		direction = RIGHT;
	}
	else if (keyCode == EventKeyboard::KeyCode::KEY_LEFT_ARROW)
	{
		/*--左移動--*/
		m_player[1].ChangeSpd(Vec2(-PLAYER_SPD, 0.0f));
		m_player[1].GetSprite()->setRotation(0.0f);
		direction = LEFT;
	}

	/*--SPACEキーが押された場合--*/
	if (keyCode == EventKeyboard::KeyCode::KEY_SPACE)
	{
		if (m_player[1].GetStockShoot())
		{
			/*--粘液があれば--*/

			//粘液の発射
			//move_mucus(direction)
		}
	}
}

 /*--キーボード入力終了時の関数--*/
void HelloWorld::onKeyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event * event)
{
	/*--上キーを離したときに上に進んでいた場合--*/
	if (keyCode == EventKeyboard::KeyCode::KEY_UP_ARROW && m_player[1].GetSpd()==Vec2(0.0f, PLAYER_SPD))
	{
		m_player[1].ChangeSpd(Vec2(0.0f, 0.0f));
	}
	
	/*--下キーを離したときに下に進んでいた場合--*/
	if (keyCode == EventKeyboard::KeyCode::KEY_DOWN_ARROW && m_player[1].GetSpd() == Vec2(0.0f, -PLAYER_SPD))
	{
		m_player[1].ChangeSpd(Vec2(0.0f, 0.0f));
	}
	
	/*--右キーを離したときに右に進んでいた場合--*/
	if (keyCode == EventKeyboard::KeyCode::KEY_RIGHT_ARROW && m_player[1].GetSpd() == Vec2(PLAYER_SPD,0.0f))
	{
		m_player[1].ChangeSpd(Vec2(0.0f, 0.0f));
	}
	
	/*--左キーを離したときに左に進んでいた場合--*/
	if (keyCode == EventKeyboard::KeyCode::KEY_LEFT_ARROW && m_player[1].GetSpd() == Vec2(-PLAYER_SPD,0.0f))
	{
		m_player[1].ChangeSpd(Vec2(0.0f, 0.0f));
	}

}