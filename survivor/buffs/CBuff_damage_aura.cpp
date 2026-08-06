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
    if (caster) {std::cout << "caster正常" << std::endl;}
    if (ability) {std::cout << "ability正常" << std::endl;}

    EmitSoundOn("hoof_stomp");
    auto effect = CreateEffect("CEffect_circle",caster->GetPos(),nullptr).lock();
    effect->SetParticleControl(0,CVector2(100,0));

    // auto units = FindUnitsInRadius(3, caster->GetPos(),100,0);
    // for (auto& x: units) {
    //     auto unit = x.lock();
    //     ApplyDamage(DamageContext{caster,unit.get(),100});
    //     unit->AddNewModifier(caster,ability,"buff",json{{"duration", 1}});
    // }
}
