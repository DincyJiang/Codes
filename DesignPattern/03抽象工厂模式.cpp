/*

抽象工厂针对的是产品族，而不是产品等级结构。
产品族：同一产地或者同一厂商，功能不同。
产品等级：功能相同，产地或者厂商不同。

如果增加一个新的水果：西瓜，就不符合开闭原则了
*/

#include<iostream>
#include<string>
using namespace std;

class AbstractApple{
public:
    virtual void ShowName()=0;
};
class ChinaApple : public AbstractApple{
public:
    virtual void ShowName(){
        cout<<"中国Apple"<<endl;
    }
};
class USAApple : public AbstractApple{
public:
    virtual void ShowName(){
        cout<<"美国Apple"<<endl;
    }
};
class JapanApple : public AbstractApple{
public:
    virtual void ShowName(){
        cout<<"日本Apple"<<endl;
    }
};
class AbstractBanana{
public:
    virtual void ShowName()=0;
};
class ChinaBanana : public AbstractBanana{
public:
    virtual void ShowName(){
        cout<<"中国Banana"<<endl;
    }
};
class USABanana : public AbstractBanana{
public:
    virtual void ShowName(){
        cout<<"美国Banana"<<endl;
    }
};
class JapanBanana : public AbstractBanana{
public:
    virtual void ShowName(){
        cout<<"日本Banana"<<endl;
    }
};
class AbstractPear{
public:
    virtual void ShowName()=0;
};
class ChinaPear : public AbstractPear{
public:
    virtual void ShowName(){
        cout<<"中国Pear"<<endl;
    }
};
class USAPear : public AbstractPear{
public:
    virtual void ShowName(){
        cout<<"美国Pear"<<endl;
    }
};
class JapanPear : public AbstractPear{
public:
    virtual void ShowName(){
        cout<<"日本Pear"<<endl;
    }
};

//抽象工厂  针对产品族
class AbstractFactroy{
public:
    virtual AbstractApple* CreateApple()=0;
    virtual AbstractBanana* CreateBanana()=0;
    virtual AbstractPear* CreatePear()=0;
};
class ChinaFactroy : public AbstractFactroy{
public:
    virtual AbstractApple* CreateApple(){
        return new ChinaApple;
    }
    virtual AbstractBanana* CreateBanana(){
        return new ChinaBanana;
    }
    virtual AbstractPear* CreatePear(){
        return new ChinaPear;
    }
};
class USAFactroy : public AbstractFactroy{
public:
    virtual AbstractApple* CreateApple(){
        return new USAApple;
    }
    virtual AbstractBanana* CreateBanana(){
        return new USABanana;
    }
    virtual AbstractPear* CreatePear(){
        return new USAPear;
    }
};
class JapanFactroy : public AbstractFactroy{
public:
    virtual AbstractApple* CreateApple(){
        return new JapanApple;
    }
    virtual AbstractBanana* CreateBanana(){
        return new JapanBanana;
    }
    virtual AbstractPear* CreatePear(){
        return new JapanPear;
    }
};
void test(){
    AbstractFactroy* factroy=nullptr;
    AbstractApple* apple=nullptr;
    AbstractBanana* banana=nullptr;
    AbstractPear* pear=nullptr;
    factroy=new ChinaFactroy;
    apple=factroy->CreateApple();
    banana=factroy->CreateBanana();
    pear=factroy->CreatePear();
    apple->ShowName();
    banana->ShowName();
    pear->ShowName();

    delete factroy;
    delete apple;
    delete banana;
    delete pear;
}
int main(){

    test(); 
    return 0;
}