//
// Created by admin on 2026/7/29.
//

#include "CBuff.h"

#include <iostream>

#include "../unit/CUnit.h"

void CBuff::Update(float _deltaTime) {
    mElapsedTime += _deltaTime;
    if (mElapsedTime >= mDuration && mDuration!=-1) {
        this->Destroy();
    }
}

void CBuff::Destroy() {
    auto owner = mOwner.lock();
    owner->mBuffSystem.DestroyBuff(this);//buff系统移除
    //聚合器移除

    OnDestroy();
    mDeath = true;
}
void CBuff::OnCreated() {
    std::cout << "buff创建" << std::endl;
}

void CBuff::OnDestroy() {

}
