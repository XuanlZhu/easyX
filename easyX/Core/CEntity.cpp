//
// Created by admin on 2026/7/22.
//

#include "CEntity.h"

#include "CThinker.h"
#include "ResourceManager/CThinkerManager.h"
#include "../survivor/func/Global.h"
#include <utility>

void CEntity::SetContextThink(std::string _name, std::function<float()> _func, int _interval) {
    Global::thinkerManager->CreateThinker(this,std::move(_func),_interval);
}
