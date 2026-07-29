#pragma once
#include <graphics.h>
#include <thread>
#include <atomic>
#include <chrono>

#include "CInput.h"
// using namespace std;

class CSprite;
class CScene;

class CGame
{
public:
    CGame(int _width = 800, int _height = 600);
    virtual ~CGame();

    void Start();//线程开启
    void Stop();//线程停止
    void Mainloop();//主循环
    void Run();//启动游戏
    void SetCurrentScene(CScene* _scene);//设置当前场景
    CScene* mCurrentScene;//当前场景
    virtual void OnKeyPress(int _key);
    virtual void OnKeyRelease(int _key);
    std::chrono::time_point<std::chrono::high_resolution_clock> mStartTime = std::chrono::high_resolution_clock::now();
protected:
    virtual void Setup();//初始化
    virtual void Update(float _deltaTime);//每帧更新
    virtual void Draw();//绘制
    virtual void ProcessInput();//输入处理
    int mWidth;
    int mHeight;
private:
    bool mRunning;
    std::thread mGameThread;
    CInput mInput;
};

