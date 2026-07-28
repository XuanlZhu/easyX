//
// Created by admin on 2026/7/27.
//

#pragma once
#include <string>
#include <unordered_map>
#include <windows.h>
#include <mmsystem.h>


#pragma comment(lib,"winmm.lib")
#include "../miniaudio/miniaudio.h"
// #include <stdio.h>

class CEntity;

class CSoundManager
{
public:
    CSoundManager();
    void PlayLoop(std::string _name);
    void Play(std::string _name);
    ma_engine mEngine;
private:
    // std::unordered_map<std::string,Mix_Chunk*> mSounds;
    // Mix_Music* mMusic = nullptr;
};


// void PlayLoop(std::string _name)
// {
//     // PlaySound(mSounds[_name].c_str(),NULL,SND_FILENAME | SND_ASYNC);
//     std::string path = "C:/Users/admin/Documents/GitHub/easyX/survivor/sounds/";
//     path = path + _name +".wav";
//     std::wstring value(path.begin(), path.end());
//
//     PlaySound( value.c_str(),NULL,SND_FILENAME | SND_ASYNC | SND_LOOP);
// }
//
// void Play(std::string _name)
// {
//     std::string path = "C:/Users/admin/Documents/GitHub/easyX/survivor/sounds/";
//     path = path + _name +".wav";;
//     std::wstring value(path.begin(), path.end());
//     // PlaySound( value.c_str(),NULL,SND_FILENAME | SND_ASYNC);
//     // mciSendString(value.c_str(),NULL,0,NULL);
// }
