/*
外观模式（Facade），为子系统中的一组接口提供一个一致的界面，
定义一个高层接口，这个接口使得这一子系统更加容易使用。

外观模式就是将复杂的子类系统抽象到同一个接口进行管理
外界只需要通过此接口与子类系统进行交互而不必要直接与复杂的子类系统进行交互

外观模式案例：
实现家庭影院外观模式应用
实现KTV模式：电视打开，灯关掉，音响打开，麦克风打开，DVD打开
实现游戏模式：电视打开，音响打开，游戏机打开

*/

#include<iostream>
using namespace std;

class Television{
public:
    void On(){
        cout<<"电视机打开..."<<endl;
    }
    void Off(){
        cout<<"电视机关闭..."<<endl;
    }
};

class Light{
public:
    void On(){
        cout<<"灯打开..."<<endl;
    }
    void Off(){
        cout<<"灯关闭..."<<endl;
    }
};

class Sound{
public:
    void On(){
        cout<<"音响打开..."<<endl;
    }
    void Off(){
        cout<<"音响关闭..."<<endl;
    }
};

class Microphone{
public:
    void On(){
        cout<<"麦克风打开..."<<endl;
    }
    void Off(){
        cout<<"麦克风关闭..."<<endl;
    }
};

class DVDPlayer{
public:
    void On(){
        cout<<"DVD播放器打开..."<<endl;
    }
    void Off(){
        cout<<"DVD播放器关闭..."<<endl;
    }
};

class GameMachine{
public:
    void On(){
        cout<<"游戏机打开..."<<endl;
    }
    void Off(){
        cout<<"游戏机关闭..."<<endl;
    }
};

class KTVMode{
public:
    KTVMode(){
        pTV = new Television;
        pLight = new Light;
        pSound = new Sound;
        pMicrophone = new Microphone;
        pDVDPlayer = new DVDPlayer;
    }
    ~KTVMode(){
        delete pTV;
        delete pLight;
        delete pSound;
        delete pMicrophone;
        delete pDVDPlayer;
    }
    void runKTV(){
        cout<<"开启KTV模式。。。"<<endl;
        pTV->On();
        pLight->Off();
        pSound->On();
        pMicrophone->On();
        pDVDPlayer->On();
    }
    void closeKTV(){
        cout<<"关闭KTV模式。。。"<<endl;
        pTV->Off();
        pLight->On();
        pSound->Off();
        pMicrophone->Off();
        pDVDPlayer->Off();
    }
public:
    Television* pTV;
    Light* pLight;
    Sound* pSound;
    Microphone* pMicrophone;
    DVDPlayer* pDVDPlayer;
};

class GameMode{
public:
    GameMode(){
        pTV = new Television;
        pSound = new Sound;
        pGameMachine = new GameMachine;
    }
    ~GameMode(){
        delete pTV;
        delete pSound;
        delete pGameMachine;
    }
    void runGame(){
        cout<<"开启游戏模式。。。"<<endl;
        pTV->On();
        pSound->On();
        pGameMachine->On();
    }
    void closeGame(){
        cout<<"关闭游戏模式。。。"<<endl;
        pTV->Off();
        pSound->Off();
        pGameMachine->Off();
    }
public:
    Television* pTV;
    Sound* pSound;
    GameMachine* pGameMachine;
};
void test01(){
    KTVMode* KTV=new KTVMode;
    KTV->runKTV();
}

void test02(){
    GameMode* pGameMode=new GameMode;
    pGameMode->runGame();
}
int main(){

    test01();
    test02();
    return 0;
}

