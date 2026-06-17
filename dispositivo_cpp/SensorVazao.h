#ifndef SENSORVAZAO_H
#define SENSORVAZAO_H

#include "Sensor.h"

class SensorVazao : public Sensor {
public:
    SensorVazao();

    float ler() override;
};

#endif