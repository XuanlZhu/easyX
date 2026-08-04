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
        survivor/func/GameDefine.h
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
        survivor/ability/CAblity_stamp.cpp
        survivor/ability/CAblity_stamp.h
        survivor/ability/CAbility_flyingKnife.cpp
        survivor/ability/CAbility_flyingKnife.h
        survivor/sprite/CProjectile.cpp
        survivor/sprite/CProjectile.h
        survivor/effects/CEffect_projectile.cpp
        survivor/effects/CEffect_projectile.h
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

