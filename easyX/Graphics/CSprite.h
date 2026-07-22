//
// Created by admin on 2026/7/14.
//
#pragma once

#include <graphics.h>
#include <string>

#include "CCamera.h"
#include "Core/CEntity.h"
#include "Core/CVector2.h"
// using namespace std;

class CSprite:public CEntity
{
public:
    CSprite();// 构造
    CSprite(std::string _path);
    CSprite(std::string _path,float _length);
    // bool LoadImage(const wchar_t* _path);// 加载图片
    // bool LoadImage(const wchar_t* _path,int x,int y);// 加载图片
    virtual void Draw(CCamera& _camera);// 绘制
    void SetPosition(float _x, float _y);// 设置位置
    void SetPosition(CVector2 _pos);// 设置位置
    CVector2 GetPos();// 获取位置
    virtual void Update(float _deltaTime);

    float mSpeed = 5;//速度
    float mChangeX=0;//偏移
    float mChangeY=0;
    float mLength=50;//长度
protected:
    IMAGE* mImage = nullptr;//图片
    CVector2 mPos;//位置
    std::string mImagePath;//图片路径，需要使用资源管理器，而不是持有mImage
};
