#include "GameScene.h"

using namespace KamataEngine;

//GameScene::~GameScene() { delete sprite_; }
GameScene::~GameScene() { delete model_; }

void GameScene::Initialize() {
	// メンバ変数への代入処理(省略)
	// ここにインゲームの初期化処理を書く
	textureHandle_ = TextureManager::Load("mario.jpg");
	sprite_ = Sprite::Create(textureHandle_, {100, 50});
	model_ = Model::Create();

	worldTransform_.Initialize();
	camera_.Initialize();

	//サウンドでーたの読み込み
	soundDataHandle_ = Audio::GetInstance()->LoadWave("fanfare.wav");
	//音楽再生
	Audio::GetInstance()->PlayWave(soundDataHandle_);
	// サウンドでーたの読み込み
	voiceHandle_ = Audio::GetInstance()->PlayWave(soundDataHandle_, true);
	;


}
void GameScene::Update() {
	// ここにインゲームの更新処理を書く
	Vector2 position = sprite_->GetPosition();
	
	position.x += 2.0f;
	position.y += 1.0f;

	//移動した座標をスプライトに反映
	sprite_->SetPosition(position);
	if (Input::GetInstance()->TriggerKey(DIK_SPACE)) {
		Audio::GetInstance()->StopWave(voiceHandle_);
	}
}
void GameScene::Draw() {
	//DirectXcommonインスタンスの取得
	DirectXCommon* dxCommon = DirectXCommon::GetInstance();
	////スプライト描画前処理
	//Sprite::PreDraw(dxCommon->GetCommandList());
	//sprite_->Draw();
	////スプライト描画後処理
	//Sprite::PostDraw();

	Model::PreDraw(dxCommon->GetCommandList());
	//ここに3Dモデルインスタンスの描画処理を記述する
	model_->Draw(worldTransform_, camera_, textureHandle_);

	Model::PostDraw();
	
}