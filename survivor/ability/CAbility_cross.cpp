//
// Created by admin on 2026/8/5.
//

#include "CAbility_cross.h"

#include "../func/CBuffManager.h"
#include "../func/Global.h"
#include "../unit/CUnit.h"
#include "Core/CVector2.h"

#include <nlohmann/json.hpp>
using json = nlohmann::json;

void CAbility_cross::OnSpellStart() {
    mLastCastTime = GetNowTime();//记录施法时间
    EmitSoundOn("whirling_ranged_cast");
    for (int i = 0; i < 3; i++) {
        CreateModifierThinker(mCaster,this,"CBuff_cross_thinker",json{{"duration", 3}},mCaster->GetPos(),1);
    }

}