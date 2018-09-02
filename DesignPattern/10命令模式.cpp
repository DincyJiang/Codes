/*
命令模式 Command
在软件系统中，“行为请求者”与“行为实现者”通常呈现一种“紧耦合”。
但在某些场合，比如要对行为进行“记录、撤销/重做、事务”等处理，
这种无法抵御变化的紧耦合是不合适的。
在这种情况下，如何将“行为请求者”与“行为实现者”解耦？
将一组行为抽象为对象，实现二者之间的松耦合。
这就是命令模式（Command Pattern）。

*/
#include<iostream>
#include<queue>
#include"unistd.h"
using namespace std;

//协议处理类
class HandleClientProtocol{
public:
    void AddMoney(){
        cout<<"给玩家增加金币！"<<endl;
    }
    void AddDiamond(){
        cout<<"给玩家增加砖石！"<<endl;
    }
    void AddEquipment(){
        cout<<"给玩家穿装备！"<<endl;
    }
    void AddLevel(){
        cout<<"玩家升级！"<<endl;
    }
};

//命令接口
class AbstractCommand{
public:
    virtual void handle()=0;
};

class AddMoneyCommand:public AbstractCommand{
public:
    AddMoneyCommand(HandleClientProtocol* protocol){
        this->pProtocol=protocol;
    }
    virtual void handle(){
        this->pProtocol->AddMoney();
    }
public:
    HandleClientProtocol* pProtocol;
};
class AddDiamondCommand:public AbstractCommand{
public:
    AddDiamondCommand(HandleClientProtocol* protocol){
        this->pProtocol=protocol;
    }
    virtual void handle(){
        this->pProtocol->AddDiamond();
    }
public:
    HandleClientProtocol* pProtocol;
};
class AddEquipmentCommand:public AbstractCommand{
public:
    AddEquipmentCommand(HandleClientProtocol* protocol){
        this->pProtocol=protocol;
    }
    virtual void handle(){
        this->pProtocol->AddEquipment();
    }
public:
    HandleClientProtocol* pProtocol;
};
class AddLevelCommand:public AbstractCommand{
public:
    AddLevelCommand(HandleClientProtocol* protocol){
        this->pProtocol=protocol;
    }
    virtual void handle(){
        this->pProtocol->AddLevel();
    }
public:
    HandleClientProtocol* pProtocol;
};
//服务器
class Server{
public:
    void addRequset(AbstractCommand* command){
        mCommands.push(command);
    }
    void starthandle(){
        
        while(!mCommands.empty()){
            sleep(2);//延时2秒
            AbstractCommand* command=mCommands.front();
            command->handle();
            mCommands.pop();
        }

    }

public:
    queue<AbstractCommand*> mCommands; //需要处理的命令队列
};

void test(){
    HandleClientProtocol* protocol=new HandleClientProtocol;
    AbstractCommand* addmoney=new AddMoneyCommand(protocol);
    AbstractCommand* adddiamond=new AddDiamondCommand(protocol);
    AbstractCommand* addequipment=new AddEquipmentCommand(protocol);
    AbstractCommand* addlevel=new AddLevelCommand(protocol);
   
    Server* server=new Server;
    //把客户端的请求加入队列中
    server->addRequset(addmoney);
    server->addRequset(adddiamond);
    server->addRequset(addequipment);
    server->addRequset(addlevel);

    //开始处理请求
    server->starthandle();

}
int main(){
    test();

    return 0;
}


