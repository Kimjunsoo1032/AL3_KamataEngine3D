#pragma once
#include "KamataEngine.h"
class Player {
	KamataEngine::Sprite* sprite_ = nullptr;
	KamataEngine::Camera* camera_ = nullptr;

public:
	void Initialize(KamataEngine::Model* model, uint32_t texutreHandle, KamataEngine::Camera* camera);
	void Update();
	void Draw();

private:
	KamataEngine::WorldTransform worldTransform_;
	KamataEngine::Model* model_ = nullptr;
	uint32_t textureHandle_ = 0u;
};
