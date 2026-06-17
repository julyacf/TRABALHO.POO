#ifndef SENSOR_H
#define SENSOR_H

#include <string>

using namespace std;

class Sensor {
protected:
    string tag;
    float valor;
    string unidade;

public:
    Sensor(string tag, string unidade);

    virtual float ler() = 0;

    float getValor();

    string getTag();
};

#endif