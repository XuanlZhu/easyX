//
// Created by admin on 2026/7/27.
//

#include "CSoundManager.h"

#include <iostream>

CSoundManager::CSoundManager() {
    ma_engine_init(NULL, &mEngine);//初始化引擎

}

void CSoundManager::PlayLoop(std::string _name) {
    // PlaySound(mSounds[_name].c_str(),NULL,SND_FILENAME | SND_ASYNC);
    std::string path = "C:/Users/admin/Documents/GitHub/easyX/survivor/sounds/";
    path = path + _name +".wav";
    std::wstring value(path.begin(), path.end());

    PlaySound( value.c_str(),NULL,SND_FILENAME | SND_ASYNC | SND_LOOP);
}
void CSoundManager::Play(std::string _name) {
    std::string path = "C:/Users/admin/Documents/GitHub/easyX/survivor/sounds/";
    path = path + _name +".wav";;
    ma_engine_play_sound(&mEngine, path.c_str(), NULL);
}

