//
// Created by admin on 2026/7/17.
//

#include "CPlayer.h"
#include <cstdio>
#include <iostream>

void CPlayer::Update(float _deltaTime) {
    mPos.x += mChangeX * _deltaTime;
    mPos.y += mChangeY * _deltaTime;
    // outtextxy(100, 100, L"Hello EasyX");
    // std::cout << _deltaTime << std::endl;
    // std::cout << mChangeX << std::endl;
}
