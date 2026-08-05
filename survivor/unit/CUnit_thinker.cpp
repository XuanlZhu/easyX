//
// Created by admin on 2026/8/5.
//

#include "CUnit_thinker.h"


void CUnit_thinker::Update(float _deltaTime) {
    if (!thinker_buff.lock()) {
        OnDeath();return;
    }
}
