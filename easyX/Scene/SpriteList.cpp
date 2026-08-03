//
// Created by admin on 2026/7/14.
//

#include "SpriteList.h"

#include <iostream>
#include "../../survivor/func/Global.h"
#include "../../survivor/unit/CPlayer.h"


void SpriteList::Update(float _deltaTime) {

    auto sprites = mSprites;
    for(auto sprite : sprites)
    {
        if(sprite)
        {
            sprite->Update(_deltaTime);
        }
    }
    ClearList();//清理
}

void SpriteList::ClearList() {
    mSprites.erase(
        std::remove_if(mSprites.begin(),mSprites.end(),
            [](auto _sprite)
            {
                return !_sprite->isdraw;
            }
        ),
        mSprites.end()
    );
}

void SpriteList::Draw(CCamera& _camera)
{
    //裁切
    for(auto sprite : mSprites)
    {
        if((Global::player->GetPos()-sprite->GetPos()).Length()<=500)
        {
            sprite->Draw(_camera);
        }
    }
}

void SpriteList::Append(std::shared_ptr<CSprite> _sprite) {
    mSprites.push_back(_sprite);
}
