#ifndef MY_USED_FUNCTIONS_H
#define MY_USED_FUNCTIONS_H


extern bool flag;


#include <iostream>
#include <cmath>
#include "STD_TYPES.h"



bool checkTheInput(bool flagVal);
f64 roundTheValues(f64 result);
void inverse(f32 matrixA[][10], f32 matrix[][10], u32 n, u32 rA, u32 columnA);
double determinant(f32 matrix[10][10],u32 n);
void getTheMatrices(f32 mat[][10], u32 r, u32 c);
void multiplication(f32 matrixA[][10], f32 matrixB[][10], u32 rA, u32 columnA, u32 rB, u32 columnB);





#endif
