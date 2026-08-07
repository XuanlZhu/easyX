cmake_minimum_required(VERSION 4.2)
project(easyX)

add_definitions(-DUNICODE -D_UNICODE)

#set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(easyX)

add_executable(easyX
        easyX/Core/CGame.cpp
        easyX/Core/CGame.h
        survivor/CMyGame.cpp
        survivor/CMyGame.h
        survivor/start.cpp
        easyX/Core/CInput.cpp
        easyX/Core/CInput.h
        easyX/Graphics/CCamera.cpp
        easyX/Graphics/CCamera.h
        easyX/Graphics/CSprite.cpp
        easyX/Graphics/CSprite.h
        easyX/Graphics/CTexture.cpp
        easyX/Graphics/CTexture.h
        easyX/Scene/CScene.cpp
        easyX/Scene/CScene.h
        easyX/Scene/SpriteList.cpp
        easyX/Scene/SpriteList.h
        easyX/Core/CVector2.cpp
        easyX/Core/CVector2.h
        easyX/Map/CTileMap.cpp
        easyX/Map/CTileMap.h
        easyX/Core/EKey.h
        survivor/map/CScene1.cpp
        survivor/map/CScene1.h
        survivor/unit/CPlayer.cpp
        survivor/unit/CPlayer.h
        survivor/func/Global.cpp
        survivor/func/Global.h
        survivor/unit/CUnit.cpp
        survivor/unit/CUnit.h
        easyX/ResourceManager/CImageManager.cpp
        easyX/ResourceManager/CImageManager.h
        easyX/ResourceManager/CThinkerManager.cpp
        easyX/ResourceManager/CThinkerManager.h
        easyX/Core/CThinker.cpp
        easyX/Core/CThinker.h
        easyX/Core/CEntity.cpp
        easyX/Core/CEntity.h
        easyX/Graphics/CEffect.cpp
        easyX/Graphics/CEffect.h
        easyX/ResourceManager/CEffectManager.cpp
        easyX/ResourceManager/CEffectManager.h
        survivor/effects/CEffectNumber.cpp
        survivor/effects/CEffectNumber.h
        survivor/ability/CAbility.cpp
        survivor/ability/CAbility.h
        easyX/ResourceManager/CSoundManager.cpp
        easyX/ResourceManager/CSoundManager.h
        easyX/ResourceManager/CAnimaManager.cpp
        easyX/ResourceManager/CAnimaManager.h
        survivor/effects/CEffect_circle.cpp
        survivor/effects/CEffect_circle.h
        easyX/ResourceManager/CUnitManager.cpp
        easyX/ResourceManager/CUnitManager.h
        survivor/func/CBuffSystem.cpp
        survivor/func/CBuffSystem.h
        survivor/buffs/CBuff.cpp
        survivor/buffs/CBuff.h
        survivor/func/CBuffManager.cpp
        survivor/func/CBuffManager.h
        survivor/effects/CEffect_stunned.cpp
        survivor/effects/CEffect_stunned.h
        survivor/func/CAttributeSystem.cpp
        survivor/func/CAttributeSystem.h
        survivor/buffs/CBuff_test.cpp
        survivor/buffs/CBuff_test.h
        easyX/ResourceManager/CSpriteManager.cpp
        easyX/ResourceManager/CSpriteManager.h
        survivor/sprite/CXpGem.cpp
        survivor/sprite/CXpGem.h
        survivor/effects/CEffect_levelup.cpp
        survivor/effects/CEffect_levelup.h
        survivor/effects/CEffect_levelup2.cpp
        survivor/effects/CEffect_levelup2.h
        survivor/ability/CAbility_stamp.cpp
        survivor/ability/CAbility_stamp.h
        survivor/ability/CAbility_ice.cpp
        survivor/ability/CAbility_ice.h
        survivor/sprite/CProjectile.cpp
        survivor/sprite/CProjectile.h
        survivor/effects/CEffect_projectile.cpp
        survivor/effects/CEffect_projectile.h
        survivor/effects/CEffect_whip.cpp
        survivor/effects/CEffect_whip.h
        survivor/ability/CAbility_whip.cpp
        survivor/ability/CAbility_whip.h
        survivor/effects/CEffect_gem.cpp
        survivor/effects/CEffect_gem.h
        survivor/ability/CAbility_Knife.cpp
        survivor/ability/CAbility_Knife.h
        survivor/effects/CEffect_knife.cpp
        survivor/effects/CEffect_knife.h
        survivor/ability/CAbility_axe.cpp
        survivor/ability/CAbility_axe.h
        survivor/unit/CUnit_thinker.cpp
        survivor/unit/CUnit_thinker.h
        survivor/effects/CEffect_axe.cpp
        survivor/effects/CEffect_axe.h
        survivor/buffs/CBuff_axe_thinker.cpp
        survivor/buffs/CBuff_axe_thinker.h
        survivor/ability/CAbility_cross.cpp
        survivor/ability/CAbility_cross.h
        survivor/buffs/CBuff_cross_thinker.cpp
        survivor/buffs/CBuff_cross_thinker.h
        survivor/effects/CEffect_cross.cpp
        survivor/effects/CEffect_cross.h
        survivor/effects/CEffect_fly_fire.cpp
        survivor/effects/CEffect_fly_fire.h
        survivor/ability/CAbility_KingBook.cpp
        survivor/ability/CAbility_KingBook.h
        survivor/buffs/CBuff_KingBook.cpp
        survivor/buffs/CBuff_KingBook.h
        survivor/ability/CAbility_damage_aura.cpp
        survivor/ability/CAbility_damage_aura.h
        survivor/buffs/CBuff_damage_aura.cpp
        survivor/buffs/CBuff_damage_aura.h
        survivor/effects/CEffect_damage_aura.cpp
        survivor/effects/CEffect_damage_aura.h
        survivor/ability/CAbility_water.cpp
        survivor/ability/CAbility_water.h
        survivor/sprite/CProjectile_Tracking.cpp
        survivor/sprite/CProjectile_Tracking.h
        survivor/sprite/CProjectile_TrackingAttack.cpp
        survivor/sprite/CProjectile_TrackingAttack.h
        survivor/func/ConstantTable.h
        easyX/UI/UIManager.cpp
        easyX/UI/UIManager.h
        survivor/buffs/CBuff_AttributePrimary.cpp
        survivor/buffs/CBuff_AttributePrimary.h
)

# EasyX库路径
target_link_directories(easyX PRIVATE
        "C:/Program Files/Microsoft Visual Studio/18/Community/VC/Auxiliary/VS/lib/x64"
)

include(FetchContent)

FetchContent_Declare(
        json
        URL https://github.com/nlohmann/json/releases/download/v3.12.0/json.tar.xz
)

FetchContent_MakeAvailable(json)




# 链接EasyX
target_link_libraries(easyX
        EasyXw
        nlohmann_json::nlohmann_json
)

