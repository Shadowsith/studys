#ifndef _MATRIX_H
#define _MATRIX_H

extern int   matrixrows(int m);
extern int   matrixcols(int n);
extern int** memallocmatrix(int** matrix, int m, int n);
extern int** freematrix(int** matrix, int m, int n);
extern int** newmatrix(int** matrix, int m, int n);
extern void  matrixinput();
extern void  printmatrix(int** matrix, int m, int n);
extern int** scalarmultiplication(int** matrix, int m, int n);
extern int** matrixaddition(int** matrix, int m, int n);
extern int** matrixsubtraction(int** matrix, int m, int n);
extern int** matrixmultiplication(int** matrix, int m, int n);

#endif  // #define _MATRIX_H
