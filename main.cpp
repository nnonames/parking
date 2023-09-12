#include "car.h"
#include "main.h"
#include "map.h"

int main(int argc, char *argv[])
{
    int remainSpace = carMax;
    int vcarAddr = 0;

    vector <Cars::Car> vcar(carMax);

    while (true) {
        cout << "\t\t\t\tCpp �����忡 ���� ���� ȯ���մϴ�." << endl;

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
            cout << "\t���� �ڸ��� �����ϴ�. �˼��մϴ�." << endl;
            return 0;
        }

        cout << endl << "\t\t�����ô� ���� 1, �����ôº��� 0�� �Է��ϼ��� (����� Q �Ǵ� q)... >> : ";
        cin >> answer;

        if (answer == "QUIT" || answer == "quit" || answer == "q" || answer == "Q") { return 0; }

        else if (answer == "1") {
            cout << "\t\t���� ��ȣ�� [ 01A2345 ] �������� �Է��ϼ���... >> : ";
            cin >> answer;

            cout << endl << "\t\t��� ���θ� �˷��ּ���... (Y or N) >> : ";
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
                    cout << "\t\t��� ���θ� ���� �˷��ּ���... (Y or N) >> : " << endl;
                    cin >> disabled;
                }
            }
            cout << endl << "\t\t������ ���ٺ��� �̷�� ���ϴ�.." << endl << endl;

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
            cout << "\t\t���� ��ȣ�� [ 01A2345 ] �������� �Է��ϼ���... >> : ";
            cin >> answer;
            cout << endl;
            for (int i = 0; ; i++) {
                if (i >= carMax) {
                    cout << "\t\t��ġ�ϴ� ������ ã�� ���߽��ϴ�." << endl;
                    break;
                }
                else if (vcar[i].FindCar(answer) == 1) {
                    cout << "\t\t��ġ�ϴ� ������ ã�ҽ��ϴ�." << endl;
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