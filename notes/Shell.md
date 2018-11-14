
# 构建基本脚本

### 创建脚本文件

在创建shell脚本文件时，必须在文件的第一行指定要使用的shell。其格式为: #!/bin/bash。在通常的shell脚本中，井号(#)用作注释行。shell脚本文件的第一行是个例外，#后面的惊叹号会告诉shell用哪个shell来运行脚本。test1.sh：

```shell
#!/bin/bash
# This script displays the date and who's logged on
date
who
```

根据需要，使用分号将两个命令放在一行上，但在shell脚本中，你可以在独立的行中书写命令。shell会按根据命令在文件中出现的顺序进行处理。

shell会通过PATH环境变量来查找命令。查看PATH环境变量：

```shell
$ echo $PATH
```

PATH环境变量被设置成只在一组目录中查找命令。要让shell找到test1脚本，只需采取以下两种作法之一:

* 将shell脚本文件所处的目录添加到PATH环境变量中;

* 在提示符中用绝对或相对文件路径来引用shell脚本文件。

执行脚本：

```shell
$ ./test1.sh
bash: ./test1.sh: Permission denied
```

现在shell找到了脚本文件，但还有一个问题。shell指明了你还没有执行文件的权限。快速查看一下文件权限就能找到问题所在。

```shell
$ ls -l test1
-rw-rw-r--    1 user     user           73 Sep 24 19:56 test1
```

下一步是通过chmod命令赋予文件属主执行文件的权限：

```shell
$ chmod u+x test1.sh
$ ./test1.sh
Wed Nov 14 08:36:40 UTC 2018
```

### 显示消息













