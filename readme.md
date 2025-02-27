使用CMake在vscode上练习写c++数据结构，结合gtest进行测试。

## 项目结构

2025年2月27日10:35

└── src
    ├── STL
    ├── algorithm
        ├── CMakeLists.txt
        ├── pattern_matching
            └── KMP.h
        └── sort
            └── sort.h
    ├── main.cpp
    ├── structure
        ├── CMakeLists.txt
        ├── composite
            ├── enum.h
            └── union.h
        ├── graph
            ├── graph.h
            ├── graph_algorithm.h
            └── simple_graph.h
        ├── list
            ├── list.h
            ├── my_priority_queue_sample.h
            ├── queue.h
            └── stack.h
        └── tree
            └── disjoint_set.h
    └── test
        ├── CMakeLists.txt
        ├── algorithm
            ├── pattern_matching
                └── kmp_test.cc
            └── sort
                └── sort_test.cc
        ├── hello_test.cc
        └── structure
            ├── composite
                └── composite_test.cc
            ├── graph
                └── graph_test.cc
            ├── list
                ├── list_test.cc
                ├── queue_test.cc
                └── stack_test.cc
            └── tree
                └── disjoint_set_test.cc

## 使用方法

- 下载代码前需要做到：

  - 下载并安装CMake
  - 保证CMake可以通过命令行调用
    - 验证方式： cmake --version可以正常运行。
- 下载代码后编译程序;在项目根目录下执行

  - ``mkdir build && cd build; cmake ..; make``
- 运行gtest；此时在子目录build下

  - `ctest`
- 增添/修改代码后，在子目录build下执行 `make`可重新构建项目

## 注意事项

- 如果切换了编译器，请删除build目录，重新构建项目。
