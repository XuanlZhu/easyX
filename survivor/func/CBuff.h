//
// Created by admin on 2026/7/29.
//

#pragma once
#include <memory>

class CAbility;
class CUnit;


class CBuff {
public:
    void Update(float _deltaTime);//更新
    bool IsDead(){return mDeath;};
    void Destroy();//销毁
    void OnCreated();//当创建
    void OnDestroy();//当销毁

    float mElapsedTime = 0;//逝去时间
    float mDuration = -1;//持续时间
    bool mDeath = false;
    // bool isDestroying = false;
    std::weak_ptr<CUnit> mOwner;
    std::weak_ptr<CUnit> mCaster;
    std::weak_ptr<CAbility> mAbility;

};
