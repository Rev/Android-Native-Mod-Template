#include <GLES2/gl2.h>
#include <jni.h>
#include <string>
#include <unistd.h>
#include <pthread.h>
#include <dlfcn.h>
#include <vector>

#include "Engine/Vector2.h"
#include "Engine/Vector3.h"
#include "Engine/Quaternion.h"
#include "Engine/Rect.h"
#include "Engine/Color.h"

#include "Etc/Logging.h"
#include "Etc/Obfuscate.h"
#include "Etc/Utils.h"

#include "Mod/Chams.h"
#include "Mod/Offsets.h"
#include "Mod/Hooks.h"
#include "Mod/Patch.h"

void *thread_main(void *)
{
    do
    {
        sleep(5);
    } while (!isLibraryLoaded(LibraryToLoad));

    LOGDEBUG("INITIALIZED!");

    offsets = new Offsets();

    Functions();
    Hooks();
    Patches();

    isChams();

    return nullptr;
}

__attribute__((constructor))
void lib_main()
{
    pthread_t ptid;
    pthread_create(&ptid, nullptr, thread_main, nullptr);
}