/*
描述

定义字符串的以下几种操作：

reverse(A)获得A字符串的逆序字符串，例如reverse("abc") = "cba"
shuffle(A)获得A随机重排的字符串，例如shuffle("dog") ∈ {"dog", "dgo", "odg", "ogd", "gdo", "god"}
merge(A1, A2)，合并A1和A2两个字符串，合并过程中只保证A1和A2本身字母的顺序，例如merge("qwe", "asd")的可能结果有很多， “qweasd”和“qwased”都是可能的取值。现在给定一个字符串S，S ∈merge(reverse(A), shuffle(A))。求以字母表顺序排序的A的最小值。

输入描述

输入一个字符串S。


输出描述

输出一个字符串，为A的最小取值。


样例输入 1 

abcdefgabcdefg
样例输出 1

agfedcb
提示

reverse("agfedcb") = "bcdefga"shuffle("agfedcb") = "abcdefg"merge("bcdefga", "abcdefg") = "abcdefgabcdefg"
*/

