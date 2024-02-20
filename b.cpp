//Dado a sequência de Fibonacci, onde se inicia por 0 e 1 e o próximo valor sempre será a soma dos 2 valores anteriores (exemplo: 0, 1, 1, 2, 3, 5, 8, 13, 21, 34...), escreva um programa na linguagem que desejar onde, informado um número, ele calcule a sequência de Fibonacci e retorne uma mensagem avisando se o número informado pertence ou não a sequência.
//IMPORTANTE:esse número pode ser informado através de qualquer entrada de sua preferência ou pode ser previamente definido no código;

#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'

#define dbg(x) cout << #x << " = " << x << endl

typedef unsigned long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

bool pertenceFibonacci(int num) {
    int a = 0, b = 1;
    while (b < num) {
        int temp = b;
        b = a + b;
        a = temp;
    }
    return (b == num);
}

int main() {
    int numero;
    cout << "Digite um numero para verificar se pertence a sequencia de Fibonacci: ";
    cin >> numero;

    if (pertenceFibonacci(numero))
        cout << numero << " pertence ao Fibonacci." << endl;
    else
        cout << numero << " nao pertence ao Fibonacci." << endl;

    return 0;
}