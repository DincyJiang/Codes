/*
描述

小蛤写了一个http服务器,他将网站放置于/etc/html目录下,由于小蛤疏忽,代码编写有bug,导致用户可以通过类似 http://www.c.com/../passwd 的链接跨过服务器限制,访问到位于/etc下的重要系统密码文件passwd,小蛤现在想设计一个程序,用来检测用户从浏览器传过来的路径是否正确,避免用户越权访问其他目录(网站应只能访问/etc/html下的文件).你可以帮帮小蛤吗?

输入描述
一个路径(长度小于1000),中间没有空格,小蛤已经帮你去除了网站前缀,只保留如 /topic/../1.php 这样的链接(去除后的结果是一个unix-style的完全路径),以/开头

输出描述

请帮助小蛤化简该链接,如果该待化简的路径多次包含/../,只要其中有一次超过了网站根目录(即/),例如/../topic/index.php中的第一次..,就输出XXX-exploited-XXX,否则输出化简后的结果,末尾不能有多余的/

样例输入 1 

/topic/1/haha.php/
样例输出 1

/topic/1/haha.php
样例输入 2 

/announcement/./update/../index.php
样例输出 2

/announcement/index.php
样例输入 3 

/topic/../../passwd
样例输出 3

XXX-exploited-XXX
提示

/./表示当前目录

/../表示上层目录
*/

#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;


// AC 
string func(const string& path) {
  string res, temp;
  stringstream ss(path);
  vector<string> vec;
  while (getline(ss, temp, '/')) {
    if (temp == "" || temp == ".") continue;
    if (temp == ".." && vec.empty()) return "XXX-exploited-XXX";
    if (temp == ".." && !vec.empty()) vec.pop_back();
    else if (temp != "..") vec.push_back(temp);
  }
  for (string& s : vec) res += "/" + s;
  return res.empty() ? "XXX-exploited-XXX" : res;
}

int main() {
  string path;
  cin >> path;
  cout << func(path) << endl;
  
  return 0;
}