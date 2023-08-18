#include <iostream>

using namespace std;

class Triangle
{
private:
    float a, b, c;

public:
    Triangle(float a, float b, float c) : a(a), b(b), c(c) {}
    float getA() { return a; }
    float getB() { return b; }
    float getC() { return c; }
    void setA(float a) { this->a = a; }
    void setB(float b) { this->b = b; }
    void setC(float c) { this->c = c; }
    float perimeter() { return a + b + c; }
};

int main()
{
    float a, b, c;
    cout << "Ingrese los lados del triangulo: ";
    cout << "a: ";
    cin >> a;
    cout << "b: ";
    cin >> b;
    cout << "c: ";
    cin >> c;
    Triangle t(a, b, c);
    cout << "El perimetro del triangulo es: " << t.perimeter() << endl;
    return 0;
}

// g++ -std=c++14 -Wall -Wextra -pedantic AriasJasonNicolas_Ejercicio1.cpp -o archivo.out && ./archivo.out