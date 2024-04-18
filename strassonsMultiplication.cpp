#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> matrixAddition(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int n = A.size();
    vector<vector<int>> result(n, vector<int>(n, 0));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            result[i][j] = A[i][j] + B[i][j];
        }
    }

    return result;
}

vector<vector<int>> matrixSubtraction(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int n = A.size();
    vector<vector<int>> result(n, vector<int>(n, 0));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            result[i][j] = A[i][j] - B[i][j];
        }
    }

    return result;
}


vector<vector<int>> strassenMultiplication(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int n = A.size();

    if (n == 1) {
        vector<vector<int>> C(1, vector<int>(1, 0));
        C[0][0] = A[0][0] * B[0][0];
        return C;
    }

    
    
    vector<vector<int>> A11(n/2, vector<int>(n/2, 0));
    vector<vector<int>> A12(n/2, vector<int>(n/2, 0));
    vector<vector<int>> A21(n/2, vector<int>(n/2, 0));
    vector<vector<int>> A22(n/2, vector<int>(n/2, 0));
    vector<vector<int>> B11(n/2, vector<int>(n/2, 0));
    vector<vector<int>> B12(n/2, vector<int>(n/2, 0));
    vector<vector<int>> B21(n/2, vector<int>(n/2, 0));
    vector<vector<int>> B22(n/2, vector<int>(n/2, 0));

    
    for (int i = 0; i < n/2; ++i) {
        for (int j = 0; j < n/2; ++j) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + n/2];
            A21[i][j] = A[i + n/2][j];
            A22[i][j] = A[i + n/2][j + n/2];
        }
    }

   
    for (int i = 0; i < n/2; ++i) {
        for (int j = 0; j < n/2; ++j) {
            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + n/2];
            B21[i][j] = B[i + n/2][j];
            B22[i][j] = B[i + n/2][j + n/2];
        }
    }

    vector<vector<int>> P1 = strassenMultiplication(matrixAddition(A11, A22), matrixAddition(B11, B22));
    vector<vector<int>> P2 = strassenMultiplication(matrixAddition(A21, A22), B11);
    vector<vector<int>> P3 = strassenMultiplication(A11, matrixSubtraction(B12, B22));
    vector<vector<int>> P4 = strassenMultiplication(A22, matrixSubtraction(B21, B11));
    vector<vector<int>> P5 = strassenMultiplication(matrixAddition(A11, A12), B22);
    vector<vector<int>> P6 = strassenMultiplication(matrixSubtraction(A21, A11), matrixAddition(B11, B12));
    vector<vector<int>> P7 = strassenMultiplication(matrixSubtraction(A12, A22), matrixAddition(B21, B22));

    // Computing the result matrices
    vector<vector<int>> C11 = matrixAddition(matrixSubtraction(matrixAddition(P1, P4), P5), P7);
    vector<vector<int>> C12 = matrixAddition(P3, P5);
    vector<vector<int>> C21 = matrixAddition(P2, P4);
    vector<vector<int>> C22 = matrixAddition(matrixSubtraction(matrixAddition(P1, P3), P2), P6);

    // Combining the result matrices
    vector<vector<int>> C(n, vector<int>(n, 0));
    for (int i = 0; i < n/2; ++i) {
        for (int j = 0; j < n/2; ++j) {
            C[i][j] = C11[i][j];
            C[i][j + n/2] = C12[i][j];
            C[i + n/2][j] = C21[i][j];
            C[i + n/2][j + n/2] = C22[i][j];
        }
    }

    return C;
}

// Function to print a matrix
void printMatrix(const vector<vector<int>>& matrix) {
    for (int i=0;i<matrix.size();i++) {
        for (int j=0;j<matrix[0].size();j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    vector<vector<int>> A = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
    vector<vector<int>> B = {{17, 18, 19, 20}, {21, 22, 23, 24}, {25, 26, 27, 28}, {29, 30, 31, 32}};

    cout << "Matrix A:" << endl;
    printMatrix(A);

    cout << "\nMatrix B:" << endl;
    printMatrix(B);

    cout << "\nResult of Strassen's Multiplication:" << endl;
    vector<vector<int>> C = strassenMultiplication(A, B);
    printMatrix(C);

    return 0;
}
