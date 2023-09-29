#include <iostream>

using namespace std;

int main()
{
    // stack
    int a = 10;
    cout << "a: " << a << endl;

    // heap
    int *b = new int;
    *b = 20;
    cout << "b: " << *b << endl;
    cout << "b: " << b << endl;
    delete b;
    return 0;
}

// g++ -std=c++14 -Wall -Wextra -pedantic AriasJasonNicolas_Ejercicio1.cpp -o archivo.out && ./archivo.out