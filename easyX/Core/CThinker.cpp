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
