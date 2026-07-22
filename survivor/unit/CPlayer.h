//
// Created by admin on 2026/7/17.
//

#pragma once
#include "Scene/CScene.h"


class CPlayer : public CSprite
{
public:
    using CSprite::CSprite;
    float mSpeed = 25.0f;
    void Update(float _deltaTime) override;
};
