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
	/*��������ǉ���*/
	/****************/

	/*--�p�b�h�摜�ǂݍ���--*/
	m_sPad = Sprite::create("Pad1.png");
	m_sPadRight = Sprite::create("PadRight.png");
	m_sPadLeft = Sprite::create("PadLeft.png");
	m_sPadUp = Sprite::create("PadUp.png");
	m_sPadDown = Sprite::create("PadDown.png");

	/*--�p�b�h���\��--*/
	m_sPad->setVisible(false);
	m_sPadRight->setVisible(false);
	m_sPadLeft->setVisible(false);
	m_sPadUp->setVisible(false);
	m_sPadDown->setVisible(false);

	/*--�p�b�h�摜���V�[���ɂȂ�--*/
	this->addChild(m_sPad);
	this->addChild(m_sPadRight);
	this->addChild(m_sPadLeft);
	this->addChild(m_sPadUp);
	this->addChild(m_sPadDown);

	//�v���C���[�摜���V�[���ɂȂ�
	for (int i = 0; i < MAX_PLAYER; i++)
	{
		this->addChild(m_player[i].GetSprite());
	}

	//�v���C���[�̐F��ύX
	m_player[1].GetSprite()->setColor(Color3B(255, 0, 255));

	/*--�^�b�`�̐ݒ�--*/
	EventListenerTouchOneByOne* listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = CC_CALLBACK_2(HelloWorld::onTouchBegan, this);
	listener->onTouchMoved = CC_CALLBACK_2(HelloWorld::onTouchMoved, this);
	listener->onTouchEnded = CC_CALLBACK_2(HelloWorld::onTouchEnded, this);
	listener->onTouchCancelled = CC_CALLBACK_2(HelloWorld::onTouchCancelled, this);
	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);
	

	/*--�L�[�{�[�h����--*/
	auto keyboardListener = cocos2d::EventListenerKeyboard::create();
	keyboardListener->onKeyPressed = CC_CALLBACK_2(HelloWorld::onKeyPressed, this);
	keyboardListener->onKeyReleased = CC_CALLBACK_2(HelloWorld::onKeyReleased, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(keyboardListener, this);


	//�X�V����
	this->scheduleUpdate();

    return true;
}


//���t���[���̍X�V����
void HelloWorld::update(float delta)
{

	HackMan hackMan;

	hackMan.RegisterPlayer(m_player);

	hackMan.Play();
}

/*--�^�b�`�J�n���̊֐�--*/
bool HelloWorld::onTouchBegan(Touch* touch, Event* unused_event)
{
	//�^�b�`�����ӏ��̍��W���擾
	touchPos = touch->getLocation();

	/*--��ʂ̍������^�b�`�����ꍇ--*/
	if (touchPos.x < SCREEN_WIDTH / 2)
	{
		/*--�p�b�h�̈ʒu��ݒ�--*/
		m_sPad->setPosition(touchPos);
		m_sPadRight->setPosition(touchPos);
		m_sPadLeft->setPosition(touchPos);
		m_sPadUp->setPosition(touchPos);
		m_sPadDown->setPosition(touchPos);

		//�p�b�h��\��
		m_sPad->setVisible(true);
	}
	else
	{
		/*--��ʂ̉E�����^�b�`�����ꍇ--*/
		if (m_player[0].GetStockShoot())
		{
			/*--�S�t�������--*/

			//�S�t�̔���
		}		
	}

	return true;
}


