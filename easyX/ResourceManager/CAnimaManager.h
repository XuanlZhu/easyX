//
// Created by admin on 2026/7/28.
//

#pragma once
#include <vector>
#include <string>
#include <graphics.h>

class CAnimaManager
{
public:
    CAnimaManager();
    // 加载sprite sheet
    void Load(std::string _name,int frameWidth,int frameHeight);
    // 获取某行动画
    std::vector<IMAGE>& GetAnimation(int row);
    // 获取某帧
    IMAGE& GetFrame(int row,int frame);
private:
    std::vector<std::vector<IMAGE>> mAnimations;
};
