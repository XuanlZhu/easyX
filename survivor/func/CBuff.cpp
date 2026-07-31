//
// Created by admin on 2026/7/29.
//

#include "CBuff.h"

#include <iostream>

#include "Global.h"
#include "../unit/CUnit.h"
#include "Graphics/CEffect.h"

CBuff::~CBuff() {
    // std::cout << "CBuff开始析构" << std::endl;
    auto effect = mEffect.lock();
    if (effect) {
        effect->Destroy();
    }
}


void CBuff::Update(float _deltaTime) {
    // std::cout << "CBuff更新" << std::endl;
    if (mDeath) return;

    mElapsedTime += _deltaTime;
    if (mElapsedTime >= mDuration && mDuration!=-1) {
        this->Destroy();
    }
}

void CBuff::Destroy() {
    // std::cout << "buff开始销毁" << std::endl;
    OnDestroy();
    mBuffSystem->DestroyBuff(this);//buff系统移除
    //聚合器移除

    mDeath = true;
    // std::cout << "buff销毁完成" << std::endl;
}
void CBuff::OnCreated() {
    // std::cout << "buff创建" << std::endl;
    mEffect = CreateEffect("CEffect_stunned",CVector2(),mOwner.lock().get());
    // std::cout << "buff创建完成" << std::endl;
}

void CBuff::OnDestroy() {
    // std::cout << "buff当销毁OnDestroy" << std::endl;
    // 析构时，lock是没用的
}

