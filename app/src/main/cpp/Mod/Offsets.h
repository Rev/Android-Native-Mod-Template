#ifndef OFFSETS_H
#define OFFSETS_H

struct Offsets
{
    #if defined(__ARM_ARCH_7A__)

        DWORD isPlayerUpdate = 0xF80A78; // Update (Player)
        DWORD isPlayerHealth = 0xF73090; // get_health (Player)
        DWORD isRadar        = 0xF7A56C; // get_CanShowOnMinimap (Player)
        DWORD isSetWeapon    = 0xEF9C98; // SetWeapon (LocalPlayer)

        DWORD isKills        = 0x48; // kills (Player)
        DWORD isDeaths       = 0x4C; // deaths (Player)
        DWORD isFly          = 0x1C; // allowFly (FirstPersonMovement)
        DWORD isLocalPlayer  = 0x3C; // localPlayer (Player)
        DWORD isFPSMovement  = 0x14; // fpsMovement (LocalPlayer)

    #elif defined(__aarch64__)

        DWORD isPlayerUpdate = 0x133F9E4; // Update (Player)
        DWORD isPlayerHealth = 0x133495C; // get_health (Player)
        DWORD isRadar        = 0x133A7A8; // get_CanShowOnMinimap (Player)
        DWORD isSetWeapon    = 0x12D381C; // SetWeapon (LocalPlayer)

        DWORD isKills        = 0x8C; // kills (Player)
        DWORD isDeaths       = 0x90; // deaths (Player)
        DWORD isFly          = 0x30; // allowFly (FirstPersonMovement)
        DWORD isLocalPlayer  = 0x78; // localPlayer (Player)
        DWORD isFPSMovement  = 0x28; // fpsMovement (LocalPlayer)

    #endif
};

Offsets *offsets;

#endif
