#pragma once
#include "../easyX/Core/CGame.h"
class CMyGame: public CGame
{
public:
    CMyGame();
    ~CMyGame();
    void OnKeyPress(int _key) override;
    void OnKeyRelease(int _key) override;
    void Update(float _deltaTime) override;//每帧更新
    void Setup() override;
};

