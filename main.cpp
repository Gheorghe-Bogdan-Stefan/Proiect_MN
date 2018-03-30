#include "Utility.h"
#include "Cholesky.h"
#include "SolveCholesky.h"

int main() {
    ofstream output("input.txt", ios::app);

    // Write your text here for crypting and decrypting (max. 120 characters).
    char text[] = "'Secretul fericirii este sa faci ceva in acest sens' - John Burroughs ";

    cout << "Cholesky Method" << endl;
    int length = strlen(text);
    int sum = 1;
    int toAdd = 2;
    for (; sum < length;) {
        sum += toAdd;
        toAdd++;
    }
    toAdd--;
    sum = 2 * sum - toAdd;
    int dimension = sqrt(sum);

    Cholesky cholesky(text, dimension);

    SolveCholesky solveCholesky;
    solveCholesky.createMatrixForSolving(cholesky);

    try {
        solveCholesky.solveMe();
    } catch (string &error) {
        cerr << "Error: " << error << endl;
    }

    output <<  solveCholesky;

    output.close();
    return 0;
}
