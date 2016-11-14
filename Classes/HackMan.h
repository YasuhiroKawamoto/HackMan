/********************************************/
/*内　容　ゲームクラスのヘッダーファイル	*/
/*制作者　加藤駿							*/
/*制作日　2016/11/14						*/
/********************************************/
#include "cocos2d.h"
#include "GameMain.h"
#include"Player.h"

#pragma once

//ゲームの制限時間
#define PLAY_TIME (60*60)
#define A_LITTLE (2)

/*--ゲームクラス--*/
class HackMan
{
private:
	Player* m_player[MAX_PLAYER];			//プレイヤー情報
	int m_map[MAP_H][MAP_W];				//マップ情報

public:
	HackMan();								//コンストラクタ
	~HackMan();								//デストラクタ
	void Play();							//ゲーム本編
	void RegisterPlayer(Player player[]);	//プレイヤーの登録

private:
	bool isFinished(int playTime);			//ゲームの終了判定
	
	//円の当たり判定
	bool collision(const OBJECT* A,const OBJECT* B);

};
