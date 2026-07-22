//
// Created by admin on 2026/7/22.
//

#pragma once
#include <functional>
#include "CEntity.h"
#include "../survivor/func/Global.h"


class CThinker
{
public:
    CEntity* mOwner = nullptr;
    virtual void Think();

    virtual void Update(float _deltaTime);
    void Destroy(){mIsDead = true;}
    bool IsDead(){return mIsDead;}


    std::function<float()> mFunc = []{return 0;};
    bool mIsDead = false;
    float mCreateTime = GetNowTime();
    float mElapsedTime = 0;
    float mInterval = 0;
};
