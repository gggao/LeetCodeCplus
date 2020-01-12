leetcode c++ 的解决方法

## 组件
vscode + cmake

vscode 插件：
c/c++, c++ Intellisense, CMake, CMake Tools


### windows

#### mingw 

将程序添加到 PATH 变量中
F:\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin

#### cmake

添加到 PATH 环境变量
CTRL + SHIFT + P 打开控制面板
CMake:config
CMake:seleck a kit, 选择一个编译套件, mingw 相关套件会被识别。

第一次生成 makefile 需要指定平台的生成器[cmake 跨平台]
因为使用 mingw，所以第一次需要执行：cmake -G "MinGW Makefiles"

```shell
mkdir build
cd build
cmake .. -G "MinGW Makefiles"
make
```

也可以指定编译运行单个程序
make {ID}.{name}

编译、调试、单测都可以在 cmake 的工具栏里处理

#### googletest

git clone https://github.com/google/googletest.git
mkdir build && cd build
cmake ..
make
sudo make install

添加环境变量：
GTEST_ROOT F:\Program Files (x86)\googletest-distribution
否则执行 cmake 时会找不到相关目录, 也可以使用命令：
cmake -DGTEST_ROOT="F:\Program Files (x86)\googletest-distribution"

### 问题
1. 一个工程一般有一个main，或者写 MakeFile, 用 cmake 可以更简单的实现，而且和 vscode 对接的很好。
2. 一般的 vs 工程，需要写非常多的 task.json 或者 launch.json, 或者写复杂的 MakeFile， 利用 cmake 更方便。


