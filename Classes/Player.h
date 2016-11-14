/********************************************/
/*内　容　プレイヤークラスのヘッダーファイル*/
/*制作者　加藤駿							*/
/*制作日　2016/11/14						*/
/********************************************/
#pragma once

#include "cocos2d.h"
#include "GameMain.h"

#define MAX_PLAYER (2)
#define PLAYER_SPD (5.0f/60.0f/60.0f)

class Player
{
private:
	OBJECT m_player;					//プレイヤー情報
	int m_score;						//スコア
	int m_resurrectionTime;				//復活までの時間
	bool m_shootStock;					//粘液のストック

public:
	Player();							//コンストラクタ
	~Player();							//デストラクタ
	OBJECT GetObj();					//全ての情報を返す
	cocos2d::Sprite* GetSprite();		//画像情報を返す
	cocos2d::Vec2 GetPos();				//位置を返す
	cocos2d::Vec2 GetSpd();				//速度を返す
	int GetState();						//状態を返す
	bool GetStockShoot();				//粘液のストック
	void Shoot();						//粘液を発射
	void StockShoot();					//粘液を追加
	void Damege();						//粘液を受けた時の処理
	void Resurrection();				//復活の処理
	void ChangeSpd(cocos2d::Vec2 spd);	//速度の変更
	void Move();						//移動
	void Draw();						//描画
};