#include "SensorNivel.h"
#include <cstdlib>

SensorNivel::SensorNivel()
    : Sensor("Nivel", "%")
{
}

float SensorNivel::ler() {
    valor = rand() % 101;
    return valor;
}