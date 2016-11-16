#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "funktionen.h"

#define OK 0
#define ERR 1

int main(void) {
 int a;
 int b;

 a = add(2,4);
 b = mult(3, 5);
 printf("Die Summe ist %d und das Produkt ist %d\n", a, b);
 return OK;
}
