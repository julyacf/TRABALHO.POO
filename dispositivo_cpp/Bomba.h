#ifndef BOMBA_H
#define BOMBA_H

class Bomba {
private:
    bool ligada;

public:
    Bomba();

    void ligar();

    void desligar();

    bool estaLigada();
};

#endif