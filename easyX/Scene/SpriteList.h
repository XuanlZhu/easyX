//
// Created by admin on 2026/7/14.
//

#pragma once
#include <memory>
#include <vector>

#include "Graphics/CSprite.h"
using namespace std;

class CCamera;

class SpriteList {
public:
    void Draw(CCamera& _camera);//绘制
    void Append(std::shared_ptr<CSprite> _sprite);//添加精灵
    void Update(float _deltaTime);//更新
    void ClearList();//清理表
    // vector<CSprite*> mSprites;
    std::vector<std::shared_ptr<CSprite>> mSprites;
};
