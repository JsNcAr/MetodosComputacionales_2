#include "microwave.h"
#include <iostream>

// Constructor
Microwave::Microwave() : seconds(0), minutes(0) {}

// Establece el tiempo del microondas
void Microwave::set_time(int time_sec_param, int time_min_param)
{
    if (time_sec_param >= 0 && time_min_param >= 0 && time_sec_param <= 60 && time_min_param <= 90)
    {
        seconds = time_sec_param;
        minutes = time_min_param;
    }
    else
    {
        std::cout << "Error: Tiempo no válido" << std::endl;
    }
}

// Agrega segundos al tiempo del microondas
void Microwave::add_time_sec(int add_time_sec_param)
{
    if (add_time_sec_param >= 0)
    {
        int total_seconds = minutes * 60 + seconds + add_time_sec_param;
        minutes = total_seconds / 60;
        seconds = total_seconds % 60;
        if (minutes > 90)
        {
            minutes = 90;
            seconds = 0;
            std::cout << "Error: Tiempo máximo excedido" << std::endl;
        }
    }
    else
    {
        std::cout << "Error: Tiempo no válido" << std::endl;
    }
}

// Agrega minutos al tiempo del microondas
void Microwave::add_time_min(int add_time_min_param)
{
    if (add_time_min_param >= 0)
    {
        int total_minutes = minutes + add_time_min_param;
        if (total_minutes <= 90)
        {
            minutes = total_minutes;
        }
        else
        {
            minutes = 90;
            std::cout << "Error: Tiempo máximo excedido" << std::endl;
        }
    }
    else
    {
        std::cout << "Error: Tiempo no válido" << std::endl;
    }
}

// Resta segundos al tiempo del microondas
void Microwave::del_time_sec(int del_time_sec_param)
{
    if (del_time_sec_param >= 0)
    {
        int total_seconds = minutes * 60 + seconds - del_time_sec_param;
        if (total_seconds >= 0)
        {
            minutes = total_seconds / 60;
            seconds = total_seconds % 60;
        }
        else
        {
            minutes = 0;
            seconds = 0;
            std::cout << "Error: Tiempo mínimo alcanzado" << std::endl;
        }
    }
    else
    {
        std::cout << "Error: Tiempo no válido" << std::endl;
    }
}

// Resta minutos al tiempo del microondas
void Microwave::del_time_min(int del_time_min_param)
{
    if (del_time_min_param >= 0)
    {
        if (minutes >= del_time_min_param)
        {
            minutes -= del_time_min_param;
        }
        else
        {
            minutes = 0;
            std::cout << "Error: Tiempo mínimo alcanzado" << std::endl;
        }
    }
    else
    {
        std::cout << "Error: Tiempo no válido" << std::endl;
    }
}

// Muestra el tiempo en el formato HH:MM
void Microwave::show_time()
{
    std::cout << (minutes < 10 ? "0" : "") << minutes << ":" << (seconds < 10 ? "0" : "") << seconds << std::endl;
}
