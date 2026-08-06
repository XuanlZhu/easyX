//
// Created by admin on 2026/8/6.
//

#pragma once
#include "CBuff.h"
#include "Core/CVector2.h"


class CBuff_KingBook : public CBuff
{
public:
    CBuff_KingBook();
    void OnIntervalThink() override;
    void OnCreated() override;
    bool is_back=false;
    CVector2 mSpeed = CVector2(600,0);
    std::vector<std::weak_ptr<CUnit>> last_hit;

    CVector2 mOffset;
};
