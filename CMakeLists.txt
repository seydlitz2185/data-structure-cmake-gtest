cmake_minimum_required(VERSION 3.10)
project(data_structure_with_gtest)
enable_testing()
include(GoogleTest)
#windows only
#set(CMAKE_C_COMPILER "C:/msys64/usr/bin/clang.exe")
#set(CMAKE_CXX_COMPILER "C:/msys64/usr/bin/clang++.exe")
# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip

 )
FetchContent_MakeAvailable(googletest)
include_directories(${GTEST_INCLUDE_DIRS})
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# 添加算法和数据结构模块（先编译库）
add_subdirectory(src/algorithm)
add_subdirectory(src/structure)

# 最后添加测试目录（确保测试能链接到已定义的库）
add_subdirectory(src/test)


