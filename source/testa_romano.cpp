#define CATCH_CONFIG_MAIN
#include "../lib/catch.hpp"
#include "../lib/romano.hpp"
/* Copyright 2021 */
using namespace std;   // NOLINT

TEST_CASE("Teste: caractere I somente antes do I, V e X", "[romano][inteiro]") {
    REQUIRE(teste3("IX") == 1);
    REQUIRE(teste3("IV") == 1);
    REQUIRE(teste3("II") == 1);
    REQUIRE(teste3("IC") == 0);
    REQUIRE(teste3("IM") == 0);
    REQUIRE(teste3("IL") == 0);
}
TEST_CASE("Teste: caracteres Validos", "[romano][inteiro]") {
    REQUIRE(teste1("I") == 1);
    REQUIRE(teste1("V") == 1);
    REQUIRE(teste1("X") == 1);
    REQUIRE(teste1("L") == 1);
    REQUIRE(teste1("C") == 1);
    REQUIRE(teste1("D") == 1);
    REQUIRE(teste1("M") == 1);
    REQUIRE(teste1("B") == 0);
    REQUIRE(teste1("N") == 0);
    REQUIRE(teste1("Q") == 0);
    REQUIRE(teste1("GG") == 0);
    REQUIRE(teste1("KKK") == 0);
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
    REQUIRE(teste2("VV") == 0);
    REQUIRE(teste2("XXXX") == 0);
    REQUIRE(teste2("LL") == 0);
    REQUIRE(teste2("CCCC") == 0);
    REQUIRE(teste2("DD") == 0);
    REQUIRE(teste2("MMMM") == 0);
    REQUIRE(teste2("CCC") == 1);
}

