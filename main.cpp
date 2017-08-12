#include <iostream>
#include "nQueens.h"

int main() {
    int N = 8;

    nQueens * queens = new nQueens();
    queens->solve(N);
    //board->print_board();
    return 0;
}