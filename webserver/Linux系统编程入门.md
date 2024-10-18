

## GCC

### GCC常见的参数选项

![image-20240714100152329](C:\Users\juluo\AppData\Roaming\Typora\typora-user-images\image-20240714100152329.png)

![image-20240714100245991](C:\Users\juluo\AppData\Roaming\Typora\typora-user-images\image-20240714100245991.png)

## 什么是库

- 库文件是计算机上的一类语言，可以简单的把库文件看成一种代码仓库，它提供给使用者一些可以直接拿来用的变量，函数或类
- 库是特殊的一种程序，编写库的程序和编写一般的程序区别不大，只是库不能单独运行
- 库文件有两种，静态库和动态库（共享库），区别是：静态库在程序链接阶段被复制到了程序中；动态库在链接阶段没有被复制到程序中，而是程序在运行时由系统动态加载到了内存中供程序使用
- 库的好处
  - 代码保密
  - 方便部署和分发



## 静态库

### 静态库的制作

- `gcc`获得 `.o `文件

```
gcc -c txt1.c txt2.c .
```



- 将` .o` 文件打包，使用 `ar `工具（archive）

```
ar rcs libxxx.a xxx.o xxx.o
```

### 静态库的使用

- `-L`搜索库的路径
- `-l`来指定需要使用的库

```
g++ main.cpp -o run -L ./lib/ -l add
```

















