/* Escreva um programa que inverta os caracteres de um string.

IMPORTANTE:
	a) Essa string pode ser informada através de qualquer entrada de sua preferência ou pode ser previamente definida no código;
	b) Evite usar funções prontas, como, por exemplo, reverse;
*/

#include <iostream>
#include <string>

using namespace std;

int main() {
    string entrada;
    cout << "Digite uma string: ";
    getline(cin, entrada);

    int tamanho = entrada.size();
    string invertida(tamanho, ' ');

   
    for (int i = 0; i < tamanho; ++i) {
        invertida[i] = entrada[tamanho - i - 1];
    }

    cout << "String invertida: " << invertida << endl;

    return 0;
}
