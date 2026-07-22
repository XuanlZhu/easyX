//
// Created by admin on 2026/7/14.
//

#include "CInput.h"

#include <iostream>
#include <Windows.h>

CInput::CInput()
{

}
void CInput::Update()
{
    for (int i = 0; i < 256; i++)
    {
        // 保存上一帧状态
        mLastKeyState[i] = mKeyState[i];
        // 获取当前键盘状态
        mKeyState[i] = (GetAsyncKeyState(i) & 0x8000) != 0;
        // 按键按下事件
        if (mKeyState[i] && !mLastKeyState[i])
        {
            if (OnKeyDown)
            {
                OnKeyDown(i);
                // std::cout << "按下了："<< i << std::endl;
            }
        }
        // 按键释放事件
        if (!mKeyState[i] && mLastKeyState[i])
        {
            if (OnKeyUp)
            {
                // std::cout << "释放了："<< i << std::endl;
                OnKeyUp(i);
            }
        }
    }
}




// void CInput::Update()
// {
//     for(int i = 0; i < 256; i++)
//     {
//         mLastKeyState[i] = mKeyState[i];
//         // 获取键盘状态
//         mKeyState[i] = (GetAsyncKeyState(i) & 0x8000) != 0;
//         // 按下事件
//         if(mKeyState[i] && !mLastKeyState[i])
//         {
//             if(OnKeyDown)
//             {
//                 OnKeyDown(i);
//             }
//         }
//         // 松开事件
//         if(!mKeyState[i] &&mLastKeyState[i])
//         {
//             if(OnKeyUp)
//             {
//                 OnKeyUp(i);
//             }
//         }
//     }
// }