#include <cstdio>
#include <stdio.h>
#include <iostream>
#include <string>
#include <thread>
#include <chrono>

using namespace std;

class Hopper
{
    public:
    int *numOfBeans = new int;
  
    void AddBeans()
    {
        cout << "Add how many coffee beans?\n" << endl;
        string b;
        cin >> b;
        *numOfBeans = std::stoi(b) + *numOfBeans;
        cout << "\nThere are now " << *numOfBeans << " coffee beans in the hopper. This is " << *numOfBeans / 4.5 << "oz.\n" << endl;
    }
};


class Reservoir
{
    public:
    int *cupsOfWater = new int;
    
    void AddWater()
   {
       cout << "Add how many cups of water?\n" << endl;
       string w;
       cin >> w;
       *cupsOfWater = std::stoi(w) + *cupsOfWater;
       cout << "\nThere are now " << *cupsOfWater << " cups of water in the reservoir.\n" << endl;
   }
};


class Heater{
    public:
    bool *heated = new bool;
    
    void HeatWater(){
        if(*heated == false){
            *heated = true;
            cout << "The water is 72 degrees" << endl;
            std::this_thread::sleep_for (std::chrono::milliseconds(100));
            cout << "The water is heated to 82 degrees" << endl;
            std::this_thread::sleep_for (std::chrono::milliseconds(100));
            cout << "The water is heated to 92 degrees" << endl;
            std::this_thread::sleep_for (std::chrono::milliseconds(100));
            cout << "The water is heated to 102 degrees" << endl;
            std::this_thread::sleep_for (std::chrono::milliseconds(100));
            cout << "The water is heated to 112 degrees" << endl;
            std::this_thread::sleep_for (std::chrono::milliseconds(100));
            cout << "The water is heated to 122 degrees" << endl;
            std::this_thread::sleep_for (std::chrono::milliseconds(100));
            cout << "The water is heated to 132 degrees" << endl;
            std::this_thread::sleep_for (std::chrono::milliseconds(100));
            cout << "The water is heated to 142 degrees" << endl;
            std::this_thread::sleep_for (std::chrono::milliseconds(100));
            cout << "The water is heated to 152 degrees" << endl;
            std::this_thread::sleep_for (std::chrono::milliseconds(100));
            cout << "The water is heated to 162 degrees" << endl;
            std::this_thread::sleep_for (std::chrono::milliseconds(100));
            cout << "The water is heated to 172 degrees" << endl;
            std::this_thread::sleep_for (std::chrono::milliseconds(100));
            cout << "The water is heated to 182 degrees" << endl;
            std::this_thread::sleep_for (std::chrono::milliseconds(100));
            cout << "The water is heated to 185 degrees\n" << endl;
        }
        else{
            cout << "The water is already heated.\n" << endl;
        }
    }
    
};


class CoffeeMaker{
     public:
    
     bool powerOn = true;
     char poweredOff;
    
     int *cupsMade = new int;
    
     Reservoir Water;
     Hopper Beans;
     Heater Heat;
    
    char getInput(){
        cout << "Enter a command:" << endl;
        cout << "'B' to add beans" << endl;
        cout << "'W' to add water" << endl;
        cout << "'H' to heat water" << endl;
        cout << "'X' to power down\n" << endl;
        char button;
        cin >> button;
        return button;
    }
    
    void CheckForSuccessfulCups(){
        if(*Heat.heated == true){
            if(*Water.cupsOfWater <= (*Beans.numOfBeans / 45)) *cupsMade = *Water.cupsOfWater;
            else if(*Water.cupsOfWater >= (*Beans.numOfBeans / 45)) *cupsMade = (*Beans.numOfBeans / 45);
        }
        else{
           *cupsMade = 0;
        }
        cout << "You have made " << *cupsMade << " cups of coffee in total.\n" << endl;
    }
    
    void MakingCoffee(){
        cout << "\nCOFFEE PLUS PLUS™ COFFEE MAKER\n" << endl;
        
        while(powerOn == true){
            char command = getInput();
            
            switch(command){
                case 'B': case 'b':
                     Beans.AddBeans();
                     CheckForSuccessfulCups();
                     break;
                case 'W': case 'w':
                     Water.AddWater();
                     CheckForSuccessfulCups();
                     break;
                case 'H': case 'h':
                     Heat.HeatWater();
                     CheckForSuccessfulCups();
                     break;
                case 'X': case 'x':
                     cout << "\n...POWERING OFF...\n" << endl;
                     powerOn = false;
                     break;
            }
        }
    }
};

char getInput(){
    std::this_thread::sleep_for (std::chrono::seconds(1));
    cout << "\nEnter a command:\n" << endl;
    cout << "'B' to add beans\n" << endl;
    cout << "'W' to add water\n" << endl;
    cout << "'H' to heat water\n" << endl;
    cout << "'X' to power down\n" << endl;
    char button;
    cin >> button;
    return button;
}


int main()
{
    CoffeeMaker CoffeePlusPlus;
    
    while(CoffeePlusPlus.poweredOff != 'O' && CoffeePlusPlus.poweredOff != 'o'){
        cout << "Enter 'O' to turn on" << endl;
        cin >> CoffeePlusPlus.poweredOff;
    }
    
    CoffeePlusPlus.MakingCoffee();

    return 0;
}
