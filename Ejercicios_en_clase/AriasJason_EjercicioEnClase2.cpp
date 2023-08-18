#include <iostream>
#include <string>
using namespace std;

void cycle(int *ptrA, int *ptrB, int *ptrC, int *ptrD, string direction)
{
    if (direction == "right")
    {
        int temp = *ptrA;
        *ptrA = *ptrD;
        *ptrD = *ptrC;
        *ptrC = *ptrB;
        *ptrB = temp;
    }
    else if (direction == "left")
    {
        int temp = *ptrA;
        *ptrA = *ptrB;
        *ptrB = *ptrC;
        *ptrC = *ptrD;
        *ptrD = temp;
    }
}

int main()
{
    int a = 2, b = 3, c = 4, d = 6;
    cout << "Initial Numbers" << endl;
    cout << a << " " << b << " " << c << " " << d << endl;
    cout << "One cycle to the right" << endl;
    cycle(&a, &b, &c, &d, "right");
    cout << a << " " << b << " " << c << " " << d << endl;
    cout << "Two cycles to the left" << endl;
    cycle(&a, &b, &c, &d, "left");
    cycle(&a, &b, &c, &d, "left");
    cout << a << " " << b << " " << c << " " << d << endl;
    cout << "Adresses" << endl;
    cout << &a << " " << &b << " " << &c << " " << &d << endl;
    return 0;
}

//  g++ -std=c++14 -Wall -Wextra -pedantic AriasJasonNicolas_Ejercicio1.cpp -o archivo.out && ./archivo.out