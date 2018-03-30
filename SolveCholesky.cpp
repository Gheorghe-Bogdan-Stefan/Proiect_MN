//
// Created by krucisatorul on 12/2/17.
//

#include "SolveCholesky.h"
#include "Utility.h"

SolveCholesky::~SolveCholesky() {
    int i = 0;
    int length = this->dimension;
    if (this->matrixA != NULL) {
        for (i = 0; i < length; i++) {
            delete [] this->matrixA[i];
        }
        delete [] this->matrixA;
        this->matrixA = NULL;
    }
    if (this->matrixL != NULL) {
        for (i = 0; i < length; i++) {
            delete [] this->matrixL[i];
        }
        delete [] this->matrixL;
        this->matrixL = NULL;
    }
    if (this->matrixLTranspose != NULL) {
        for (i = 0; i < length; i++) {
            delete [] this->matrixLTranspose[i];
        }
        delete [] this->matrixLTranspose;
        this->matrixLTranspose = NULL;
    }
}

void SolveCholesky::createMatrixForSolving(Cholesky cholesky) {
    this->dimension = cholesky.getDimension();
    this->matrixL = new int *[this->dimension];
    this->matrixA = new int *[this->dimension];
    this->matrixLTranspose = new int *[this->dimension];
    for (int i = 0; i < this->dimension; i++) {
        this->matrixL[i] = new int[this->dimension];
        this->matrixA[i] = new int[this->dimension];
        this->matrixLTranspose[i] = new int[this->dimension];
        for (int j = 0; j < this->dimension; j++) {
            this->matrixL[i][j] = 0;
            this->matrixA[i][j] = cholesky.getElementFromMatrixA(i, j);
            this->matrixLTranspose[i][j] = 0;
        }
    }
}

void SolveCholesky::solveMe() {
    float **auxiliar = new float *[this->dimension];
    for (int i = 0; i < this->dimension; i++) {
        auxiliar[i] = new float[this->dimension];
        for (int j = 0; j < this->dimension; j++) {
            auxiliar[i][j] = 0;
        }
    }
    if (this->matrixA[0][0] <=  0) {
        cout << "Matrix[0][0] <= 0!";
        throw "Not a good Matrix!";
    } else {
        float alfa = 0, sum = 0;
        auxiliar[0][0] = sqrt(this->matrixA[0][0]);
        for (int i = 1; i < this->dimension; i++) {
            auxiliar[i][0] = this->matrixA[i][0] / auxiliar[0][0];
        }
        for (int k = 1; k < this->dimension; k++) {
            sum = 0;
            for (int l = 0; l <= k - 1; l++) {
                sum += pow(auxiliar[k][l], 2);
            }
            alfa = this->matrixA[k][k] - sum;
            if (alfa <= 0) {
                break;
            } else {
                auxiliar[k][k] = sqrt(alfa);
                if (k == this->dimension - 1) {
                    break;
                } else {
                    for (int i = k; i < this->dimension; i++) {
                        sum = 0;
                        for (int l = 0; l <= k - 1; l++) {
                            sum += auxiliar[i][l] * auxiliar[k][l];
                        }
                        auxiliar[i][k] = (this->matrixA[i][k] - sum )
                                         / auxiliar[k][k];
                    }
                }
            }
        }
    }

    for (int i = 0; i < dimension; i++) {
        for (int j = 0; j < dimension; j++) {
            if (auxiliar[i][j] != 0) {
                this->matrixLTranspose[i][j] = auxiliar[j][i];
            }
        }
    }
    cout << endl << "Decrypted information: " << endl;
    for (int i = 0; i < dimension; i++) {
        for (int j = 0; j < dimension; j++) {
            if (auxiliar[i][j] != 0) {
                this->matrixL[i][j] = auxiliar[i][j];
                cout << (char )this->matrixL[i][j];
            }
        }
    }
    for (int i = 0; i < dimension; i++) {
        delete[] auxiliar[i];
    }
    delete[] auxiliar;
}

ostream &operator<<(ostream &os, const SolveCholesky &solveCholesky) {
    int length = solveCholesky.dimension;
    for (int i = 0; i < length; i++) {
        for (int j = 0; j < length; j++) {
            os << solveCholesky.matrixA[i][j] << ' ';
        }
        os << endl;
    }
    return os;
}

SolveCholesky::SolveCholesky() {
    this->matrixA = NULL;
    this->matrixL = NULL;
    this->matrixLTranspose = NULL;
    this->dimension = 0;
}
