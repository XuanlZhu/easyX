#include "CGame.h"
#include <chrono>
#include <iostream>

#include "EKey.h"
#include "Scene/CScene.h"
#include "../survivor/func/Global.h"
#include "ResourceManager/CEffectManager.h"
#include "ResourceManager/CThinkerManager.h"
#include "ResourceManager/CUnitManager.h"
#include "../survivor/func/CBuffManager.h"

CGame::CGame(int _width, int _height) {
    mWidth = _width;
    mHeight = _height;

    //创建EasyX窗口
    initgraph(mWidth, mHeight);
    setbkmode(TRANSPARENT);//文字透明模式，
    // mInput = CInput();

    mInput.OnKeyDown = [this](int _key)
    {
        OnKeyPress(_key);
    };
    mInput.OnKeyUp = [this](int _key)
    {
        OnKeyRelease(_key);
    };
}

CGame::~CGame()
{
    closegraph();//关闭图形窗口
}
//开始线程
void CGame::Start()
{
    mRunning = true;
    mGameThread = std::thread(&CGame::Mainloop,this);//调用对象的Mainloop
}
//停止线程
void CGame::Stop()
{
    if (mGameThread.joinable())
    {
        mGameThread.join();
        mRunning = false;
    }
}
//主循环
void CGame::Mainloop()
{
    const float targetFPS = 60.0f;
    auto frameTime = std::chrono::duration<float>(1.0f / targetFPS);//帧时间
    auto lastTime = std::chrono::high_resolution_clock::now();//上一帧的时间

    while (mRunning)
    {
        auto frameStart = std::chrono::high_resolution_clock::now();//帧开始
        float deltaTime =std::chrono::duration<float>(frameStart - lastTime).count();//逝去时间
        lastTime = frameStart;

        ProcessInput();//输入
        Update(deltaTime);//更新
        BeginBatchDraw();
        cleardevice();
        Draw();//绘制
        EndBatchDraw();

        //限制帧率
        auto frameEnd = std::chrono::high_resolution_clock::now();
        auto usedTime = frameEnd - frameStart;
        if(usedTime < frameTime)
        {
            std::this_thread::sleep_for(frameTime - usedTime);
        }
    }
}

void CGame::Run()
{
    Setup();//初始化
    mCurrentScene->Init();//场景初始化

    Start();//启动线程
}
//设置当前场景
void CGame::SetCurrentScene(CScene* _scene) {
    mCurrentScene = _scene;
}

//当键盘按下
void CGame::OnKeyPress(int _key) {
    // if (!mCurrentScene->mPlayer){return;}
    // CSprite& player = *mCurrentScene->mPlayer;
    //
    // if (_key == EKey::A){
    //     player.mChangeX = -player.mSpeed;
    // }
    // else if (_key == EKey::D){
    //     player.mChangeX = player.mSpeed;
    // }
    // else if (_key == EKey::W){
    //     player.mChangeY = player.mSpeed;
    // }
    // else if (_key == EKey::S){
    //     player.mChangeY = -player.mSpeed;
    // }
}

void CGame::OnKeyRelease(int _key) {
    // if (!mCurrentScene->mPlayer){return;}
    // CSprite& player = *mCurrentScene->mPlayer;
    //
    // if (_key == EKey::A){
    //     player.mChangeX = 0;
    // }
    // else if (_key == EKey::D){
    //     player.mChangeX = 0;
    // }
    // else if (_key == EKey::W){
    //     player.mChangeY = 0;
    // }
    // else if (_key == EKey::S){
    //     player.mChangeY = 0;
    // }
}

//初始化
void CGame::Setup()
{
}
//更新
void CGame::Update(float _deltaTime)
{
    Global::thinkerManager->Update(_deltaTime);//定时器
    Global::effectManager->Update(_deltaTime);//特效
    Global::buffManager->Update(_deltaTime);//buff管理器//可能情况：buff还在，owner不在了
    Global::spriteList->Update(_deltaTime);//精灵表使用裸指针,精灵表的清除要放在前面
    Global::unitManager->Update(_deltaTime);//单位管理器//只做清理

}
//绘制函数
void CGame::Draw()
{
    if (mCurrentScene)
    {
        mCurrentScene->Draw();
    }
}
//输入
void CGame::ProcessInput()
{
    mInput.Update();//输入更新
    // if(mCurrentScene)
    // {
    //     mCurrentScene->ProcessInput();
    // }
}
