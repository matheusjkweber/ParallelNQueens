//
// Created by matheus on 11/08/17.
//

#ifndef N_QUEENS_NQUEENS_H
#define N_QUEENS_NQUEENS_H

#include <vector>
#include <iostream>
#include <thread>
#include <mutex>


class nQueens {
    private:
        int solutions;
        std::vector<std::vector<int>> all_solutions;
        std::mutex g_mutex;

    public:
        void solve(int n);
        void printSolution(std::vector<int> s);
        bool rowIsSafe(int row, std::vector<int> s);
        bool solveInThread(int thread, int start, int n);
        bool verifySolution(std::vector<int> solution);
};


#endif //N_QUEENS_NQUEENS_H
