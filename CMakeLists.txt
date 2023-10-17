cmake_minimum_required(VERSION 3.24)
project(Raytracer)

set(CMAKE_CXX_STANDARD 17)

add_executable(Raytracer main.cpp)

target_include_directories(Raytracer PUBLIC /opt/homebrew/opt/libpng/include/libpng16)
target_link_directories(Raytracer PUBLIC /opt/homebrew/opt/libpng/lib)
target_link_libraries(Raytracer /opt/homebrew/opt/libpng/lib/libpng16.dylib)

#find_library(libpng libpng)
#target_include_directories(Raytracer PUBLIC ${libpng})

include(FetchContent)
FetchContent_Declare(
        googletest
        # Specify the commit you depend on and update it regularly.
        URL https://github.com/google/googletest/archive/5376968f6948923e2411081fd9372e71a59d8e77.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Now simply link against gtest or gtest_main as needed. Eg
#add_executable(CycleTest Tests/CycleTest.cpp Cycle.cp)
#target_link_libraries(CycleTest gtest_main)
