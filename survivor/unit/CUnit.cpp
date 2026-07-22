//
// Created by admin on 2026/7/20.
//

#include "CUnit.h"
#include "../func/Global.h"
#include <iostream>
#include <nlohmann/json_fwd.hpp>
using json = nlohmann::json;

// CUnit::CUnit() {
// }
//
CUnit::CUnit(std::string _name) {
    auto& table= Global::unitJson;
    if(!table.contains(_name))
    {
        std::cout<<"单位不存在:"<<_name<<std::endl;
        return;
    }
    json data = table[_name];
    // cout<<data<<endl;
    if (data.contains("img")) {
        std::string img = "PNG/" + data["img"].get<std::string>() + ".png";
        mImage = Global::imgManager->GetImage(img);
    }
}