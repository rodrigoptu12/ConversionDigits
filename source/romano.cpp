#include <iostream>
#include <map>
#include "../lib/catch.hpp"
#include "../lib/romano.hpp"

/* Copyright 2021 */
using namespace std;   // NOLINT


std::map<string, int> romanos = { {"I", 1}, {"V", 5, }, {"X", 10, }, {"L", 50, }, {"C", 100, }, {"D", 500, },
{"M", 1000, }};
// teste para verificar se os caracteres sao validos
int teste1(string x) {
    string aux;
    for (int i = 0; i< x.length(); i++) {
        aux = x[i];
        if (romanos.find(aux) == romanos.end()) {
            return 0;
        }
    }
    return 1;
}
// Teste para verificar repetições proibidas.
int teste2(string x) {
    int repeat = 1;
    string aux;
    for (int i = 0; i< x.length(); i++) {
        aux = x[i];
        if (x[i] == x[i+1]) {
            repeat+=1;
            if (aux == "L" || aux == "V"|| aux == "D" & repeat >1) {
                return 0;
            }
            if (repeat > 3) {
                return 0;
            }
        } else {
        repeat = 1;
        }
    }
    return 1;
}
// O caractere I é utilizado somente antes do I, V e X.
int teste3(string x) {
    string aux;
    int valor = 0;
    valor = x.find("I");
    aux = x[valor+1];
    if (aux == "I" || aux == "V" || aux == "X") {
        return 1;
    } else {
        return 0;
    }
}

/*int main() {
    string x;
    int teste;
    cout << "Digite o Numero Romano a ser convertido : " << endl;
    cin >> x;
    teste1(x);
    teste2(x);
    teste = teste3(x);
    cout << teste << endl;
    // teste 1
    /*for (int i = 0; i< x.length(); i++) {
        aux = x[i];
        if (romanos.find(aux) == romanos.end()) cout << " Valor invalido !" << endl;
    }*/
    /*for (int i = 0; i< x.length(); i++) {
        if (x[i] == x[i+1]) {
            repeat+=1;
            if (repeat > 3) {
                cout << " Valor invalido !" << endl;
                return 0;
            }
        } else {
        repeat = 1;
        }
    }*/
        /*if (romanos.find(x)!= romanos.end()) cout << romanos[x] << endl;
        else
        cout << " Valor invalido !" << endl;*/
    // cout << "\nVocê digitou o número: " << romanos.second << endl;
    // cppcheck-suppress syntaxError
  //  return 0;*/
// }

