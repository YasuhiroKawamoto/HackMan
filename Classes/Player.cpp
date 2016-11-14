/********************************************/
/*���@�e�@�v���C���[�N���X�̃\�[�X�t�@�C��	*/
/*����ҁ@�����x							*/
/*������@2016/11/12						*/
/********************************************/
#include "cocos2d.h"
#include"Player.h"
#include "GameMain.h"

//�{�[�[�[�[�[�[�[�[�[�[�[�[
//�b�@�@�\:�v���C���[�̃R���X�g���N�^
//�b���@��:�Ȃ�(void)
//�{�[�[�[�[�[�[�[�[�[�[�[�[
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
	m_resurrectionTime = 0;
	m_score = 0;
	m_shootStock = 0;
}


//�{�[�[�[�[�[�[�[�[�[�[�[�[
//�b�@�@�\:�v���C���[�̃f�X�g���N�^
//�{�[�[�[�[�[�[�[�[�[�[�[�[
Player::~Player()
{

}


//�{�[�[�[�[�[�[�[�[�[�[�[�[
//�b�@�@�\:�v���C���[�̑S�Ă̏���Ԃ�
//�b���@��:�Ȃ�(void)
//�b�Ԃ�l:�I�u�W�F�N�g�^�̏��(OBJECT)
//�{�[�[�[�[�[�[�[�[�[�[�[�[
OBJECT Player::GetObj()
{
	return m_player;
}

//�{�[�[�[�[�[�[�[�[�[�[�[�[
//�b�@�@�\:�v���C���[�̉摜����Ԃ�
//�b���@��:�Ȃ�(void)
//�b�Ԃ�l:�摜���(Sprite*)
//�{�[�[�[�[�[�[�[�[�[�[�[�[
cocos2d::Sprite * Player::GetSprite()
{
	return m_player.sprite;
}

//�{�[�[�[�[�[�[�[�[�[�[�[�[
//�b�@�@�\:�v���C���[�̈ʒu��Ԃ�
//�b���@��:�Ȃ�(void)
//�b�Ԃ�l:�ʒu(Vec2)
//�{�[�[�[�[�[�[�[�[�[�[�[�[
cocos2d::Vec2 Player::GetPos()
{
	return m_player.pos;
}

//�{�[�[�[�[�[�[�[�[�[�[�[�[
//�b�@�@�\:�v���C���[�̑��x��Ԃ�
//�b���@��:�Ȃ�(void)
//�b�Ԃ�l:���x(Vec2)
//�{�[�[�[�[�[�[�[�[�[�[�[�[
cocos2d::Vec2 Player::GetSpd()
{
	return m_player.spd;
}

//�{�[�[�[�[�[�[�[�[�[�[�[�[
//�b�@�@�\:�v���C���[�̏�Ԃ�Ԃ�
//�b���@��:�Ȃ�(void)
//�b�Ԃ�l:���(int)
//�{�[�[�[�[�[�[�[�[�[�[�[�[
int Player::GetState()
{
	return m_player.state;
}

//�{�[�[�[�[�[�[�[�[�[�[�[�[
//�b�@�@�\:�v���C���[�̏�Ԃ�Ԃ�
//�b���@��:�Ȃ�(void)
//�b�Ԃ�l:���(int)
//�{�[�[�[�[�[�[�[�[�[�[�[�[
bool Player::GetStockShoot()
{
	return m_shootStock;
}

//�{�[�[�[�[�[�[�[�[�[�[�[�[
//�b�@�@�\:�S�t�𔭎�
//�b���@��:�Ȃ�(void)
//�b�Ԃ�l:�Ȃ�(void)
//�{�[�[�[�[�[�[�[�[�[�[�[�[
void Player::Shoot()
{
	//�S�t�c�����O�ɂ���
	m_shootStock = false;
}

//�{�[�[�[�[�[�[�[�[�[�[�[�[
//�b�@�@�\:�S�t���X�g�b�N
//�b���@��:�Ȃ�(void)
//�b�Ԃ�l:�Ȃ�(void)
//�{�[�[�[�[�[�[�[�[�[�[�[�[
void Player::StockShoot()
{
	if (m_shootStock == false)
	{
		m_shootStock = true;
	}
}

//�{�[�[�[�[�[�[�[�[�[�[�[�[
//�b�@�@�\:�S�t���󂯂����̏���
//�b���@��:�Ȃ�(void)
//�b�Ԃ�l:�Ȃ�(void)
//�{�[�[�[�[�[�[�[�[�[�[�[�[
void Player::Damege()
{
	m_player.state--;
	m_resurrectionTime = 0;
}

//�{�[�[�[�[�[�[�[�[�[�[�[�[
//�b�@�@�\:�����̏���
//�b���@��:�Ȃ�(void)
//�b�Ԃ�l:�Ȃ�(void)
//�{�[�[�[�[�[�[�[�[�[�[�[�[
void Player::Resurrection()
{
	m_resurrectionTime++;

	if (m_resurrectionTime > 300)
	{
		m_player.state = 2;
	}
}

//�{�[�[�[�[�[�[�[�[�[�[�[�[
//�b�@�@�\:�v���C���[�̑��x��ύX
//�b���@��:���x(Vec2)
//�b�Ԃ�l:�Ȃ�(void)
//�{�[�[�[�[�[�[�[�[�[�[�[�[
void Player::ChangeSpd(cocos2d::Vec2 spd)
{
	m_player.spd = spd;
}

//�{�[�[�[�[�[�[�[�[�[�[�[�[
//�b�@�@�\:�v���C���[�̈ړ�
//�b���@��:�Ȃ�(void)
//�b�Ԃ�l:�Ȃ�(void)
//�{�[�[�[�[�[�[�[�[�[�[�[�[
void Player::Move()
{
	m_player.pos += m_player.spd;
}

//�{�[�[�[�[�[�[�[�[�[�[�[�[
//�b�@�@�\:�v���C���[�̕`��
//�b���@��:�Ȃ�(void)
//�b�Ԃ�l:�Ȃ�(void)
//�{�[�[�[�[�[�[�[�[�[�[�[�[
void Player::Draw()
{
	m_player.sprite->setPosition(m_player.pos);
}

