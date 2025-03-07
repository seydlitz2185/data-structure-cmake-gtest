使用CMake在vscode上练习写c++数据结构，结合gtest进行测试。

项目目的：

1. 每写一个数据结构/算法，自己再写一个对应的测试，有助于加深理解。
2. 不喜欢网页上在线写算法。
3. 练习构建c++跨平台程序。

如果你和我有相似的想法，可以参考这个仓库构建自己的cmake项目。

## 项目结构

2025年3月07日21:55

```
└── CMakeLists.txt #负责构建整个项目
└── src
    ├── algorithm #在这里练习写算法，只允许存放头文件，下同
        ├── CMakeLists.txt #将所在目录下的全部头文件组织起来，暴露头文件路径，下同
        ├── pattern_matching #模式匹配算法
            └── KMP.h #KMP算法
        └── sort
            └── sort.h #基础排序算法
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
    └── test #存放测试文件，本项目中规定测试文件扩展名都为.cc
        ├── CMakeLists.txt
        ├── hello_test.cc
	├── algorithm
            ├── pattern_matching
                └── kmp_test.cc
            └── sort
                └── sort_test.cc
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
```

## 使用方法

- 下载代码前需要做到：

  - 下载并安装[CMake](https://cmake.org/download/ "官网链接")
  - 保证CMake可以通过命令行调用
    - 验证方式： cmake --version可以正常运行。
- 下载代码后编译程序;在项目根目录下执行

  - 使用默认编译器进行编译： ``mkdir build && cd build; cmake ..; cmake --build .``
  - 手动指定编译器进行编译： ``mkdir build && cd build; cmake -G "MinGW Makefiles" -DUSE_CLANG=ON ..; cmake --build .``
- 运行gtest；此时在子目录build下

  - `ctest`
- 增添/修改代码后，在子目录build下执行 `make`可重新构建项目

## 注意事项

- 如果切换了编译器，请删除build目录，重新构建项目。
