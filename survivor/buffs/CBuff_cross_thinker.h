//
// Created by admin on 2026/8/5.
//

#pragma once
#include "CBuff.h"
#include "Core/CVector2.h"


class CBuff_cross_thinker : public CBuff
{
public:
    CBuff_cross_thinker();
    void OnIntervalThink() override;
    void OnCreated() override;
    bool is_back=false;
    CVector2 mSpeed = CVector2(600,0);
    std::vector<std::weak_ptr<CUnit>> last_hit;
};
