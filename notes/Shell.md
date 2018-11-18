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
    * [for命令](#for命令)
    * [C语言风格的for命令](#C语言风格的for命令)
    * [while命令](#while命令)
    * [until命令](#until命令)
    * [嵌套循环](#嵌套循环)
    * [循环处理文件数据](#循环处理文件数据)
    * [控制循环](#控制循环)
    * [处理循环的输出](#处理循环的输出)
    * [实例](#实例)
* [三、处理用户输入](#三处理用户输入)
    * [命令行参数](#命令行参数)
    * [特殊参数变量](#特殊参数变量)
    * [移动变量](#移动变量)
    * [处理选项](#处理选项)
    * [将选项标准化](#将选项标准化)
    * [获得用户输入](#获得用户输入)
* [四、呈现数据](#四呈现数据)
    * [理解输入和输出](#理解输入和输出)
    * [在脚本中重定向输出](#在脚本中重定向输出)
    * [在脚本中重定向输入](#在脚本中重定向输入)
    * [创建自己的重定向](#创建自己的重定向)
    * [列出打开的文件描述符](#列出打开的文件描述符)
    * [阻止命令输出](#阻止命令输出)
    * [创建临时文件](#创建临时文件)
    * [记录消息](#记录消息)
    * [实例](#实例)
* [五、控制脚本](#五控制脚本)
    * [处理信号](#处理信号)
    * [以后台模式运行脚本](#以后台模式运行脚本)
    * [在非控制台下运行脚本](#在非控制台下运行脚本)
    * [作业控制](#作业控制)
    * [调整谦让度](#调整谦让度)
    * [定时运行作业](#定时运行作业)
    
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

### if-then的高级特性

bash shell提供了两项可在if-then语句中使用的高级特性: 

* 用于数学表达式的双括号

双括号命令允许你在比较过程中使用高级数学表达式，双括号命令的格式如下:

(( expression ))

```shell
val++      后增
val--      后减
++val      先增
--val      先减
!          逻辑求反
~          位求反
**         幂运算
<<         左位移
>>         右位移
&          位布尔和
|          位布尔或
&&         逻辑和
||         逻辑或
```

* 用于高级字符串处理功能的双方括号

双方括号命令提供了针对字符串比较的高级特性。双方括号命令的格式如下: 

[[ expression ]]

双方括号里的expression使用了test命令中采用的标准字符串比较。但它提供了test命令未提供的另一个特性——模式匹配(pattern matching)。在模式匹配中，可以定义一个正则表达式来匹配字符串值。

```shell
if [[ $USER == r* ]]
then
echo "Hello $USER"
fi
```

### case命令

case命令会采用列表格式来检查单个变量的多个值。

```shell
case variable in
pattern1 | pattern2) 
   commands1;; 
pattern3) 
   commands2;;
*) 
   default commands;;
esac
```

### for命令

```shell
for var in list 
do
   commands
done
```

#### 读取列表中的值

for命令最基本的用法就是遍历for命令自身所定义的一系列值。

```shell
for test in Alabama Alaska Arizona Arkansas California Colorado
do
    echo The next state is $test
done
```

#### 读取列表中的复杂值

有时会遇到难处理的数据。使用转义字符(反斜线)来将单引号转义; 使用双引号来定义用到单引号的值。for循环假定每个值都是用空格分割的。如果有包含空格的数据值，就必须用双引号将这些值圈起来。

```shell
for test in I don\'t know if "this'll" work
do
    echo "word:$test"
done

for test in Nevada "New Hampshire" "New Mexico" "New York"
do
    echo "Now going to $test"
done
```

#### 从变量读取列表

通常shell脚本遇到的情况是，你将一系列值都集中存储在了一个变量中，然后需要遍历变量中的整个列表。用了另一个赋值语句向$list变量包含的已有列表中添加(或者说是拼接)了一个值。

```shell
list="Alabama Alaska Arizona Arkansas Colorado"
list=$list" Connecticut"
for state in $list
do
    echo "Have you ever visited $state?"
done
```

#### 从命令读取值

在命令替换中使用了cat命令来输出文件states的内容。

```shell
file="states"
for state in $(cat $file)
do
    echo "Visit beautiful $state"
done
```

#### 更改字段分隔符

造成这个问题的原因是特殊的环境变量IFS，叫作内部字段分隔符(internal field separator)。 IFS环境变量定义了bash shell用作字段分隔符的一系列字符。默认情况下，bash shell会将下列字符当作字段分隔符:

* 空格

* 制表符

* 换行符

如果bash shell在数据中看到了这些字符中的任意一个，它就会假定这表明了列表中一个新数据字段的开始。在处理可能含有空格的数据(比如文件名)时，这会非常麻烦。要解决这个问题，可以在shell脚本中临时更改IFS环境变量的值来限制被bash shell当作字段分隔符的字符。例如，如果你想修改IFS的值，使其只能识别换行符，那就必须这么做:

```shell
IFS=$'\n'
```

将这个语句加入到脚本中，告诉bash shell在数据值中忽略空格和制表符。

还有其他一些IFS环境变量的绝妙用法。假定你要遍历一个文件中用冒号分隔的值(比如在/etc/passwd文件中)。你要做的就是将IFS的值设为冒号。 

```shell
IFS=:
```

如果要指定多个IFS字符，只要将它们在赋值行串起来就行。这个赋值会将换行符、冒号、分号和双引号作为字段分隔符。

```shell
IFS=$'\n':;"
```

#### 用通配符读取目录

可以用for命令来自动遍历目录中的文件。进行此操作时，必须在文件名或路径名中使用通配符。它会强制shell使用文件扩展匹配。文件扩展匹配是生成匹配指定通配符的文件名或路径名的过程。

```shell
for file in /home/rich/test/*
```

也可以在for命令中列出多个目录通配符，将目录查找和列表合并进同一个for语句。

```shell
for file in /home/rich/.b* /home/rich/badtest
```

### C语言风格的for命令

```shell
for (( a = 1; a < 10; a++ ))
```

注意，有些部分并没有遵循bash shell标准的for命令:

* 变量赋值可以有空格;

* 条件中的变量不以美元符开头;

* 迭代过程的算式未用expr命令格式。

C语言风格的for命令也允许为迭代使用多个变量。循环会单独处理每个变量，你可以为每
个变量定义不同的迭代过程。尽管可以使用多个变量，但你只能在for循环中定义一种条件。

```shell
for (( a=1, b=10; a <= 10; a++, b-- ))
```

### while命令

```shell
while testcommand 
do
other commands
done
```

最常见的test command的用法是用方括号来检查循环命令中用到的shell变量的值。

```shell
var1=10
while [ $var1 -gt 0 ]
do
echo $var1
    var1=$[ $var1 - 1 ]
done
```

while命令允许你在while语句行定义多个测试命令。只有最后一个测试命令的退出状态码会被用来决定什么时候结束循环。在含有多个命令的while语句中，在每次迭代中所有的测试命令都会被执行，包括测试命令失败的最后一次迭代。

```shell
while echo $var1
       [ $var1 -ge 0 ]
do
    echo "This is inside the loop"
    var1=$[ $var1 - 1 ]
done
```

### until命令

until命令和while命令工作的方式完全相反。until命令要求你指定一个通常返回非零退出状态码的测试命令。只有测试命令的退出状态码不为0，bash shell才会执行循环中列出的命令。一旦测试命令返回了退出状态码0，循环就结束了。

```shell
until test commands 
do
   other commands
done
```

和while命令类似，你可以在until命令语句中放入多个测试命令。只有最后一个命令的退出状态码决定了bash shell是否执行已定义的other commands。

```shell
var1=100
until [ $var1 -eq 0 ]
do
echo $var1
    var1=$[ $var1 - 25 ]
done
```

### 嵌套循环

```shell
for (( a = 1; a <= 3; a++ ))
do
   echo "Starting loop $a:"
   for (( b = 1; b <= 3; b++ ))
   do
      echo " Inside loop: $b"
   done
done
```

这个被嵌套的循环(也称为内部循环，inner loop)会在外部循环的每次迭代中遍历一次它所有的值。注意，两个循环的do和done命令没有任何差别。bash shell知道当第一个done命令执行时是指内部循环而非外部循环。

### 循环处理文件数据

通常必须遍历存储在文件中的数据。这要求结合已经讲过的两种技术: 

* 使用嵌套循环

* 修改IFS环境变量

通过修改IFS环境变量，就能强制for命令将文件中的每行都当成单独的一个条目来处理，即便数据中有空格也是如此。一旦从文件中提取出了单独的行，可能需要再次利用循环来提取行中的数据。

典型的例子是处理/etc/passwd文件中的数据。这要求你逐行遍历/etc/passwd文件，并将IFS变量的值改成冒号，这样就能分隔开每行中的各个数据段了。

```shell
#!/bin/bash
# changing the IFS value
IFS.OLD=$IFS
IFS=$'\n'
for entry in $(cat /etc/passwd)
do
    echo "Values in $entry –"
    IFS=:
    for value in $entry
    do
        echo "   $value"
    done
done
```

### 控制循环

#### break命令

break命令是退出循环的一个简单方法。可以用break命令来退出任意类型的循环，包括while和until循环。

有时你在内部循环，但需要停止外部循环。break命令接受单个命令行参数值: break n。其中n指定了要跳出的循环层级。默认情况下，n为1，表明跳出的是当前的循环。如果你将n设为2，break命令就会停止下一级的外部循环。

#### continue命令

continue命令可以提前中止某次循环中的命令，但并不会完全终止整个循环。

### 处理循环的输出

在shell脚本中，你可以对循环的输出使用管道或进行重定向。这可以通过在done命令之后添加一个处理命令来实现。shell会将for命令的结果重定向到文件output.txt中，而不是显示在屏幕上。

```shell
for file in /home/rich/*
do
    if [ -d "$file" ]
    then
        echo "$file is a directory"
    elif
        echo "$file is a file"
    fi
done > output.txt
```

### 实例

#### 查找可执行文件

运行这段代码时，你会得到一个可以在命令行中使用的可执行文件的列表。

```shell
#!/bin/bash
# finding files in the PATH
IFS=: # 设置IFS 分隔符
for folder in $PATH # 创建一个for循环，对环境变量PATH中的目录进行迭代
do
    echo "$folder:"
    for file in $folder/* # 用另一个for循环来迭代特定目录中的所有文件
    do
        if [ -x $file ] # 检查各个文件是否具有可执行权限
        then
            echo " $file"
        fi 
    done
done
```

#### 创建多个用户账户

将需要添加的新用户账户放在一个文本文件中，然后创建一个简单的脚本进行处理。这个文本文件的格式如下:userid, user name。两个值之间使用逗号分隔，这样就形成了一种名为逗号分隔值的文件格式(或者是.csv)。必须作为root用户才能运行这个脚本，因为useradd命令需要root权限。

```shell
#!/bin/bash
# process new user accounts
input="users.csv"
while IFS=',' read -r userid name # 将IFS分隔符设置成逗号, 使用read命令读取文件中的各行
do
  echo "adding $userid"
  useradd -c "$name" -m $userid
done < "$input" # 把数据从文件中送入while命令
```

# 三、处理用户输入

### 命令行参数

向shell脚本传递数据的最基本方法是使用命令行参数。命令行参数允许在运行脚本时向命令行添加数据。脚本会通过特殊的变量来处理命令行参数。

```shell
$ ./addem 10 30
```

#### 读取参数

位置参数(positional parameter)。这也包括shell所执行的脚本名称。位置参数变量是标准的数字：$0是程序名，$1是第一个参数，$2是第二个参数，依次类推，直到第九个参数$9。可以在shell脚本中像使用其他变量一样使用$1变量。shell脚本会自动将命令行参数的值分配给变量，不需要你作任何处理。

```shell
$ cat test1.sh
#!/bin/bash
# using one command line parameter
#
factorial=1
for (( number = 1; number <= $1 ; number++ )) do
       factorial=$[ $factorial * $number ]
    done
echo The factorial of $1 is $factorial $
$ ./test1.sh 5
The factorial of 5 is 120
```

如果需要输入更多的命令行参数，则每个参数都必须用空格分开。

```shell
$ ./test2.sh 2 5
```

要在参数值中包含空格，必须要用引号(单引号或双引号均可)。将文本字符串作为参数传递时，引号并非数据的一部分。它们只是表明数据的起止位置。

```shell
$ ./test3.sh 'Rich Blum'
$ ./test3.sh "Rich Blum"
```

如果脚本需要的命令行参数不止9个，你仍然可以处理，但是需要稍微修改一下变量名。在第9个变量之后，你必须在变量数字周围加上花括号，比如${10}。这项技术允许你根据需要向脚本添加任意多的命令行参数。

```shell
#!/bin/bash
# handling lots of parameters
#
total=$[ ${10} * ${11} ]
echo The tenth parameter is ${10}
$ ./test4.sh 1 2 3 4 5 6 7 8 9 10 11 12
The tenth parameter is 10
```

#### 读取脚本名

可以用$0参数获取shell在命令行启动的脚本名。但是如果使用另一个命令来运行shell脚本，命令会和脚本名混在一起，出现在$0参数中。另一个问题是如果传给$0变量的实际字符串不仅仅是脚本名，而是完整的脚本路径时，变量$0就会使用整个路径。

有个方便的小命令可以帮到我们。basename命令会返回不包含路径的脚本名。

```shell
#!/bin/bash
# Using basename with the $0 parameter #
name=$(basename $0)
echo
echo The script name is: $name
#
$ bash /home/Christine/test5b.sh
The script name is: test5b.sh $
$ ./test5b.sh
The script name is: test5b.sh
$
```

#### 测试参数

在shell脚本中使用命令行参数时要小心些。如果脚本不加参数运行，可能会出问题。当脚本认为参数变量中会有数据而实际上并没有时，脚本很有可能会产生错误消息。这种写脚本的方法并不可取。在使用参数前一定要检查其中是否存在数据。

```shell
#!/bin/bash
# testing parameters before use #
if [ -n "$1" ]
then
    echo Hello $1, glad to meet you.
else
    echo "Sorry, you did not identify yourself. "
fi
```

### 特殊参数变量

#### 参数统计

特殊变量$#含有脚本运行时携带的命令行参数的个数。可以在脚本中任何地方使用这个特殊变量，就跟普通变量一样。

```shell
#!/bin/bash
# getting the number of parameters
#
echo There were $# parameters supplied.
```

这个变量还提供了一个简便方法来获取命令行中最后一个参数，${!#}变量代表了最后一个命令行参数变量。当命令行上没有任何参数时，$#的值为0，但${!#}变量会返回命令行用到的脚本名。

```shell
#!/bin/bash
# Grabbing the last parameter
#
params=$#
echo
echo The last parameter is $params echo The last parameter is ${!#} echo

$ bash test10.sh 1 2 3 4 5
The last parameter is 5
The last parameter is 5

$ bash test10.sh
The last parameter is 0
The last parameter is test10.sh
```

#### 抓取所有的数据

$*和$@变量可以用来轻松访问所有的参数。这两个变量都能够在单个变量中存储所有的命令行参数。$*变量会将命令行上提供的所有参数当作一个单词保存。$@变量会将命令行上提供的所有参数当作同一字符串中的多个独立的单词。通常通过for命令遍历命令行参数。

```shell
#!/bin/bash
# testing $* and $@
#
echo
count=1
for param in "$*"
do
   echo "\$* Parameter #$count = $param"
   count=$[ $count + 1 ]
done
#
echo
count=1
for param in "$@"
do
   echo "\$@ Parameter #$count = $param"
   count=$[ $count + 1 ]
done
$
$ ./test.sh rich barbara katie jessica
$* Parameter #1 = rich barbara katie jessica
$@ Parameter #1 = rich
$@ Parameter #2 = barbara
$@ Parameter #3 = katie
$@ Parameter #4 = jessica
```

### 移动变量

shift命令会根据它们的相对位置来移动命令行参数。在使用shift命令时，默认情况下它会将每个参数变量向左移动一个位置。变量$3的值会移到$2中，变量$2的值会移到$1中，而变量$1的值则会被删除(注意，变量$0的值，也就是程序名，不会改变)。

这是遍历命令行参数的另一个好方法，尤其是在你不知道到底有多少参数时。你可以只操作第一个参数，移动参数，然后继续操作第一个参数。

```shell
#!/bin/bash
# demonstrating the shift command
echo
count=1
while [ -n "$1" ]
do
    echo "Parameter #$count = $1"
    count=$[ $count + 1 ]
    shift
done
$
$ ./test13.sh rich barbara katie jessica
Parameter #1 = rich
Parameter #2 = barbara
Parameter #3 = katie
Parameter #4 = jessica
```

使用shift命令的时候要小心。如果某个参数被移出，它的值就被丢弃了，无法再恢复。另外，你也可以一次性移动多个位置，只需要给shift命令提供一个参数，指明要移动的位置数就行了。

```shell
#!/bin/bash
# demonstrating a multi-position shift
#
echo
echo "The original parameters: $*"
shift 2
echo "Here's the new first parameter: $1" $
$ ./test14.sh 1 2 3 4 5
The original parameters: 1 2 3 4 5
Here's the new first parameter: 3
```

### 处理选项

选项是跟在单破折线后面的单个字母，它能改变命令的行为。

#### 查找选项

* 处理简单选项

可以使用shift命令来依次处理脚本程序携带的命令行参数。也可以用同样的方法来处理命令行选项。在提取每个单独参数时，用case语句来判断某个参数是否为选项。

```shell
#!/bin/bash
# extracting command line options as parameters #
echo
while [ -n "$1" ]
do
   case "$1" in
     -a) echo "Found the -a option" ;;
     -b) echo "Found the -b option" ;;
     -c) echo "Found the -c option" ;;
      *) echo "$1 is not an option" ;;
   esac
shift done
$
$ ./test15.sh -a -b -c -d
Found the -a option
Found the -b option
Found the -c option
-d is not an option
```

* 分离参数和选项

在shell脚本中同时使用选项和参数的情况。Linux中处理这个问题的标准方式是用特殊字符来将二者分开，该字符会告诉脚本何时选项结束以及普通参数何时开始。对Linux来说，这个特殊字符是双破折线(--)。shell会用双破折线来表明选项列表结束。在双破折线之后，脚本就可以放心地将剩下的命令行参数当作参数，而不是选项来处理了。要检查双破折线，只要在case语句中加一项就行了。

```shell
#!/bin/bash
# extracting options and parameters echo
while [ -n "$1" ]
do
    case "$1" in
        -a) echo "Found the -a option" ;;
        -b) echo "Found the -b option" ;;
        -c) echo "Found the -c option" ;;
        --) shift
            break ;;
        *) echo "$1 is not an option";;
    esac
    shift
done
```

在遇到双破折线时，脚本用break命令来跳出while循环。由于过早地跳出了循环，我们需要再加一条shift命令来将双破折线移出参数变量。

用一组普通的选项和参数来运行这个脚本，结果说明在处理时脚本认为所有的命令行参数都是选项。

```shell
$ ./test.sh -c -a -b test1 test2 test3
Found the -c option
Found the -a option
Found the -b option
test1 is not an option
test2 is not an option
test3 is not an option
```

用双破折线来将命令行上的选项和参数划分开来。当脚本遇到双破折线时，它会停止处理选项，并将剩下的参数都当作命令行参数。

```shell
$ ./test.sh -c -a -b -- test1 test2 test3
Found the -c option
Found the -a option
Found the -b option
Parameter #1: test1
Parameter #2: test2
Parameter #3: test3
```

* 处理带值的选项

有些选项会带上一个额外的参数值。当命令行选项要求额外的参数时，脚本必须能检测到并正确处理。下面是如何处理的例子。

```shell
#!/bin/bash
# extracting command line options and values echo
while [ -n "$1" ]
do
    case "$1" in
        -a) echo "Found the -a option";;
        -b) param="$2"
            echo "Found the -b option, with parameter value $param"
            shift ;;
        -c) echo "Found the -c option";;
        --) shift
            break ;;
        *) echo "$1 is not an option";;
esac
shift 
done
#
count=1
for param in "$@"
do
    echo "Parameter #$count: $param"
    count=$[ $count + 1 ]
done

$ ./test.sh -b test1 -a -d
Found the -b option, with parameter value test1 Found the -a option
-d is not an option
```

#### 使用getopt命令

getopt命令是一个在处理命令行选项和参数时非常方便的工具。它能够识别命令行参数，从而在脚本中解析它们时更方便。

* 命令的格式

getopt命令可以接受一系列任意形式的命令行选项和参数，并自动将它们转换成适当的格式。它的命令格式如下:

```shell
getopt optstring parameters
```

optstring是这个过程的关键所在。它定义了命令行有效的选项字母，还定义了哪些选项字母需要参数值。首先，在optstring中列出你要在脚本中用到的每个命令行选项字母。然后，在每个需要参数值的选项字母后加一个冒号。getopt命令会基于你定义的optstring解析提供的参数。

```shell
# 冒号(:)被放在了字母b后面，因为b选项需要一个参数值。
$ getopt ab:cd -a -b test1 -cd test2 test3 
-a -b test1 -c -d -- test2 test3
```

如果指定了一个不在optstring中的选项，默认情况下，getopt命令会产生一条错误消息。如果想忽略这条错误消息，可以在命令后加-q选项。

```shell
$ getopt -q ab:cd -a -b test1 -cde test2 test3 
-a -b 'test1' -c -d -- 'test2' 'test3'
```

* 在脚本中使用getopt

用getopt命令生成的格式化后的版本来替换已有的命令行选项和参数。用set命令能够做到。set命令的选项之一是双破折线(--)，它会将命令行参数替换成set命令的命令行值。然后，该方法会将原始脚本的命令行参数传给getopt命令，之后再将getopt命令的输出传给set命令，用getopt格式化后的命令行参数来替换原始的命令行参数。

```shell
set -- $(getopt -q ab:cd "$@")
```

现在原始的命令行参数变量的值会被getopt命令的输出替换，而getopt已经为我们格式化好了命令行参数。

```shell
#!/bin/bash
# Extract command line options & values with getopt #
set -- $(getopt -q ab:cd "$@")
#
echo
while [ -n "$1" ]
do
    case "$1" in
    -a) echo "Found the -a option" ;;
    -b) param="$2"
        echo "Found the -b option, with parameter value $param"
        shift ;;
    -c) echo "Found the -c option" ;;
    --) shift
        break ;;
    *) echo "$1 is not an option";;
    easc
    shift
done
#
count=1
for param in "$@"
do
    echo "Parameter #$count: $param"
    count=$[ $count + 1 ]
done
```

现在可以运行带有复杂选项的脚本了。

```shell
$ ./test.sh -ac
Found the -a option
Found the -c option
```

#### 使用更高级的getopts

与getopt不同，前者将命令行上选项和参数处理后只生成一个输出，而getopts命令能够和已有的shell参数变量配合默契。每次调用它时，它一次只处理命令行上检测到的一个参数。处理完所有的参数后，它会退出并返回一个大于0的退出状态码。这让它非常适合用解析命令行所有参数的循环中。

getopts命令的格式如下: 

```shell
getopts optstring variable
```

optstring值类似于getopt命令中的那个。有效的选项字母都会列在optstring中，如果选项字母要求有个参数值，就加一个冒号。要去掉错误消息的话，可以在optstring之前加一个冒号。getopts命令将当前参数保存在命令行中定义的variable中。

getopts命令会用到两个环境变量。如果选项需要跟一个参数值，OPTARG环境变量就会保存这个值。OPTIND环境变量保存了参数列表中getopts正在处理的参数位置。这样你就能在处理完选项之后继续处理其他命令行参数了。

```shell
#!/bin/bash
# simple demonstration of the getopts command #
echo
while getopts :ab:c opt
do
   case "$opt" in
      a) echo "Found the -a option" ;;
      b) echo "Found the -b option, with value $OPTARG";;
      c) echo "Found the -c option" ;;
      *) echo "Unknown option: $opt";;
   esac 
done
$
$ ./test.sh -ab test1 -c
Found the -a option
Found the -b option, with value test1
Found the -c option
```

getopts命令解析命令行选项时会移除开头的单破折线，所以在case定义中不用单破折线。

getopts命令有几个好用的功能：

* 可以在参数值中包含空格。

```shell
$ ./test.sh -b "test1 test2" -a
```

* 将选项字母和参数值放在一起使用，而不用加空格。

```shell
$ ./test19.sh -abtest1
```

getopts还能够将命令行上找到的所有未定义的选项统一输出成问号。

```shell
$ ./test19.sh -acde
Found the -a option
Found the -c option
Unknown option: ?
Unknown option: ?
```

在getopts处理每个选项时，它会将OPTIND环境变量值增一。在getopts完成处理时，你可以使用shift命令和OPTIND值来移动参数。

```shell
#!/bin/bash
# Processing options & parameters with getopts #
echo
while getopts :ab:cd opt
do
    case "$opt" in
    a) echo "Found the -a option"  ;;
    b) echo "Found the -b option, with value $OPTARG" ;;
    c) echo "Found the -c option"  ;;
    d) echo "Found the -d option"  ;;
    *) echo "Unknown option: $opt" ;;
    esac
done
#
shift $[ $OPTIND - 1 ]
#
echo
count=1
for param in "$@"
do
    echo "Parameter $count: $param"
    count=$[ $count + 1 ]
done
#
$
$ ./test.sh -a -b test1 -d test2 test3 test4
Found the -a option
Found the -b option, with value test1
Found the -d option
Parameter 1: test2
Parameter 2: test3
Parameter 3: test4
```

现在你就拥有了一个能在所有shell脚本中使用的全功能命令行选项和参数处理工具。

### 将选项标准化

Linux中用到的一些命令行选项的常用含义。

```shell
-a       显示所有对象
-c       生成一个计数
-d       指定一个目录
-e       扩展一个对象
-f       指定读入数据的文件
-h       显示命令的帮助信息
-i       忽略文本大小写
-l       产生输出的长格式版本
-n       使用非交互模式(批处理)
-o       将所有输出重定向到的指定的输出文件
-q       以安静模式运行
-r       递归地处理目录和文件
-s       以安静模式运行
-v       生成详细输出
-x       排除某个对象
-y       对所有问题回答yes
```

### 获得用户输入

#### 基本的读取

read命令从标准输入(键盘)或另一个文件描述符中接受输入。在收到输入后，read命令会将数据放进一个变量。

```shell
#!/bin/bash
# testing the read command
#
# 生成提示的echo命令使用了-n选项。该选项不会在字符串末尾输出换行符，允许脚本用户紧跟其后输入数据，而不是下一行。这让脚本看起来更像表单。
echo -n "Enter your name: "  
read name
echo "Hello $name, welcome to my program. " #
$
$ ./test.sh
Enter your name: Rich Blum
Hello Rich Blum, welcome to my program.
```

read命令包含了-p选项，允许你直接在read命令行指定提示符。

```shell
#!/bin/bash
# testing the read -p option
#
read -p "Please enter your age: " age 
days=$[ $age * 365 ]
echo "That makes you over $days days old! " 
#
$ ./test.sh
Please enter your age: 10
That makes you over 3650 days old!
```

read命令会将提示符后输入的所有数据分配给单个变量，要么你就指定多个变量。输入的每个数据值都会分配给变量列表中的下一个变量。如果变量数量不够，剩下的数据就全部分配给最后一个变量。

```shell
read -p "Enter your name: " first last
```

也可以在read命令行中不指定变量。如果是这样，read命令会将它收到的任何数据都放进特殊环境变量REPLY中。REPLY环境变量会保存输入的所有数据，可以在shell脚本中像其他变量一样使用。

```shell
#!/bin/bash
# Testing the REPLY Environment variable #
read -p "Enter your name: "
echo
echo Hello $REPLY, welcome to my program. #
$
$ ./test.sh
Enter your name: Christine
Hello Christine, welcome to my program.
```

#### 超时

使用read命令时要当心。脚本很可能会一直苦等着脚本用户的输入。如果不管是否有数据输入，脚本都必须继续执行，你可以用-t选项来指定一个计时器。-t选项指定了read命令等待输入的秒数。当计时器过期后，read命令会返回一个非零退出状态码。

```shell
#!/bin/bash
# timing the data entry
#
if read -t 5 -p "Please enter your name: " name 
then
   echo "Hello $name, welcome to my script"
else 
   echo
   echo "Sorry, too slow! "
fi
$ ./test.sh
Please enter your name: Rich
Hello Rich, welcome to my script
```

也可以不对输入过程计时，而是让read命令来统计输入的字符数。当输入的字符达到预设的字符数时，就自动退出，将输入的数据赋给变量。将-n选项和值1一起使用，告诉read命令在接受单个字符后退出。只要按下单个字符回答后，read命令就会接受输入并将它传给变量，无需按回车键。

```shell
#!/bin/bash
# getting just one character of input
#
read -n1 -p "Do you want to continue [Y/N]? " answer
case $answer in
Y | y) echo
       echo "fine, continue on...";;
N | n) echo
       echo OK, goodbye
       exit;;
esac
echo "This is the end of the script"
$ ./test.sh
Do you want to continue [Y/N]? Y 
fine, continue on...
This is the end of the script
$
$ ./test.sh
Do you want to continue [Y/N]? n
OK, goodbye
$
```

#### 隐藏方式读取

-s选项可以避免在read命令中输入的数据出现在显示器上(实际上，数据会被显示，只是read命令会将文本颜色设成跟背景色一样)。输入提示符输入的数据不会出现在屏幕上，但会赋给变量，以便在脚本中使用。

```shell
#!/bin/bash
# hiding input data from the monitor
#
read -s -p "Enter your password: " pass
echo
echo "Is your password really $pass? " $
$ ./test.sh
Enter your password:
Is your password really T3st1ng?
```

#### 从文件中读取

可以用read命令来读取Linux系统上文件里保存的数据。每次调用read命令，它都会从文件中读取一行文本。当文件中再没有内容时，read命令会退出并返回非零退出状态码。其中最难的部分是将文件中的数据传给read命令。最常见的方法是对文件使用cat命令，将结果通过管道直接传给含有read命令的while命令。

```shell
#!/bin/bash
# reading data from a file #
count=1
cat test | while read line 
do
   echo "Line $count: $line"
   count=$[ $count + 1]
done
echo "Finished processing the file"
$
$ cat test
The quick brown dog jumps over the lazy fox. 
This is a test, this is only a test.
O Romeo, Romeo! Wherefore art thou Romeo?
$
$ ./test.sh
Line 1: The quick brown dog jumps over the lazy fox. 
Line 2: This is a test, this is only a test.
Line 3: O Romeo, Romeo! Wherefore art thou Romeo?
Finished processing the file
```

# 四、呈现数据

### 理解输入和输出

#### 标准文件描述符

Linux用文件描述符(file descriptor)来标识每个文件对象。文件描述符是一个非负整数，可以唯一标识会话中打开的文件。每个进程一次最多可以有九个文件描述符。出于特殊目的，bash shell保留了前三个文件描述符(0、1和2)。

* 0       STDIN         标准输入       键盘          输入重定向符号(<)

* 1       STDOUT        标准输出       显示器     输出重定向符号(>)     追加符号(>>)

* 2       STDERR        标准错误       显示器

#### 重定向错误

* 只重定向错误

将文件描述符2放在重定向符号前。该值必须紧紧地放在重定向符号前，否则不会工作。

```shell
$ ls -al badfile 2> test
```

* 重定向错误和数据

如果想重定向错误和正常输出，必须用两个重定向符号。需要在符号前面放上待重定向数据所对应的文件描述符，然后指向用于保存数据的输出文件。

```shell
$ ls -al test test2 test3 badtest 2> test6 1> test7
```

将STDERR和STDOUT的输出重定向到同一个输出文件，特殊的重定向符号&>。相较于标准输出，bash shell自动赋予了错误消息更高的优先级。

```shell
$ ls -al test test2 test3 badtest &> test7
$ cat test7
ls: cannot access test: No such file or directory
ls: cannot access badtest: No such file or directory
-rw-rw-r-- 1 rich rich 158 2014-10-16 11:32 test2
-rw-rw-r-- 1 rich rich   0 2014-10-16 11:33 test3
```

### 在脚本中重定向输出

#### 临时重定向

在重定向到文件描述符时，必须在文件描述符数字之前加一个&:

```shell
#!/bin/bash
# testing STDERR messages
echo "This is an error" >&2
echo "This is normal output"
```

像平常一样运行这个脚本，你可能看不出什么区别。默认情况下，Linux会将STDERR导向STDOUT。

```shell
$ ./test
This is an error
This is normal output
```

在运行脚本时重定向了STDERR，脚本中所有导向STDERR的文本都会被重定向。

```shell
$ ./test 2> test1
This is normal output
$ cat test1
This is an error
```

#### 永久重定向

用exec命令告诉shell在脚本执行期间重定向某个特定文件描述符。

```shell
#!/bin/bash
# redirecting output to different locations
exec 2>testerror
echo "This is the start of the script"
echo "now redirecting all output to another location"
exec 1>testout
echo "This output should go to the testout file"
echo "but this should go to the testerror file" >&2  # 尽管STDOUT被重定向了，但你仍然可以将echo语句的输出发给STDERR
```

### 在脚本中重定向输入

将STDIN重定向到文件后，当read命令试图从STDIN读入数据时，它会到文件去取数据，而不是键盘。

```shell
#!/bin/bash
# redirecting file input
exec 0< testfile
count=1
while read line
do
   echo "Line #$count: $line"
   count=$[ $count + 1 ]
done
$ ./test
Line #1: This is the first line.
Line #2: This is the second line.
Line #3: This is the third line.
```

### 创建自己的重定向

在shell中最多可以有9个打开的文件描述符。其他6个从3~8的文件描述符均可用作输入或输出重定向。你可以将这些文件描述符中的任意一个分配给文件，然后在脚本中使用它们。

#### 创建输出文件描述符

用exec命令来给输出分配文件描述符。和标准的文件描述符一样，一旦将另一个文件描述符分配给一个文件，这个重定向就会一直有效，直到你重新分配。

```shell
#!/bin/bash
# using an alternative file descriptor
exec 3>test_out
echo "This should display on the monitor"
echo "and this should be stored in the file" >&3
echo "Then this should be back on the monitor"
$ ./test
This should display on the monitor
Then this should be back on the monitor
$ cat test_out
and this should be stored in the file
```

也可以不用创建新文件，而是使用exec命令来将输出追加到现有文件中。

```shell
exec 3>>test13out
```

#### 重定向文件描述符

恢复已重定向的文件描述符。可以分配另外一个文件描述符给标准文件描述符，反之亦然。这意味着可以将STDOUT的原来位置重定向到另一个文件描述符，然后再利用该文件描述符重定向回STDOUT。

```shell
#!/bin/bash
# storing STDOUT, then coming back to it
exec 3>&1  # 任何发送给文件描述符3的输出都将出现在显示器上
exec 1>test_out
echo "This should store in the output file"
echo "along with this line."
exec 1>&3  # 将输出数据发送给文件描述符3，它仍然会出现在显示器上，尽管STDOUT已经被重定向了。
echo "Now things should be back to normal"
$ ./test
Now things should be back to normal
$ cat test_out
This should store in the output file
along with this line.
```

#### 创建输入文件描述符

可以用和重定向输出文件描述符同样的办法重定向输入文件描述符。在重定向到文件之前，先将STDIN文件描述符保存到另外一个文件描述符，然后在读取完文件之后再将STDIN恢复到它原来的位置。

```shell
#!/bin/bash
# redirecting input file descriptors
exec 6<&0 
exec 0< testfile
count=1 
while read line
do
   echo "Line #$count: $line"
   count=$[ $count + 1 ] 
done
exec 0<&6
read -p "Are you done now? " answer
case $answer in 
Y|y) echo "Goodbye";;
N|n) echo "Sorry, this is the end.";;
esac
$ ./test
Line #1: This is the first line.
Line #2: This is the second line.
Line #3: This is the third line.
Are you done now? y
Goodbye
```

#### 创建读写文件描述符

可以用同一个文件描述符对同一个文件进行读写。shell会维护一个内部指针，指明在文件中的当前位置。任何读或写都会从文件指针上次的位置开始。

```shell
exec 3<> testfile
```

#### 关闭文件描述符

关闭文件描述符，将它重定向到特殊符号&-。一旦关闭了文件描述符，就不能在脚本中向它写入任何数据，否则shell会生成错误消息。如果随后你在脚本中打开了同一个输出文件，shell会用一个新文件来替换已有文件。这意味着如果你输出数据，它就会覆盖已有文件。

```shell
#!/bin/bash
# testing closing file descriptors
exec 3> test_file
echo "This is a test line of data" >&3
exec 3>&-   # 关闭文件描述符3
cat test17file
exec 3> test_file  # 重新打开文件描述符3，此时test_file是新的文件，覆盖掉原来的test_file
echo "This'll be bad" >&3
$ ./test17
This is a test line of data
$ cat test17file
This'll be bad
```

### 列出打开的文件描述符

lsof命令会列出整个Linux系统打开的所有文件描述符。在很多Linux系统中，lsof命令位于/usr/sbin目录。要想以普通用户账户来运行它，必须通过全路径名来引用:

```shell
$ /usr/sbin/lsof
```

显示当前Linux系统上打开的每个文件的有关信息。包括后台运行的所有进程以及登录到系统的任何用户。

有大量的命令行选项和参数可以用来帮助过滤lsof的输出。最常用的有-p和-d，前者允许指定进程ID(PID)，后者允许指定要显示的文件描述符编号。

要想知道进程的当前PID，可以用特殊环境变量$$(shell会将它设为当前PID)。-a选项用来对其他两个选项的结果执行布尔AND运算，这会产生如下输出。

```shell
$ /usr/sbin/lsof -a -p $$ -d 0,1,2
COMMAND  PID USER   FD   TYPE DEVICE SIZE NODE NAME
bash    3344 rich    0u   CHR  136,0       2 /dev/pts/0
bash    3344 rich    1u   CHR  136,0       2 /dev/pts/0
bash    3344 rich    2u   CHR  136,0       2 /dev/pts/0
```

FD：文件描述符号以及访问类型(r代表读，w代表写，u代表读写)

### 阻止命令输出

将STDERR重定向到一个叫作null文件的特殊文件。在Linux系统上null文件的标准位置是/dev/null。你重定向到该位置的任何数据都会被丢掉，不会显示。

```shell
$ ls -al > /dev/null
```

也可以在输入重定向中将/dev/null作为输入文件。由于/dev/null文件不含有任何内容，程序员通常用它来快速清除现有文件中的数据，而不用先删除文件再重新创建。

```shell
$ cat testfile
This is the first line.
This is the second line.
This is the third line.
$ cat /dev/null > testfile
$ cat testfile
```

### 创建临时文件

Linux使用/tmp目录来存放不需要永久保留的文件。大多数Linux发行版配置了系统在启动时自动删除/tmp目录的所有文件。系统上的任何用户账户都有权限在读写/tmp目录中的文件。

mktemp命令可以在/tmp目录中创建一个唯一的临时文件。shell会创建这个文件，但不用默认的umask值。它会将文件的读和写权限分配给文件的属主，并将你设成文件的属主。一旦创建了文件，你就在脚本中有了完整的读写权限，但其他人没法访问它(当然，root用户除外)。

#### 创建本地临时文件

默认情况下，mktemp会在本地目录中创建一个文件。要用mktemp命令在本地目录中创建一个临时文件，你只要指定一个文件名模板就行了。模板可以包含任意文本文件名，在文件名末尾加上6个X就行了。

```shell
$ mktemp testing.XXXXXX
testing.1DRLuV     # mktemp命令的输出正是它所创建的文件的名字。
```

在脚本中使用mktemp命令时，可能要将文件名保存到变量中，这样就能在后面的脚本中引用了。

```shell
#!/bin/bash 
# creating and using a temp file
tempfile=$(mktemp test.XXXXXX)
exec 3>$tempfile
echo "This script writes to temp file $tempfile"

echo "This is the first line" >&3

echo "Done creating temp file. The contents are:"
cat $tempfile
rm -f $tempfile 2> /dev/null 
$ ./test
This script writes to temp file test.vCHoya
Done creating temp file. The contents are:
This is the first line
This is the second line.
This is the last line.
$ ls -al test*
-rwxr--r-- 1 rich rich 356 Oct 29 22:03 test19*
```

#### 在/tmp目录创建临时文件

-t选项会强制mktemp命令来在系统的临时目录来创建该文件。在用这个特性时，mktemp命令会返回用来创建临时文件的全路径，而不是只有文件名。

```shell
$ mktemp -t test.XXXXXX
/tmp/test.xG3374
```

#### 创建临时目录

-d选项告诉mktemp命令来创建一个临时目录而不是临时文件。这样你就能用该目录进行任何需要的操作了，比如创建其他的临时文件。

```shell
#!/bin/bash
# using a temporary directory
tempdir=$(mktemp -d dir.XXXXXX)
cd $tempdir
tempfile1=$(mktemp temp.XXXXXX)
tempfile2=$(mktemp temp.XXXXXX)
exec 7> $tempfile1
exec 8> $tempfile2
echo "Sending data to directory $tempdir"
echo "This is a test line of data for $tempfile1" >&7
echo "This is a test line of data for $tempfile2" >&8
```

### 记录消息

将输出同时发送到显示器和日志文件，只要用特殊的tee命令就行。tee命令相当于管道的一个T型接头。它将从STDIN过来的数据同时发往两处。一处是STDOUT，另一处是tee命令行所指定的文件名: tee filename

由于tee会重定向来自STDIN的数据，你可以用它配合管道命令来重定向命令输出。

```shell
$ date | tee testfile
Sun Oct 19 18:56:21 EDT 2014
$ cat testfile
Sun Oct 19 18:56:21 EDT 2014
```

默认情况下，tee命令会在每次使用时覆盖输出文件内容。如果你想将数据追加到文件中，必须用-a选项。

```shell
#!/bin/bash
# using the tee command for logging
tempfile=test_file
echo "This is the start of the test" | tee $tempfile
echo "This is the second line of the test" | tee -a $tempfile
echo "This is the end of the test" | tee -a $tempfile
$ ./test
This is the start of the test
This is the second line of the test
This is the end of the test
$ cat test22file
This is the start of the test
This is the second line of the test
This is the end of the test
```

### 实例

读取.csv格式的数据文件，输出SQL INSERT语句来将数据插入数据。

```shell
#!/bin/bash
# read file and create INSERT statements for MySQL
outfile='members.sql'
IFS=','  # 使用IFS字符解析读入的文本，我们在这里将IFS指定为逗号
while read lname fname address city state zip  # 使用read语句从数据文件中读取文本
do
    cat >> $outfile << EOF  # 输出重定向将cat命令的输出追加到由$outfile变量指定的文件中。EOF符号标记了追加到文件中的数据的起止。
INSERT INTO members (lname,fname,address,city,state,zip) VALUES ('$lname', '$fname', '$address', '$city', '$state', '$zip');
EOF
done < ${1}  # $1代表第一个命令行参数。它指明了待读取数据的文件

$ ./test23 < members.csv
```

# 五、控制脚本

### 处理信号

### 以后台模式运行脚本

### 在非控制台下运行脚本

### 作业控制

### 调整谦让度

### 定时运行作业

































































































































































































































































































