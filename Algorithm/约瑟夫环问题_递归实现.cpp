////约瑟夫环问题，改个名字可以直接运行的程序
////注意在qtcreator的中文编码问题
////递归实现
//#include <iostream>
//using namespace std;
////该函数返回第n次扔海里的人的编号，编号从0开始计算
//int ysfdg(int sum,int value,int n)
//{
//    if(n==1)
//        return (sum+value-1)%sum;
//    else
//        return(ysfdg(sum-1,value,n-1)+value)%sum;
//}
//int main()
//{
//    //sum是总人数
//    int n=1,sum=41;
//    while(n!=sum)
//    {
//        int a=ysfdg(sum,3,n);
//        cout<<"第"<<n<<"次杀死第"<<a+1<<"个人"<<endl;
//        n++;
//    }
//    cout<<"最后剩下的人是第"<<ysfdg(sum,3,n)+1<<"个人"<<endl;
//    return 0;
//}
