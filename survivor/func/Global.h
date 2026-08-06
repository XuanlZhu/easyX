//
// Created by admin on 2026/7/20.
//

#pragma once
#include <string>
#include <nlohmann/json.hpp>
#include <memory>

#include "../ability/CAbility.h"
#include "Core/CVector2.h"

class CProjectile;
class CAbility;
class CBuffManager;
class CUnitManager;
class SpriteList;
class CAnimaManager;
class CSoundManager;
class CSprite;
class CUnit;
class CEffect;
class CEffectManager;
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
    inline static CEffectManager* effectManager = nullptr;//特效管理器
    inline static CSoundManager* soundManager = nullptr;//音频管理器
    inline static CAnimaManager* animaManager = nullptr;//动画管理器
    inline static SpriteList* spriteList = nullptr;//精灵表
    inline static CUnitManager* unitManager = nullptr;//单位管理器
    inline static CBuffManager* buffManager = nullptr;//buff管理器
};
struct DamageContext { CUnit* _attacker; CUnit* _victim; float _damage; };//伤害结构体
struct LinearProjectileContext { CAbility* ability; CUnit* Source;CVector2 vSpawnOrigin; float fStartRadius;float fEndRadius;float fDistance;CVector2 vVelocity;int iUnitTargetTeam;std::string EffectName;json ExtraData; };//线性投射物结构体
struct TrackingProjectileContext { CAbility* ability;CUnit* Source;CUnit* Target; CVector2 vSpawnOrigin;float iMoveSpeed;std::string EffectName;json ExtraData; };//线性投射物结构体


json LoadJson(std::string _path);
std::weak_ptr<CUnit> CreateUnitByName(std::string _unitName,CVector2 _location,CUnit* _owner,int _team);
float GetNowTime();
int RandomInt(int _min,int _max);
float RandomFloat(float _min,float _max);
CVector2 RandomVector(int length);
std::weak_ptr<CEffect> CreateEffect(std::string _className,CVector2 _pos,CSprite* _attacher);//创建特效
void SendOverheadEventMessage(CSprite* _owner,std::string _value);//头顶文字
float CalcDistanceBetweenEntityOBB(CSprite* _s1,CSprite* _s2);//计算两个精灵的距离
void ApplyDamage(DamageContext _context);//造成伤害
void EmitSoundOn(std::string _name);
std::vector<std::weak_ptr<CUnit>> FindUnitsInRadius(int _team,CVector2 _pos,float _radius,int _order);
std::vector<std::weak_ptr<CUnit>> FindUnitsInLine(int _team,CVector2 startPos,CVector2 endPos,float width);
std::weak_ptr<CSprite> CreateCSprite(std::string _sprite,CVector2 _pos);//创建精灵，并下发到精灵表
std::weak_ptr<CProjectile> CreateLinearProjectile(LinearProjectileContext _context);
std::weak_ptr<CProjectile> CreateTrackingProjectile(TrackingProjectileContext _context);
std::weak_ptr<CUnit> CreateModifierThinker(CUnit* caster,CAbility* ability,std::string name,json table,CVector2 origin,int team);
