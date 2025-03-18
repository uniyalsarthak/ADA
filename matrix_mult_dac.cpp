#include<bits/stdc++.h>
using namespace std;

typedef vector<vector<int>> Matrix;     //used to declare a 2d matrix

// Function to add two matrices
Matrix add(Matrix A, Matrix B) 
{
    int n = A.size();
    Matrix C(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
    return C;
}

// Function to multiply matrices using Divide and Conquer
Matrix multiply(Matrix A, Matrix B) 
{
    int n = A.size();
    Matrix C(n, vector<int>(n, 0));

    if (n == 1) 
    {
        C[0][0] = A[0][0] * B[0][0];
        return C;
    }

    int half = n / 2;
    Matrix A11(half, vector<int>(half)), A12(half, vector<int>(half)), 
           A21(half, vector<int>(half)), A22(half, vector<int>(half));
    Matrix B11(half, vector<int>(half)), B12(half, vector<int>(half)), 
           B21(half, vector<int>(half)), B22(half, vector<int>(half));

    for (int i = 0; i < half; i++)
    {
        for (int j = 0; j < half; j++) 
        {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + half];
            A21[i][j] = A[i + half][j];
            A22[i][j] = A[i + half][j + half];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + half];
            B21[i][j] = B[i + half][j];
            B22[i][j] = B[i + half][j + half];
        }
    }

    Matrix C11 = add(multiply(A11, B11), multiply(A12, B21));
    Matrix C12 = add(multiply(A11, B12), multiply(A12, B22));
    Matrix C21 = add(multiply(A21, B11), multiply(A22, B21));
    Matrix C22 = add(multiply(A21, B12), multiply(A22, B22));

    // Combining results
    for (int i = 0; i < half; i++)
    {
        for (int j = 0; j < half; j++) 
        {
            C[i][j] = C11[i][j];
            C[i][j + half] = C12[i][j];
            C[i + half][j] = C21[i][j];
            C[i + half][j + half] = C22[i][j];
        }
    }
    return C;
}

void printMatrix(Matrix C) 
{
    for(int i=0;i<C.size();i++)
    {
        for(int j=0;j<C[0].size();j++)
        {
            cout<<C[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main() 
{
    int n = 4; // Matrix size must be power of 2
    
    Matrix A = {{1, 2,3,4}, {3, 4,5,6},{1, 2,3,4}, {3, 4,5,6}};
    Matrix B = {{5, 6,7,8}, {7, 8,9,1},{5, 6,7,8}, {7, 8,9,1}};
    Matrix C = multiply(A, B);
    cout << "Product Matrix:"<<endl;
    printMatrix(C);
}
