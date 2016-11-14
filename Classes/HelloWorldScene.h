#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include"Player.h"

class HelloWorld : public cocos2d::Layer
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();

    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);

	//�֐��̐錾
	void update(float delta) override;

	/*--�p�b�h�摜--*/
	cocos2d::Sprite* m_sPad;
	cocos2d::Sprite* m_sPadRight;
	cocos2d::Sprite* m_sPadLeft;
	cocos2d::Sprite* m_sPadUp;
	cocos2d::Sprite* m_sPadDown;
	
	//�^�b�`�ʒu�ۑ��p
	cocos2d::Vec2 touchPos;

	//�v���C���[����
	Player m_player[MAX_PLAYER];

	/*--�^�b�`�C�x���g�p�֐�--*/
	bool onTouchBegan(cocos2d::Touch * touch, cocos2d::Event * unused_event);
	void onTouchMoved(cocos2d::Touch * touch, cocos2d::Event * unused_event);
	void onTouchEnded(cocos2d::Touch * touch, cocos2d::Event * unused_event);
	void onTouchCancelled(cocos2d::Touch * touch, cocos2d::Event * unused_event);

	//�L�[�{�[�h�p
	void onKeyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event *event);
	void onKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event * event);

};

#endif // __HELLOWORLD_SCENE_H__