/*--�^�b�`���̊֐�--*/
void HelloWorld::onTouchMoved(Touch* touch, Event* unused_event)
{
	/*--��x��\���ɂ���--*/
	m_sPadRight->setVisible(false);
	m_sPadLeft->setVisible(false);
	m_sPadUp->setVisible(false);
	m_sPadDown->setVisible(false);

	//�p�b�h�̒����̋󔒂̕�
	int center = 30;

	//���̒���
	int arrowSize = 120;

	//���݂̍��W���擾
	Vec2 pos = touch->getLocation();

	/*--��ʂ̍������^�b�`�����ꍇ--*/
	if (touchPos.x < SCREEN_WIDTH / 2)
	{
		/*--�c�������͈͓̔����ǂ����̔���--*/
		if (pos.y < touchPos.y + center &&pos.y > touchPos.y - center)
		{
			/*--�E�����̔���--*/
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

			/*--�������̔���--*/
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
			/*--�����c���͈͓̔����ǂ����̔���--*/
			/*--������̔���--*/
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

			/*--�������̔���--*/
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


/*--�^�b�`�I�����̊֐�--*/
void HelloWorld::onTouchEnded(Touch* touch, Event* unused_event)
{
	/*--�p�b�h���\��--*/
	m_sPad->setVisible(false);
	m_sPadRight->setVisible(false);
	m_sPadLeft->setVisible(false);
	m_sPadUp->setVisible(false);
	m_sPadDown->setVisible(false);

	m_player[0].ChangeSpd(Vec2(0.0f, 0.0f));
}


/*--�^�b�`�L�����Z�����̊֐�--*/
void HelloWorld::onTouchCancelled(Touch* touch, Event* unused_event)
{

}


/*--�L�[�{�[�h���͎��̊֐�--*/
void HelloWorld::onKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event * event)
{
	if (keyCode == EventKeyboard::KeyCode::KEY_UP_ARROW)
	{
		/*--��ړ�--*/
		m_player[1].ChangeSpd(Vec2(0.0f, PLAYER_SPD));
		m_player[1].GetSprite()->setRotation(90.0f);
		direction = UP;
	}
	else if (keyCode == EventKeyboard::KeyCode::KEY_DOWN_ARROW)
	{
		/*--���ړ�--*/
		m_player[1].ChangeSpd(Vec2(0.0f, -PLAYER_SPD));
		m_player[1].GetSprite()->setRotation(-90.0f);
		direction = DOWN;
	}
	else if (keyCode == EventKeyboard::KeyCode::KEY_RIGHT_ARROW)
	{
		/*--�E�ړ�--*/
		m_player[1].ChangeSpd(Vec2(PLAYER_SPD, 0.0f));
		m_player[1].GetSprite()->setRotation(180.0f);
		direction = RIGHT;
	}
	else if (keyCode == EventKeyboard::KeyCode::KEY_LEFT_ARROW)
	{
		/*--���ړ�--*/
		m_player[1].ChangeSpd(Vec2(-PLAYER_SPD, 0.0f));
		m_player[1].GetSprite()->setRotation(0.0f);
		direction = LEFT;
	}

	/*--SPACE�L�[�������ꂽ�ꍇ--*/
	if (keyCode == EventKeyboard::KeyCode::KEY_SPACE)
	{
		if (m_player[1].GetStockShoot())
		{
			/*--�S�t�������--*/

			//�S�t�̔���
			//move_mucus(direction)
		}
	}
}

 /*--�L�[�{�[�h���͏I�����̊֐�--*/
void HelloWorld::onKeyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event * event)
{
	/*--��L�[�𗣂����Ƃ��ɏ�ɐi��ł����ꍇ--*/
	if (keyCode == EventKeyboard::KeyCode::KEY_UP_ARROW && m_player[1].GetSpd()==Vec2(0.0f, PLAYER_SPD))
	{
		m_player[1].ChangeSpd(Vec2(0.0f, 0.0f));
	}
	
	/*--���L�[�𗣂����Ƃ��ɉ��ɐi��ł����ꍇ--*/
	if (keyCode == EventKeyboard::KeyCode::KEY_DOWN_ARROW && m_player[1].GetSpd() == Vec2(0.0f, -PLAYER_SPD))
	{
		m_player[1].ChangeSpd(Vec2(0.0f, 0.0f));
	}
	
	/*--�E�L�[�𗣂����Ƃ��ɉE�ɐi��ł����ꍇ--*/
	if (keyCode == EventKeyboard::KeyCode::KEY_RIGHT_ARROW && m_player[1].GetSpd() == Vec2(PLAYER_SPD,0.0f))
	{
		m_player[1].ChangeSpd(Vec2(0.0f, 0.0f));
	}
	
	/*--���L�[�𗣂����Ƃ��ɍ��ɐi��ł����ꍇ--*/
	if (keyCode == EventKeyboard::KeyCode::KEY_LEFT_ARROW && m_player[1].GetSpd() == Vec2(-PLAYER_SPD,0.0f))
	{
		m_player[1].ChangeSpd(Vec2(0.0f, 0.0f));
	}

}