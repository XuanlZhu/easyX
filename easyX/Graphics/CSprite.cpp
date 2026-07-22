//
// Created by admin on 2026/7/14.
//
#include "CSprite.h"

#include "../../survivor/func/Global.h"
#pragma comment(lib, "MSIMG32.LIB") // 链接库

// 透明贴图函数
void putimage_alpha(int x, int y, IMAGE& img) {
    int w = img.getwidth();
    int h = img.getheight();
    AlphaBlend(GetImageHDC(NULL), x, y, w, h, GetImageHDC(&img), 0, 0, w, h, { AC_SRC_OVER, 0, 255, AC_SRC_ALPHA });
}
void putimage_alpha(int x,int y,int dstW,int dstH,IMAGE& img) {
    int srcW = img.getwidth();
    int srcH = img.getheight();
    AlphaBlend(GetImageHDC(NULL), x, y, dstW, dstH, GetImageHDC(&img), 0, 0, srcW, srcH, { AC_SRC_OVER, 0, 255, AC_SRC_ALPHA });
}

CSprite::CSprite(){
}
CSprite::CSprite(std::string _path) {
    mImage = Global::imgManager->GetImage(_path);
}
CSprite::CSprite(std::string _path, float length) {
    mImage = Global::imgManager->GetImage(_path);
    mLength = length;
}


void CSprite::Draw(CCamera& _camera)
{
    CVector2 screenPos = _camera.WorldToScreen(mPos);

    // putimage(screenPos.x,screenPos.y,mImage);
    // putimage_alpha(screenPos.x,screenPos.y,*mImage);
    if (mImage) {
        putimage_alpha(screenPos.x,screenPos.y,mLength,mLength,*mImage);
        // putimage_alpha(screenPos.x,screenPos.y,*mImage);
    }
}

void CSprite::SetPosition(float _x, float _y) {
    mPos.x = _x;mPos.y = _y;
}

void CSprite::SetPosition(CVector2 _pos) {
    mPos.x = _pos.x;mPos.y = _pos.y;
}

CVector2 CSprite::GetPos(){
    return mPos;
}

void CSprite::Update(float _deltaTime) {
}



// bool CSprite::LoadImage(const wchar_t* _path){
//     loadimage(&mImage, _path);
//     if(mImage.getwidth()==0)
//     {
//         outtextxy(100,100,L"图片加载失败");
//         return false;
//     }
//     return true;
// }

// bool CSprite::LoadImageW(const wchar_t *_path, int x, int y) {
//     loadimage(&mImage, _path,x,y);
//     if(mImage.getwidth()==0)
//     {
//         outtextxy(100,100,L"图片加载失败");
//         return false;
//     }
//     return true;
// }
