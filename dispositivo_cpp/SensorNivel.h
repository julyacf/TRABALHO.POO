#ifndef SENSORNIVEL_H
#define SENSORNIVEL_H

#include "Sensor.h"

class SensorNivel : public Sensor {
public:
    SensorNivel();

    float ler() override;
};

#endif