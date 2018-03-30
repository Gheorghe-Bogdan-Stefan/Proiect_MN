//
// Created by krucisatorul on 12/2/17.
//

#ifndef NUMERICALMETHODS_SOLVECHOLESKY_H
#define NUMERICALMETHODS_SOLVECHOLESKY_H


#include "Cholesky.h"

class SolveCholesky {
private:
    int **matrixA;
    int **matrixL;
    int **matrixLTranspose;
    int dimension;

public:

    // Constructor
    SolveCholesky();

    // Destructor
    ~SolveCholesky();

    // Get matrix A from Cholesky and send to A from SolveCholesky
    void createMatrixForSolving(Cholesky cholesky);

    // Here I've applied Cholesky algorithm
    void solveMe();

    // Print crypted information
    friend ostream &operator<<(ostream &os,
                               const SolveCholesky &solveCholesky);
};

#endif //NUMERICALMETHODS_SOLVECHOLESKY_H
