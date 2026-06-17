#include "EstacaoBombeamento.h"
#include <iostream>

using namespace std;

void EstacaoBombeamento::atualizarSensores() {

    cout << "Nivel: "
         << sensorNivel.ler()
         << "%" << endl;

    cout << "Pressao: "
         << sensorPressao.ler()
         << " bar" << endl;

    cout << "Vazao: "
         << sensorVazao.ler()
         << " L/min" << endl;

    cout << "Temperatura: "
         << sensorTemperatura.ler()
         << " C" << endl;
}