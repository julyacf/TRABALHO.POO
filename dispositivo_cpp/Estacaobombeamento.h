#ifndef ESTACAOBOMBEAMENTO_H
#define ESTACAOBOMBEAMENTO_H

#include "SensorNivel.h"
#include "SensorPressao.h"
#include "SensorVazao.h"
#include "SensorTemperatura.h"
#include "Bomba.h"

class EstacaoBombeamento {
private:
    SensorNivel sensorNivel;
    SensorPressao sensorPressao;
    SensorVazao sensorVazao;
    SensorTemperatura sensorTemperatura;

    Bomba bomba1;
    Bomba bomba2;

public:
    void atualizarSensores();
};

#endif