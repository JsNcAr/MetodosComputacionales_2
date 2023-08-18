#include "remotecontrol.h"
#include <iostream>

RemoteControl::RemoteControl(Microwave microwave_param) : microwave(microwave_param) {}

void RemoteControl::set_time(int time_sec_param, int time_min_param)
{
    microwave.set_time(time_sec_param, time_min_param);
}

void RemoteControl::add_time_sec(int add_time_sec_param)
{
    microwave.add_time_sec(add_time_sec_param);
}

void RemoteControl::add_time_min(int add_time_min_param)
{
    microwave.add_time_min(add_time_min_param);
}

void RemoteControl::del_time_sec(int del_time_sec_param)
{
    microwave.del_time_sec(del_time_sec_param);
}

void RemoteControl::del_time_min(int del_time_min_param)
{
    microwave.del_time_min(del_time_min_param);
}

void RemoteControl::show_time()
{
    microwave.show_time();
}

// Implementa otros métodos si es necesario
