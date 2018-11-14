
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

在echo命令后面加上了一个字符串，该命令就能显示出这个文本字符串。默认情况下，不需要使用引号将要显示的文本字符串划定出来。

```shell
#!/bin/bash
echo The time and date are:
```

echo命令可用单引号或双引号来划定文本字符串。如果在字符串中用到了它们，你需要在文本中使用其中一种引号，而用另外一种来将字符串划定起来。

```shell
#!/bin/bash
echo "This is a test to see if you're paying attention"
echo 'Rich says "scripting is easy".'
```

把文本字符串和命令输出显示在同一行中，可以用echo语句的-n参数：你需要在字符串的两侧使用引号，保证要显示的字符串尾部有一个空格。命令输出将会在紧接着字符串结束的地方出现。

```shell
#!/bin/bash
echo -n "The time and date are: "
date
```

### 使用变量

#### 环境变量

shell维护着一组环境变量，用来记录特定的系统信息。比如系统的名称、登录到系统上的用户名、用户的系统ID(也称为UID)、用户的默认主目录以及shell查找程序的搜索路径。可以用set命令来显示一份完整的当前环境变量列表。

```shell
$ set
BASH=/bin/bash
HOME=/home/Samantha
```

在脚本中，可以在环境变量名称之前加上美元符($)来使用这些环境变量。

```shell
#!/bin/bash
# display user information from the system.
echo "User info for userid: $USER"
echo UID: $UID
echo HOME: $HOME
```

注意，echo命令中的环境变量会在脚本运行时替换成当前值。

只要脚本在引号中出现美元符，它就会以为你在引用一个变量。要显示美元符，你必须在它前面放置一个反斜线。

```shell
$ echo "The cost of the item is \$15"
The cost of the item is $15
```

${variable}形式引用的变量。变量名两侧额外的花括号通常用来帮助识别美元符后的变量名。

#### 用户变量

除了环境变量，shell脚本还允许在脚本中定义和使用自己的变量。

* 用户变量可以是任何由字母、数字或下划线组成的文本字符串，长度不超过20个。

* 用户变量区分大小写。

* 使用等号将值赋给用户变量。在变量、等号和值之间不能出现空格。

* shell脚本会自动决定变量值的数据类型。

* 与系统变量类似，用户变量可通过美元符引用。

```shell
#!/bin/bash
days=10
guest="Katie"
echo "$guest checked in $days days ago"
```

#### 命令替换




