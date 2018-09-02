/*
策略模式（Strategy)


问题：
在面向对象系统的分析与设计过程中经常会遇到这样一种情况：对于某一个业务逻辑
（算法实现） 在不同的对象中有不同的细节实现， 但是逻辑（算法） 的框架（或通用的应用
算法）是相同的。 

Strategy 模式解决的是和 Template 模式类似的问题， 但是 Strategy 模式是将逻辑
（算法）封装到一个类中，并采取组合（委托）的方式解决这个问题。

*/

#include<iostream>
using namespace std;

//抽象武器，武器策略
class WeaponStrategy{
public:
    virtual void UseWeapon()=0;
};
class Knife : public WeaponStrategy{
public:
    virtual void UseWeapon(){
        cout<<"使用匕首"<<endl;
    }
};
class AKM : public WeaponStrategy{
public:
    virtual void UseWeapon(){
        cout<<"使用AKM"<<endl;
    }
};
class Character{
public:
    void setWeapon(WeaponStrategy* weapon){
        pWeapon=weapon;
    }
    void fight(){
        this->pWeapon->UseWeapon();
    }
public:
    WeaponStrategy* pWeapon;
};
void test(){
    Character* a=new Character;
    WeaponStrategy* myWeapon=new Knife;
    a->setWeapon(myWeapon);
    a->fight();
    delete a;
    delete myWeapon;
}
int main(){
    test();

    return 0;
}



