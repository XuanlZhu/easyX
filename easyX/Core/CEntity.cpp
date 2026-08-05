//
// Created by admin on 2026/7/22.
//

#include "CEntity.h"

#include "CThinker.h"
#include "ResourceManager/CThinkerManager.h"
#include "../survivor/func/Global.h"
#include <utility>

CEntity::~CEntity()
{
    for(auto& pair : thinkerTable)
    {
        auto thinker = pair.second.lock();
        if(thinker)
        {
            thinker->Destroy();
        }
    }
    thinkerTable.clear();
}

void CEntity::SetContextThink(std::string _name, std::function<float()> _func, float _interval) {
    // thinkerTable[_name] = thinker;
    auto it = thinkerTable.find(_name);
    //如果存在
    if(it != thinkerTable.end())
    {
        it->second.lock()->ChangeFunc(std::move(_func), _interval);
    }else {
        auto thinker = Global::thinkerManager->CreateThinker(this,std::move(_func),_interval,_name);
        thinkerTable[_name] = thinker;
    }
}

void CEntity::RemoveThinker(std::string _name)
{
    auto it = thinkerTable.find(_name);
    if(it != thinkerTable.end())
    {
        thinkerTable.erase(it);
    }
}

std::string CEntity::GetName() {
    std::string name = typeid(*this).name();
    name = name.substr(6);
    return name;
};
