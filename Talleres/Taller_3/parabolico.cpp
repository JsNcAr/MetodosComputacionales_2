
#include <iostream>
#include <vector>
#include <fstream>
#include <cmath>
#define g 10.0
#define m 1
#define b 0.2

using namespace std;

// Función para calcular la derivada de x con respecto al tiempo
double dxdt(double /*t*/, double /*x*/, double vx) {
    return vx;
}

// Función para calcular la derivada de vx con respecto al tiempo
double dvxdt(double /*t*/, double /*x*/, double vx, double vy) {
    double v = sqrt(vx * vx + vy * vy);
    return -b / m * v * vx;
}

// Función para calcular la derivada de y con respecto al tiempo
double dydt(double /*t*/, double /*y*/, double vy) {
    return vy;
}

// Función para calcular la derivada de vy con respecto al tiempo
double dvydt(double /*t*/, double /*y*/, double vy, double vx) {
    double v = sqrt(vx * vx + vy * vy);
    return -g - b / m * v * vy;
}

int main() {
    float x_init = 0;
    float y_init = 10;
    float vx_init = 10;
    float vy_init = 10;

    float dt = 0.01;
    float t_total = 2.733;
    cout << "total_time:" <<  t_total << endl;
    int N = t_total/dt;
    cout << N;

    vector<double> pos_x(N + 1);
    vector<double> pos_y(N + 1);
    
    pos_x[0] = x_init;
    pos_y[0] = y_init;


    for (int i = 0; i < N; i++) {
        double t = i * dt;

        // Método de Runge-Kutta de 4to orden
        double k1vx = dt * dvxdt(t, pos_x[i], vx_init, vy_init);
        double k1vy = dt * dvydt(t, pos_y[i], vy_init, vx_init);
        double k1x = dt * dxdt(t, pos_x[i], vx_init);
        double k1y = dt * dydt(t, pos_y[i], vy_init);

        double k2vx = dt * dvxdt(t + 0.5 * dt, pos_x[i] + 0.5 * k1x, vx_init + 0.5 * k1vx, vy_init + 0.5 * k1vy);
        double k2vy = dt * dvydt(t + 0.5 * dt, pos_y[i] + 0.5 * k1y, vy_init + 0.5 * k1vy, vx_init + 0.5 * k1vx);
        double k2x = dt * dxdt(t + 0.5 * dt, pos_x[i] + 0.5 * k1x, vx_init + 0.5 * k1vx);
        double k2y = dt * dydt(t + 0.5 * dt, pos_y[i] + 0.5 * k1y, vy_init + 0.5 * k1vy);

        double k3vx = dt * dvxdt(t + 0.5 * dt, pos_x[i] + 0.5 * k2x, vx_init + 0.5 * k2vx, vy_init + 0.5 * k2vy);
        double k3vy = dt * dvydt(t + 0.5 * dt, pos_y[i] + 0.5 * k2y, vy_init + 0.5 * k2vy, vx_init + 0.5 * k2vx);
        double k3x = dt * dxdt(t + 0.5 * dt, pos_x[i] + 0.5 * k2x, vx_init + 0.5 * k2vx);
        double k3y = dt * dydt(t + 0.5 * dt, pos_y[i] + 0.5 * k2y, vy_init + 0.5 * k2vy);

        double k4vx = dt * dvxdt(t + dt, pos_x[i] + k3x, vx_init + k3vx, vy_init + k3vy);
        double k4vy = dt * dvydt(t + dt, pos_y[i] + k3y, vy_init + k3vy, vx_init + k3vx);
        double k4x = dt * dxdt(t + dt, pos_x[i] + k3x, vx_init + k3vx);
        double k4y = dt * dydt(t + dt, pos_y[i] + k3y, vy_init + k3vy);

        pos_x[i + 1] = pos_x[i] + (k1x + 2 * k2x + 2 * k3x + k4x) / 6.0;
        pos_y[i + 1] = pos_y[i] + (k1y + 2 * k2y + 2 * k3y + k4y) / 6.0;

        vx_init += (k1vx + 2 * k2vx + 2 * k3vx + k4vx) / 6.0;
        vy_init += (k1vy + 2 * k2vy + 2 * k3vy + k4vy) / 6.0;
    }

    // Guardar datos en un archivo CSV
    ofstream myfile;
    myfile.open("parabolic_with_friction.csv");
    myfile << "x,y\n";
    for (int i = 0; i < N; i++) {
        myfile << pos_x[i] << "," << pos_y[i] << "\n";
    }
    myfile.close();

    return 0;

}
