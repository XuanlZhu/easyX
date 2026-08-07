//
// Created by admin on 2026/8/7.
//

#include "UIManager.h"

#include <easyx.h>

#include "../../survivor/unit/CPlayer.h"
#include "Graphics/CCamera.h"
#include "../survivor/func/Global.h"

void UIManager::Update(float _deltaTime) {

}

void UIManager::Draw(CCamera& _camera) {
    printPos = CVector2(0,400);
    // PrintAttribute("AttackDamage");
    // PrintAttribute("Strength");
    // PrintAttribute("Agility");
    // PrintAttribute("Intellect");
    // PrintAttribute("MovementSpeed");
    // // PrintAttribute("HealthRegen");
    // PrintAttribute("AttackSpeed");
    // PrintAttribute("AttackRange");
    auto player = Global::player;
    for (auto& [key, value] :player->jsonKV["Attribute"].items()) {
        PrintAttribute(key);
    }
    std::string str = "mLevel:" + to_string(Global::player->mLevel);std::wstring value(str.begin(), str.end());outtextxy(0,printPos.y,value.c_str());printPos.y += 12;
}
void UIManager::PrintAttribute(std::string key) {
    auto player = Global::player;
    std::string str = key + ":" + to_string((int)player->GetAttribute(key));
    std::wstring value(str.begin(), str.end());
    outtextxy(printPos.x,printPos.y,value.c_str());
    printPos.y += 12;
}
