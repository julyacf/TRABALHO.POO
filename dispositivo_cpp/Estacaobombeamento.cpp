#include "EstacaoBombeamento.h"
#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

EstacaoBombeamento::EstacaoBombeamento() {

    sensores.push_back(&sensorNivel);
    sensores.push_back(&sensorPressao);
    sensores.push_back(&sensorVazao);
    sensores.push_back(&sensorTemperatura);

}

void EstacaoBombeamento::atualizarSensores() {


    for (Sensor* sensor : sensores) {
    sensor->ler();
}

float nivel = sensorNivel.getValor();
float pressao = sensorPressao.getValor();
float vazao = sensorVazao.getValor();
float temperatura = sensorTemperatura.getValor();

string alerta = "";
string mensagemAlternancia = "";

// Alternância automática a cada 10 ciclos
contadorCiclos++;
// Alternância automática a cada 10 ciclos
contadorCiclos++;

if (contadorCiclos >= 10) {

    contadorCiclos = 0;
    bombaPrincipal1 = !bombaPrincipal1;

    if (bombaPrincipal1)
        mensagemAlternancia =
            "*** Alternancia automatica das bombas ***\n"
            "Bomba 1 agora e a principal.";
    else
        mensagemAlternancia =
            "*** Alternancia automatica das bombas ***\n"
            "Bomba 2 agora e a principal.";
}

    alarmes.clear();
    Repository::salvarHistorico(
    nivel,
    pressao,
    vazao,
    temperatura
);

    alarmes.clear();

    // Simulação de falha
if (rand() % 20 == 0) {
    nivel = 0;
    alarmes.push_back(
        Alarme("Falha no sensor de nivel")
    );
}


    cout << "Nivel: " << nivel << "%" << endl;
    cout << "Pressao: " << pressao << " bar" << endl;
    cout << "Vazao: " << vazao << " L/min" << endl;
    cout << "Temperatura: " << temperatura << " C" << endl;

    if (!mensagemAlternancia.empty()) {
    cout << "\n" << mensagemAlternancia << endl;
}

    if (!alerta.empty()) {
    cout << alerta << endl;
}

    // Regra 1 - Nivel baixo
    if (nivel < 25) {

    if (bombaPrincipal1) {
        bomba1.ligar();
        bomba2.desligar();
        alerta = "ALERTA: Nivel baixo! Bomba 1 ligada.";
    }
    else {
        bomba2.ligar();
        bomba1.desligar();
        alerta = "ALERTA: Nivel baixo! Bomba 2 ligada.";
    }

    alarmes.push_back(
        Alarme("Nivel baixo")
    );
}

    // Regra 2 - Nivel alto
   if (nivel > 85) {
    bomba1.desligar();
    bomba2.desligar();

    alarmes.push_back(
        Alarme("Nivel alto")
    );

    cout << "Nivel alto! Bomba 1 desligada." << endl;
}
    // Regra 3 - Pressao alta
if (pressao > 7.5) {
    bomba2.desligar();

    alarmes.push_back(
        Alarme("Bomba 2 bloqueada por alta pressao")
    );
}
    // Regra 4 - Temperatura alta
    if (temperatura > 65) {
        alarmes.push_back(
    Alarme("Temperatura alta")
     );
    }

    if (!alerta.empty()) {
    cout << "\n" << alerta << endl;
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


vector<string> mensagens;

for (Alarme alarme : alarmes) {
    mensagens.push_back(alarme.getMensagem());
}

Repository::salvarJson(
    nivel,
    pressao,
    vazao,
    temperatura,
    bomba1.estaLigada(),
    bomba2.estaLigada(),
    mensagens
);

cout << endl;
    cout << endl;
}

void EstacaoBombeamento::ligarBomba1() {
    bomba1.ligar();

    cout << "Bomba 1 ligada com sucesso!" << endl;

    Repository::salvarComando("Ligar bomba 1");
}

void EstacaoBombeamento::desligarBomba1() {
    bomba1.desligar();

    cout << "Bomba 1 desligada com sucesso!" << endl;

    Repository::salvarComando("Desligar bomba 1");
}

void EstacaoBombeamento::ligarBomba2() {
    bomba2.ligar();

    cout << "Bomba 2 ligada com sucesso!" << endl;

    Repository::salvarComando("Ligar bomba 2");
}

void EstacaoBombeamento::desligarBomba2() {
    bomba2.desligar();

    cout << "Bomba 2 desligada com sucesso!" << endl;

    Repository::salvarComando("Desligar bomba 2");
}