#include<bits/stdc++.h>
using namespace std;

/*
Implement a Smart Home Automation System where a Remote Control can execute commands such as Turn On Light,
Turn Off Light, and Turn On Fan, Turn Off Fan.
*/

//interfaces
class IDevice{
    public:
    virtual void turnOn()=0;
    virtual void turnOff()=0;
};

class ICommand{
    public:
    virtual void execute()=0;
    virtual void undo()=0;
};

//concrete devices
class Light:public IDevice{
    public:
    void turnOn(){
        cout<<"Light Turned On"<<endl;
    }
    void turnOff(){
        cout<<"Light Turned Off"<<endl;
    }
};

class Fan:public IDevice{
    public:
    void turnOn(){
        cout<<"Fan Turned On"<<endl;
    }
    void turnOff(){
        cout<<"Fan Turned Off"<<endl;
    }
};

//concrete commands
class TurnOnLight:public ICommand{
    protected:
    Light light;
    
    public:
    
    TurnOnLight(Light light){
        this->light=light;
    }
    
    void execute(){
        light.turnOn();
    }

    void undo(){
        light.turnOff();
    }
};

class TurnOffLight:public ICommand{
    protected:
    Light light;
    
    public:
    
    TurnOffLight(Light light){
        this->light=light;
    }
    
    void execute(){
        light.turnOff();
    }

    void undo(){
        light.turnOn();
    }
};

class TurnOnFan:public ICommand{
    protected:
    Fan fan;
    
    public:
    
    TurnOnFan(Fan fan){
        this->fan=fan;
    }
    
    void execute(){
        fan.turnOn();
    }

    void undo(){
        fan.turnOff();
    }
};

class TurnOffFan:public ICommand{
    protected:
    Fan fan;
    
    public:
    
    TurnOffFan(Fan fan){
        this->fan=fan;
    }
    
    void execute(){
        fan.turnOff();
    }

    void undo(){
        fan.turnOn();
    }
};

//Remote Service Invoker
class RemoteControl{
    protected:
    vector<ICommand*>commands;
    stack<ICommand*>commandsExecuted;
    stack<ICommand*>commandsForRedo;

    public:
    
    RemoteControl(int buttons){
        commands.resize(buttons);
    }

    void setCommand(int btn,ICommand* command){
        commands[btn]=command;
    }

    void pressButton(int btn){
        commands[btn]->execute();
        commandsExecuted.push(commands[btn]);
    }

    void undo(){
        if(commandsExecuted.size()==0){
            cout<<"No commands to undo"<<endl;
        }else{
            ICommand* lastCommand=commandsExecuted.top();
            commandsExecuted.pop();
            lastCommand->undo();
            //this commands goto redo stack
            commandsForRedo.push(lastCommand);
        }
    }
    void redo(){
        if(commandsForRedo.size()==0){
            cout<<"No commands to redo"<<endl;
        }else{
            ICommand* command=commandsForRedo.top();
            commandsForRedo.pop();
            command->execute();
            //again its opposite goes back to undo stack since its the last command now
            commandsExecuted.push(command);
        }
    }
};

int main(){
    
    //devices
    Light light;
    Fan fan;

    //create commands for devices
    ICommand* turnOnLight=new TurnOnLight(light);
    ICommand* turnOffLight=new TurnOffLight(light);
    ICommand* turnOnFan=new TurnOnFan(fan);
    ICommand* turnOffFan=new TurnOffFan(fan);

    //remote
    RemoteControl remote(4);
    //mapp comands to a remote
    remote.setCommand(0,turnOnLight);
    remote.setCommand(1,turnOffLight);
    remote.setCommand(2,turnOnFan);
    remote.setCommand(3,turnOffFan);

    //invoke commands via remote
    remote.redo();
    remote.pressButton(0);
    remote.pressButton(2);

    remote.undo();
    remote.undo();
    remote.redo();
    remote.undo();

    return 0;
}