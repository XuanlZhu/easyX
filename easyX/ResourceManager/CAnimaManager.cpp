//
// Created by admin on 2026/7/28.
//

#include "CAnimaManager.h"

CAnimaManager::CAnimaManager() {

}
void CAnimaManager::Load(std::string path,int frameWidth,int frameHeight)
{
    IMAGE sheet;
    loadimage(&sheet,path.c_str());

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
