//
// Created by admin on 2026/7/14.
//

#include "CScene.h"
// #include <string>
// using namespace std;
#include "../survivor/func/Global.h"
#include "ResourceManager/CEffectManager.h"

CScene::CScene() {
    // mCTileMap = CTileMap("Project/map1.csv");
}

CScene::~CScene() {
}

void CScene::Init() {
    //加载资源
    // mPlayer.Load("player.png");
    // mEnemyTexture.Load("enemy.png");
    //创建对象
    //初始化地图
    //设置相机
}

void CScene::Update(float deltaTime) {
    // mThinkerManager.Update(_deltaTime);//定时器

    // mCollision.Update();//碰撞器
}


void CScene::Draw()
{
    //背景绘制
    mCTileMap.Draw(mCamera);//瓦片地图绘制
    mSpriteList.Draw(mCamera);//精灵表绘制，还没做裁切
    Global::effectManager->Draw(mCamera);//特效绘制
    //UI绘制
}
//设置玩家
void CScene::SetPlayer(CSprite *_player) {
    mPlayer = _player;
}

void CScene::ProcessInput() {
    // 接收输入，并把输入分发给当前场景里的对象
}
