/********************************************/
/*内　容　オブジェクトのヘッダーファイル	*/
/*制作者　加藤駿							*/
/*制作日　2016/11/11						*/
/********************************************/
// 多重インクルードの防止 ==================================================
#pragma once

#include "cocos2d.h"



// 定数の定義 ==============================================================

// ゲーム画面
#define SCREEN_WIDTH  960   // 幅[pixel]
#define SCREEN_HEIGHT 640   // 高さ[pixel]

/*-----[マップのサイズ]-----*/
#define MAP_W (SCREEN_WIDTH/32)		// ステージ　幅
#define MAP_H (SCREEN_HEIGHT/32)	// ステージ　高さ

//２次元ベクトル構造体
typedef struct tag_vector2
{
	float x;
	float y;

}VEC2;

//画像サイズ構造体
typedef struct tag_grp
{
	int x;
	int y;
	int w;
	int h;

}GRP;

//オブジェクト構造体
typedef struct tag_object
{
	//画像の情報
	cocos2d::Sprite* sprite;		
	GRP  grp;	//画像の幅と高さ
	
	VEC2 pos;	//座標
	VEC2 spd;	//速度

	int state;	//状態　２：元気　　
				//		１：粘液かけられ
				//		０：死亡

}OBJECT;			//オブジェクト用



