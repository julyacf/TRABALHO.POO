#ifndef SENSORPRESSAO_H
#define SENSORPRESSAO_H

#include "Sensor.h"

class SensorPressao : public Sensor {
public:
    SensorPressao();

    float ler() override;
};

#endif