#include "Sensor.h"

Sensor::Sensor(string tag, string unidade) {
    this->tag = tag;
    this->unidade = unidade;
    this->valor = 0;
}

float Sensor::getValor() {
    return valor;
}

string Sensor::getTag() {
    return tag;
}