cmake_minimum_required(VERSION 3.24)
project(Raytracer)

set(CMAKE_CXX_STANDARD 17)

add_executable(
        Raytracer
        main.cpp
        Vec3.cpp
        Vec3.h
        Color.cpp
        Color.h
        Ray.h
        Ray.cpp
        Hittable.cpp Hittable.h Sphere.cpp Sphere.h)
