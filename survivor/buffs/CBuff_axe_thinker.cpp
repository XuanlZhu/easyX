//
// Created by admin on 2026/8/5.
//

#include "CBuff_axe_thinker.h"

#include "../unit/CUnit.h"
#include "../func/Global.h"

bool vector_has(std::vector<std::weak_ptr<CUnit>> vec,std::weak_ptr<CUnit> _unit) {
    bool has = false;
    for (auto& it : vec)
    {
        auto unit = it.lock();
        if (unit && unit.get() == _unit.lock().get())
        {
            has = true;
            break;
        }
    }
    return has;
}

CBuff_axe_thinker::CBuff_axe_thinker() {
    effect_name = "CEffect_axe";
    think_interval = 0.03f;//思考间隔
    mSpeed = CVector2(0,-600).Rotate(RandomInt(-15,15));
}

void CBuff_axe_thinker::OnIntervalThink() {
    auto owner =  mOwner.lock();
    owner->SetPosition(owner->GetPos()+mSpeed*think_interval);

    auto newSpeed = mSpeed - CVector2(0,-700)*think_interval;
    if (mSpeed.y<=0 && newSpeed.y>0) {last_hit = {};}//清空last_hit
    mSpeed = newSpeed;

    auto units = FindUnitsInRadius(3,owner->GetPos(),45/2,0);
    for (auto unit : units) {
        if (vector_has(last_hit,unit)){continue;};
        ApplyDamage(DamageContext{mCaster.lock().get(),unit.lock().get(),50});
        EmitSoundOn("axe_attack");
    }
    last_hit = units;
}

