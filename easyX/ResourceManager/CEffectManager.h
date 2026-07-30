//
// Created by admin on 2026/7/26.
//

#pragma once
#include <functional>
#include <memory>
#include <string>
#include <vector>

class CSprite;
class CCamera;
class CVector2;
class CEffect;

class CEffectManager {
public:
    std::weak_ptr<CEffect> CreateEffect(std::string _className,CVector2 _pos,CSprite* _attacher);//创建Effect
    void Update(float _deltaTime);//更新
    void Draw(CCamera& _camera);//绘制
    std::vector<std::shared_ptr<CEffect>> mEffects;
private:
    void DestroyEffects();//销毁effect
};
