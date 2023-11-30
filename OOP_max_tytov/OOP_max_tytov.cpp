#include <iostream>
#include <windows.h>
#include <string>
#include <math.h>

#define SIZE 3
using namespace std;
class TRIANGLE {
private:
    POINT data[SIZE];
public:
 

    void key() {
        for (int i = 0; i < SIZE; i++) {
            cout << "Вершина " << i + 1 << endl << "X: ";
            cin >> data[i].x;
            cout << "Y: ";
            cin >> data[i].y;
        }
    }
    void completion(POINT pt[SIZE]) {
        for (int i = 0; i < SIZE; i++){
            data[i] = pt[i];
        }
    }
    double operator*() {
        double result = (data[0].x * (data[1].y - data[2].y)) + (data[1].x * (data[2].y - data[0].y)) + (data[2].x * (data[0].y - data[1].y));
        return abs(0.5*result);
    }
    void operator<<(string str) {
        cout << str << endl;
        for (int i = 0; i < SIZE; i++) {
            cout << "Вершина: " << i + 1 << endl << "X: " << data[i].x << "  Y: " << data[i].y << endl;
        }
    }
    bool operator()(POINT pt) {
        int a = (data[0].x - pt.x) * (data[1].y - data[0].y) - (data[1].x - data[0].x) * (data[0].y  - pt.y);
        int b = (data[1].x - pt.x) * (data[2].y - data[1].y) - (data[2].x - data[1].x) * (data[1].y - pt.y);
        int c = (data[2].x - pt.x) * (data[0].y - data[2].y) - (data[0].x - data[2].x) * (data[2].y - pt.y);
        if ((a >= 0 && b >= 0 && c >= 0) || (a <= 0 && b <= 0 && c <= 0))
        {
            return true;
        }
        return false;
    }
};

int main()
{
    setlocale(LC_ALL, "Russian");
    TRIANGLE abc1,abc2;
    abc1.key();
    POINT tri[3] = {
        {2,-3},
        {1,1},
        {-6,5}
    };
    abc2.completion(tri);
    abc2 << "Треугольник 2: ";
    double sq = *abc2;
    printf("Площадь треугольника: %.1f", sq);
    POINT pt = { 2,2 };
    if (abc1(pt)) {
        cout << endl << "Точка принадлежит!";
    }
    else {
        cout << endl << "Точка не принадлежит!";
    }
}

