/*
装饰模式  Decorator Pattern

装饰模式指的是在不必改变原类文件和使用继承的情况下，动态地扩展一个对象的功能。
它是通过创建一个包装对象，也就是装饰来包裹真实的对象。

一般情况下，用继承拓展功能


*/

#include<iostream>
using namespace std;

class AbstractHero{
public:
    virtual void ShowStatus()=0;
public:
    int mHp;
    int mMp;
    int mAt;
    int mDf;
};

class HeroA : public AbstractHero{
public:
    HeroA(){
        mHp=0;
        mMp=0;
        mAt=0;
        mDf=0;
    };
    virtual void ShowStatus(){
        cout<<"血量："<<mHp<<endl;
        cout<<"魔法："<<mMp<<endl;
        cout<<"攻击："<<mAt<<endl;
        cout<<"防御："<<mDf<<endl;
    }
};

//穿上衣服之后还是英雄
class AbstractEquipment : public AbstractHero{
public:
    AbstractEquipment(AbstractHero* hero):pHero(hero){

    }
    virtual void ShowStatus(){

    }
public:
    AbstractHero* pHero;
};
class KuangtuEquipment : public AbstractEquipment{
public:
    KuangtuEquipment(AbstractHero* hero):AbstractEquipment(hero){

    }
    void AddKuangtu(){
        cout<<"英雄穿上狂徒之后..."<<endl;
        this->mHp=this->pHero->mHp;
        this->mMp=this->pHero->mMp;
        this->mAt=this->pHero->mAt;
        this->mDf=this->pHero->mDf+30;
        delete this->pHero;
    }
    virtual void ShowStatus(){
        AddKuangtu();
        cout<<"血量："<<mHp<<endl;
        cout<<"魔法："<<mMp<<endl;
        cout<<"攻击："<<mAt<<endl;
        cout<<"防御："<<mDf<<endl;
    }
};

class WujinEquipment : public AbstractEquipment{
public:
    WujinEquipment(AbstractHero* hero):AbstractEquipment(hero){

    }
    void AddWujin(){
        cout<<"英雄拿上无尽之后..."<<endl;
        this->mHp=this->pHero->mHp;
        this->mMp=this->pHero->mMp;
        this->mAt=this->pHero->mAt+80;
        this->mDf=this->pHero->mDf;
        delete this->pHero;
    }
    virtual void ShowStatus(){
        AddWujin();
        cout<<"血量："<<mHp<<endl;
        cout<<"魔法："<<mMp<<endl;
        cout<<"攻击："<<mAt<<endl;
        cout<<"防御："<<mDf<<endl;
    }
};



void test(){
    AbstractHero* hero=new HeroA;
    hero->ShowStatus();
    cout<<"------------------"<<endl;
    hero=new KuangtuEquipment(hero);
    hero->ShowStatus();
    cout<<"------------------"<<endl;
    hero=new WujinEquipment(hero);
    hero->ShowStatus();


}

int main(){

    test();

    return 0;
}
