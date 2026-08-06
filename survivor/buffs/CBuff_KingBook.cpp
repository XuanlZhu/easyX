//
// Created by admin on 2026/8/6.
//

#include "CBuff_KingBook.h"

#include "../unit/CUnit.h"
#include "../func/Global.h"

extern bool vector_has(std::vector<std::weak_ptr<CUnit>> vec,std::weak_ptr<CUnit> _unit);


CBuff_KingBook::CBuff_KingBook() {
    effect_name = "CEffect_cross";
    think_interval = 0.03f;//思考间隔
}
void CBuff_KingBook::OnCreated() {
    CBuff::OnCreated();
    mOffset = mOwner.lock()->GetPos()-mCaster.lock()->GetPos();
}

void CBuff_KingBook::OnIntervalThink()
{
    auto owner = mOwner.lock();
    auto caster = mCaster.lock();

    owner->SetPosition(caster->GetPos()+mOffset.Rotate(5));
    mOffset = (owner->GetPos() - caster->GetPos());
    //伤害
    auto units = FindUnitsInRadius(3,owner->GetPos(),45/2,0);
    for (auto unit : units) {
        if (vector_has(last_hit,unit)){continue;};
        ApplyDamage(DamageContext{mCaster.lock().get(),unit.lock().get(),50});
        EmitSoundOn("axe_attack");
    }
    last_hit = units;
}

