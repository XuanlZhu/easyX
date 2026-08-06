//
// Created by admin on 2026/8/6.
//

#pragma once
#include "CBuff.h"
#include "Core/CVector2.h"


class CBuff_damage_aura : public CBuff
{
public:
    CBuff_damage_aura();
    void OnIntervalThink() override;
};
