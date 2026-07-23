//
// Created by admin on 2026/7/22.
//

#include "CThinker.h"


//触发
void CThinker::Think() {
    mInterval = mFunc();
}
//更新
void CThinker::Update(float _deltaTime) {
    mElapsedTime += _deltaTime;
    if(mElapsedTime >= mInterval)
    {
        Think();//触发
        mElapsedTime = 0;
        //判断销毁
        if (mInterval<=0) {
            Destroy();
        }
    }
}

void CThinker::Destroy() {
    mIsDead = true;
    if(mOwner)
    {
        mOwner->RemoveThinker(mName);
        mOwner = nullptr;
    }
}

void CThinker::ChangeFunc(std::function<float()> _func, float _interval) {
    mFunc = std::move(_func);
    mInterval = _interval;
}
