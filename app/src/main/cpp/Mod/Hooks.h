#ifndef HOOKS_H
#define HOOKS_H

#include "Functions.h"

void (*old_PlayerUpdate)(void *instance);
void PlayerUpdate (void *instance)
{
    if(instance != nullptr)
    {
        void *isLocalPlayer = *(void **)((uint64_t) instance + offsets->isLocalPlayer);

        *(int *)((uint64_t) instance + offsets->isKills) = 99999;

        *(int *)((uint64_t) instance + offsets->isDeaths) = 99999;

        if(isLocalPlayer != nullptr)
        {

            void *isFPSMovement = *(void **)((uint64_t) isLocalPlayer + offsets->isFPSMovement);

            SetWeapon(isLocalPlayer, 2); // Vector SMG

            if(isFPSMovement != nullptr)
            {
                *(bool *)((uint64_t) isFPSMovement + offsets->isFly) = true;
            }

        }

    }

    return old_PlayerUpdate(instance);
}

void Hooks()
{
    ARMPatch::hook((void *) getAbsoluteAddress(LibraryToLoad, offsets->isPlayerUpdate), (void *) &PlayerUpdate, (void **) &old_PlayerUpdate);
}

#endif
