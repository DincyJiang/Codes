/*
观察者模式：Visitor 
在面向对象系统的开发和设计过程，经常会遇到一种情况就是需求变更(Requirement Changing)，
经常我们做好的一个设计、实现了一个系统原型，咱们的客户又会有了新的需 求。
我们又因此不得不去修改已有的设计，最常见就是解决方案就是给已经设计、实现好的 类添加新的方法去实现客户新的需求，
这样就陷入了设计变更的梦魇:不停地打补丁，其带 来的后果就是设计根本就不可能封闭、编译永远都是整个系统代码。
Visitor 模式则提供了一种解决方案:将更新(变更)封装到一个类中(访问操作)，并 由待更改类提供一个接收接口，则可达到效果。

观察者模式是用于建立一种对象与对象之间的依赖关系，一个对象发生改变时将自动通知其他对象，
其他对象将相应作出反应。在观察者模式中，发生改变的对象称为观察目标，而被通知的对象称为观察者，
一个观察目标可以对应多个观察者


*/

#include<iostream>
#include<list>
using namespace std;

//抽象的观察者
class AbstractHero{
public:
    virtual void update()=0;
};
class HeroA : public AbstractHero{
public:
    HeroA(){
        cout<<"英雄A正在撸BOSS..."<<endl;
    }
    virtual void update(){
        cout<<"英雄A停止撸BOSS，待机状态..."<<endl;
    }
};
class HeroB : public AbstractHero{
public:
    HeroB(){
        cout<<"英雄B正在撸BOSS..."<<endl;
    }
    virtual void update(){
        cout<<"英雄B停止撸BOSS，待机状态..."<<endl;
    }
};
class HeroC : public AbstractHero{
public:
    HeroC(){
        cout<<"英雄C正在撸BOSS..."<<endl;
    }
    virtual void update(){
        cout<<"英雄C停止撸BOSS，待机状态..."<<endl;
    }
};
class HeroD : public AbstractHero{
public:
    HeroD(){
        cout<<"英雄D正在撸BOSS..."<<endl;
    }
    virtual void update(){
        cout<<"英雄D停止撸BOSS，待机状态..."<<endl;
    }
};
class HeroE : public AbstractHero{
public:
    HeroE(){
        cout<<"英雄E正在撸BOSS..."<<endl;
    }
    virtual void update(){
        cout<<"英雄E停止撸BOSS，待机状态..."<<endl;
    }
};

//观察目标
class AbstractBoss{
public:
    //添加观察者
    virtual void addHero(AbstractHero* hero)=0;
    //删除观察者
    virtual void deleteHero(AbstractHero* hero)=0;
    //通知观察者
    virtual void notify()=0;
};
class BOSSA : public AbstractBoss{
public:
    //添加观察者
    virtual void addHero(AbstractHero* hero){
        pHeroList.push_back(hero);
    }
    //删除观察者
    virtual void deleteHero(AbstractHero* hero){
        pHeroList.remove(hero);
    }
    //通知观察者
    virtual void notify(){
        for(auto i : pHeroList){
            i->update();
        }
    }
private:
    list<AbstractHero*> pHeroList;
};

void test(){
    AbstractHero* heroA=new HeroA;
    AbstractHero* heroB=new HeroB;
    AbstractHero* heroC=new HeroC;
    AbstractHero* heroD=new HeroD;
    AbstractHero* heroE=new HeroE;
    
    AbstractBoss* bossA=new BOSSA;
    bossA->addHero(heroA);
    bossA->addHero(heroB);
    bossA->addHero(heroC);
    bossA->addHero(heroD);
    bossA->addHero(heroE);

    cout<<"heroC阵亡..."<<endl;
    bossA->deleteHero(heroC);
    cout<<"BOSS阵亡...通知其他英雄停止攻击"<<endl;
    bossA->notify();

    delete heroA;
    heroA=nullptr;
    delete heroB;
    heroB=nullptr;
    delete heroC;
    heroC=nullptr;
    delete heroD;
    heroD=nullptr;
    delete heroE;
    heroE=nullptr;
    delete bossA;
    bossA=nullptr;
}
int main(){ 
    test();

    return 0;
}

