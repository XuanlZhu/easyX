//
// Created by admin on 2026/7/14.
//

#include "SpriteList.h"



void SpriteList::Update(float _deltaTime) {
    ClearList();//清理
    for(auto sprite : mSprites)
    {
        if(sprite)
        {
            sprite->Update(_deltaTime);
        }
    }
}

void SpriteList::ClearList() {
    mSprites.erase(
        std::remove_if(mSprites.begin(),mSprites.end(),
            [](CSprite* _sprite)
            {
                return !_sprite->isdraw;
            }
        ),
        mSprites.end()
    );
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

void SpriteList::Append(CSprite* _sprite) {
    mSprites.push_back(_sprite);
}
