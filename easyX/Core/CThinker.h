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
    void Destroy();
    bool IsDead(){return mIsDead;}
    void ChangeFunc(std::function<float()> _func, float _interval);


    std::function<float()> mFunc = []{return 0;};
    std::string mName;
    float mCreateTime = GetNowTime();
    float mElapsedTime = 0;
    float mInterval = 0;
private:
    bool mIsDead = false;
};
