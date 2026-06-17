#include "SensorTemperatura.h"
#include <cstdlib>

SensorTemperatura::SensorTemperatura()
    : Sensor("Temperatura", "C")
{
}

float SensorTemperatura::ler() {
    valor = 20 + (rand() % 61);

    return valor;
}