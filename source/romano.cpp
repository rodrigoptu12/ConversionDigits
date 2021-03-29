#include <iostream>
#include <map>
#include "../lib/catch.hpp"
#include "../include/romano.hpp"
/* Copyright 2021 */
using namespace std;   // NOLINT


std::map<string, int> romanos = { {"I", 1}, {"V", 5, }, {"X", 10, }, {"L", 50, }, {"C", 100, }, {"D", 500, },
{"M", 1000, }};
// teste para verificar se os caracteres sao validos
int teste1(string x) {
    string aux;
    int valor;
    for (int i = 0; i< x.length(); i++) {
        aux = x[i];
        if (romanos.find(aux) == romanos.end()) {
            return -1;
        }
        valor = romanos[aux];
    }
    return valor;
}
// Teste para verificar repetições proibidas.
int teste2(string x) {
    int repeat = 1;
    string aux;
    for (int i = 0; i< x.length(); i++) {
        aux = x[i];
        if (x[i] == x[i+1]) {
            repeat+=1;
            if (aux == "L" || aux == "V"|| aux == "D" && repeat >1) {
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
    if (valor > x.length()) {
        return 1;
    }
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
    if (valor > x.length()) {
        return 1;
    }
    aux = x[valor+1];
    if (aux == "D" || aux == "M") {
        return -1;
    } else {
        return 1;
    }
}
// O caractere V nunca é escrito a esquerda do X,L,D. O caractere V nunca é escrito ao lado dele mesmo.
// Os simbolos V, L e D ,M nunca podem ser subtraidos. VL  LV.
int teste5(string x) {
    string aux;
    int valor = 0;
    valor = x.find("V");
    if (valor < x.length()) {
    aux = x[valor+1];
    if (aux == "X" || aux == "V" || aux == "L" || aux == "D")
        return -1;
    }
    valor = x.find("L");
    if (valor < x.length()) {
    aux = x[valor+1];
    if (aux == "C" || aux == "D" || aux == "M")
        return -1;
    }
    valor = x.find("D");
    if (valor < x.length()) {
    aux = x[valor+1];
    if (aux == "M")
            return -1;
    } else {
        return 1;
    }
}
// converte numero romano para numero arabico
int conversor(string x) {
    if (x.length() > 30) {
        return -1;
    }
    if (teste1(x) == -1 || teste2(x) == -1 || teste3(x) == -1 ||teste4(x) == -1 || teste5(x) == -1) {
        return -1;
    }
    string aux;
    bool Verificador = 0;
    int arabico = 0, aux2 = 0;
    for (int i = x.length()-1; i>= 0; i--) {
        aux = x[i];
        if (Verificador) {
            if (!(teste1(aux) > aux2)) {
                return -1;
            } else {
                Verificador = 0;
            }
        }
        if (teste1(aux) >= aux2) {
            arabico += teste1(aux);
        } else {
            Verificador = 1;
            arabico -= teste1(aux);
        }
        aux2 = teste1(aux);
    }
    if (arabico > 3000) {
        return -1;
    }
    return arabico;
}
