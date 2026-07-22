//
// Created by admin on 2026/7/16.
//

#pragma once
#include <vector>
#include <string>
#include <graphics.h>

#include "Graphics/CCamera.h"
using namespace std;

class CTileMap
{
public:
    CTileMap();
    CTileMap(string _path);
    CTileMap(string _path,vector<string> _mTilesPath);
    bool LoadTiles();// 加载瓦片图片
    void Draw(CCamera& _camera);// 绘制地图
    void SetCollisionData(vector<int> _CollisionData);//设置碰撞信息
    bool CheckCollision(int _x,int _y);//检测碰撞
    //瓦片路径
    vector<string> mTilesPath = {
        // "../survivor/PNG/Tile/shoals_wall_1.png",
    };
    //瓦片碰撞
    vector<int> mTilesCollision = {

    };
private:
    vector<vector<int>> mMapData;// 地图二维数组
    vector<IMAGE> mTiles;// 瓦片图片
    // 一个瓦片大小
    int mTileWidth = 32;
    int mTileHeight = 32;
};
