project(data_structure_with_gtest)

#set(CMAKE_C_COMPILER "C:/msys64/usr/bin/clang.exe")
#set(CMAKE_CXX_COMPILER "C:/msys64/usr/bin/clang++.exe")

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
include_directories(${GTEST_INCLUDE_DIRS})

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip

 )
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)
enable_testing()

add_executable( 
  data_structure
  src/main.cpp
  src/graph/graph.h
  src/graph/graph_algorithm.h
  src/sort/sort.h
  src/list/list.h
  src/list/stack.h
  src/list/queue.h
  src/list/disjoint_set.h
  src/string/KMP.h
  src/composite/enum.h
  )

add_executable(
    data_structure_test
    src/test/hello_test.cc
    src/test/sort_test.cc
    src/test/list_test.cc
    src/test/stack_test.cc
    src/test/queue_test.cc
    src/test/kmp_test.cc
    src/test/disjoint_set_test.cc
    src/test/composite_test.cc
)
target_link_libraries(
  data_structure_test
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(data_structure_test)