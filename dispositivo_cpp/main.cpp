#include "EstacaoBombeamento.h"
#include <cstdlib>
#include <ctime>

int main() {

    srand(time(0));

    EstacaoBombeamento estacao;

    estacao.atualizarSensores();

    return 0;
}