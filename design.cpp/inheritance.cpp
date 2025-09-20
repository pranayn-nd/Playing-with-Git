#include <bits/stdc++.h>
using namespace std;

class Car{

public:
    string brand;
    string model;
private:
    bool isEngineOn;
    int currentSpeed;
    // use getters and seetters instead of public variable
public:
    Car(string b, string m) {
        this->brand = b;
        this->model = m;
        isEngineOn = false;
        currentSpeed = 0;
    }

    void startEngine() {
        if(isEngineOn){
            cout << brand << " " << model << " : Engine is started already , ready to drive! " << endl;
            return;
        }
        isEngineOn = true;
        cout << brand << " " << model << " : Engine starts with a roar!" << endl;
    }

    void accelerate(){
        if(!isEngineOn){
            cout << brand << " " << model << " : Engine is off , cannot accelerate " << endl;
            return;
        }
        currentSpeed += 20;
        cout << brand << " " << model << " : Vehicle speed is Increased to " << currentSpeed << " kmph" << endl;
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
        cout << brand << " " << model << " : Engine has been  switched off" << endl;
    }
};

class ManualCar : public Car {
private:
    int currentGear;

public:
    ManualCar(string b, string m) : Car(b,m){
        currentGear = 0;
    }

    void shiftGear(int gear){
        currentGear = gear;
        cout << brand << " " << model << " : shifted to gear " << currentGear << endl;

    }
};

class ElectricCar : public Car{
private:
    int currentCharge;
public:
    ElectricCar(string b, string m) : Car(b,m){
        currentCharge = 100;
    }

    void chargeBattery() {
        currentCharge = 100;
        cout << brand << " " << model << " : Battery fully Charged!" << endl;
    }

};

int main(){

    ManualCar* myManualCar = new ManualCar("Ford", "Mustang");
    myManualCar->startEngine();
    myManualCar->shiftGear(1);
    myManualCar->accelerate();
    myManualCar->shiftGear(2);
    myManualCar->accelerate();
    myManualCar->brake();
    myManualCar->stopEngine();
    delete myManualCar;
     
    ElectricCar* myElectricCar = new ElectricCar("Tesla", "Model S");
    myElectricCar->chargeBattery();
    myElectricCar->startEngine();
    myElectricCar->accelerate();
    myElectricCar->brake();
    myElectricCar->stopEngine();
    delete myElectricCar;
    return 0;
}
