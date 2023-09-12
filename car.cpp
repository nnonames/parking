#include "car.h"
#include "map.h"

char map[Y][X] = {
{'0', '0', '0', '0', '0'},
{'0', '0', '0', '0', '0'},
{'0', '0', '0', '0', '0'},
{'0', '0', '0', '0', '0'},
{'0', '0', '0', '0', '0'} };

namespace Cars {

    Car::Car() { }
    Car::~Car() { }
    void Car::CarIn(string namestr, tm *in, int posx, int posy, bool isDisabled) {
        this->name = namestr;
        this->month = in->tm_mon; //2592000s
        this->day = in->tm_mday; //86400s
        this->hour = in->tm_hour; //3600s
        this->min = in->tm_min; //60s
        this->sec = in->tm_sec;
        this->usetime;
        this->posX = posx;
        this->posY = posy;
        this->Disabled = isDisabled;
        map[posy][posx] = '1';

        cout << "\t\t배정된 구역은 [Y,X] [" << this->posY << "," << this->posX << "] 입니다." << endl;
        cout << "\t\t배정된 시각은 " << this->month << "월 " << this->day << "일 ";
        cout << this->hour << "시 " << this->min << "분 " << this->sec << "초 입니다." << endl;
    }
    bool Car::FindCar(string str) {
        if (this->name == str) { return true; }
        else { return false; }
    }
    
    void Car::CarOut(string name, tm *out, int useTime) {
        this->usetime = useTime;
        map[posY][posX] = '0';
        cout << "\t\t출차할 구역은 [Y,X] [" << posY << "," << posX << "] 입니다." << endl;
        cout << "\t\t출차 시각은 " << out->tm_mon << "월 " << out->tm_mday << "일 ";
        cout << out->tm_hour << "시 " << out->tm_min << "분 " << out->tm_sec << "초 입니다." << endl;
        cout << "\t\t이용하신 시간은 " << usetime / 3600 << "시간 ";
        cout << (usetime % 3600) / 60 << "분 " << ((usetime % 3600) % 60) << "초 이며,";
        cout << "결제 하실 금액은 ";
        if (usetime <= 600 ) { cout << 400; }
        else {
            cout << ((usetime / 3600) * 2000) + (((usetime % 3600) / 1800) * 1000) + ((((usetime % 3600) % 1800) / 600) * 400);
        }
        cout << "원 입니다." << endl;
    }
    string Car::GetCarName() {
        return (this->name);
    }
}
