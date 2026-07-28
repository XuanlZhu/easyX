//
// Created by admin on 2026/7/21.
//

#pragma once
#include <unordered_map>
#include <string>
#include <graphics.h>
// using namespace std;


class CImageManager
{
private:
    std::unordered_map<std::string, IMAGE> mImages;
public:
    IMAGE* GetImage(std::string _path);
};
