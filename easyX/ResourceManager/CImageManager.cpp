//
// Created by admin on 2026/7/21.
//

#include "CImageManager.h"
#include <string>
using namespace std;

IMAGE* CImageManager::GetImage(string _path) {

    auto it = mImages.find(_path); //已经加载
    if(it != mImages.end()) { return &it->second; } //第一次加载

    wstring wpath(_path.begin(), _path.end());
    loadimage(&mImages[_path],wpath.c_str(),50,50);
    return &mImages[_path];
}


// IMAGE* CImageManager::GetImage(string _path)
// {
//     auto it = mImages.find(_path);
//     if(it != mImages.end())
//     {
//         return &it->second;
//     }
//     IMAGE& img = mImages[_path];
//     wstring wpath(_path.begin(), _path.end());
//     if(loadimage(&img, wpath.c_str()) == 0)
//     {
//         return nullptr;
//     }
//     return &mImages[_path];
// }