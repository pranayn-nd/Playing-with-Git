// overloading 
#include <bits/stdc++.h>
using namespace std;

class SportsCar{

    string brand;
    string model;
    bool isEngineOn;
    int currentSpeed;
    int currentGear;
    // use getters and seetters instead of public variable
public:
    SportsCar(string b, string m) {
        this->brand = b;
        this->model = m;
        isEngineOn = false;
        currentSpeed = 0;
        currentGear = 0;
    }

    void startEngine() {
        if(isEngineOn){
            cout << brand << " " << model << " : Engine is started already , ready to drive! " << endl;
            return;
        }
        isEngineOn = true;
        cout << brand << " " << model << " : Engine starts with a roar!" << endl;
    }

    void shiftGear(int gear){
        if(!isEngineOn){
            cout << brand << " " << model << " : Engine is off , Cannot shift the gear " << endl;
            return;
        }
        currentGear = gear;
        cout << brand << " " << model << " :Shift gear to " << currentGear << endl;
    }

    void accelerate(){
        if(!isEngineOn){
            cout << brand << " " << model << " : Engine is off , cannot accelerate " << endl;
            return;
        }
        currentSpeed += 20;
        cout << brand << " " << model << " : Vehicle speed is Increased to " << currentSpeed << " kmph" << endl;
    }
    void accelerate(int speed){
        if(!isEngineOn){
            cout << brand << " " << model << " : Engine is off , cannot accelerate " << endl;
            return;
        }
        currentSpeed += speed ;
        cout << brand << " " << model << " : Accelerating to " << currentSpeed << " km/h " << endl;

    }
    void brake(){
        currentSpeed = currentSpeed - 20;
        if(currentSpeed < 0) currentSpeed = 0;
        cout << brand << " " << model << " : Engine speed is decreased to " << currentSpeed <<" kmph" << endl;

    }
    void stopEngine(){
        if(!isEngineOn){
            cout << brand << " " << model << " : Engine is already off"<< endl;
            return;
        }
        isEngineOn = false;
        currentSpeed = 0;
        currentGear = 0;
        cout << brand << " " << model << " : Engine has been  switched off" << endl;
    }
};

int main(){

    SportsCar* myCar = new SportsCar("Ford", "Mustang");

    myCar->startEngine();
    myCar->shiftGear(1);
    myCar->accelerate();
    myCar->shiftGear(2);
    myCar->accelerate(30);
    myCar->brake();
    myCar->stopEngine();
    return 0;
}