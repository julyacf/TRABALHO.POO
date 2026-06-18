#include "EstacaoBombeamento.h"
#include <iostream>
#include <fstream>

using namespace std;

void EstacaoBombeamento::atualizarSensores() {

    float nivel = sensorNivel.ler();
    float pressao = sensorPressao.ler();
    float vazao = sensorVazao.ler();
    float temperatura = sensorTemperatura.ler();

     ofstream arquivo("../data/leituras.json");
     arquivo << "{\n";
     arquivo << "  \"nivel\": " << nivel << ",\n";
     arquivo << "  \"pressao\": " << pressao << ",\n";
     arquivo << "  \"vazao\": " << vazao << ",\n";
     arquivo << "  \"temperatura\": " << temperatura << ",\n";
     arquivo << "  \"bomba1\": "
        << (bomba1.estaLigada() ? "true" : "false")
        << ",\n";
     arquivo << "  \"bomba2\": "
        << (bomba2.estaLigada() ? "true" : "false")
        << "\n";
     arquivo << "}\n";
     arquivo.close();



    alarmes.clear();
    cout << "Nivel: " << nivel << "%" << endl;
    cout << "Pressao: " << pressao << " bar" << endl;
    cout << "Vazao: " << vazao << " L/min" << endl;
    cout << "Temperatura: " << temperatura << " C" << endl;

    // Regra 1 - Nivel baixo
if (nivel < 20) {
    bomba1.ligar();

    alarmes.push_back(
        Alarme("Nivel baixo")
    );

    cout << "ALERTA: Nivel baixo! Bomba 1 ligada." << endl;
}
    // Regra 2 - Nivel alto
   if (nivel > 85) {
    bomba1.desligar();

    alarmes.push_back(
        Alarme("Nivel alto")
    );

    cout << "Nivel alto! Bomba 1 desligada." << endl;
}
    // Regra 3 - Pressao alta
    if (pressao > 6.5) {
       alarmes.push_back(
           Alarme("Pressao alta")
       );
    }

    // Regra 4 - Temperatura alta
    if (temperatura > 65) {
        alarmes.push_back(
    Alarme("Temperatura alta")
     );
    }
cout << "Bomba 1: ";

if (bomba1.estaLigada()) {
    cout << "Ligada" << endl;
}
else {
    cout << "Desligada" << endl;
}

cout << "Bomba 2: ";

if (bomba2.estaLigada()) {
    cout << "Ligada" << endl;
}
else {
    cout << "Desligada" << endl;
}
cout << "\nAlarmes ativos:" << endl;

if (alarmes.empty()) {
    cout << "Nenhum alarme." << endl;
}
else {
    for (Alarme alarme : alarmes) {
        cout << "- "
             << alarme.getMensagem()
             << endl;
    }
}

cout << endl;
    cout << endl;
}