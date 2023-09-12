#pragma once

#include <iostream>
#include <ctime>

using namespace std;

namespace Cars {

    class Car
    {
    public:
        string name;
        int month;
        int day;
        int hour;
        int min;
        int sec;
        int usetime;
        unsigned int posX, posY;
        bool Disabled = false;  
        Car();
        ~Car();

        void CarIn(string namestr, tm *in, int posx, int posy, bool isDisabled);
        void CarOut(string name, tm *out, int usetime);
        bool FindCar(string str);
        string GetCarName();
    };
}
