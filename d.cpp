/* Dado o valor de faturamento mensal de uma distribuidora, detalhado por estado:

	SP – R$67.836,43
	RJ – R$36.678,66
	MG – R$29.229,88
	ES – R$27.165,48
	Outros – R$19.849,53

Escreva um programa na linguagem que desejar onde calcule o percentual de representação que cada estado teve dentro do valor total mensal da distribuidora.*/

#include <iostream>
#include <fstream>
#include <iomanip>
#include <nlohmann/json.hpp>

using namespace std;
using json = nlohmann::json;

int main() {
    ifstream arquivo_json("dados.json");

    if (!arquivo_json.is_open()) {
        cerr << "Erro ao abrir o arquivo JSON.\n";
        return 1;
    }

    json dados;
    arquivo_json >> dados;

    double total_mensal = 0.0;
    for (const auto& item : dados) {
        total_mensal += item["valor"].get<double>();
    }

    cout << "Total mensal: R$ " << fixed << setprecision(2) << total_mensal << endl;

    return 0;
}