project(CMake-Demo)

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
    demo
    main.cpp
    graph/graph.h
    graph/graph_algorithm.h
    sort/sort.h
    list/list.h
    list/stack.h
    list/queue.h
  list/disjoint_set.h
    string/KMP.h
    )

add_executable(
    hello_test
    test/hello_test.cc
    test/sort_test.cc
    test/list_test.cc
    test/stack_test.cc
    test/queue_test.cc
    test/kmp_test.cc
    test/disjoint_set_test.cc
)
target_link_libraries(
  hello_test
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(hello_test)