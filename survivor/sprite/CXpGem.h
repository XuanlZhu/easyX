//
// Created by admin on 2026/8/3.
//

#pragma once
#include "Graphics/CSprite.h"


class CXpGem : public CSprite
{
public:
    CXpGem();
    void Pickup();
    void Update(float _deltaTime) override;
    bool isflying = false;
    float mSpeed=10;
    int BountyXP=0;
};
