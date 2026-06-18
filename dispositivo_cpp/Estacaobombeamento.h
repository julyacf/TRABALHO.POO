#ifndef ESTACAOBOMBEAMENTO_H
#define ESTACAOBOMBEAMENTO_H

#include "SensorNivel.h"
#include "SensorPressao.h"
#include "SensorVazao.h"
#include "SensorTemperatura.h"
#include "Bomba.h"
#include "Alarme.h"
#include <vector>

class EstacaoBombeamento {
private:
    SensorNivel sensorNivel;
    SensorPressao sensorPressao;
    SensorVazao sensorVazao;
    SensorTemperatura sensorTemperatura;

    Bomba bomba1;
    Bomba bomba2;

    vector<Alarme> alarmes;

public:
    void atualizarSensores();
};

#endif