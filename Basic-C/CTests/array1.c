#include <stdio.h>

#define N 2
#define M 2

void matadd(int a[][N], int b[][N]) {
int sum[M][N];
int m,n;

for ( m = 0; m < N; m++) { 
     for ( n = 0; n < N; n++) {
     sum[n][m] = a[n][m] + b[n][m];
     }
}


int i,j;
for (i = 0; i < N; i++) {
    for(j = 0; j < N; j++) {
       printf("%d", sum[i][j]);
    }
    printf("\n");
  }

return;
}

void matmult(int a[][N], int b[][N]) {
int mul[M][N];
int m,n;
/*
mul[0][0] = a[0][0]*b[0][0]+a[0][1]*b[1][0];

mul[0][1] = a[0][0]*b[0][1]+a[0][1]*b[1][1];

mul[1][0] = a[1][0]*b[0][0]+a[1][1]*b[1][0];

mul[1][1] = a[1][0]*b[0][1]+a[1][1]*b[1][1];
*/

for ( m = 0; m < N; m++) {
    for ( n = 0; n < N; n++) {
    mul[n][m] = a[n][m]*b[m][n];
    }
    }   

int i,j;
for (i = 0; i < N; i++) {
    for(j = 0; j < N; j++) {
       printf("%d", mul[i][j]);
    }
    printf("\n");
  }


return;
}


void printarray (int field[][N], int LCount, int CCount) {
int i,j;
for (i = 0; i < LCount; i++) {
    for(j = 0; j < CCount; j++) {
       printf("%d", field[i][j]);
    }
    printf("\n");
  }
 return;
}


int main(void) {

int array0[M][N] = { 
    {4,3},
    {2,1}
   };

int array1[M][N] = {
    {4,3},
    {1,2},
   };

//printarray(array0,N,N);
//printf("+\n");
//printarray(array1,N,N);
//printf("=\n");
//matadd(array0,array1);
matmult(array0,array1);


return 0;
}
