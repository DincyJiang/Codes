
# GDB基本使用方法

### 一、前提条件：编译时加入debug信息。

gcc或g++在编译时加入-g，-g分4个等级：

* -g0等于不加-g。即不包含任何信息

* -g1只包含最小信息，一般来说只有你不需要debug，只需要backtrace信息，并且真的很在意程序大小，或者有其他保密/特殊需求时才会使用-g1。

* –g2为gdb默认等级，包含绝大多数你需要的信息。

* –g3包含一些额外信息，例如包含宏定义信息。当你需要调试宏定义时，请使用-g3

```shell
g++ -g -Wall -o test.out test.cpp
```

### 二、开启调试

#### 运行程序

三种方法使用gdb运行程序：

```shell
$ gdb test.out
进入gdb后输入：
r arg1 arg2 ...
```

```shell
$ gdb --args test.out arg1 arg2 ...
进入gdb后输入：
r
```

```shell
$ gdb
进入gdb后输入：
file test.out
set args arg1 arg2 ...
r
```

#### 调试正在运行的程序

```shell
gdb test.out pid
```

#### 查core

```shell
gdb test.out core_file
```

### 三、常用命令

1. backtrace(bt)：显示栈信息。

2. frame(f) x ：切换到第x帧，其中x会在bt命令中显示，从0开始。0表示栈顶。

3. up/down x ：往栈顶移动x帧。如果不输入x，x默认值是1。

4. print(p) x ：打印x的信息，x可以是变量，也可以是对象或数组。

5. print *x ：打印x的内容。

6. print &x ：打印x的地址。

7. call func ：调用函数，此命令需要一个正在运行的程序。

8. set substitute-path src_path dst_path ：替换源码路径，当编译机与运行程序的机器代码路径不同时，需要使用该指令替换代码路径，否则无法在gdb中看到源码。

9. command m ：设置程序执行到断点m时要看的内容，如果不输入m，m默认是最后一个断点。

```shell
command m
> printf "x is %d\n", x
> c
> end
```

10. x /nfu ${addr} ：打印addr的内容。addr可以是任何合法的地址表达式，例如0x562fb3d，一个当前有效的指针变量p，或者一个当前有效的变量var的地址&var。nfu是格式，n表示查看的长度，f表示格式（例如16进制或10进制），u表示单位（例如单字节b，双字h，四字w等）。举个栗子：

```gdb
(gdb) x /3xw 0x562fb3d //这个指令的意思为：以16进制格式显示地址0x562fb3d处3个单位，每个单位四字节的内容。你将得到下列数值：
0x562fb3d:    0x00282ff4    0x080484e0    0x00000000
```































