//
// Created by admin on 2026/7/14.
//

#pragma once
#include "SpriteList.h"
#include "Graphics/CCamera.h"
#include "Map/CTileMap.h"


class CScene
{
public:
    CScene();
    ~CScene();
    //初始化场景
    virtual void Init();
    //更新逻辑
    virtual void Update(float deltaTime);
    //绘制
    virtual void Draw();
    void SetPlayer(CSprite* _player);
    SpriteList mSpriteList;
    CTileMap mCTileMap;//瓦片地图
    virtual void ProcessInput();
    CSprite* mPlayer;//玩家
    CCamera mCamera;//相机
protected:

};
