#include "SensorPressao.h"
#include <cstdlib>

SensorPressao::SensorPressao()
    : Sensor("Pressao", "bar")
{
}

float SensorPressao::ler() {
    valor = (rand() % 101) / 10.0;

    return valor;
}
