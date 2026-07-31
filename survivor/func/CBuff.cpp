//
// Created by admin on 2026/7/29.
//

#include "CBuff.h"

#include <iostream>

#include "Global.h"
#include "../unit/CUnit.h"
#include "Graphics/CEffect.h"

CBuff::~CBuff() {
    auto effect = mEffect.lock();
    if (effect) {
        effect->Destroy();
    }
}


void CBuff::Update(float _deltaTime) {
    mElapsedTime += _deltaTime;
    if (mElapsedTime >= mDuration && mDuration!=-1) {
        this->Destroy();
    }
}

void CBuff::Destroy() {
    // std::cout << "buff开始销毁" << std::endl;
    mBuffSystem->DestroyBuff(this);//buff系统移除
    //聚合器移除

    OnDestroy();
    mDeath = true;
    // std::cout << "buff销毁完成" << std::endl;
}
void CBuff::OnCreated() {
    // std::cout << "buff创建" << std::endl;
    mEffect = CreateEffect("CEffect_stunned",CVector2(),mOwner.lock().get());
}

void CBuff::OnDestroy() {
    // std::cout << "buff销毁" << std::endl;
    // 析构时，lock是没用的
}

