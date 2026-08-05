//
// Created by admin on 2026/8/3.
//

#include "CProjectile.h"
#include "../func/Global.h"
#include "ResourceManager/CImageManager.h"
#include "../unit/CUnit.h"
#include "Graphics/CEffect.h"


CProjectile::CProjectile() {
    // mImage = Global::imgManager->GetImage("PNG/gem1.png");
    // mLength = fStartRadius/2;//长度
}

void CProjectile::Update(float _deltaTime) {
    if (!isInit) {
        isInit = true;
        mEffect = CreateEffect(EffectName,CVector2(),this);//创建特效
        mEffect.lock()->SetParticleControl(0,vVelocity);
        fExpireTime = fDistance/vVelocity.Length();//计算时间
    }

    fAge += _deltaTime;
    if (fAge>=fExpireTime) {Destroy();return;}

    float t = fAge / fExpireTime;  // 归一化时间 0~1
    float radius = fStartRadius +(fEndRadius - fStartRadius) * t;
    mLength = radius*2;//长度
    SetPosition(mPos+vVelocity*_deltaTime);//位移

    //搜索单位
    // std::vector<std::shared_ptr<CUnit>> result;
    auto ability = Ability.lock();

    auto units = FindUnitsInRadius(3,mPos,mLength/2,0);
    for (auto it : units) {
        auto unit = it.lock();
        // std::cout << "搜索单位，遍历" << std::endl;
        if (unit->GetTeam() == iUnitTargetTeam) {
            if (ability) {
                if (ability->OnProjectileHit(unit.get(),unit->GetPos(),ExtraData)){Destroy();return;}
            }
        }
    }
}


