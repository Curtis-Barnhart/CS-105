cmake_minimum_required(VERSION 3.24)
project(Raytracer)

set(CMAKE_CXX_STANDARD 17)

add_executable(Raytracer main.cpp Vec3.cpp Vec3.h
        Color.cpp
        Color.h
        cmake-build-debug/bin/Ray.h
        Ray.cpp
        Ray.cpp
        Ray.h
        Ray.cpp
        Ray.h
        cmake-build-debug/bin/Ray.cpp
        cmake-build-debug/bin/Ray.h
)
