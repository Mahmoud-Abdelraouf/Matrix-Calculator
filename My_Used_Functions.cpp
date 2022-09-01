#include "My_Used_Functions.h"
#include "STD_TYPES.h"
using namespace std;
/******************************Fun1******************************/
void getTheMatrices(f32 mat[][10], u32 r, u32 c)
{
    for (u32 row = 0; row < r; row++)
    {
        for (u32 col = 0; col < c; col++)
        {
            cin >> mat[row][col];
            if (cin.fail())
            {
                cout << "The operation you chose is invalid for the given matrices.\n";
                flag = 0;
            }
            cin.clear();
            cin.ignore();


        }
    }
}
/******************************Fun2******************************/
bool checkTheInput(bool flagVal)
{
    flagVal = 1;
    if (cin.fail())
    {
        cout << "The operation you chose is invalid for the given matrices.\n";
        flagVal = 0;
    }
    cin.clear();
    cin.ignore();
    return flagVal;
}
/******************************Fun3******************************/
f64 roundTheValues(f64 result)
{
    f64 approximator = 0;
    approximator = result - (s64)(result);
    if (result < 0)
    {
        if (approximator <= -0.5)
        {
            return (result - approximator - 1);
        }
        else
        {
            return (result - approximator);
        }
    }
    else
    {
        if (approximator >= 0.5)
        {
            return (result - approximator + 1);
        }
        else
        {
            return (result - approximator);
        }
    }
}
/******************************Fun4******************************/
f64 determinant(f32 matrix[10][10], u32 n)
{
    f64 det = 0;
    f32 submatrix[10][10]; // the exact (n-1) matrix
    if (n == 1)
        return matrix[0][0];
    if (n == 2)
        return ((matrix[0][0] * matrix[1][1]) - (matrix[1][0] * matrix[0][1]));
    else
    {
        // x >> the no of the canceled row in each iteration
        for (u32 x = 0; x < n; x++)
        {
            int tempi = 0;
            // i >> the no of the next row(r+1)which used to detect the (n-1) matrix which appear after canceled the first row(r)
            for (u32 i = 1; i < n; i++)
            {
                u32 tempj = 0;
                // to detect the exact column of the matrix(n-1)
                for (u32 j = 0; j < n; j++)
                {
                    if (j == x) // because when we calculate the determinant we cancel the row and the calumn which we stand on,so we should ignore its value
                        continue;
                    //to detect the (n-1) matrix until reach to matrix 2X2 of each
                    submatrix[tempi][tempj] = matrix[i][j];
                    tempj++;
                }
                tempi++;
            }
            // the general form to calculate the determinant
            det += (pow(-1, x) * matrix[0][x] * determinant(submatrix, n - 1));
        }
    }
    return det;
}
/******************************Fun5******************************/
void multiplication(f32 matrixA[][10], f32 matrixB[][10], u32 rA, u32 columnA, u32 rB, u32 columnB)
{
    if (columnA != rB)
    {
        flag = 0;
        cout << "The operation you chose is invalid for the given matrices.\n";
    }
    else
    {
        f32 mult = 0;
        for (u32 row = 0; row < rA; row++)
        {
            for (u32 col = 0; col < columnB; col++)
            {
                mult = 0;
                for (u32 k = 0; k < columnA; k++)
                {
                    mult += (matrixA[row][k] * matrixB[k][col]);
                }
                cout << roundTheValues(mult) << " ";
            }
            cout << "\n";
        }
    }
}

/******************************Fun6******************************/
void inverse(f32 matrixA[][10], f32 matrix[][10], u32 n, u32 rA, u32 columnA)
{
    f32 adj[10][10], result[10][10], det = 0;
    f32 submatrix[10][10]; // the store exact (n-1) matrix
    det = (determinant(matrix, n));
    for (u32 f = 0; f < n; f++)
    {
        // x >> the no of the canceled row in each iteration
        for (u32 x = 0; x < n; x++)
        {
            u32 tempi = 0;
            // i >> the no of the next row(r+1)which used to detect the (n-1) matrix which appear after canceled the first row(r)
            for (u32 i = 0; i < n; i++)
            {
                if (i == f)
                    continue;
                u32 tempj = 0;
                // to detect the exact column of the matrix(n-1)
                for (u32 j = 0; j < n; j++)
                {
                    if (j == x) // because when we calculate the determinant we cancel the row and the calumn which we stand on,so we should ignore its value
                        continue;
                    //to detect the (n-1) matrix until reach to matrix 2X2 of each
                    submatrix[tempi][tempj] = matrix[i][j];
                    tempj++;
                }
                tempi++;
            }
            // cout<<roundTheValues((1 / determinant(matrix, n)) * determinant(submatrix, n - 1))<<" ";
            adj[f][x] = pow(-1, f + x) * (1 / det) * determinant(submatrix, n - 1);
        }
    }
    // to transposition the adj
    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < n; col++)
        {
            result[row][col] = adj[col][row];
        }
    }
    multiplication(matrixA, result, rA, columnA, n, n);

}
