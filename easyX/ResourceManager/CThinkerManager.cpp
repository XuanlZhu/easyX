//
// Created by admin on 2026/7/22.
//

#include "CThinkerManager.h"

#include <iostream>
#include <utility>

void CThinkerManager::Update(float _deltaTime) {
    // std::cout << "CThinkerManager更新" << std::endl;
    for(auto& thinker : mThinkers)
    {
        thinker->Update(_deltaTime);
        // std::cout << "CThinker更新" << std::endl;
    }
    DestroyThinkers();//销毁
}

void CThinkerManager::DestroyThinkers()
{
    mThinkers.erase(
        std::remove_if(mThinkers.begin(),mThinkers.end(),
            [](std::shared_ptr<CThinker>& _thinker)
            {
                return _thinker->IsDead();
            }
        ),
        mThinkers.end()
    );
}

void CThinkerManager::CreateThinker(CEntity* _owner,std::function<float()> _func, int _interval) {
    std::shared_ptr<CThinker> thinker = std::make_shared<CThinker>();//创建thinker
    thinker->mOwner = _owner;
    thinker->mFunc = std::move(_func);
    thinker->mInterval = _interval;

    mThinkers.push_back(thinker);
}
