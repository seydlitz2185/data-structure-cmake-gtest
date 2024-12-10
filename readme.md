使用CMake在vscode上练习写c++数据结构，结合gtest进行测试。

## 使用方法

- 下载代码前需要做到：
  - 下载并安装CMake
  - 保证CMake可以通过命令行调用
    - 验证方式： cmake --version可以正常运行。
- 下载代码后编译程序
  - 命令行在CMakeList.txt相同的目录下执行	`cmake --build ./build`
- 运行gtest
  - cd到编译后生成的子目录./build下，命令行执行 `ctest`
