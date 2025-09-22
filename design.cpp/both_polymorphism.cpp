// method overriding

#include <bits/stdc++.h>
using namespace std;

class Car{

protected:
    string brand;
    string model;
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

    void stopEngine(){
        if(!isEngineOn){
            cout << brand << " " << model << " : Engine is already off"<< endl;
            return;
        }
        isEngineOn = false;
        currentSpeed = 0;
        cout << brand << " " << model << " : Engine has been  switched off" << endl;
    }

    virtual void accelerate() = 0;
    virtual void accelerate(int) = 0;
    virtual void brake() = 0;
    virtual ~Car() {}
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
    //overriding accelerate
    void accelerate() {
        if(!isEngineOn){
            cout << brand << " " << model << " : Cannot accelerate! Engine is off." << endl;
            return;
        }
        currentSpeed +=20;
        cout << brand << " " << model << " : Accelerating to " << currentSpeed << " Km/h " << endl;
    }
    void accelerate(int speed){
        if(!isEngineOn){
            cout << brand << " " << model << " : Engine is off , cannot accelerate " << endl;
            return;
        }
        currentSpeed += speed ;
        cout << brand << " " << model << " : Accelerating to " << currentSpeed << " km/h " << endl;

    }

    //overriding brake
    void brake() {
        currentSpeed -= 20;
        if(currentSpeed < 0) currentSpeed = 0;
        cout << brand << " " << model << " : Braking! speed is now " << currentSpeed << " Km/h " << endl;
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
    
    void accelerate() {
        if(!isEngineOn){
            cout << brand << " " << model << " : Cannot accelerate! Engine is off." << endl;
            return;
        }
        currentCharge=currentCharge-10;
        currentSpeed +=15;
        cout << brand << " " << model << " : Accelerating to " << currentSpeed << " Km/h " << endl;
    }
    void accelerate(int speed){
        if(!isEngineOn){
            cout << brand << " " << model << " : Engine is off , cannot accelerate " << endl;
            return;
        }
        currentSpeed += speed ;
        cout << brand << " " << model << " : Accelerating to " << currentSpeed << " km/h " << endl;

    }
    void brake() {
        currentSpeed -= 15;
        if(currentSpeed < 0) currentSpeed = 0;
        cout << brand << " " << model << " : Braking! speed is now " << currentSpeed << " Km/h " << endl;
    }

};

int main(){

    Car* myManualCar = new ManualCar("Ford", "Mustang");
    myManualCar->startEngine();
    myManualCar->accelerate();
    myManualCar->accelerate();
    myManualCar->brake();
    myManualCar->stopEngine();
    delete myManualCar;
     
    Car* myElectricCar = new ElectricCar("Tesla", "Model S");
    myElectricCar->startEngine();
    myElectricCar->accelerate();
    myElectricCar->brake();
    myElectricCar->stopEngine();
    delete myElectricCar;
    return 0;
}
