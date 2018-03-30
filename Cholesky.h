//
// Created by krucisatorul on 12/1/17.
//

#ifndef NUMERICALMETHODS_CHOLESKY_H
#define NUMERICALMETHODS_CHOLESKY_H

//A = L * L_transpose;

#include "Utility.h"

class Cholesky {
private:
    int **matrixA;
    int **matrixL;
    int **matrixLTranspose;
    int dimension;
public:

    // Constructor
    Cholesky();

    // Destructor
    ~Cholesky();

    // Put text in L, and find A wich is L * Ltranspose
    Cholesky(char *text, int dimension);

    // Get the dimension used for the matrices
    int getDimension() const;

    // Is used for sending A from Cholesky to A from SolveCholesky
    int getElementFromMatrixA(int i, int j);

    // Print crypted information from input
    friend ostream &operator<<(ostream &os, const Cholesky &cholesky);
};


#endif //NUMERICALMETHODS_CHOLESKY_H
