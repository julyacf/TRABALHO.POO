#ifndef REPOSITORY_H
#define REPOSITORY_H

#include <string>
#include <vector>

using namespace std;

class Repository {
private:
    Repository() = delete; 

public:
    static void salvarHistorico(float nivel,
                                float pressao,
                                float vazao,
                                float temperatura);

    static void salvarJson(float nivel,
                           float pressao,
                           float vazao,
                           float temperatura,
                           bool bomba1,
                           bool bomba2,
                           const vector<string>& alarmes);

    static void salvarComando(const string& comando);
};

#endif