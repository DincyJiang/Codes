
# GDB常用命令

### 前提条件：编译时加入debug信息。

gcc或g++在编译时加入-g，-g分4个等级：

* -g0等于不加-g。即不包含任何信息

* -g1只包含最小信息，一般来说只有你不需要debug，只需要backtrace信息，并且真的很在意程序大小，或者有其他保密/特殊需求时才会使用-g1。

* –g2为gdb默认等级，包含绝大多数你需要的信息。

* –g3包含一些额外信息，例如包含宏定义信息。当你需要调试宏定义时，请使用-g3

```shell
g++ -g -Wall -o test.out test.cpp
```

### 开启调试

#### 运行程序

三种方法使用gdb运行程序：

```shell
$ gdb test.out
进入gdb后输入：
r arg1 arg2 ...
```

```shell
$ gdb --args test.out arg1 arg2
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






