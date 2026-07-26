//
// Created by admin on 2026/7/26.
//

#pragma once
#include "Core/CVector2.h"
#include <graphics.h>
#include <memory>

class CCamera;
class CSprite;

class CEffect
{
public:
    CEffect();
    // CEffect(CVector2 _pos);
    virtual void Update(float _deltaTime);//更新
    virtual void Draw(CCamera& _camera);//绘制
    //是否死亡
    bool IsDead();
    std::weak_ptr<CSprite> mAttacher;//附着者
    CVector2 mPos;//位置
    float mLifeTime = 1;//生命时间
private:
    float mAge = 0;//已经存在时间
    float mRadius;//半径
    bool mIsAttach = false;//是否附着
    bool mIsDead = false;
};
