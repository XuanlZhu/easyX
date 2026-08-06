//
// Created by admin on 2026/8/6.
//

#include "CBuff_damage_aura.h"
#include "../func/Global.h"
#include "Graphics/CEffect.h"
#include "../unit/CUnit.h"

CBuff_damage_aura::CBuff_damage_aura() {
    think_interval = 1;//思考间隔
}

void CBuff_damage_aura::OnIntervalThink() {
    auto caster = mCaster.lock().get();
    auto ability = mAbility.lock().get();

    EmitSoundOn("butterfly");
    auto effect = CreateEffect("CEffect_damage_aura",caster->GetPos(),caster).lock();
    effect->SetParticleControl(0,CVector2(125,0));

    auto units = FindUnitsInRadius(3, caster->GetPos(),125,0);
    for (auto& x: units) {
        auto unit = x.lock();
        ApplyDamage(DamageContext{caster,unit.get(),34});
        // unit->AddNewModifier(caster,ability,"buff",json{{"duration", 1}});
    }
}
