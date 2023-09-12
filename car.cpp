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

        cout << "\t\t������ ������ [Y,X] [" << this->posY << "," << this->posX << "] �Դϴ�." << endl;
        cout << "\t\t������ �ð��� " << this->month << "�� " << this->day << "�� ";
        cout << this->hour << "�� " << this->min << "�� " << this->sec << "�� �Դϴ�." << endl;
    }
    bool Car::FindCar(string str) {
        if (this->name == str) { return true; }
        else { return false; }
    }
    
    void Car::CarOut(string name, tm *out, int useTime) {
        this->usetime = useTime;
        map[posY][posX] = '0';
        cout << "\t\t������ ������ [Y,X] [" << posY << "," << posX << "] �Դϴ�." << endl;
        cout << "\t\t���� �ð��� " << out->tm_mon << "�� " << out->tm_mday << "�� ";
        cout << out->tm_hour << "�� " << out->tm_min << "�� " << out->tm_sec << "�� �Դϴ�." << endl;
        cout << "\t\t�̿��Ͻ� �ð��� " << usetime / 3600 << "�ð� ";
        cout << (usetime % 3600) / 60 << "�� " << ((usetime % 3600) % 60) << "�� �̸�,";
        cout << "���� �Ͻ� �ݾ��� ";
        if (usetime <= 600 ) { cout << 400; }
        else {
            cout << ((usetime / 3600) * 2000) + (((usetime % 3600) / 1800) * 1000) + ((((usetime % 3600) % 1800) / 600) * 400);
        }
        cout << "�� �Դϴ�." << endl;
    }
    string Car::GetCarName() {
        return (this->name);
    }
}
