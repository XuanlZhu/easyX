//
// Created by admin on 2026/8/3.
//

#pragma once


#include <memory>
#include <string>
#include <vector>
class CSprite;
class CUnit;

class CSpriteManager {
public:
    std::shared_ptr<CSprite> GetSharedPtr(CSprite* _unit);
    std::shared_ptr<CSprite> CreateCSprite(std::string _sprite);//创建精灵，并下发到精灵表

    float mTime=0;
};