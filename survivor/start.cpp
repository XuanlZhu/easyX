
#include <iostream>

#include "CMyGame.h"
#include "../easyX/Core/CGame.h"
#include "../easyX/Graphics/CSprite.h"
#include "func/Global.h"
#include "ResourceManager/CEffectManager.h"
#include "unit/CPlayer.h"


int main()
{

    Global::game = new CMyGame();
    Global::game->Run();

    auto plyer = Global::player;

    plyer->SetContextThink("123",[&] {

        CreateEffect("CEffectNumber",plyer->GetPos());
        return 3;
    },0);

    // plyer->SetContextThink("123",[&] {
    //     // std::cout << "Init Graphics Success" << std::endl;
    //     auto creep= CreateUnitByName("creep", plyer->GetPos()+RandomVector(400), nullptr, 3).lock();
    //     if (creep) {
    //         creep->SetAttackTarget(plyer);
    //     }
    //     return 1;
    // },0);

    // CVector2(5000,5000)+RandomVector(600);


    // CreateUnitByName("creep", CVector2(5000,5100), nullptr, 3);

    // shared_ptr<CSprite> gem = make_shared<CSprite>();//宝石
    // gem->SetPosition(5000,5000);
    // Global::game->SpriteListAppend(gem);//添加到精灵表

    // auto gem = make_shared<CSprite>("PNG/gem1.png",20);//共享指针
    // gem->SetPosition(5000,5100);
    // Global::game->SpriteListAppend(gem);//添加精灵表

    while(true)
    {
        // std::cout << "Init Graphics Success" << std::endl;
        // cleardevice();
        // outtextxy(100,100,L"图片加载失败");
        // enemy.Draw();
        // Sleep(16); //约60帧

    }
    closegraph();
    return 0;
}
