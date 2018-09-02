/*
适配器模式（adapter）

在计算机编程中，适配器模式（有时候也称包装样式或者包装）将一个类的接口适配成用户所期待的。
一个适配允许通常因为接口不兼容而不能在一起工作的类工作在一起，
做法是将类自己的接口包裹在一个已存在的类中。

共有两类适配器模式：
对象适配器模式
-- 在这种适配器模式中，适配器容纳一个它包裹的类的实例。在这种情况下，适配器调用被包裹对象的物理实体。
类适配器模式
-- 这种适配器模式下，适配器继承自已实现的类（一般多重继承）。

类模式的 Adapter 采用继承的方式复用 Adaptee的接口，
而在对象模式的 Adapter 中我们则采用组合的方式实现 Adaptee 的复用。

生活中案例：电源适配器

*/


#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//类模式的Adapter
class Target_calss{
public:
    Target_calss(){}
    virtual ~Target_calss(){}
    virtual void Request(){
        cout<<"Target_calss::Request"<<endl;
    }
};
class Adaptee_class{
public:
    Adaptee_class(){}
    ~Adaptee_class(){}
    void SpecificRequest(){
        cout<<"Adaptee_class::SpecificRequest"<<endl;
    }
};
class Adapter_class : public Target_calss, private Adaptee_class{
public:
    Adapter_class(){}
    ~Adapter_class(){}
    virtual void Request(){
        this->SpecificRequest();
    }
};

//对象模式的adapter
class Target_object{
public:
    Target_object(){}
    ~Target_object(){}
    virtual void Request(){
        cout<<"Target_object::Rerquest"<<endl;
    }
};
class Adaptee_object{
public:
    Adaptee_object(){}
    ~Adaptee_object(){}
    void SpecificRequest(){
        cout<<"Adaptee_object::SpecificRequest"<<endl;
    }
};
class Adapter_object : public Target_object{
public:
    Adapter_object(Adaptee_object* adapter){
        this->_adapter=adapter;
    }
    ~Adapter_object(){}
    void Request(){
        _adapter->SpecificRequest();
    }
private:
    Adaptee_object* _adapter;
};
void test01(){
    Target_calss* adapter=new Adapter_class();
    adapter->Request();
}
void test02(){
    Adaptee_object* ade=new Adaptee_object;
    Target_object* adapter=new Adapter_object(ade);
    adapter->Request();
}
int main(){
    //测试类模式
    test01();
    //测试对象模式
    test02();
    return 0;
}