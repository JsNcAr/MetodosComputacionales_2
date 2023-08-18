#ifndef REMOTECONTROL_H
#define REMOTECONTROL_H

#include "microwave.h"

class RemoteControl
{
private:
    Microwave microwave;

public:
    RemoteControl(Microwave microwave_param);

    // Métodos para interactuar con el microondas
    void set_time(int time_sec_param, int time_min_param);
    void add_time_sec(int add_time_sec_param);
    void add_time_min(int add_time_min_param);
    void del_time_sec(int del_time_sec_param);
    void del_time_min(int del_time_min_param);
    void show_time();
};

#endif // REMOTECONTROL_H
