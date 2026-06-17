#include "SensorVazao.h"
#include <cstdlib>

SensorVazao::SensorVazao()
    : Sensor("Vazao", "L/min")
{
}

float SensorVazao::ler() {
    valor = rand() % 101;

    return valor;
}
