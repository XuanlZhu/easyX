//
// Created by admin on 2026/8/7.
//

#pragma once
#include <string>

#include "Core/CVector2.h"

class CCamera;

class UIManager
{
public:
    void Update(float _deltaTime);//更新
    void Draw(CCamera& _camera);//绘制
    void PrintAttribute(std::string key);


    CVector2 printPos;
};
