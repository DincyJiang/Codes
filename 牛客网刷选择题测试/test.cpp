#include <iostream>
#include <cstdio>

using namespace std;

// int main() {
//     char str[] = "abcde";
//     cout << str << endl;
//     char *p = "abcde";
//     cout << p << endl;
//     // int array[][4];
//     return 0;
// }

// int main () {
//     char s[] = "123", *p;
//     p = s;
//     printf("%c%c%c", *p++, *p++, *p++); // 未定义行为，取决于编译器。不知道应该先自增，还是先输出。 123
//     return 0;
// }

// int main () {
//     printf("a\bre\'hi\'y\\\bou\n"); // are'hi'y\ou  答案是：re’hi’you 
//     // ’\b’是退格符，输出时将光标往左边回退一个位置，‘\’’为单引号字符，’\\’为\字符，’\n’为回车换行符
// }

// int main() {
//     int a = 011;
//     printf("%d\n", ++a);
//     cout << 0111 << endl;
// }

// int main() {
//     char c = 'a';
//     if ('a' < c <= 'z')
//         printf("LOW");
//     else
//         printf("UP");
// }

// int main()
// {
// char c1,c2;
// int a1,a2;
// c1=getchar();
// scanf("%2d",&a1);
// c2=getchar();
// scanf("%3d",&a2);
// printf ("%d,%d,%c,%c\n",a1,a2,c1,c2);
// return 0;
// }

// int main () {
//     cout << ("microsoft" == "microsoft") << endl;
//     char *str = "microsoft";
//     cout << (str == "microsoft") << endl;
//     return 0;
// }

// int main() {
//     char a[5];
//     char *p = a;
//     p = "abcd";
//     cout << p << endl;
//     return 0;
// }

// int main() {
//     int printf = 2;
//     int i = 2;
//     int sin = 2;
//     cout << printf << i << sin << endl;
//     return 0;
// }

// union dt {
//     int a;
//     char b;
//     double c;
// } data;

// int main () {
//     data.a = 5;
//     printf("%f\n", data.c);
// }

// int main() {
//     unsigned int a = 1;
//     signed int b = -3;
//     int c;
//     (a+b > 0) ? (c=1) : (c=0);
//     printf("%d", c);
//     return 0;
// }

// int main() {
//     int k = 2;
//     int *ptr1 = &k;
//     int *ptr2 = &k;
//     ptr2 = k; // 出错，不能把整型赋给指针变量
//     return 0;
// }

// int main() {
//     double x;
//     x = 218.82631;
//     printf("%-6.2e\n", x);  // 2.19e+02
//     return 0;
// }

// int main() {
//     int a[10] = {};
//     int b[10] = {0};
//     int c[10] = {10, 0, -1.0};
//     return 0;
// }

// int main() {
//     int a = 1, b = 10;
//     do {
//         b -= a;
//         a++;
//     } while (b-- < 0);
//     printf("a=%d,b=%d\n", a, b);
//     return 0;
// }

// sum (int a, int b) { // 默认返回值类型为int

// }

// int main() {
//     int t = 141;
//     int res = 0;
//     while (t) {
//         if (t % 10 == 1) ++res;
//         t /= 10;
//     }
//     cout << res << endl;
//     return 0;
// }

