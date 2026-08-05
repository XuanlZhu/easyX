//
// Created by admin on 2026/8/5.
//

#pragma once
#include "CBuff.h"
#include "Core/CVector2.h"


class CBuff_axe_thinker : public CBuff
{
public:
    CBuff_axe_thinker();
    void OnIntervalThink() override;
    CVector2 mSpeed;
    std::vector<std::weak_ptr<CUnit>> last_hit;
};
