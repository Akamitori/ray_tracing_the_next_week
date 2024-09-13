cmake_minimum_required(VERSION 3.29)
project(ray_tracing_in_one_weekend)

set(CMAKE_CXX_STANDARD 20)

# Set default build type to Release if not specified
if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release CACHE STRING "Choose the type of build, options are: Debug Release" FORCE)
endif ()

# Platform-specific optimizations
if(WIN32)
    # MSVC on Windows
    set(CMAKE_CXX_FLAGS_DEBUG "/Zi /Od /RTC1")  # Debug info, no optimization, runtime checks
    set(CMAKE_CXX_FLAGS_RELEASE "/O2 /Ob2 /Ot /arch:AVX2 /GL /fp:fast /GR- /EHsc")  # Optimize for speed
    set(CMAKE_SHARED_LINKER_FLAGS_RELEASE "/LTCG")  # Link-time code generation

elseif(APPLE)
    # Clang on macOS
    set(CMAKE_CXX_COMPILER "clang++")
    set(CMAKE_CXX_FLAGS_DEBUG "-g -O0 -fno-omit-frame-pointer")  # Debug info, no optimization
    set(CMAKE_CXX_FLAGS_RELEASE "-Ofast -march=native -mtune=native -funroll-loops -ffast-math -flto -fno-exceptions -fno-rtti -fvisibility=hidden -DNDEBUG")
    set(CMAKE_EXE_LINKER_FLAGS_RELEASE "-flto")

elseif(UNIX)
    # GCC on Linux
    set(CMAKE_CXX_COMPILER "g++")
    set(CMAKE_CXX_FLAGS_DEBUG "-g -O0 -fno-omit-frame-pointer")  # Debug info, no optimization
    set(CMAKE_CXX_FLAGS_RELEASE "-Ofast -march=native -mtune=native -funroll-loops -ffast-math -flto -fno-exceptions -fno-rtti -fvisibility=hidden -DNDEBUG")
    set(CMAKE_EXE_LINKER_FLAGS_RELEASE "-flto")
endif()

# Add executable
add_executable(raytracing src/main.cpp
        src/rtweekend.h
        src/vec3.h
        src/vec3.cpp
        src/color.cpp
        src/color.h
        src/ray.cpp
        src/ray.h
        src/RedirectOutput.cpp
        src/RedirectOutput.h
        src/hittable.h
        src/sphere.cpp
        src/sphere.h
        src/hittable_list.h
        src/hittable_list.cpp
        src/interval.cpp
        src/interval.h
        src/camera.cpp
        src/camera.h
        src/material.cpp
        src/material.h
)
