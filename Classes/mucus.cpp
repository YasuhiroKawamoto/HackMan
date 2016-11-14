//_/_/_/_/_/_/_/_/_/_/_/_/_/
// �S�t�̃\�[�X�t�@�C��
//
// 2016/11/12
//
// AsakawaTasuku
//_/_/_/_/_/_/_/_/_/_/_/_/_/

#include "mucus.h"
#include "HelloWorldScene.h"
#include "GameMain.h"

using namespace std;

#define SCREEN_W		(960)		// ��ʂ̕�
#define SCREEN_H		(640)		// ��ʂ̍���
#define MUCUS_SPEED		(5.0f)		// �S�t�̑���



//_/_/_/_/_/_/_/_/_/_/_/_/_/
// �S�t�̃R���X�g���N�^
//_/_/_/_/_/_/_/_/_/_/_/_/_/
Mucus::Mucus()
{
}

//_/_/_/_/_/_/_/_/_/_/_/_/_/
// �S�t�f�X�g���N�^
//_/_/_/_/_/_/_/_/_/_/_/_/_/
Mucus::~Mucus()
{

}

//_/_/_/_/_/_/_/_/_/_/_/_/_/
// �S�t�̏���������
//
// ����: �Ȃ�
//
// �߂�l:�Ȃ�
//_/_/_/_/_/_/_/_/_/_/_/_/_/
void Mucus::initialize_mucus()
{
	// �S�t�̏�����
	m_mucus.pos = 0;
	m_mucus.spd = 0;
	m_mucus.state = 0;
}

//_/_/_/_/_/_/_/_/_/_/_/_/_/
// �S�t�̍X�V����
//
// ����:����(HelloWorld*)
//
// �߂�l:�Ȃ�
//_/_/_/_/_/_/_/_/_/_/_/_/_/
void Mucus::update_mucus(Mucus* m_mucus, HelloWorld* obj,int direction)
{
	// �S�t�̕`��
	render_mucus(obj);
	
	// �S�t�̈ړ�
	move_mucus(m_mucus, direction);

}

//_/_/_/_/_/_/_/_/_/_/_/_/_/
// �S�t�̕`�揈��
//
// ����:����(HelloWorld*)
//
// �߂�l:�Ȃ�
//_/_/_/_/_/_/_/_/_/_/_/_/_/
void Mucus::render_mucus(HelloWorld* obj)
{
	m_mucus.sprite = cocos2d::Sprite::create("daiyou.png");
	m_mucus.sprite->setPosition(cocos2d::Vec2(SCREEN_W / 2, SCREEN_H / 2));
	obj->addChild(m_mucus.sprite);
	
}

//_/_/_/_/_/_/_/_/_/_/_/_/_/
// �S�t�̏I������
//
// ����:�Ȃ�
//
// �߂�l:�Ȃ�
//_/_/_/_/_/_/_/_/_/_/_/_/_/
void Mucus::finalize_mucus()
{

}

//_/_/_/_/_/_/_/_/_/_/_/_/_/
// �S�t�̈ړ�����
//
// ����:����(Mucus*,int)
//
// �߂�l:�Ȃ�
//_/_/_/_/_/_/_/_/_/_/_/_/_/
void Mucus::move_mucus(Mucus* obj, int direction)
{
	m_mucus.pos = obj->m_mucus.pos;
	m_mucus.state = 1;

	// �����Ă������
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

	// �S�t�̈ړ��v�Z
	if (m_mucus.state == 1)
	{
		m_mucus.pos += m_mucus.spd;
	}
}


//_/_/_/_/_/_/_/_/_/_/_/_/_/
// �S�t���ǂɓ����������̏���
//
// ����:�Ȃ�
//
// �߂�l:�Ȃ�
//_/_/_/_/_/_/_/_/_/_/_/_/_/
void Mucus::destract_mucus()
{
	// �ǂɓ���������
	if (m_mucus.state == true)
	{
		m_mucus.state = false;
	}
}

//_/_/_/_/_/_/_/_/_/_/_/_/_/
// �S�t���m�������������̏���
//
// ����:�Ȃ�
//
// �߂�l:�Ȃ�
//_/_/_/_/_/_/_/_/_/_/_/_/_/
void Mucus::setoff_mucus()
{
	if (m_mucus.state== true && m_mucus.state == true)
	{
		m_mucus.state = false;
	}
}


