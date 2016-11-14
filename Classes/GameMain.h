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
#define SCREEN_WIDTH  (960)				 // 幅[pixel]
#define SCREEN_HEIGHT (640)				 // 高さ[pixel]

/*--[マップチップサイズ]--*/
#define MAP_CHIP_W (64)					// マップチップ　幅
#define MAP_CHIP_H (MAP_CHIP_W)			// マップチップ　高さ (幅と同じ)

/*-----[マップのサイズ]-----*/
#define MAP_W (11)	// ステージ　幅
#define MAP_H (11)// ステージ　高さ


/*--方向--*/
enum DIRECTION
{
	NON = -1, //方向がない場合
	UP,
	DOWN,
	RIGHT,
	LEFT,
};

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
							
	cocos2d::Sprite* sprite;//画像の情報
	GRP  grp;				//画像の幅と高さ

	cocos2d::Vec2 pos;		//位置
	cocos2d::Vec2 spd;		//速度

	int state;				//状態　２：元気　　
							//		１：粘液かけられ
							//		０：死亡

}OBJECT;			//オブジェクト用



