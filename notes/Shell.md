<!-- GFM-TOC -->
* [一、构建基本脚本](#一构建基本脚本)
    * [创建脚本文件](#创建脚本文件)
    * [显示消息](#显示消息)
    * [使用变量](#使用变量)
    * [重定向输入和输出](#重定向输入和输出)
    * [管道](#管道)
    * [执行数学运算](#执行数学运算)
    * [退出脚本](#退出脚本)
* [二、结构化命令](#二结构化命令)
    * [if-then](#if-then)
    * [if-then-else](#if-then-else)
    * [嵌套if](#嵌套if)
    * [test命令](#test命令)
    * [复合条件测试](#复合条件测试)
    * [if-then的高级特性](#if-then的高级特性)
    * [case命令](#case命令)
* [参考资料](#参考资料)
<!-- GFM-TOC -->

# 一、构建基本脚本

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

shell脚本中最有用的特性之一就是可以从命令输出中提取信息，并将其赋给变量。把输出赋给变量之后，就可以随意在脚本中使用了。这个特性在处理脚本数据时尤为方便。

有两种方法可以将命令输出赋给变量，变量testing获得了date命令的输出:

* 反引号字符(`) 

```shell
#!/bin/bash
testing='date'
```

* $()格式

```shell
#!/bin/bash
testing=$(date)
```

下面这个例子很常见，它在脚本中通过命令替换获得当前日期并用它来生成唯一文件名：

```shell
#!/bin/bash
# copy the /usr/bin directory listing to a log file
today=$(date +%y%m%d)
ls /usr/bin -al > log.$today
```

这个脚本将日期值赋给一个变量，之后再将其作为文件名的一部分。文件自身含有目录列表的重定向输出。运行该脚本之后，应该能在目录中看到一个新文件。

```shell
-rw-r--r-- 1 user user 769 Jan 31 10:15 log.140131
```

目录中出现的日志文件采用$today变量的值作为文件名的一部分。日志文件的内容是/usr/bin目录内容的列表输出。

警告：命令替换会创建一个子shell来运行对应的命令。子shell(subshell)是由运行该脚本的shell 所创建出来的一个独立的子shell(child shell)。正因如此，由该子shell所执行命令是无法使用脚本中所创建的变量的。

### 重定向输入和输出

重定向可以用于输入，也可以用于输出。可以将命令的输出重定向到另一个位置(比如文件)，也可以将文件重定向到命令输入。

#### 输出重定向

最基本的重定向将命令的输出发送到一个文件中。bash shell用大于号(>)来完成这项功能。之前显示器上出现的命令输出会被保存到指定的输出文件中。

```shell
$ date > test
```

如果输出文件已经存在了，重定向操作符会用新的文件数据覆盖已有文件。可以用双大于号(>>)来追加数据。

```shell
$ date >> test6
```

#### 输入重定向

输入重定向将文件的内容重定向到命令，输入重定向符号是小于号(<)。

```shell
$ wc < test6
```

还有另外一种输入重定向的方法，称为内联输入重定向(inline input redirection)。这种方法无需使用文件进行重定向，只需要在命令行中指定用于输入重定向的数据就可以了。内联输入重定向符号是远小于号(<<)。在命令行上使用内联输入重定向时，shell会用PS2环境变量中定义的次提示符(参见第6章) 来提示输入数据。下面是它的使用情况。

```shell
$ wc << EOF
> test string 1
> test string 2
> test string 3
> EOF
```

次提示符会持续提示，以获取更多的输入数据，直到你输入了作为文本标记的那个字符串。

### 管道

有时需要将一个命令的输出作为另一个命令的输入。这可以用重定向来实现，只是有些笨拙。我们用不着将命令输出重定向到文件中，可以将其直接重定向到另一个命令。这个过程叫作管道连接(piping)。

* 管道符号由两个竖线构成，一个在另一个上面。然而管道符号的印刷体通常看起来更像是单个竖线(|)。

* 不要以为由管道串起的两个命令会依次执行。Linux系统实际上会同时运行这两个命令，在系统内部将它们连接起来。在第一个命令产生输出的同时，输出会被立即送给第二个命令。数据传输不会用到任何中间文件或缓冲区。

* 如果想要更别致点，也可以搭配使用重定向和管道来将输出保存到文件中。

* 管道最流行的用法之一是将命令产生的大量输出通过管道传送给more命令。

```shell
$ ls -al | more
```

### 执行数学运算

在shell脚本中有两种途径来进行数学运算。

#### expr命令

```shell
$ expr 1 + 5
6
```

许多expr命令操作符在shell中另有含义(比如星号)。当它们出现在在expr命令中时，会得到一些诡异的结果。要解决这个问题，对于那些容易被shell错误解释的字符，在它们传入expr命令之前，需要使用shell的转义字符(反斜线)将其标出来。

#### 使用方括号

在bash中，在将一个数学运算结果赋给某个变量时，可以用美元符和方括号($[ operation ])将数学表达式围起来。

```shell
$ var1=$[1 + 5]
$ echo $var1
6
```

这种技术也适用于shell脚本。

```shell
#!/bin/bash
var1=100
var2=50
var3=45
var4=$[$var1 * ($var2 - $var3)]
echo The final result is $var4
```

bash shell数学运算符只支持整数运算。

#### 浮点解决方案

有几种解决方案能够克服bash中数学运算的整数限制。最常见的方案是用内建的bash计算器，叫作bc。

* bc的基本用法

bash计算器实际上是一种编程语言，它允许在命令行中输入浮点表达式，然后解释并计算该表达式，最后返回结果。

```shell
$ bc
bc 1.06.95
Copyright 1991-1994, 1997, 1998, 2000, 2004, 2006 Free Software Foundation, Inc. 13 This is free software with ABSOLUTELY NO WARRANTY.
For details type 'warranty'.
12 * 5.4
64.8
```

* 在脚本中使用bc

可以用命令替换运行bc命令，并将输出赋给一个变量。这个例子将scale变量设置成了四位小数，并在expression部分指定了特定的运算：

```shell
#!/bin/bash
var1=$(echo "scale=4; 3.44 / 5" | bc)
echo The answer is $var1
```

如果需要进行大量运算，在一个命令行中列出多个表达式就会有点麻烦。最好的办法是使用内联输入重定向，它允许你直接在命令行中重定向数据。在shell脚本中，可以将输出赋给一个变量。

```shell
#!/bin/bash
var1=10.46
var2=43.67
var3=33.2
var4=71
var5=$(bc << EOF
scale = 4
a1 = ( $var1 * $var2)
b1 = ($var3 * $var4)
a1 + b1
EOF
)
echo The final answer for this mess is $var5
```

### 退出脚本

shell中运行的每个命令都使用退出状态码(exit status)告诉shell它已经运行完毕。退出状态码是一个0~255的整数值，在命令结束运行时由命令传给shell。可以捕获这个值并在脚本中使用。

#### 查看退出状态码

Linux提供了一个专门的变量$?来保存上个已执行命令的退出状态码。对于需要进行检查的命令，必须在其运行完毕后立刻查看或使用$?变量。它的值会变成由shell所执行的最后一条命令的退出状态码。

```shell
$ date
Sat Jan 15 10:01:30 EDT 2014
$ echo $?
0
```

按照惯例，一个成功结束的命令的退出状态码是0。如果一个命令结束时有错误，退出状态码就是一个正数值。无效命令会返回一个退出状态码127。

```shell
$ asdfg
-bash: asdfg: command not found
$ echo $?
127
```

#### exit命令

默认情况下，shell脚本会以脚本中的最后一个命令的退出状态码退出。你可以改变这种默认行为，返回自己的退出状态码。exit命令允许你在脚本结束时指定一个退出状态码。当查看脚本的退出码时，你会得到作为参数传给exit命令的值。退出状态码最大只能是255，超过255的话，shell通过模运算得到这个结果。

```shell
#!/bin/bash
# testing the exit status
var1=10
var2=30
var3=$[$var1 + $var2]
echo The answer is $var3
exit 5
```

# 二、结构化命令

有一类命令会根据条件使脚本跳过某些命令。这样的命令通常称为结构化命令(structured command)。结构化命令允许你改变程序执行的顺序。

### if-then

bash shell的if语句会运行if后面的那个命令。如果该命令的退出状态码是0 (该命令成功运行)，位于then部分的命令就会被执行。如果该命令的退出状态码是其他值，then部分的命令就不会被执行，bash shell会继续执行脚本中的下一个命令。fi语句用来表示if-then 语句到此结束。

```shell
#!/bin/bash
if pwd
then
    echo "It worked"
fi
```

在then部分，你可以使用不止一条命令。可以像在脚本中的其他地方一样在这里列出多条命令。bash shell会将这些命令当成一个块，如果if语句行的命令的退出状态值为0，所有的命令 都会被执行;如果if语句行的命令的退出状态不为0，所有的命令都会被跳过。

```shell
#!/bin/bash
# testing multiple commands in the then section #
testuser=Christine
#
if grep $testuser /etc/passwd
then
    echo "This is my first command"
    echo "This is my second command"
    echo "I can even put in other commands besides echo:"
    ls -a /home/$testuser/.b*
fi
```

### if-then-else

当if语句中的命令返回退出状态码0时，then部分中的命令会被执行，这跟普通的if-then语句一样。当if语句中的命令返回非零退出状态码时，bash shell会执行else部分中的命令。

```shell
#!/bin/bash
# testing the else section
#
testuser=NoSuchUser
#
if grep $testuser /etc/passwd then
   echo "The bash files for user $testuser are:"
   ls -a /home/$testuser/.b*
   echo
else
   echo "The user $testuser does not exist on this system."
   echo
fi
```

### 嵌套if

```shell
#!/bin/bash
# Testing nested ifs
#
testuser=NoSuchUser
#
if grep $testuser /etc/passwd
then
    echo "The user $testuser exists on this system."
else
    echo "The user $testuser does not exist on this system."
    if ls -d /home/$testuser/
    then
        echo "However, $testuser has a directory."
    fi
fi
```

在脚本中使用这种嵌套if-then语句的问题在于代码不易阅读，很难理清逻辑流程。可以使用else部分的另一种形式:elif。这样就不用再书写多个if-then语句了。elif使 用另一个if-then语句延续else部分。

```shell
#!/bin/bash
# Testing nested ifs - use elif #
testuser=NoSuchUser
#
if grep $testuser /etc/passwd
then
   echo "The user $testuser exists on this system."
#
elif ls -d /home/$testuser
then
   echo "The user $testuser does not exist on this system."
   echo "However, $testuser has a directory."
#
```

### test命令

if-then语句是否能测试命令退出状态码之外的条件。答案是不能。test命令提供了在if-then语句中测试不同条件的途径。如果test命令中列出的条件成立，test命令就会退出并返回退出状态码0。

如果不写test命令的condition部分，它会以非零的退出状态码退出，并执行else语句块。

```shell
if test
then
   echo "No expression returns a True"
else
   echo "No expression returns a False"
fi
```

当你加入一个条件时，test命令会测试该条件。变量my_variable中包含有内容(Full)，因此当test命令测试条件时，返回的退出状态为0。如果该变量中没有包含内容，就会出现相反的情况。

```shell
#!/bin/bash
# Testing the test command #
my_variable="Full"
#
if test $my_variable
then
   echo "The $my_variable expression returns a True"
#
else
   echo "The $my_variable expression returns a False"
fi
```

bash shell提供了另一种条件测试方法，无需在if-then语句中声明test命令。方括号定义了测试条件。注意，第一个方括号之后和第二个方括号之前必须加上一个空格，否则就会报错。

```shell
if [ condition ]
then
    commands
fi
```

test命令可以判断三类条件: 

* 数值比较

```shell
n1 -eq n2  检查n1是否与n2相等
n1 -ge n2  检查n1是否大于或等于n2
n1 -gt n2  检查n1是否大于n2
n1 -le n2  检查n1是否小于或等于n2
n1 -lt n2  检查n1是否小于n2
n1 -ne n2  检查n1是否不等于n2
```

* 字符串比较

```shell
str1 = str2    检查str1是否和str2相同
str1 != str2   检查str1是否和str2不同
str1 < str2    检查str1是否比str2小
str1 > str2    检查str1是否比str2大
-n str1        检查str1的长度是否非0
-z str1        检查str1的长度是否为0
```

要测试一个字符串是否比另一个字符串大就是麻烦的开始。当要开始使用测试条件的大于或 3 小于功能时，就会出现两个经常困扰shell程序员的问题:

(1)大于号和小于号必须转义，否则shell会把它们当作重定向符号，把字符串值当作文件名;

(2)大于和小于顺序和sort命令所采用的不同。在比较测试中，大写字母被认为是小于小写字母的。但sort命令恰好相反。

空的和未初始化的变量会对shell脚本测试造成灾难性的影响。如果不是很确定一个变量的内容，最好在将其用于数值或字符串比较之前先通过-n或-z来测试一下变量是否含有值。

* 文件比较

这一类比较测试很有可能是shell编程中最为强大、也是用得最多的比较形式。它允许你测试Linux文件系统上文件和目录的状态。

```shell
-d file  检查file是否存在并是一个目录
-e file  检查file是否存在
-f file  检查file是否存在并是一个文件
-r file  检查file是否存在并可读
-s file  检查file是否存在并非空
-w file  检查file是否存在并可写
-x file  检查file是否存在并可执行
-O file  检查file是否存在并属当前用户所有
-G file  检查file是否存在并且默认组与当前用户相同
file1 -nt file2  检查file1是否比file2新
file1 -ot file2  检查file1是否比file2旧
```

### 复合条件测试

if-then语句允许你使用布尔逻辑来组合测试。有两种布尔运算符可用: 

* [ condition1 ] && [ condition2 ]
* [ condition1 ] || [ condition2 ]












