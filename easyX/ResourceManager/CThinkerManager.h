//
// Created by admin on 2026/7/22.
//

#pragma once
#include <memory>
#include <vector>

#include "Core/CEntity.h"
// #include "Core/CThinker.h"

class CThinker;

class CThinkerManager
{
public:
    std::weak_ptr<CThinker> CreateThinker(CEntity* _owner,std::function<float()> _func, float _interval,std::string _name);//创建thinker
    void Update(float _deltaTime);//更新
private:
    void DestroyThinkers();//销毁thinker
    std::vector<std::shared_ptr<CThinker>> mThinkers;
};
