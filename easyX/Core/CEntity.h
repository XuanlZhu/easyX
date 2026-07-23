//
// Created by admin on 2026/7/22.
//

#pragma once
#include <functional>
#include <memory>
#include <string>
#include <unordered_map>
// using namespace std;
class CThinker;

class CEntity {
public:
    ~CEntity();
    void SetContextThink(std::string _name,std::function<float()> _func,float _interval=0);
    void RemoveThinker(std::string _name);

    std::unordered_map<std::string,std::weak_ptr<CThinker>> thinkerTable;

};
