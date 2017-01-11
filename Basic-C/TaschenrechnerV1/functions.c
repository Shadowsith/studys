#include <stdio.h>
#include <math.h>

#include "functions.h"
#include "main.h"


float add(float a,float b) {

printf("a + b\n");
fflush(stdout);
scanf("%f %f", &a, &b);
while ( getchar() != '\n');
float res = a + b;
return res;
}

float sub(float a,float b) {

printf("a - b\n");
fflush(stdout);
scanf("%f %f", &a, &b);
while ( getchar() != '\n');
float res = a - b;
return res;
}

float mult(float a,float b) {

printf("a * b\n");
fflush(stdout);
scanf("%f %f", &a, &b);
while ( getchar() != '\n');
float res = a * b;
return res;
}

float divt(float a,float b) {

printf("a / b\n");
fflush(stdout);
scanf("%f %f", &a, &b);
while( getchar() != '\n');
float res = a / b;
return res;
}

float square(float a,float b) {

printf("a^b\n");
fflush(stdout);
scanf("%f %f", &a, &b);
while( getchar() != '\n');
float res = pow(a,b);
return res;
}

float root(float a,float b) {

printf("b√a\n");
fflush(stdout);
scanf("%f %f", &a, &b);
while( getchar() != '\n');
float res = pow(a,1/b);
return res;
}
