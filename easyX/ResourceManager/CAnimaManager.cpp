//
// Created by admin on 2026/7/28.
//

#include "CAnimaManager.h"

CAnimaManager::CAnimaManager() {
    Load("03",64,64);
    Load("26",64,64);
    Load("529",64,64);
    Load("713",64,64);
    Load("579",64,64);
    Load("589",64,64);
}
void CAnimaManager::Load(std::string _name,int frameWidth,int frameHeight)
{
    std::string path = "C:/Users/admin/Documents/GitHub/easyX/survivor/animation/";
    path = path + _name +".png";
    std::wstring wpath(path.begin(), path.end());

    IMAGE sheet;
    loadimage(&sheet,wpath.c_str());

    int width = sheet.getwidth();
    int height = sheet.getheight();
    int cols = width / frameWidth;
    int rows = height / frameHeight;

    for(int y = 0; y < rows; y++)
    {
        std::vector<IMAGE> animation;
        for(int x = 0; x < cols; x++)
        {
            IMAGE frame;
            // 创建单帧图片
            SetWorkingImage(&sheet);
            getimage(&frame,x * frameWidth,y * frameHeight,frameWidth,frameHeight);
            animation.push_back(frame);
        }

        mAnimations.push_back(animation);
    }
    SetWorkingImage(nullptr);
}

std::vector<IMAGE>& CAnimaManager::GetAnimation(int row) {
    return mAnimations[row];
}
