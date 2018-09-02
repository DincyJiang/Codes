/*
工厂方法模式去掉了简单工厂模式中工厂方法的静态属性，使得它可以被子类继承。
这样在简单工厂模式里集中在工厂方法上的压力可以由工厂方法模式里不同的工厂子类来分担。

简单工厂模式+“开闭原则”=工厂方法模式

优点：
符合开闭原则
缺点：
类的个数成倍增加，导致类越来越多，增加维护成本

适用场景：
客户端不知道他所需要的对象的类
抽象工厂类通过其子类来指定创建哪个对象
*/

#include<iostream>
#include<string>
using namespace std;

class AbstractFruit{
public:
    virtual void ShowName()=0;
};
class Apple : public AbstractFruit{
public:
    virtual void ShowName(){
        cout<<"我是Apple"<<endl;
    }
};
class Banana : public AbstractFruit{
public:
    virtual void ShowName(){
        cout<<"我是Banana"<<endl;
    }
};
class Pear : public AbstractFruit{
public:
    virtual void ShowName(){
        cout<<"我是Pear"<<endl;
    }
};
//抽象工厂
class AbstractFactroy{
public:
    virtual AbstractFruit* CreateFruit()=0;
};
//苹果工厂
class AppleFactroy : public AbstractFactroy{
public:
    virtual AbstractFruit* CreateFruit(){
        return new Apple;
    }
};
class BananaFactroy : public AbstractFactroy{
public:
    virtual AbstractFruit* CreateFruit(){
        return new Banana;
    }
};
class PearFactroy : public AbstractFactroy{
public:
    virtual AbstractFruit* CreateFruit(){
        return new Pear;
    }
};

void test(){
    AbstractFactroy* factroy = nullptr;
    AbstractFruit* fruit = nullptr;
    factroy = new AppleFactroy;
    fruit = factroy->CreateFruit();
    fruit->ShowName();
    delete fruit;
    delete factroy;

    factroy = new BananaFactroy;
    fruit = factroy->CreateFruit();
    fruit->ShowName();
    delete fruit;
    delete factroy;

    factroy = new PearFactroy;
    fruit = factroy->CreateFruit();
    fruit->ShowName();
    delete fruit;
    delete factroy;
}

int main(){

    test();
    return 0;
}