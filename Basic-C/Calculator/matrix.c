#include <stdio.h>
#include <stdlib.h>

#include "main.h"

void matrixinput(void){

  printf("\nWelche Operationen möchten Sie nun mit Ihrer Matrix ausführen?\n");
  printf("Nutze: (Msk) für die Skalarmultiplikation der Matrix mit einer Zahl\n");
  printf("Nutze: (MA) für Addition mit einer gleichgroßen Matrix\n");
  printf("Nutze: (MS) für Matrixsubtraktion mit einer gleichgroßen Matrix\n");
  printf("Nutze: (MM) für Matrixmultiplikation mit einer gleichgroßen Matrix\n");
  printf("Nutze: (MV) für Multiplikation der Matrix mit einem Vektor\n");
  printf("Nutze: (MDet) für die Determinante deiner Matrix\n");
  printf("Nutze: (Mreset) um die Werte der Matrix auf 0 zu setzen\n");
  printf("Nutze: (Minput) um Größe und Werte deiner Matrix zu ändern\n");
  printf("Nutze: Mend um in das Hauptmenü zurückzukehren\n");
  fflush(stdout);

}

int matrixrows(int m){
  printf("Bitte gebe die Anzahl der Zeilen m deiner m x n Matrix an!\n");
  fflush(stdout);
  scanf("%d", &m);
  while (getchar() != '\n');
  return m;
}

int matrixcols(int n){

  printf("Bitte gebe die Anzahl der Spalten n deiner m x n Matrix an!\n");
  fflush(stdout);
  scanf("%d", &n);
  while (getchar() != '\n');
  return n;
}

int** memallocmatrix(int** matrix, int m, int n){
  int row, col;
 
  matrix = malloc(sizeof(int*) * m);
  if (matrix == NULL){
      printf("Kein Speicher verfügbar!\n");
      return 0;
  }

  for (row = 0; row < m; row++){
    matrix[row] = malloc(sizeof(int*) * n);
    if (matrix[row] == NULL){
        printf("Kein Speicher verfügbar!\n");
        return 0;
    }
  }
  
  return matrix;

}

int** freematrix(int** matrix, int m, int n){
  int row;

  for (row = 0; row < m; row++){
    free(matrix[row]);
  }

  free(matrix);
  return matrix;

}

int** newmatrix (int** matrix, int m, int n){

  int row, col;
  matrix = memallocmatrix(matrix,m,n);

  printf("\nNun fülle die mxn Matrix mit Zahlen!\n");

  for(row=0; row < m; row++){
    for(col=0; col < n; col++){
      printf("\tA[%d][%d] = ",row, col);
      scanf("%d", &matrix[row][col]);
    }
  }

   return matrix;

}

void printmatrix(int** matrix, int m, int n){
  int row, col;

  printf("\n");
    for(row=0; row < m; row++){
      printf("\t\n");
        for(col=0; col < n; col++){
          printf("%4d", matrix[row][col]);
        }
    }
  printf("\n");
}

// Scalar multiplication
int** scalarmultiplication(int** matrix, int m, int n){
  int row, col;
  int number;

  printf("Gebe die Zahl ein mit welcher du die Matrix multiplizieren willst: ");
  fflush(stdout);
  scanf("%d", &number);
  while (getchar() != '\n');
  
   for(row=0; row < m; row++){
    for(col=0; col < n; col++){
      matrix[row][col] *= number;
    }
  }
  
  printf("\nDas Ergebnis ist:");
  printmatrix(matrix,m,n);
  return matrix; 
}

int** matrixaddition(int** matrix, int m, int n){
  int row, col;
  int** addmatrix = memallocmatrix(addmatrix,m,n);

  printf("\nGebe nun die Matrix ein, die du zur bereits vorhandenen Matrix addieren willst!\n");
  addmatrix = newmatrix(addmatrix,m,n);
  printmatrix(addmatrix,m,n);
  
  for(row=0; row < m; row++){
    for(col=0; col < n; col++){
      matrix[row][col] += addmatrix[row][col];
    }
  }
  printf("\nDas Ergebnis ist: ");
  printmatrix(matrix,m,n);
  freematrix(addmatrix,m,n);
  return matrix;
}

int** matrixsubtraction(int** matrix, int m, int n){
  int row, col;
  int** submatrix = memallocmatrix(submatrix,m,n);

  printf("\nGebe nun die Matrix ein, die du zur bereits vorhandenen Matrix subtrahieren willst!\n");
  submatrix = newmatrix(submatrix,m,n);
  printmatrix(submatrix,m,n);
  
  for(row = 0; row < m; row++){
    for(col = 0; col < n; col++){
      matrix[row][col] -= submatrix[row][col];
    }
  }
  printf("\nDas Ergebnis ist: ");
  printmatrix(matrix,m,n);
  freematrix(submatrix,m,n);
  return matrix;
}

int** matrixmultiplication(int** matrix, int m, int n){
  int row, col, k;
  int** multmatrix = memallocmatrix(multmatrix,m,n);
  int** resultmatrix = memallocmatrix(resultmatrix,m,n);

  printf("\nGebe nun die Matrix ein, die du zur bereits vorhandenen Matrix multiplizieren willst!\n");
  multmatrix = newmatrix(multmatrix,m,n);
  printmatrix(multmatrix,m,n);

  for(row = 0; row < m; row++)
    for(col = 0; col < n; col++)
      for(k = 0; k < n; k++){
        resultmatrix[row][col] += matrix[row][k]*multmatrix[k][col];
      }
  
  freematrix(multmatrix,m,n);
  freematrix(matrix,m,n);

  printf("\nDas Ergebnis ist: ");
  printmatrix(resultmatrix,m,n);
  return resultmatrix;
}
