/*Dado um vetor que guarda o valor de faturamento diário de uma distribuidora, faça um programa, na linguagem que desejar, que calcule e retorne:
	• O menor valor de faturamento ocorrido em um dia do mês;
	• O maior valor de faturamento ocorrido em um dia do mês;
	• Número de dias no mês em que o valor de faturamento diário foi superior à média mensal.

IMPORTANTE:
	a) Usar o json ou xml disponível como fonte dos dados do faturamento mensal;
	b) Podem existir dias sem faturamento, como nos finais de semana e feriados. Estes dias devem ser ignorados no cálculo da média;
*/

#include <iostream>
#include <fstream>
#include <nlohmann/json.hpp>

using json = nlohmann::json;
using namespace std;

struct Faturamento {
    double menor;
    double maior;
    int diasAcimaMedia;
};

Faturamento calcularFaturamento(const json& faturamentoDiario, double mediaMensal) {
    Faturamento resultado;
    resultado.menor = faturamentoDiario[0]["valor"];
    resultado.maior = faturamentoDiario[0]["valor"];
    resultado.diasAcimaMedia = 0;

    for (const auto& valor : faturamentoDiario) {
        double faturamento = valor["valor"];
        if (faturamento < resultado.menor)
            resultado.menor = faturamento;
        if (faturamento > resultado.maior)
            resultado.maior = faturamento;
        if (faturamento > mediaMensal)
            resultado.diasAcimaMedia++;
    }

    return resultado;
}

int main() {
    ifstream arquivo("dados.json");
    json faturamentoMensal;
    arquivo >> faturamentoMensal;

    
    double soma = 0;
    int diasValidos = 0;
    for (const auto& valor : faturamentoMensal) {
        double faturamento = valor["valor"];
        soma += faturamento;
        diasValidos++;
    }
    double mediaMensal = soma / diasValidos;

    
    Faturamento resultado = calcularFaturamento(faturamentoMensal, mediaMensal);

    
    cout << "Menor faturamento: " << resultado.menor << endl;
    cout << "Maior faturamento: " << resultado.maior << endl;
    cout << "Dias com faturamento acima da media mensal: " << resultado.diasAcimaMedia << endl;

    return 0;
}
