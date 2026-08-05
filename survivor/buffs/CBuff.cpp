//
// Created by admin on 2026/7/29.
//

#include "CBuff.h"

#include <iostream>

#include "../func/Global.h"
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
    if (mDestroying) return;//当自己死亡

    //思考
    think_time += _deltaTime;
    if (think_interval != -1 && think_time >= think_interval) {
        think_time = 0;
        OnIntervalThink();
    }
    //计时
    mElapsedTime += _deltaTime;
    if (mElapsedTime >= mDuration && mDuration!=-1) {
        this->Destroy();
    }
}

void CBuff::Destroy() {
    // std::cout << "buff开始销毁" << std::endl;
    OnDestroy();
    mBuffSystem->DestroyBuff(this);//buff系统移除
    mAttributeSystem->UnregisterModifier(this);//属性系统移除

    mDestroying = true;
    // std::cout << "buff销毁完成" << std::endl;
}
void CBuff::OnCreated() {
    // std::cout << "buff创建" << std::endl;
    if (effect_name!="") {
        mEffect = CreateEffect(effect_name,CVector2(),mOwner.lock().get());
    }
    // std::cout << "buff创建完成" << std::endl;
}

void CBuff::OnDestroy() {
    // std::cout << "buff当销毁OnDestroy" << std::endl;
    // 析构时，lock是没用的
}

