#include <stdio.h>
#include <stdlib.h>

// Function to check if a number is a power of two
int PowerOfTwo(int n) {
    return (n && !(n & (n - 1)));
}

// Function to input the matrix with random values
void matrixInput(int size, int mat[size][size]) {
    for (int row = 0; row < size; row++) {
        for (int col = 0; col < size; col++) {
            mat[row][col] = rand() % 10;  
        }
    }
}

// Function to print the matrix
void matrixPrint(int size, int mat[size][size]) {
    for (int row = 0; row < size; row++) {
        for (int col = 0; col < size; col++) {
            printf("%d ", mat[row][col]);
        }
        printf("\n");
    }
}

// Function to add two matrices
void addMatrix(int size, int A[size][size], int B[size][size], int C[size][size]) {
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            C[i][j] = A[i][j] + B[i][j];
}

// Function to subtract two matrices
void subMatrix(int size, int A[size][size], int B[size][size], int C[size][size]) {
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            C[i][j] = A[i][j] - B[i][j];
}

// Strassen's algorithm for matrix multiplication
void strassen(int size, int A[size][size], int B[size][size], int C[size][size]) {
    if (size == 1) {
        C[0][0] = A[0][0] * B[0][0]; 
        return;
    }

    int newSize = size / 2;
    int A11[newSize][newSize], A12[newSize][newSize], A21[newSize][newSize], A22[newSize][newSize];
    int B11[newSize][newSize], B12[newSize][newSize], B21[newSize][newSize], B22[newSize][newSize];
    int C11[newSize][newSize], C12[newSize][newSize], C21[newSize][newSize], C22[newSize][newSize];
    int M1[newSize][newSize], M2[newSize][newSize], M3[newSize][newSize], M4[newSize][newSize];
    int M5[newSize][newSize], M6[newSize][newSize], M7[newSize][newSize];
    int temp1[newSize][newSize], temp2[newSize][newSize];

    // Splitting matrices into sub-matrices
    for (int i = 0; i < newSize; i++) {
        for (int j = 0; j < newSize; j++) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + newSize];
            A21[i][j] = A[i + newSize][j];
            A22[i][j] = A[i + newSize][j + newSize];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + newSize];
            B21[i][j] = B[i + newSize][j];
            B22[i][j] = B[i + newSize][j + newSize];
        }
    }

    // Calculating M matrices
    addMatrix(newSize, A11, A22, temp1);
    addMatrix(newSize, B11, B22, temp2);
    strassen(newSize, temp1, temp2, M1);

    addMatrix(newSize, A21, A22, temp1);
    strassen(newSize, temp1, B11, M2);

    subMatrix(newSize, B12, B22, temp1);
    strassen(newSize, A11, temp1, M3);

    subMatrix(newSize, B21, B11, temp1);
    strassen(newSize, A22, temp1, M4);

    addMatrix(newSize, A11, A12, temp1);
    strassen(newSize, temp1, B22, M5);

    subMatrix(newSize, A21, A11, temp1);
    addMatrix(newSize, B11, B12, temp2);
    strassen(newSize, temp1, temp2, M6);

    subMatrix(newSize, A12, A22, temp1);
    addMatrix(newSize, B21, B22, temp2);
    strassen(newSize, temp1, temp2, M7);

    // Calculating C matrices
    addMatrix(newSize, M1, M4, temp1);
    subMatrix(newSize, temp1, M5, temp2);
    addMatrix(newSize, temp2, M7, C11);

    addMatrix(newSize, M3, M5, C12);
    addMatrix(newSize, M2, M4, C21);

    subMatrix(newSize, M1, M2, temp1);
    addMatrix(newSize, temp1, M3, temp2);
    addMatrix(newSize, temp2, M6, C22);

    // Combining sub-matrices into result matrix C
    for (int i = 0; i < newSize; i++) {
        for (int j = 0; j < newSize; j++) {
            C[i][j] = C11[i][j];
            C[i][j + newSize] = C12[i][j];
            C[i + newSize][j] = C21[i][j];
            C[i + newSize][j + newSize] = C22[i][j];
        }
    }
}

int main() {
    int n;

    printf("Enter the size of the matrix: ");
    scanf("%d", &n);

    // Check if the matrix size is a power of two
    if (!PowerOfTwo(n)) {
        printf("Matrix size must be a power of two!\n");
        return 1;
    }

    // Initialize matrices
    int A[n][n], B[n][n], C[n][n];

    // Matrix input from random number generator
    printf("Matrix A Input from random number generator:\n");
    matrixInput(n, A);

    printf("Matrix B Input from random number generator:\n");
    matrixInput(n, B);

    // Print matrices A and B
    printf("Matrix A:\n");
    matrixPrint(n, A);

    printf("Matrix B:\n");
    matrixPrint(n, B);

    // Perform Strassen multiplication
    strassen(n, A, B, C);

    // Print the resultant matrix C
    printf("Resultant Matrix Using Strassen Multiplication:\n");
    matrixPrint(n, C);

    return 0;
}
