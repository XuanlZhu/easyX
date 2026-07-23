//
// Created by admin on 2026/7/20.
//

#pragma once
#include <string>
#include <nlohmann/json.hpp>
#include <memory>
#include "../unit/CUnit.h"

class CVector2;
class CImageManager;
class CScene;
class CGame;
class CThinkerManager;

class CPlayer;
using json = nlohmann::json;

class Global {
public:
    inline static CGame* game = nullptr;//游戏
    inline static CScene* scene = nullptr;//场景
    inline static std::shared_ptr<CPlayer> player = nullptr;//玩家
    inline static json unitJson = {};//unitJson
    inline static CImageManager* imgManager = nullptr;//图片管理器
    inline static CThinkerManager* thinkerManager = nullptr;//thinker管理器
};

json LoadJson(std::string _path);
std::weak_ptr<CUnit> CreateUnitByName(std::string _unitName,CVector2 _location,CUnit* _owner,int _team);
float GetNowTime();
int RandomInt(int _min,int _max);
float RandomFloat(float _min,float _max);
CVector2 RandomVector(int length);