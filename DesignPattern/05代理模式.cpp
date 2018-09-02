/*
代理模式：
为其他对象提供一种代理以控制对这个对象的访问。
组成：
抽象角色：通过接口或抽象类声明真实角色实现的业务方法。
代理角色：实现抽象角色，是真实角色的代理，通过真实角色的业务逻辑方法来实现抽象方法，并可以附加自己的操作。
真实角色：实现抽象角色，定义真实角色所要实现的业务逻辑，供代理角色调用。

举例：
通过代理服务器上外网
web服务器的缓冲服务器

*/
#include<iostream>

using namespace std;

class AbstractCommonInterface{
public:
    virtual void run()=0;
};

//必须有权限验证，不是所有人都能来启动我的系统，提供用户名和密码

//我写好的系统
class MySystem{
public:
    virtual void run(){
        cout<<"系统启动"<<endl;
    }

};
class MySystemProcess : public AbstractCommonInterface{
public:
    MySystemProcess(string username,string password){
        this->mUserName=username;
        this->mPassword=password;
        pSystem=new MySystem;
    }
    bool checkUsernameAbdUserpassword(){
        if(mUserName=="root" && mPassword=="admin"){
            return true;
        }
        else
            return false;
    }
    ~MySystemProcess(){
        if(pSystem!=nullptr)
            delete pSystem;
    }
    virtual void run(){
        if(checkUsernameAbdUserpassword()){
            cout<<"用户名和密码正确，验证通过。。。"<<endl;
            this->pSystem->run();
        }
        else{
            cout<<"用户名和密码不正确，权限不足。。。"<<endl;
        }
    }
public:
    MySystem* pSystem;
    string mUserName;
    string mPassword;
};

int main(){
    AbstractCommonInterface *s=new MySystemProcess("root","admin");
    s->run();
    return 0;
}



