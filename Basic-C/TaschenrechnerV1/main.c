#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "main.h"
#include "functions.h"

int main(void) {

int chooseop;
float a = 0;
float b = 0;
float res = 0;

printf("Wähle eine Rechenart\n");
printf("1 = Addieren\n2 = Subtrahieren\n3 = Multiplizieren\n4 = Dividieren\n");
printf("5 = Quadrieren\n6 = Wurzel ziehen\n");
scanf("%d",&chooseop);

switch(chooseop) {
  case 1: res = add(a,b); 
          printf("%.3f\n",res);
  break;

  case 2: res = sub(a,b);
  break;

  case 3: res = mult(a,b);
  break;

  case 4: res = divt(a,b);
  break;

  case 5: res = square(a,b);
  break;

  case 6: res = root(a,b);
  break; 

  default:
  break;

}


return 0;
}
