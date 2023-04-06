#include "My_Used_Functions.h"
#include "STD_TYPES.h"
using namespace std;



bool flag = 1;


int main()
{
    u32 rA = 0, columnA = 0, rB = 0, columnB = 0, noOfOperation = 0;
    f32 matrixA[10][10], matrixB[10][10];
    //get the size of the matrix A
    cout << "Please enter dimensions of Matrix A:\n";
    cin >> rA >> columnA;
    // to check the input of the size of the matrix A
    if (checkTheInput(1) == 0)
    {
        return 0;
    }
    //get the size of the matrix B
    cout << "Please enter dimensions of Matrix B:\n";
    cin >> rB >> columnB;
    // to check the input of the size of the matrix B
    if (checkTheInput(1) == 0)
    {
        return 0;
    }
    // get the value of the matrix A
    cout << "Please enter values of Matrix A:\n";
    getTheMatrices(matrixA, rA, columnA);
    if (flag == 0)
    {
        return 0;
    }
    // get the value of the matrix B
    cout << "Please enter values of Matrix B:\n";
    getTheMatrices(matrixB, rB, columnB);
    if (flag == 0)
    {
        return 0;
    }
    do
    {
        cout << "Please choose operation type(1: A+B, 2: A-B, 3: AxB, 4: A*inverse(B), 5: |A|, 6: |B|, 7: quit):\n";
        cin >> noOfOperation;
        // check the value of the no Of Operation
        if (checkTheInput(1) == 0)
        {
            return 0;
        }
        switch (noOfOperation)
        {
            //to Add
        case 1:
        {
            if (rA == rB && columnA == columnB)
            {
                for (u32 row = 0; row < rA; row++)
                {
                    for (u32 col = 0; col < columnA; col++)
                    {
                        cout << roundTheValues(matrixA[row][col] + matrixB[row][col]) << " ";
                    }
                    cout << "\n";
                    noOfOperation = 1;
                }

            }
            else
            {
                cout << "The operation you chose is invalid for the given matrices.\n";
            }
            break;
        }
        //to Subtract
        case 2:
        {
            if (rA == rB && columnA == columnB)
            {
                for (u32 row = 0; row < rA; row++)
                {
                    for (u32 col = 0; col < columnA; col++)
                    {
                        cout << roundTheValues(matrixA[row][col] - matrixB[row][col]) << " ";
                    }
                    cout << "\n";
                    noOfOperation = 2;
                }

            }
            else
            {
                cout << "The operation you chose is invalid for the given matrices.\n";
            }
            break;
        }
        // to multiplication
        case 3:
        {
            multiplication(matrixA, matrixB, rA, columnA, rB, columnB);
            noOfOperation = 3;
            break;
        }
        case 4:
        {
            if (rB == columnB && determinant(matrixB, rB) != 0)
            {
                inverse(matrixA, matrixB, rB, rA, columnA);
            }
            else
            {
                cout << "The operation you chose is invalid for the given matrices.\n";
            }
            noOfOperation = 4;
            break;
        }
        case 5:
        {
            if (rA == columnA)
            {
                cout << roundTheValues(determinant(matrixA, rA)) << "\n";
            }
            else
            {
                cout << "The operation you chose is invalid for the given matrices.\n";
            }
            noOfOperation = 5;
            break;
        }
        case 6:
        {
            if (rB == columnB)
            {
                cout << roundTheValues(determinant(matrixB, rB)) << "\n";
            }
            else
            {
                cout << "The operation you chose is invalid for the given matrices.\n";
            }
            noOfOperation = 6;
            break;
        }
        //to exit
        case 7:
        {
            cout << "Thank you!\n";
            noOfOperation = 7;
            break;
        }
        default:
        {
            cout << "The operation you chose is invalid for the given matrices.\n";
            break;
        }
        }
    } while (noOfOperation != 7);
    
    while(1);
    
    return 0;
}
/**************************************the end of the main***************************************************/

