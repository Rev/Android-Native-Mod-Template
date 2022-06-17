#ifndef FUNCTIONS_H
#define FUNCTIONS_H

void (*SetWeapon)(void *instance, int weapon);

void Functions()
{
    SetWeapon = (void(*)(void *, int)) offsets->isSetWeapon;
}

#endif