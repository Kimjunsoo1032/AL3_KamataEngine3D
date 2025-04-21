#pragma once
#include "KamataEngine.h"
#include "Player.h"
#include <vector>
class GameScene {

	uint32_t textureHandle_ = 0;

	KamataEngine::Sprite* sprite_ = nullptr;

	KamataEngine::Model* model_ = nullptr;
	
	KamataEngine::WorldTransform worldTransform_;
	KamataEngine::Camera camera_;

	//サウンドデータハンドル
	uint32_t soundDataHandle_ = 0;
	// サウンドデータハンドル
	uint32_t voiceHandle_ = 0;
	Player* player_ = nullptr;
	//std::vector<WorldTransform*> worldTransformBlocks_;
	std::vector<std::vector<WorldTransform*>> worldTransformBlocks_;

public:
	~GameScene();
	void Initialize();
	void Update();
	void Draw();

};

