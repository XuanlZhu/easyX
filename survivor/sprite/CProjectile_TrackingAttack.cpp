//
// Created by admin on 2026/8/7.
//

#include "CProjectile_TrackingAttack.h"

#include "../func/Global.h"
#include "ResourceManager/CImageManager.h"
#include "../unit/CUnit.h"
#include "../unit/CPlayer.h"
#include "Graphics/CEffect.h"
#include <memory>


CProjectile_TrackingAttack::CProjectile_TrackingAttack() {
    mImage = Global::imgManager->GetImage("PNG/tracking.png");
    mLength = 15;//长度
}

void CProjectile_TrackingAttack::Update(float _deltaTime) {
    if (!isInit) {
        isInit = true;
        // mEffect = CreateEffect(EffectName,CVector2(),this);//创建特效
    }
    //判断距离
    auto ability = Ability.lock();
    auto source = Source.lock();
    auto target = Target.lock();

    if (!source || !target){Destroy();return;}//如果目标没了，就销毁

    if (target) {
        auto dir = (target->GetPos()-mPos).Normalize();
        SetPosition(mPos+dir*iMoveSpeed*_deltaTime);//位移
    }
    //当命中
    if (CalcDistanceBetweenEntityOBB(this,target.get())<=10) {
        EmitSoundOn("ice_impact");
        auto attacker = std::dynamic_pointer_cast<CPlayer>(source);
        attacker->ProcessAttack(target.get());//计算攻击
        Destroy();return;
    }

}