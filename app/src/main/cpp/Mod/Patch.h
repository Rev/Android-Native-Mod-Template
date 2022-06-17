#ifndef PATCH_H
#define PATCH_H

struct Patches
{
    MemoryPatch health, radar;
};

Patches patches;

void Patches()
{
    #if defined(__ARM_ARCH_7A__)

        patches.health = MemoryPatch::createWithHex(LibraryToLoad, offsets->isPlayerHealth, "C8 01 44 E3 1E FF 2F E1"); // 25.0f
        patches.health.Modify();

        /* movt r0, #0x41C8
         * bx lr */

        patches.radar = MemoryPatch::createWithHex(LibraryToLoad, offsets->isRadar, "01 00 A0 E3 1E FF 2F E1"); // true
        patches.radar.Modify();

        /* mov r0, #1
         * bx lr */

    #elif defined(__aarch64__)

        patches.health = MemoryPatch::createWithHex(LibraryToLoad, offsets->isPlayerHealth, "00 30 27 1E C0 03 5F D6"); // 25.0f
        patches.health.Modify();

        /* fmov s0, #25.00000000
         * ret */

        patches.radar = MemoryPatch::createWithHex(LibraryToLoad, offsets->isRadar, "20 00 80 D2 C0 03 5F D6"); // true
        patches.radar.Modify();

        /* mov x0, #1
         * ret */

    #endif
}

#endif