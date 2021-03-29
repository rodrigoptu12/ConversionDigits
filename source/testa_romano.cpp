#define CATCH_CONFIG_MAIN
#include "../lib/catch.hpp"
#include "../include/romano.hpp"
/* Copyright 2-121 */
using namespace std;   // NOLINT

TEST_CASE("Teste: caractere I somente antes do I, V e X", "[romano][inteiro]") {
    REQUIRE(teste3("IX") == 1);
    REQUIRE(teste3("IV") == 1);
    REQUIRE(teste3("II") == 1);
    REQUIRE(teste3("IC") == -1);
    REQUIRE(teste3("IM") == -1);
    REQUIRE(teste3("IL") == -1);
    REQUIRE(teste3("ID") == -1);
}
TEST_CASE("Teste: caracteres Validos", "[romano][inteiro]") {
    REQUIRE(teste1("I") == 1);
    REQUIRE(teste1("V") == 1);
    REQUIRE(teste1("X") == 1);
    REQUIRE(teste1("L") == 1);
    REQUIRE(teste1("C") == 1);
    REQUIRE(teste1("D") == 1);
    REQUIRE(teste1("M") == 1);
    REQUIRE(teste1("B") == -1);
    REQUIRE(teste1("N") == -1);
    REQUIRE(teste1("Q") == -1);
    REQUIRE(teste1("GG") == -1);
    REQUIRE(teste1("KKK") == -1);
}
TEST_CASE("Teste: Caracteres com repetições proibidas", "[romano][inteiro]") {
    REQUIRE(teste2("I") == 1);
    REQUIRE(teste2("V") == 1);
    REQUIRE(teste2("X") == 1);
    REQUIRE(teste2("L") == 1);
    REQUIRE(teste2("C") == 1);
    REQUIRE(teste2("D") == 1);
    REQUIRE(teste2("M") == 1);
    REQUIRE(teste2("I") == 1);
    REQUIRE(teste2("VV") == -1);
    REQUIRE(teste2("XXXX") == -1);
    REQUIRE(teste2("LL") == -1);
    REQUIRE(teste2("CCCC") == -1);
    REQUIRE(teste2("DD") == -1);
    REQUIRE(teste2("MMMM") == -1);
    REQUIRE(teste2("CCC") == 1);
}
TEST_CASE("Teste: O caractere X é utilizado somente antes do I, V, X, L e C.", "[romano][inteiro]") {
    REQUIRE(teste4("XI") == 1);
    REQUIRE(teste4("XV") == 1);
    REQUIRE(teste4("XL") == 1);
    REQUIRE(teste4("XC") == 1);
    REQUIRE(teste4("XX") == 1);
    REQUIRE(teste4("XM") == -1);
    REQUIRE(teste4("XD") == -1);
}
TEST_CASE("O caractere V nunca é escrito a esquerda do X.", "[romano][inteiro]") {
    REQUIRE(teste5("XV") == 1);
    REQUIRE(teste5("VX") == -1);
    REQUIRE(teste5("XVX") == -1);
}
