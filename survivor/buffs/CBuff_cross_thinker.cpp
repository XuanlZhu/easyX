//
// Created by admin on 2026/8/5.
//

#include "CBuff_cross_thinker.h"

#include "../unit/CUnit.h"
#include "../func/Global.h"

extern bool vector_has(std::vector<std::weak_ptr<CUnit>> vec,std::weak_ptr<CUnit> _unit);


CBuff_cross_thinker::CBuff_cross_thinker() {
    effect_name = "CEffect_cross";
    think_interval = 0.03f;//思考间隔
}
void CBuff_cross_thinker::OnCreated() {
    CBuff::OnCreated();
    CreateEffect("CEffect_fly_fire",CVector2(),mOwner.lock().get());

    auto units = FindUnitsInRadius(3, mCaster.lock()->GetPos(),100,0);
    if (units.size() > 0) {
        auto unit = units[0].lock();
        mSpeed = (unit->GetPos()-mCaster.lock()->GetPos()).Normalize()*600;
    }
}



void CBuff_cross_thinker::OnIntervalThink() {
    auto owner =  mOwner.lock();
    owner->SetPosition(owner->GetPos()+mSpeed*think_interval);

    CVector2 newSpeed;
    if (is_back) {
        newSpeed = mSpeed - (owner->GetPos()-mCaster.lock()->GetPos()).Normalize()*600*think_interval;
    }else {
        newSpeed = mSpeed - mSpeed.Normalize()*700*think_interval;
        if (newSpeed.Dot(mSpeed) < 0) {last_hit = {};is_back=true;}//清空last_hit
    }

    mSpeed = newSpeed;

    auto units = FindUnitsInRadius(3,owner->GetPos(),45/2,0);
    for (auto unit : units) {
        if (vector_has(last_hit,unit)){continue;};
        ApplyDamage(DamageContext{mCaster.lock().get(),unit.lock().get(),50});
        EmitSoundOn("axe_attack");
    }
    last_hit = units;
}

