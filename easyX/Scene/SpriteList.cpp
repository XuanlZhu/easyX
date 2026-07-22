//
// Created by admin on 2026/7/14.
//

#include "SpriteList.h"



void SpriteList::Update(float _deltaTime) {
    for(auto sprite : mSprites)
    {
        if(sprite)
        {
            sprite->Update(_deltaTime);
        }
    }
}

void SpriteList::Draw(CCamera& _camera)
{
    for(auto sprite : mSprites)
    {
        if(sprite)
        {
            sprite->Draw(_camera);
        }
    }
}

void SpriteList::Append(shared_ptr<CSprite> _sprite) {
    mSprites.push_back(_sprite);
}
