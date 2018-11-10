#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <set>
#include <map>

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

// class Solution{
// public:
//     int numIslands(vector<vector<char>>& grid) {
//         int m = grid.size(); // 行数
//         int n = grid[0].size(); // 列数
//         if (m = 0 || n == 0) return 0;
//         int res = 0;
//         vector<vector<bool>> visited(m, vector<bool>(n, false));
//         for (int i = 0; i < m; ++i)
//             for (int j = 0; j < n; ++j)
//                 if (grid[i][j] == '1' && visited[i][j] == false) {
//                     DFS(grid, visited, i, j);
//                     ++res;
//                 }
//         return res; 
//     }
//     void DFS(vector<vector<char>>& grid, vector<vector<bool>>& visited, int x, int y) {
//         if (x < 0 || x >= grid.size() || 
//             y < 0 || y >= grid[0].size() ||
//             grid[x][y] == '0' ||
//             visited[x][y] == true)
//             return;
//         visited[x][y] = true;
//         DFS(grid, visited, x + 1, y);
//         DFS(grid, visited, x - 1, y);
//         DFS(grid, visited, x, y + 1);
//         DFS(grid, visited, x, y - 1);
//     }
// };

// class Solution {
// public: // 优先级队列，
//     int kthSmallest(vector<vector<int>>& matrix, int k) {
//         priority_queue<int> pq; // 默认最小堆
//         int m = matrix.size(), n = matrix[0].size();
//         for (auto &i : matrix)
//             for (auto &j : i) {
//                 pq.emplace(j);
//                 if (pq.size() > k)
//                     pq.pop();
//             }
//         return pq.top();
//     }
// };

// class Solution {
// public:
// int binary_search(vector<int> nums,int target){
//         int index=-1;
//         int begin=0;
//         int end=nums.size()-1;
//         while(index==-1){
//             int mid=(begin+end)/2;
//             if(target==nums[mid]){
//                 index=mid;
//             }
//             else if(target<nums[mid]){
//                 if(mid==0 || target>nums[mid]-1){
//                     index=mid;
//                 }
//                 end=mid-1;
//             }
//             else if(target>nums[mid]){
//                 if(mid==nums.size()-1 || target<nums[mid+1]){
//                     index=mid+1;
//                 }
//                 begin=mid+1;
//             }
//         }
//         return index;
//     }
//     int lengthOfLIS(vector<int>& nums) {
//         if(nums.empty()) return 0;
//         vector<int> stack;
//         stack.push_back(nums[0]);
//         for(int i=1;i<nums.size();++i){
//             if(nums[i]>stack.back()){
//                 stack.push_back(nums[i]);
//             }
//             else{
//                     int pos=binary_search(stack,nums[i]);
//                     stack[pos]=nums[i];
//                 }
//         }
//         return stack.size();
//     }
// };

// 时间复杂度O(n^2)
// 维护一个一维dp数组，其中dp[i]表示以nums[i]为结尾的最长递增子串的长度，
// 对于每一个nums[i]，我们从第一个数再搜索到i，如果发现某个数小于nums[i]，
// 我们更新dp[i]，更新方法为dp[i] = max(dp[i], dp[j] + 1)，
// 即比较当前dp[i]的值和那个小于num[i]的数的dp值加1的大小，
// 我们就这样不断的更新dp数组，到最后dp数组中最大的值就是我们要返回的LIS的长度
// class Solution {
// public:
//     int lengthOfLIS(vector<int>& nums) {
//         int n = nums.size();
//         vector<int> dp(n, 1);
//         int res = 0;
//         for (int i = 0; i < n; ++i) {
//             for (int j = 0; j < i; ++j)
//                 if (nums[i] > nums[j])
//                     dp[i] = max(dp[i], dp[j]+1);
//             res = max(res, dp[i]);
//         }
//         return res;
//     }
// };
// 二分查找法，思路是先建立一个空的dp数组，然后开始遍历原数组，
// 对于每一个遍历到的数字，我们用二分查找法在dp数组找第一个不小于它的数字，
// 如果这个数字不存在，那么直接在dp数组后面加上遍历到的数字，
// 如果存在，则将这个数字更新为当前遍历到的数字，最后返回dp数字的长度即可，
// 注意的是，跟上面的方法一样，特别注意的是dp数组的值可能不是一个真实的LIS。
// class Solution {
// public:
//     int lengthOfLIS(vector<int>& nums) {
//         vector<int> dp;
//         int n = nums.size();
//         for (int i = 0; i < n; ++i) {
//             int left = 0, right = dp.size();
//             // 二分查找法在dp数组找第一个不小于它的数字
//             while (left < right) {
//                 int mid = left + (right - left) / 2;
//                 if (dp[mid] < nums[i])
//                     left = mid + 1;
//                 else
//                     right = mid;
//             }
//             if (right >= dp.size()) // 如果这个数字不存在，那么直接在dp数组后面加上遍历到的数字
//                 dp.push_back(nums[i]);
//             else // 如果存在，则将这个数字更新为当前遍历到的数字
//                 dp[right] = nums[i];
//         }
//         return dp.size();
//     }
// };

// class ListNode {
// public:
//     ListNode(int n) : val(n), next(nullptr) {}
//     int val;
//     ListNode *next;
// };

// ListNode* deleteDuplicate(ListNode* head) {
//     ListNode *dummy = new ListNode(-1);
//     dummy->next = head;
//     ListNode *pre = dummy, *cur = head;
//     while (cur && cur->next) {
//         ListNode *next = cur->next;
//         if (cur->val == next->val) {
//             while (next && next->val == cur->val)
//                 next = next->next;
//             pre->next = next;
//             cur = next;
//         } else {
//             pre = cur;
//             cur = next;
//         }
//     }
//     return dummy->next;
// }

// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
// };
// void preOrder(TreeNode* root, vector<int>& res) {
//     if (root == nullptr)
//         return;
//     res.push_back(root->val);
//     preOrder(root->left, res);
//     preOrder(root->right, res);
// }
// vector<int> preOrder(TreeNode* root) {
//     vector<int> res;
//     preOrder(root, res);
//     return res;
// }

// vector<int> preOrder_diedai(TreeNode* root) {
//     vector<int> res;
//     if (root == nullptr)
//         return res;
//     stack<TreeNode*> s;
//     s.push(root);
//     while (!s.empty()) {
//         TreeNode *temp = s.top();
//         s.pop();
//         res.push_back(temp->val);
//         if (temp->right)
//             s.push(temp->right);
//         if (temp->left)
//             s.push(temp->left);
//     }
//     return res;
// }

// vector<vector<int>> levelOrder(TreeNode* root) {
//     vector<vector<int>> res;
//     if (root == nullptr) return res;
//     queue<TreeNode*> q;
//     q.push(root);
//     vector<int> vec;
//     while (!q.empty()) {
//         int n = q.size();
//         for (int i = 0; i < n; ++i) {
//             TreeNode *temp = q.front();
//             q.pop();
//             vec.push_back(temp->val);
//             if (temp->left)
//                 q.push(temp->left);
//             if (temp->right)
//                 q.push(temp->right);
//         }
//         res.push_back(vec);
//         vec.clear();
//     }
//     return res;
// }

// TreeNode* invertTree(TreeNode* root) {
//     if (root == nullptr)
//         return nullptr;
//     swap(root->left, root->right);
//     invertTree(root->left);
//     invertTree(root->right);
//     return root;
// }

// TreeNode* lowerCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
//     if (root == nullptr)
//         return nullptr;
//     if (p->val < root->val && q->val < root->val)
//         return lowerCommonAncestor(root->left, p, q);
//     if (p->val > root->val && q->val > root->val)
//         return lowerCommonAncestor(root->right, p, q);
//     return root;
// }

// TreeNode* lowerCommonAncestor_diedai(TreeNode* root, TreeNode* p, TreeNode* q) {
//     while (true) {
//         if (p->val < root->val && q->val < root->val)
//             root = root->left;
//         else if (p->val > root->val && q->val > root->val)
//             root = root->right;
//         else
//             break;
//     }
//     return root;
// }

// class A {
// public:
//     virtual void fun() {
//         cout << "A" << endl;
//     }
//     virtual ~A() {

//     }
// };

// class B : public A {
// public:
//     virtual void fun() {
//         cout << "B" << endl;
//     }
// };

// class C : public B {

// };

// int main() {
//     C c;
//     c.fun();

//     return 0;
// }

// bool isBigEndian() {
//     int a = 0x1234;
//     char b = static_cast<char>(a);
//     if (b == 0x12)
//         return true;
//     else if (b == 0x34)
//         return false;
//     else
//         return false;
// }

// int main() {
//     cout << (isBigEndian() ? "Big" : "Small") << endl;
//     return 0;
// }

// int main() {
//     char a[] = "C++";
//     cout << a;
//     a++; // error: cannot increment value of type 'char [4]'
//     cout << a << endl;
//     return 0;
// }

// class Singleton {
// private:
// 	Singleton() {}  //构造函数是私有的
// 	static Singleton *instance;
// public:
// 	static Singleton * GetInstance() {
//         if(instance == nullptr) { //判断是否第一次调用
//             lock();
//             if(instance == nullptr) {
//                 instance = new Singleton();
//             }
//         }
// 		return instance;
// 	}
// };
// Singleton * Singleton::instance = nullptr;
 
// #include <iostream>
// #include <string>
// #include <vector>

// using namespace std;

// int help(const string& s) {
//   int left = 0;
//   int right = s.size() - 1;
//   while (left < right) {
//     if (s[left] != s[right]) {
//       if (s[left+1] == s[right])
//         return left;
//       else if (s[left] == s[right-1])
//         return right;
//     } else {
//       ++left;
//       --right;
//     }
//   }
//   return left;
// }

// int main () {
//   int T;
//   cin >> T;
//   vector<int> res;
//   while (T--) {
//     string s;
//     cin >> s;
//     res.push_back(help(s));
//   }
  
//   for (auto& i : res)
//     cout << i << endl;
  
//   return 0;
// }

// struct test1 {
//     int a : 1;
//     bool b : 1;
//     bool c : 1;
//     bool d : 1;
//     bool e : 1;
//     bool f : 1;
// };
// struct test2 {
//     int a;
//     bool b;
//     bool c;
//     bool d;
//     bool e;
// };
// int main() {
//     test1 a;
//     cout << sizeof(a) << endl;

//     test2 b;
//     cout << sizeof(b) << endl;

//     bool c = true;
    
//     return 0;
// }

// int main() {

//     auto pi = new int{};
//     auto pc = new vector<int>{};

//     return 0;
// }

// void f(double y) {}

// void g(double y) {
//     [&]{f(y);}
//     auto z1 = [=](int x) {return x+y;}
//     // auto z2 = [=,y]{if (y) return 1; else return 2;}
//     auto z3 = [y]() {return 1 : 2;}
//     auto z4 = [=,y]()->int {if(y) return 1; else return 2;}
// }

// auto main() -> int
// {
//     cout << 1 << endl;
//     return 0;
// }

// template<typename T, typename U>
// auto product(const vector<T>& x, const vector<U>& y) -> decltype(x*y)
// {

// }

// #include <cstdio>

// int main() {
//     printf("My name is %s %s\n", 2);
//     return 0;
// }

