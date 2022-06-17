# For more information about using CMake with Android Studio, read the
# documentation: https://d.android.com/studio/projects/add-native-code.html

# Sets the minimum version of CMake required to build the native library.

cmake_minimum_required(VERSION 3.4.1)

# Declares and names the project.

project("nativemod")

# Creates and names a library, sets it as either STATIC
# or SHARED, and provides the relative paths to its source code.
# You can define multiple libraries, and CMake builds them for you.
# Gradle automatically packages shared libraries with your APK.

add_library( # Sets the name of the library.
        nativemod

        # Sets the library as a shared library.
        SHARED

        # Provides a relative path to your source file(s).
        native-lib.cpp
        Hooking/ARMPatch/ARMPatch.cpp
        Memory/KittyMemory/KittyMemory.cpp
        Memory/KittyMemory/KittyUtils.cpp
        Memory/KittyMemory/KittyScanner.cpp
        Memory/KittyMemory/KittyArm64.cpp
        Memory/KittyMemory/MemoryPatch.cpp
        )

# Searches for a specified prebuilt library and stores the path as a
# variable. Because CMake includes system libraries in the search path by
# default, you only need to specify the name of the public NDK library
# you want to add. CMake verifies that the library exists before
# completing its build.

find_library( # Sets the name of the path variable.
        log-lib

        # Specifies the name of the NDK library that
        # you want CMake to locate.
        log)

find_library( # Sets the name of the path variable.
        GLESV2_LIB

        # Specifies the name of the NDK library that
        # you want CMake to locate.
        GLESv2)

if(${CMAKE_ANDROID_ARCH_ABI} STREQUAL "armeabi-v7a")
    set(ARMPATCH ${CMAKE_CURRENT_SOURCE_DIR}/Hooking/ARMPatch/libsubstrate-cydia-armv7a.a)
elseif(${CMAKE_ANDROID_ARCH_ABI} STREQUAL "arm64-v8a")
    set(ARMPATCH ${CMAKE_CURRENT_SOURCE_DIR}/Hooking/ARMPatch/libsubstrate-armv8a.a)
endif(${CMAKE_ANDROID_ARCH_ABI} STREQUAL "armeabi-v7a")

# Specifies libraries CMake should link to your target library. You
# can link multiple libraries, such as libraries you define in this
# build script, prebuilt third-party libraries, or system libraries.

target_link_libraries( # Specifies the target library.
        nativemod

        ${GLESV2_LIB}
        ${ARMPATCH}
        ${log-lib})