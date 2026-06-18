#ifndef ALARME_H
#define ALARME_H

#include <string>

using namespace std;

class Alarme {
private:
    string mensagem;

public:
    Alarme(string mensagem);

    string getMensagem();
};

#endif