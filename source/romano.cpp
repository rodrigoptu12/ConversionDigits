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
            return -1;
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
                return -1;
            }
            if (repeat > 3) {
                return -1;
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
        return -1;
    }
}
// O caractere X é utilizado somente antes do I, V, X, L e C.
int teste4(string x) {
    string aux;
    int valor = 0;
    valor = x.find("X");
    aux = x[valor+1];
    if (aux == "D" || aux == "M") {
        return -1;
    } else {
        return 1;
    }
}
// O caractere V nunca é escrito a esquerda do X.
int teste5(string x) {
    string aux;
    int valor = 0;
    valor = x.find("V");
    aux = x[valor+1];
    if (aux == "X") {
        return -1;
    } else {
        return 1;
    }
}


