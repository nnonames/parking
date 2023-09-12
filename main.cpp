#include "car.h"
#include "main.h"
#include "map.h"

int main(int argc, char *argv[])
{
    int remainSpace = carMax;
    int vcarAddr = 0;

    vector <Cars::Car> vcar(carMax);

    while (true) {
        cout << "\t\t\t\tCpp 주차장에 오신 것을 환영합니다." << endl;

        for (int i = 0; i < Y; i++) {
            cout << "\n\t" << endl;
            for (int j = 0; j < X; j++) {
                if (map[i][j] == '0') { cout << "\t\t[" << i << "," << j << "]"; }
                else if (map[i][j] == '1') {
                    cout << "\t\t[" << " X " << "]";
                }
            }
        }

        cout << endl;

        if (remainSpace == 0) {
            cout << "\t남은 자리가 없습니다. 죄송합니다." << endl;
            return 0;
        }

        cout << endl << "\t\t들어오시는 분은 1, 나가시는분은 0을 입력하세요 (종료는 Q 또는 q)... >> : ";
        cin >> answer;

        if (answer == "QUIT" || answer == "quit" || answer == "q" || answer == "Q") { return 0; }

        else if (answer == "1") {
            cout << "\t\t차량 번호를 [ 01A2345 ] 형식으로 입력하세요... >> : ";
            cin >> answer;

            cout << endl << "\t\t장애 여부를 알려주세요... (Y or N) >> : ";
            cin >> disabled;

            for (; ;) {
                if (disabled == "Y" || disabled == "y") {
                    isDisabled = 1;
                    break;
                }
                else if (disabled == "N" || disabled == "n") {
                    isDisabled = 0;
                    break;
                }
                else {
                    cout << "\t\t장애 여부를 제발 알려주세요... (Y or N) >> : " << endl;
                    cin >> disabled;
                }
            }
            cout << endl << "\t\t배차는 앞줄부터 이루어 집니다.." << endl << endl;

            /*if (isDisabled == 1 && map[0][1] == '0') {
                vcar[vcarAddr].Car::CarIn(answer, now, j, i, isDisabled);
                vcarAddr++;
                remainSpace--;
                isCarSet = 1; */

            for (int i = 0; i < Y; i++) {
                for (int j = 0; j < X; j++) {
                    if (map[i][j] == '0') {
                        realTime = time(NULL);
                        now = localtime(&realTime);
                        vcar[vcarAddr].Car::CarIn(answer, now, j, i, isDisabled);
                        vcarAddr++;
                        remainSpace--;
                        isCarSet = 1;
                        break;
                    }
                }
                if (isCarSet == 1 || remainSpace == 0) { isCarSet = 0; break; }
            }
        }
        else if (answer == "0") {
            cout << "\t\t차량 번호를 [ 01A2345 ] 형식으로 입력하세요... >> : ";
            cin >> answer;
            cout << endl;
            for (int i = 0; ; i++) {
                if (i >= carMax) {
                    cout << "\t\t일치하는 차량을 찾지 못했습니다." << endl;
                    break;
                }
                else if (vcar[i].FindCar(answer) == 1) {
                    cout << "\t\t일치하는 차량을 찾았습니다." << endl;
                    useTime = time(NULL) - realTime;
                    realTime = time(NULL);
                    now = localtime(&realTime);
                    vcar[i].Car::CarOut(answer, now, useTime);
                    vcar.erase(vcar.begin() + i);
                    break;
                }
            }
        }
        cout << endl;
    }
}