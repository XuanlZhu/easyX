//
// Created by admin on 2026/7/16.
//

#include "CTileMap.h"
#include <fstream>
#include <sstream>
#include <iostream>

CTileMap::CTileMap() {
}

//构造函数
CTileMap::CTileMap(string _path)
{
    LoadTiles();//加载瓦片
    ifstream file(_path);// 打开csv文件

    if (!file.is_open()){return;}//没打开

    string line;
    // 一行一行读取
    while (getline(file, line))
    {
        vector<int> row;
        stringstream ss(line);
        string value;
        // 按逗号分割
        while (getline(ss, value, ','))
        {
            row.push_back(stoi(value));
        }
        // 加入二维数组
        mMapData.push_back(row);
    }
    file.close();
}

CTileMap::CTileMap(string _path, vector<string> _mTilesPath)
{
    //加载瓦片图片
    for (auto path : _mTilesPath)
    {
        IMAGE img;
        // string 转 wchar_t
        wstring wpath(path.begin(),path.end());
        loadimage(&img,wpath.c_str(),32,32);
        mTiles.push_back(img);//保存图片
    }

    ifstream file(_path);// 打开csv文件

    if (!file.is_open()){return;}//没打开

    //读取瓦片数组表
    string line;
    // 一行一行读取
    while (getline(file, line))
    {
        vector<int> row;
        stringstream ss(line);
        string value;
        // 按逗号分割
        while (getline(ss, value, ','))
        {
            row.push_back(stoi(value));
        }
        // 加入二维数组
        mMapData.push_back(row);
    }
    file.close();
}


//加载瓦片
bool CTileMap::LoadTiles()
{
    for (auto path : mTilesPath)
    {
        IMAGE img;
        // string 转 wchar_t
        wstring wpath(path.begin(),path.end());
        loadimage(&img,wpath.c_str(),32,32);
        mTiles.push_back(img);//保存图片
    }
    return true;
}

// void CTileMap::Draw(CCamera& _camera)
// {
//     for(int y = 0; y < mMapData.size(); y++)
//     {
//         for(int x = 0; x < mMapData[y].size(); x++)
//         {
//             int id = mMapData[y][x];
//             if(id < 0 || id >= mTiles.size()){continue;}//判断地图有效
//             // 瓦片在世界中的位置
//             CVector2 worldPos(x * mTileWidth,y * mTileHeight);
//             // 世界坐标转换成屏幕坐标
//             CVector2 screenPos = _camera.WorldToScreen(worldPos);
//             putimage(screenPos.x,screenPos.y,&mTiles[id]);
//         }
//     }
// }
//只绘制相机周围的
void CTileMap::Draw(CCamera& _camera)
{
    // 获取相机世界坐标范围
    CVector2 cameraPos = _camera.GetPosition();
    int startX = cameraPos.x / mTileWidth;
    int startY = cameraPos.y / mTileHeight;

    int endX = (cameraPos.x + 1000)/ mTileWidth + 1;
    int endY = (cameraPos.y + 1000)/ mTileHeight + 1;

    // 防止越界
    startX = max(startX,0);
    startY = max(startY,0);

    endX = min(endX,(int)mMapData[0].size());
    endY = min(endY,(int)mMapData.size());

    for(int y = startY; y < endY; y++)
    {
        for(int x = startX; x < endX; x++)
        {
            int id = mMapData[y][x];
            if(id < 0 || id >= mTiles.size()){continue;};
            CVector2 worldPos(x * mTileWidth,y * mTileHeight);
            CVector2 screenPos = _camera.WorldToScreen(worldPos);
            putimage(screenPos.x,screenPos.y,&mTiles[id]);
        }
    }
}


//设置碰撞信息
void CTileMap::SetCollisionData(vector<int> _CollisionData) {
    mTilesCollision = _CollisionData;
}

bool CTileMap::CheckCollision(int _x, int _y)
{
    // 检查地图坐标是否越界
    if (_x < 0 || _y < 0 ||_x >= mMapData.size() ||_y >= mMapData[_x].size())
    {
        return false;
    }
    // 获取瓦片ID
    int index = mMapData[_x][_y];
    // 检查瓦片碰撞数据是否越界
    if (index < 0 || index >= mTilesCollision.size())
    {
        return false;
    }
    // 返回碰撞属性
    return mTilesCollision[index];
}
