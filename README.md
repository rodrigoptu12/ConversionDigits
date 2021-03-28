cppcheck --enable=warning .
valgrind --leak-check=full ./romano.out
g++ -o romano romano.cpp

