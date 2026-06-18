 #include "Alarme.h"

Alarme::Alarme(string mensagem) {
    this->mensagem = mensagem;
}

string Alarme::getMensagem() {
    return mensagem;
}