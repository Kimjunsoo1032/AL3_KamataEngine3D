#pragma once
#include "KamataEngine.h"
class Player {
	Camera* camera_ = nullptr


public:
	void Initialize(Model* model, uint32_t texutreHandle, Camera* camera);
	void Update();
	void Draw();

private:
	WorldTransform worldTransform_;

	Model* model_ = nullptr;
	uint32_t textureHandle_ = 0u;
};
