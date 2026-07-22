//
// Created by admin on 2026/7/17.
//

#include "CScene1.h"

CScene1::CScene1() {
    //初始化瓦片地图
    mCTileMap = CTileMap("map/map2.csv",{
        "PNG/Tile/shoals_wall_1.png",
    });

}
