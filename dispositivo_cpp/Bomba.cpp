#include "Bomba.h"

Bomba::Bomba() {
    ligada = false;
}

void Bomba::ligar() {
    ligada = true;
}

void Bomba::desligar() {
    ligada = false;
}

bool Bomba::estaLigada() {
    return ligada;
}