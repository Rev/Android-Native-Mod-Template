# Android Native Mod Template
Not everything requires a mod menu - which is why I created this mod template (but, it was also a fun project to do)! It supports hooking, patching, pattern-scanning, uses cmake to build, and much more! In short, it includes everything you need to make your own mods. In case you're wondering, for the NDK, I use the latest LTS version - which can be downloaded [here](https://github.com/android/ndk/wiki#current-lts-release). 

Version 1.2027 of Forward Assault has been used as an example in the source of this template.

## Implementation
Implementing your mod into an application is very easy!

1. Once you build the apk, open it using an archiver (such as 7-Zip, WinRAR, etc), and find the 'lib' directory. 

![image](https://user-images.githubusercontent.com/64957743/172854358-d5a3cf9a-37b6-4e7a-88de-4b68ef3b26f6.png)

From there, you will be presented with two additional folders. Choose the folder that resembles the cpu architecture you want to use (whether it be armeabi-v7a, or arm64-v8a).

![image](https://user-images.githubusercontent.com/64957743/172854465-9bc9ceca-04fc-45fc-acb5-a23d69134409.png)


2. Move the 'libnativemod.so' library to the target applications lib/chosen-cpu-architecture/ folder.

![image](https://user-images.githubusercontent.com/64957743/172854827-44556607-7609-422f-8486-948922e93500.png)

3. Then, find your applications launch activity, and place the following code under the 'onCreate' method in that launch activity.

```
const-string v0, "nativemod"

invoke-static {v0}, Ljava/lang/System;->loadLibrary(Ljava/lang/String;)V
```

![image](https://user-images.githubusercontent.com/64957743/172854983-bec97ca3-399e-4f81-b234-8d9de3dec846.png)

4. Compile it, and you're done!

## Credits
* Ruit and his cats - [KittyMemory](https://github.com/MJx0/KittyMemory/)
* RusJJ - [ARMPatch](https://github.com/RusJJ/ARMPatch/)
* shmoo419 - [UnityStuff](https://github.com/shmoo419/UnityStuff/)
* YclepticStudios - [gmath](https://github.com/YclepticStudios/gmath/)
* adamyaxley - [Obfuscate](https://github.com/adamyaxley/Obfuscate/)
