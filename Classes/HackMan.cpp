/****************************************/
/*内　容　ゲームクラスのソースファイル	*/
/*制作者　加藤駿						*/
/*制作日　2016/11/10					*/
/****************************************/
#include "cocos2d.h"
#include "GameMain.h"
#include"Player.h"
#include"HackMan.h"

USING_NS_CC;


//＋ーーーーーーーーーーーー
//｜機　能:ゲームのコンストラクタ
//｜引　数:なし(void)
//＋ーーーーーーーーーーーー
HackMan::HackMan()
{
	//マップデータ
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

	/*--マップデータをメンバーに変換--*/
	for (int i = 0; i < MAP_H; i++)
	{
		for (int j = 0; j < MAP_W; j++)
		{
			m_map[i][j] = map[i][j];
		}
	}

}


//＋ーーーーーーーーーーーー
//｜機　能:ゲームのデストラクタ
//＋ーーーーーーーーーーーー
HackMan::~HackMan()
{

}


//＋ーーーーーーーーーーーー
//｜機　能:プレイヤーの登録
//｜引　数:プレイヤー(Player*[])
//｜返り値:なし(void)
//＋ーーーーーーーーーーーー
void HackMan::RegisterPlayer(Player player[])
{
	for (int i = 0; i < MAX_PLAYER; i++)
	{
		m_player[i] = &player[i];
	}
}


//＋ーーーーーーーーーーーー
//｜機　能:ゲーム本編
//｜引　数:なし(void)
//｜返り値:なし(void)
//＋ーーーーーーーーーーーー
void HackMan::Play()
{
	//エラー回避用
	OBJECT* obj;
	OBJECT player[MAX_PLAYER];

	//プレイ時間のカウント用
	int playTime = 0;

	
	/*--ゲーム本編(時間経過で終了)--*/
	while (isFinished(playTime) == false)
	{
		/*--プレイヤー情報をコピー--*/
		for (int i = 0; i < MAX_PLAYER; i++)
		{
			player[i] = m_player[i]->GetObj();
		}

		/*--プレイヤーの処理--*/
		for (int i = 0; i < MAX_PLAYER; i++)
		{
			//移動
			m_player[i]->Move();
			
			//描画
			m_player[i]->Draw();

			/*--復活処理--*/
			if (m_player[i]->GetState() == 1)
			{
				m_player[i]->Resurrection();
			}
		}


		/*--プレイヤーと粘液の判定--*/
		for (int i = 0; i < MAX_PLAYER; i++)
		{
			for (int j= 0;  j < /*粘液最大数*/1 ; j++)
			{
				if (/*粘液のstateの判定*/true)
				{
					/*--当たっていたら--*/
					if (collision(&player[i],/*粘液位置*/obj))
					{
						//プレイヤーにダメージ
						m_player[i]->Damege();
					}
				}
			}
		}


		/*--プレイヤー同士の当たり判定--*/
		for (int i = 0; i < MAX_PLAYER; i++)
		{
			/*--プレイヤーが元気な場合--*/
			if (m_player[i]->GetState() == 2)
			{
				for (int j = 0; j < MAX_PLAYER; j++)
				{
					/*--相手が違うプレイヤーの場合--*/
					if (i != j)
					{
						/*--プレイヤーと相手が当たっていた場合--*/
						if (collision(&player[i], &player[j]))
						{
							/*--相手が粘液状態の場合--*/
							if (m_player[j]->GetState() == 1)
							{
								m_player[j]->Damege();
							}
						}
					}
				}
			}
		}


		/*--プレイヤーとエサの当たり判定--*/
		for (int i = 0; i < MAX_PLAYER; i++)
		{
			for (int j = 0; j < /*エサ最大数*/1; j++)
			{
				if (/*エサのstateの判定*/true)
				{
					/*--当たっていたら--*/
					if (collision(&player[i],/*エサ位置*/obj))
					{
						//粘液をストック
						m_player[i]->StockShoot();
					}
				}
			}
		}
		
		//時間のカウント
		playTime++;
	}
}


//＋ーーーーーーーーーーーー
//｜機　能:ゲームの終了判定
//｜引　数:プレイ時間(int)
//｜返り値:終了判定(bool)
//＋ーーーーーーーーーーーー
bool HackMan::isFinished(int playTime)
{
	if (playTime > PLAY_TIME)
	{
		return true;
	}

	return false;
}

//＋ーーーーーーーーーーーーーーーーーーーー＋
//｜関数名:collision
//｜機能  :円の当たり判定 計算
//｜引数  :オブジェクト (OBJECT*,OBJECT*)
//｜戻り値:結果 (int)
//＋ーーーーーーーーーーーーーーーーーーーー＋
bool HackMan::collision(const OBJECT* A, const OBJECT* B)
{
	float x1 = A->pos.x;		//A中心座標x
	float y1 = A->pos.y;		//A中心座標y
	float x2 = B->pos.x;		//B中心座標x
	float y2 = B->pos.y;		//B中心座標y
	float r1 = A->grp.w / 2;	//A半径
	float r2 = B->grp.w / 2;	//B半径

	float X = x1 - x2;		//2点間の距離ｘ
	float Y = y1 - y2;		//2点間の距離ｙ
	float R = r1 + r2;		//2つの半径の和

							/*-----[当たり判定]-----*/
	if (X*X + Y*Y <= R*R)
	{
		//当たっていた場合
		return true;
	}

	//当たっていない場合
	return false;
}

