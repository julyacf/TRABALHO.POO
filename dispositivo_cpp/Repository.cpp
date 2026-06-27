#include "Repository.h"
#include <fstream>
#include <stdexcept>

using namespace std;

void Repository::salvarHistorico(float nivel,
                                 float pressao,
                                 float vazao,
                                 float temperatura)
{
    ofstream historico("../data/historico.csv", ios::app);

    if (!historico.is_open()) {
        throw runtime_error("Erro ao abrir historico.csv");
    }

    if (historico.tellp() == 0)
        historico << "nivel,pressao,vazao,temperatura\n";

    historico << nivel << ","
              << pressao << ","
              << vazao << ","
              << temperatura
              << endl;
}

void Repository::salvarJson(float nivel,
                            float pressao,
                            float vazao,
                            float temperatura,
                            bool bomba1,
                            bool bomba2,
                            const vector<string>& alarmes)
{
    ofstream arquivo("../data/leituras.json");

    if (!arquivo.is_open()) {
        throw runtime_error("Erro ao abrir leituras.json");
    }

    arquivo << "{\n";
    arquivo << "  \"nivel\": " << nivel << ",\n";
    arquivo << "  \"pressao\": " << pressao << ",\n";
    arquivo << "  \"vazao\": " << vazao << ",\n";
    arquivo << "  \"temperatura\": " << temperatura << ",\n";

    arquivo << "  \"bomba1\": "
            << (bomba1 ? "true" : "false")
            << ",\n";

    arquivo << "  \"bomba2\": "
            << (bomba2 ? "true" : "false")
            << ",\n";

    arquivo << "  \"alarmes\": [";

    for (size_t i = 0; i < alarmes.size(); i++) {
        arquivo << "\"" << alarmes[i] << "\"";

        if (i < alarmes.size() - 1)
            arquivo << ", ";
    }

    arquivo << "]\n}";
}

void Repository::salvarComando(const string& comando)
{
    ofstream comandos("../data/comandos.txt", ios::app);

    if (!comandos.is_open()) {
        throw runtime_error("Erro ao abrir comandos.txt");
    }

    comandos << comando << endl;
}