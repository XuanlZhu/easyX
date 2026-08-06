//
// Created by admin on 2026/8/6.
//

#include "CAbility_water.h"

#include "../func/CBuffManager.h"
#include "../func/Global.h"
#include "../unit/CUnit.h"
#include "Core/CVector2.h"

#include <nlohmann/json.hpp>
using json = nlohmann::json;

void CAbility_water::OnSpellStart() {
    mLastCastTime = GetNowTime();//记录施法时间
    
    // EmitSoundOn("whirling_ranged_cast");
    CreateModifierThinker(mCaster,this,"CBuff_KingBook",json{{"duration", 5}},mCaster->GetPos()+CVector2(0,-length),1);

}