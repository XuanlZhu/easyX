#include "../survivor/CMyGame.h"
#include "../easyX/Core/EKey.h"
#include "func/Global.h"
#include "map/CScene1.h"
#include "ResourceManager/CImageManager.h"
#include "ResourceManager/CThinkerManager.h"
#include "Scene/CScene.h"
#include "unit/CPlayer.h"

CMyGame::CMyGame() {

}

CMyGame::~CMyGame() {
    delete mCurrentScene;//场景
    delete Global::imgManager;//图片管理器
    delete Global::thinkerManager;//thinker管理器
}

void CMyGame::Setup() {
    CGame::Setup();//父类
    Global::unitJson = LoadJson("npc_unit.json");//加载json文件
    Global::scene = new CScene1();//生成场景
    Global::game->SetCurrentScene(Global::scene);//设置场景
    Global::imgManager = new CImageManager();//设置图片管理器
    Global::thinkerManager = new CThinkerManager();//thinker管理器
    //生成玩家
    Global::player = CreateUnitByName("player", CVector2(5000,5000), nullptr, 1).lock();
    Global::scene->SetPlayer(Global::player.get());//设置玩家
}
void CMyGame::Update(float _deltaTime) {
    CGame::Update(_deltaTime);//父类
    mCurrentScene->mSpriteList.Update(_deltaTime);//精灵更新
    //控制相机,
    mCurrentScene->mCamera.SetPosition(mCurrentScene->mPlayer->GetPos()-CVector2(mWidth/2, mHeight/2));

}


void CMyGame::OnKeyPress(int _key) {
    if (!mCurrentScene->mPlayer){return;}
    CSprite& player = *mCurrentScene->mPlayer;
    //移动
    if (_key == EKey::A){
        player.mChangeX = -player.mSpeed;
    }
    else if (_key == EKey::D){
        player.mChangeX = +player.mSpeed;
    }
    else if (_key == EKey::W){
        player.mChangeY = -player.mSpeed;
    }
    else if (_key == EKey::S){
        player.mChangeY = player.mSpeed;
    }
}

void CMyGame::OnKeyRelease(int _key) {
    if (!mCurrentScene->mPlayer){return;}
    CSprite& player = *mCurrentScene->mPlayer;
    //移动
    if (_key == EKey::A){
        player.mChangeX = 0;
    }
    else if (_key == EKey::D){
        player.mChangeX = 0;
    }
    else if (_key == EKey::W){
        player.mChangeY = 0;
    }
    else if (_key == EKey::S){
        player.mChangeY = 0;
    }
}


