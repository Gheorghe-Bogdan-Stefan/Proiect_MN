//
// Created by krucisatorul on 12/1/17.
//

#include "Cholesky.h"
#include "Utility.h"


Cholesky::Cholesky() {
    this->matrixA = NULL;
    this->matrixL = NULL;
    this->matrixLTranspose = NULL;
    dimension = 0;
}

Cholesky::~Cholesky() {
    for (int i = 0; i < this->dimension; i++) {
        delete[] this->matrixL[i];
        delete[] this->matrixLTranspose[i];
        delete[] this->matrixA[i];
    }
    // delete[] this->matrixL;
    // delete[] this->matrixLTranspose;
    // delete this->matrixA;
    this->matrixL = NULL;
    this->matrixLTranspose = NULL;
    this->matrixA = NULL;

}

Cholesky::Cholesky(char text[], int dimension) {
    this->dimension = dimension;
    this->matrixA = new int* [this->dimension];
    this->matrixL = new int* [this->dimension];
    this->matrixLTranspose = new int* [this->dimension];
    for (int i = 0; i < this->dimension; i++) {
        this->matrixA[i] = new int [this->dimension];
        this->matrixL[i] = new int [this->dimension];
        this->matrixLTranspose[i] = new int [this->dimension];
        for (int j = 0; j < this->dimension; j++) {
            this->matrixA[i][j] = 0;
            this->matrixL[i][j] = 0;
            this->matrixLTranspose[i][j] = 0;
        }
    }

    int length = strlen(text);
    int k = 0;
    for (int i = 0; i < dimension; i++) {
        for (int j = 0; j < dimension; j++) {
            if (j <= i && k < length) {
                this->matrixL[i][j] = text[k];
                ++k;
            } else {
                matrixL[i][j] = 0;
            }
        }
    }

    for (int i = 0; i < dimension; i++) {
        for (int j = 0; j < dimension; j++) {
            matrixLTranspose[i][j] = matrixL[j][i];
        }
    }

    for (int i = 0; i < dimension; i++) {
        for (int j = 0; j < dimension; j++) {
            for (k = 0; k < dimension; k++) {
                matrixA[i][j] += matrixL[i][k] * matrixLTranspose[k][j];
            }
        }
    }
    cout << (*this);
}

int Cholesky::getDimension() const {
    return dimension;
}

ostream &operator<<(ostream &os, const Cholesky &cholesky) {
    os << "Crypted Information: " << endl;
    os << "Matrix L: " << endl;
    for (int i = 0; i < cholesky.dimension; i++) {
        for (int j = 0; j < cholesky.dimension; j++) {
            os << cholesky.matrixL[i][j] << ' ';
        }
        os << endl;
    }
    os << "Matrix L Transpose: " << endl;
    for (int i = 0; i < cholesky.dimension; i++) {
        for (int j = 0; j < cholesky.dimension; j++) {
            os << cholesky.matrixLTranspose[i][j] << ' ';
        }
        os << endl;
    }
    os << "Dimension: " << endl;
    os << cholesky.dimension << endl;
    os << "Matrix A: " << endl;
    for (int i = 0; i < cholesky.dimension; i++) {
        for (int j = 0; j < cholesky.dimension; j++) {
            os << cholesky.matrixA[i][j] << ' ';
        }
        os << endl;
    }
    return os;
}

int Cholesky::getElementFromMatrixA(int i, int j) {
    return (this->matrixA[i][j]);
}
