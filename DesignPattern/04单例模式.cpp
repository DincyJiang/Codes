/*
单例模式：
在它的核心结构中只包含一个被称为单例的特殊类。
一个类只有一个对象实例。
单例模式分为懒汉式和饿汉式

实现单例模式的步骤：
1.构造函数私有化
2.增加静态的私有的当前类的指针变量
3.提供静态的对外接口，可以让用户获得单例对象

单例模式的对象释放问题：可以不释放，因为就只有一个对象，占不了多大的内存

*/
#include<iostream>
using namespace std;

class A{
private:  //构造函数私有化
    A(){
        new A;
    }
public:
    static A* getInstance(){  //提供静态的对外接口，可以让用户获得单例对象
        return a;
    }
private:
    static A* a;  //增加静态的私有的当前类的指针变量
};
A* A::a=nullptr; //静态成员必须在类外初始化

//懒汉式
class SingleLazy{
private:
    SingleLazy(){cout<<"SingleLazy构造函数"<<endl;}
public:
    static SingleLazy* getInstance(){
        if(pSingleLazy==nullptr){
            pSingleLazy=new SingleLazy;
        }
        return pSingleLazy;
    }
private:
    static SingleLazy* pSingleLazy;
};
SingleLazy* SingleLazy::pSingleLazy=nullptr; //静态成员必须在类外初始化

//饿汉式
class SingleHungry{
private:
    SingleHungry(){cout<<"SingleHungry构造函数"<<endl;}
public:
    static SingleHungry* getInstance(){
        return pSingleHungry;
    }
private:
    static SingleHungry* pSingleHungry;
};
SingleHungry* SingleHungry::pSingleHungry=new SingleHungry; //在main函数开始之前就创造出来，所以叫饿汉

void test(){
    SingleLazy* p1=SingleLazy::getInstance();
    SingleLazy* p2=SingleLazy::getInstance();
    if(p1==p2){
        cout<<"两个指针指向同一块内存空间，是单例模式"<<endl;
    }
    else{
        cout<<"不是单例模式！"<<endl;
    }
    SingleHungry* p3=SingleHungry::getInstance();
    SingleHungry* p4=SingleHungry::getInstance();
    if(p1==p2){
        cout<<"两个指针指向同一块内存空间，是单例模式"<<endl;
    }
    else{
        cout<<"不是单例模式！"<<endl;
    }
}
void test1(){
    
}
int main()
{
    cout<<"main开始"<<endl;
    test();


    return 0;
}