/*
模板方法模式（Template Method)

定义一个操作中的算法骨架,而将一些步骤延迟到子类中。
Template Method使得子类可以不改变一个算法的结构即可重定义该算法的某些特定步骤。

问题：
在面向对象系统的分析与设计过程中经常会遇到这样一种情况：对于某一个业务逻辑
（算法实现） 在不同的对象中有不同的细节实现， 但是逻辑（算法） 的框架（或通用的应用
算法）是相同的。 Template 提供了这种情况的一个实现框架。

Template 模式是采用继承的方式实现这一点： 将逻辑（算法） 框架放在抽象基类中， 并
定义好细节的接口，子类中实现细节。

Template 模式实际上就是利用面向对象中多态的概念实现算法实现细节和高层接口的
松耦合。
*/

#include<iostream>
using namespace std;

class DrinkTemplate{
public:
    virtual ~DrinkTemplate(){}
    virtual void BoilWater()=0; //煮水
    virtual void Brew()=0; //冲泡
    virtual void PourInCup()=0; //倒入杯中
    virtual void AddSomething()=0; //加料

    //模板方法
    void Make(){
        BoilWater();
        Brew();
        PourInCup();
        AddSomething();
    }
};

//冲泡咖啡
class Coffee : public DrinkTemplate{
public:
    virtual void BoilWater() //煮水
    {
        cout<<"煮山泉水"<<endl;
    }
    virtual void Brew() //冲泡
    {
        cout<<"冲泡咖啡"<<endl;
    }
    virtual void PourInCup() //倒入杯中
    {
        cout<<"咖啡倒入杯中"<<endl;
    }
    virtual void AddSomething() //加料
    {
        cout<<"加糖加奶"<<endl;
    }

};

//冲泡茶叶
class Tea : public DrinkTemplate{
public:
    virtual void BoilWater() //煮水
    {
        cout<<"煮自来水"<<endl;
    }
    virtual void Brew() //冲泡
    {
        cout<<"冲泡铁观音"<<endl;
    }
    virtual void PourInCup() //倒入杯中
    {
        cout<<"茶水倒入杯中"<<endl;
    }
    virtual void AddSomething() //加料
    {
        cout<<"加柠檬"<<endl;
    }
};


void test(){
    DrinkTemplate* tea=new Tea;
    tea->Make();
    cout<<"------------------"<<endl;
    DrinkTemplate* caffee=new Coffee;
    caffee->Make();
    delete tea;
    delete caffee;
}
int main(){
    test();

    return 0;
}
