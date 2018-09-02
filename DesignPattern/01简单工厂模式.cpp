/*
简单工厂模式又称静态工厂方法模式。它存在的目的很简单：定义一个用于创建对象的接口。

优点：
客户端和具体实现类解耦
对于某些对象常见过程比较复杂情况，我们不用考虑这些
缺点：
增加新的功能是通过修改源代码实现，不符合开闭原则
这个类的职责过重，这个类发生问题会影响很多使用这个工厂的模块

使用场景：
工厂类负责创建的对象比较少。由于创建的对象比较少，不会造成方法中的业务逻辑太过复杂

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
//水果工厂
class FruitFactroy{
public:
    static AbstractFruit* CreateFruit(string flag){
        if(flag=="apple"){
            return new Apple;
        }
        else if(flag=="banana"){
            return new Banana;
        }
        else if(flag=="pear"){
            return new Pear;
        }
        else{
            return nullptr;
        }

    }
};
void test(){
    FruitFactroy* factroy = new FruitFactroy;
    AbstractFruit* fruit=factroy->CreateFruit("apple");
    fruit->ShowName();
    delete fruit;
    fruit=factroy->CreateFruit("banana");
    fruit->ShowName();
    delete fruit;
    fruit=factroy->CreateFruit("pear");
    fruit->ShowName();
    delete fruit;
    delete factroy;
}

int main(){

    test();
    return 0;
}

