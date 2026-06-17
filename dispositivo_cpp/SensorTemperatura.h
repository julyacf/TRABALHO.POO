#ifndef SENSORTEMPERATURA_H
#define SENSORTEMPERATURA_H

#include "Sensor.h"

class SensorTemperatura : public Sensor {
public:
    SensorTemperatura();

    float ler() override;
};

#endif