//
// Created by matheus on 11/08/17.
//

#include "nQueens.h"

void nQueens::solve(int n){
    std::vector<std::thread> threads;
    for(int i = 0; i < n; i++){
        threads.push_back(std::thread (&nQueens::solveInThread, this, i, i, n));
        //solve(i, i, n);
    }

    for (auto& th : threads) th.join();
}

bool nQueens::solveInThread(int thread, int st, int n){
    int col = 0;
    std::vector<int> s;

    while(col <= n){
        bool queenIsPlaced = false;

        for(int row = st + 1; row <= n; row++){

            if(rowIsSafe(row, s)){
                queenIsPlaced = true;
                s.push_back(row);
                col++;
                if(col == n){
                    std::lock_guard<std::mutex> lock(g_mutex);
                    if(verifySolution(s)){
                        all_solutions.push_back(s);
                        solutions++;
                        std::cout << "Solution: " << solutions << ", found in thread: " << thread << "\n";
                        printSolution(s);
                    }
                }
                break;
            }
        }

        if(!queenIsPlaced){
            if(s.empty()){
                return false;
            }
            st = s.at(s.size() - 1);
            s.pop_back();
            col--;
        }else{
            st = 0;
        }

    }
    return false;
}

bool nQueens::verifySolution(std::vector<int> solution){
    for(int i = 0; i < all_solutions.size(); i++){
        if(all_solutions.at(i) == solution){
            return false;
        }
    }

    return true;
}

void nQueens::printSolution(std::vector<int> s){
    for(int i = 0; i < s.size(); i++){
        for(int j = 0; j < s.size(); j++){
            if(j+1 == s.at(i)){
                std::cout << " Q ";
            }else{
                std::cout << " - ";
            }
        }
        std::cout << "\n";
    }
    std::cout << "\n";
}

bool nQueens::rowIsSafe(int row, std::vector<int> s){
    for(int col = 0; col < s.size(); col++){
       if(s.at(col) == row){
            return false;
        }
        if(std::abs(row - s.at(col)) == (s.size() - col)){
            return false;
        }
    }

    return true;
}

