#ifndef ESTACAOBOMBEAMENTO_H
#define ESTACAOBOMBEAMENTO_H

#include "Sensor.h"
#include "SensorNivel.h"
#include "SensorPressao.h"
#include "SensorVazao.h"
#include "SensorTemperatura.h"
#include "Bomba.h"
#include "Alarme.h"
#include "Repository.h"

#include <vector>

using namespace std;

class EstacaoBombeamento {

private:

    // Sensores concretos
    SensorNivel sensorNivel;
    SensorPressao sensorPressao;
    SensorVazao sensorVazao;
    SensorTemperatura sensorTemperatura;

    // Coleção polimórfica
    vector<Sensor*> sensores;

    // Atuadores
    Bomba bomba1;
    Bomba bomba2;

    // Alarmes
    vector<Alarme> alarmes;

    // Controle da alternância das bombas
    int contadorCiclos = 0;
    bool bombaPrincipal1 = true;

public:

    // Construtor
    EstacaoBombeamento();

    // Operações
    void atualizarSensores();

    void ligarBomba1();
    void desligarBomba1();

    void ligarBomba2();
    void desligarBomba2();
};

#endif