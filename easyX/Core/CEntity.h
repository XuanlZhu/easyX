//
// Created by admin on 2026/7/22.
//

#pragma once
#include <functional>
#include <string>
// using namespace std;

class CEntity {
public:
    void SetContextThink(std::string _name,std::function<float()> _func,int _interval=0);
};
