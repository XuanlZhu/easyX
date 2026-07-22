//
// Created by admin on 2026/7/14.
//

#pragma once
#include <functional>

class CInput
{
public:
    CInput();
    // 每帧更新输入状态
    void Update();
    // 当前是否按下
    bool IsKeyDown(int _key);
    // 事件回调
    std::function<void(int)> OnKeyDown;
    std::function<void(int)> OnKeyUp;
private:
    // 当前帧按键状态
    bool mKeyState[256] = {};
    // 上一帧按键状态
    bool mLastKeyState[256] = {};
};
