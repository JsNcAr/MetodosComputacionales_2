#ifndef MICROWAVE_H
#define MICROWAVE_H

class Microwave
{
private:
    int seconds;
    int minutes;

public:
    Microwave(); // Constructor

    // Métodos para configurar y obtener el tiempo
    void set_time(int time_sec_param, int time_min_param);
    void add_time_sec(int add_time_sec_param);
    void add_time_min(int add_time_min_param);
    void del_time_sec(int del_time_sec_param);
    void del_time_min(int del_time_min_param);
    void show_time();
};

#endif // MICROWAVE_H
