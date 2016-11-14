//_/_/_/_/_/_/_/_/_/_/_/_/_/
// 粘液のヘッダファイル
//
// 2016/11/12
//
// AsakawaTasuku
//_/_/_/_/_/_/_/_/_/_/_/_/_/

#pragma once

#include"HelloWorldScene.h"

// 構造体宣言
//typedef struct tag_object
//{ 
//	float pos_x;					// 座標x
//	float pos_y;					// 座標y
//	float spd_x;					// 速度x
//	float spd_y;					// 速度y
//	bool isVisible;					// 1:表示　0:非表示
//	cocos2d::Sprite* m_pSprite;		// スプライト
//
//}OBJECT;

// 方向
//enum DIRECTION
//{
//	UP,
//	DOWN,
//	RIGHT,
//	LEFT,
//};

// Mucusクラス
class Mucus
{
	private:
		OBJECT m_mucus;		

	public:
		Mucus();											// 粘液のコンストラクタ
		~Mucus();											// 粘液のデストラクタ
		void initialize_mucus();							// 粘液の初期化処理
		void update_mucus(Mucus* m_mucus,HelloWorld* obj,int KeyCode);	// 粘液の更新処理
		void render_mucus(HelloWorld* obj);					// 粘液の描画処理
		void finalize_mucus();								// 粘液の終了処理
		void Mucus::move_mucus(Mucus* obj, int direction);			// 粘液の移動処理
		void destract_mucus();								// 粘液が壁に当たった時の処理
		void Mucus::setoff_mucus();							// 粘液同士が当たった時の処理
		

};


