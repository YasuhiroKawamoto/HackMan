/****************************************/
/*���@�e�@�Q�[���N���X�̃\�[�X�t�@�C��	*/
/*����ҁ@�����x						*/
/*������@2016/11/10					*/
/****************************************/
#include "cocos2d.h"
#include "GameMain.h"
#include"Player.h"
#include"HackMan.h"

USING_NS_CC;


//�{�[�[�[�[�[�[�[�[�[�[�[�[
//�b�@�@�\:�Q�[���̃R���X�g���N�^
//�b���@��:�Ȃ�(void)
//�{�[�[�[�[�[�[�[�[�[�[�[�[
HackMan::HackMan()
{
	//�}�b�v�f�[�^
	int map[MAP_H][MAP_W] =
	{
		{ 1,1,1,1,1,1,1,1,1,1,1 },
		{ 1,0,0,0,0,0,0,0,0,0,1 },
		{ 1,0,1,0,1,0,1,0,1,0,1 },
		{ 1,0,0,0,0,0,0,0,0,0,1 },
		{ 1,0,1,0,1,0,1,0,1,0,1 },
		{ 1,0,0,0,0,0,0,0,0,0,1 },
		{ 1,0,1,0,1,0,1,0,1,0,1 },
		{ 1,0,0,0,0,0,0,0,0,0,1 },
		{ 1,0,1,0,1,0,1,0,1,0,1 },
		{ 1,0,0,0,0,0,0,0,0,0,1 },
		{ 1,1,1,1,1,1,1,1,1,1,1 },
	};

	/*--�}�b�v�f�[�^�������o�[�ɕϊ�--*/
	for (int i = 0; i < MAP_H; i++)
	{
		for (int j = 0; j < MAP_W; j++)
		{
			m_map[i][j] = map[i][j];
		}
	}

}


//�{�[�[�[�[�[�[�[�[�[�[�[�[
//�b�@�@�\:�Q�[���̃f�X�g���N�^
//�{�[�[�[�[�[�[�[�[�[�[�[�[
HackMan::~HackMan()
{

}


//�{�[�[�[�[�[�[�[�[�[�[�[�[
//�b�@�@�\:�v���C���[�̓o�^
//�b���@��:�v���C���[(Player*[])
//�b�Ԃ�l:�Ȃ�(void)
//�{�[�[�[�[�[�[�[�[�[�[�[�[
void HackMan::RegisterPlayer(Player player[])
{
	for (int i = 0; i < MAX_PLAYER; i++)
	{
		m_player[i] = &player[i];
	}
}


//�{�[�[�[�[�[�[�[�[�[�[�[�[
//�b�@�@�\:�Q�[���{��
//�b���@��:�Ȃ�(void)
//�b�Ԃ�l:�Ȃ�(void)
//�{�[�[�[�[�[�[�[�[�[�[�[�[
void HackMan::Play()
{
	//�G���[���p
	OBJECT* obj;
	OBJECT player[MAX_PLAYER];

	//�v���C���Ԃ̃J�E���g�p
	int playTime = 0;

	
	/*--�Q�[���{��(���Ԍo�߂ŏI��)--*/
	while (isFinished(playTime) == false)
	{
		/*--�v���C���[�����R�s�[--*/
		for (int i = 0; i < MAX_PLAYER; i++)
		{
			player[i] = m_player[i]->GetObj();
		}

		/*--�v���C���[�̏���--*/
		for (int i = 0; i < MAX_PLAYER; i++)
		{
			//�ړ�
			m_player[i]->Move();
			
			//�`��
			m_player[i]->Draw();

			/*--��������--*/
			if (m_player[i]->GetState() == 1)
			{
				m_player[i]->Resurrection();
			}
		}


		/*--�v���C���[�ƔS�t�̔���--*/
		for (int i = 0; i < MAX_PLAYER; i++)
		{
			for (int j= 0;  j < /*�S�t�ő吔*/1 ; j++)
			{
				if (/*�S�t��state�̔���*/true)
				{
					/*--�������Ă�����--*/
					if (collision(&player[i],/*�S�t�ʒu*/obj))
					{
						//�v���C���[�Ƀ_���[�W
						m_player[i]->Damege();
					}
				}
			}
		}


		/*--�v���C���[���m�̓����蔻��--*/
		for (int i = 0; i < MAX_PLAYER; i++)
		{
			/*--�v���C���[�����C�ȏꍇ--*/
			if (m_player[i]->GetState() == 2)
			{
				for (int j = 0; j < MAX_PLAYER; j++)
				{
					/*--���肪�Ⴄ�v���C���[�̏ꍇ--*/
					if (i != j)
					{
						/*--�v���C���[�Ƒ��肪�������Ă����ꍇ--*/
						if (collision(&player[i], &player[j]))
						{
							/*--���肪�S�t��Ԃ̏ꍇ--*/
							if (m_player[j]->GetState() == 1)
							{
								m_player[j]->Damege();
							}
						}
					}
				}
			}
		}


		/*--�v���C���[�ƃG�T�̓����蔻��--*/
		for (int i = 0; i < MAX_PLAYER; i++)
		{
			for (int j = 0; j < /*�G�T�ő吔*/1; j++)
			{
				if (/*�G�T��state�̔���*/true)
				{
					/*--�������Ă�����--*/
					if (collision(&player[i],/*�G�T�ʒu*/obj))
					{
						//�S�t���X�g�b�N
						m_player[i]->StockShoot();
					}
				}
			}
		}
		
		//���Ԃ̃J�E���g
		playTime++;
	}
}


//�{�[�[�[�[�[�[�[�[�[�[�[�[
//�b�@�@�\:�Q�[���̏I������
//�b���@��:�v���C����(int)
//�b�Ԃ�l:�I������(bool)
//�{�[�[�[�[�[�[�[�[�[�[�[�[
bool HackMan::isFinished(int playTime)
{
	if (playTime > PLAY_TIME)
	{
		return true;
	}

	return false;
}

//�{�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�{
//�b�֐���:collision
//�b�@�\  :�~�̓����蔻�� �v�Z
//�b����  :�I�u�W�F�N�g (OBJECT*,OBJECT*)
//�b�߂�l:���� (int)
//�{�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�{
bool HackMan::collision(const OBJECT* A, const OBJECT* B)
{
	float x1 = A->pos.x;		//A���S���Wx
	float y1 = A->pos.y;		//A���S���Wy
	float x2 = B->pos.x;		//B���S���Wx
	float y2 = B->pos.y;		//B���S���Wy
	float r1 = A->grp.w / 2;	//A���a
	float r2 = B->grp.w / 2;	//B���a

	float X = x1 - x2;		//2�_�Ԃ̋�����
	float Y = y1 - y2;		//2�_�Ԃ̋�����
	float R = r1 + r2;		//2�̔��a�̘a

							/*-----[�����蔻��]-----*/
	if (X*X + Y*Y <= R*R)
	{
		//�������Ă����ꍇ
		return true;
	}

	//�������Ă��Ȃ��ꍇ
	return false;
}

