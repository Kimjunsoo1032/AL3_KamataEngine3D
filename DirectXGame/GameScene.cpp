#include "GameScene.h"
#include "MyMath.h"
using namespace KamataEngine;

// GameScene::~GameScene() { delete sprite_; }
GameScene::~GameScene() {
	delete model_;
	delete player_;
	for (std::vector<WorldTransform*>& worldTransformBlockLine : worldTransformBlock_) {
		for (WorldTransform* worldTransformBlock : worldTransformBlockLine) {
			delete worldTransformBlock;
		}
	}
	worldTransformBlocks_.clear();

}


void GameScene::Initialize() {
	// メンバ変数への代入処理(省略)
	// ここにインゲームの初期化処理を書く
	textureHandle_ = TextureManager::Load("mario.jpg");
	sprite_ = Sprite::Create(textureHandle_, {100, 50});
	model_ = Model::Create();

	worldTransform_.Initialize();
	camera_.Initialize();

	// サウンドでーたの読み込み
	soundDataHandle_ = Audio::GetInstance()->LoadWave("fanfare.wav");
	// 音楽再生
	Audio::GetInstance()->PlayWave(soundDataHandle_);
	// サウンドでーたの読み込み
	voiceHandle_ = Audio::GetInstance()->PlayWave(soundDataHandle_, true);
	;
	player_ = new Player();
	player_->Initialize(model_, textureHandle_, &camera_);
	//
	//
	const uint32_t kNumBlockVirtical = 10;
	const uint32_t kNumBlockHorizontal = 20;

	const float kBlockWidth = 2.0f;
	const float kBlockHeight = 2.0f;
	worldTransformBlocks_.resize(kNumBlockHorizontal);
	for (uint32_t i = 0; i < kNumBlockHorizontal; ++i) {
		for (uint32_t j = 0; j < kNumBlockHorizontal; i++) {
			worldTransformBlocks_[i][j] = new WorldTransform();
			worldTransformBlocks_[i][j]->Initialize();
			worldTransformBlocks_[i][j]->translation_.x = kBlockWidth * j;
			worldTransformBlocks_[i][j]->translation_.y = kBlockHeight * i;
		}
	}

	worldTransformBlocks_.resize(kNumBlockVirtical);
	for (uint32_t i = 0; i < kNumBlockVirtical; ++i) {
		worldTransformBlocks_[i].resize(kNumBlockHorizontal)
	}
}
void GameScene::Update() {
	// ここにインゲームの更新処理を書く
	Vector2 position = sprite_->GetPosition();

	position.x += 2.0f;
	position.y += 1.0f;

	// 移動した座標をスプライトに反映
	sprite_->SetPosition(position);
	if (Input::GetInstance()->TriggerKey(DIK_SPACE)) {
		Audio::GetInstance()->StopWave(voiceHandle_);
	}
	player_->Update();
	for (WorldTransform* worldTransformBlock : worldTransformBlocks_) {
		// 어핀계수행렬의 작성
		worldTransformBlock->matWorld_ = MakeAffineMatrix(worldTransformBlock->scale_, worldTransformBlock->rotation_, worldTransformBlock->translation_); // 어핀관수행렬
		worldTransformBlock->TransferMatrix();
	}
}
void GameScene::Draw() {
	// DirectXcommonインスタンスの取得
	DirectXCommon* dxCommon = DirectXCommon::GetInstance();
	////スプライト描画前処理
	// Sprite::PreDraw(dxCommon->GetCommandList());
	// sprite_->Draw();
	////スプライト描画後処理
	// Sprite::PostDraw();

	Model::PreDraw(dxCommon->GetCommandList());
	// ここに3Dモデルインスタンスの描画処理を記述する
	model_->Draw(worldTransform_, camera_, textureHandle_);
	player_->Draw();
	Model::PostDraw();
	for (WorldTransform* worldTransformBlock : worldTransformBlocks_) {
		modelBlock_->Draw(*worldTransformBlock, camera_);
	}
}