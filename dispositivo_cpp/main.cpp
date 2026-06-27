#include "EstacaoBombeamento.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

int main() {

    srand(time(0));

    EstacaoBombeamento estacao;

    int opcao;

    do {

        cout << "\n=== ESTACAO DE BOMBEAMENTO ===\n";
        cout << "1 - Ligar bomba 1\n";
        cout << "2 - Desligar bomba 1\n";
        cout << "3 - Ligar bomba 2\n";
        cout << "4 - Desligar bomba 2\n";
        cout << "5 - Atualizar sensores\n";
        cout << "0 - Sair\n";
        cout << "Opcao: ";

        cin >> opcao;

        switch(opcao) {

        case 1:
            estacao.ligarBomba1();
            break;

        case 2:
            estacao.desligarBomba1();
            break;

        case 3:
            estacao.ligarBomba2();
            break;

        case 4:
            estacao.desligarBomba2();
            break;

        case 5:
            estacao.atualizarSensores();
            break;

        case 0:
            cout << "Encerrando...\n";
            break;

        default:
            cout << "Opcao invalida.\n";
        }

    } while(opcao != 0);

    return 0;
}