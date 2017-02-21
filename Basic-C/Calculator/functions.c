#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "main.h"

//------maintainability-------

// An assciart which shows a simple calculator
void showasciicalculator(void){

  printf(" ---------- \n");
  printf("|     Erg. |\n");
  printf("|----------|\n");
  printf("|          |\n");
  printf("|7 8 9 + - |\n");
  printf("|4 5 6 / * |\n");
  printf("|1 2 3 =   |\n");
  printf("|__________|\n\n");
  fflush(stdout);

}

// A list of all options which can be used
void showavailableoptions(void){

  printf("\nNutze: (input) um zwei Startwerte (a & b) einzugeben\n");
  printf("Nutze: (+) (-) (/) (*) für die Standardrechnungen\n");
  printf("Nutze: (%%) für Modulo (Restwert)\n");
  printf("Nutze: (pow) für das Potenzieren, (root) für Wurzelziehen\n");
  printf("Nutze: (!) für Fakultät\n");
  printf("Nutze: (binomial) für Binomialkoeffizienten\n");
  printf("Nutze: (M) für Matrixberechnungen\n");
  printf("Nutze: (forward) für Weiterrechenen mit dem Zwischenergebnis (a<-Ergebnis)\n");
  printf("Nutze: (replace) um Wert a !oder! b zu verändern\n");
  printf("Nutze: (show) um das Zwischenergebnis zu sehen\n");
  printf("Nutze: (clear) um alles außer das Ergebnis auf 0 zu setzten\n");
  printf("Nutze: (reset) um alles auf 0 zu setzen\n");
  printf("Nutze: (asciiart) um den imaginären Rechner erscheinen zu lasen\n");
  printf("Nutze: (end) um den Taschenrechner zu beenden\n\n");
  fflush(stdout);

}

// Input for new numbers
double input(double a){
  
  fflush(stdout);
  scanf("%lf", &a);
  while ( getchar() != '\n');
  return a;

}

void showvirtualasciicalc(double a){

  printf(" ---------- \n");
  printf("|   %.3f  |\n", a);
  printf("|----------|\n");
  printf("|          |\n");
  printf("|7 8 9 + - |\n");
  printf("|4 5 6 / * |\n");
  printf("|1 2 3 =   |\n");
  printf("|__________|\n\n");
  fflush(stdout);

}


//-------calculation-----------

// addition
double add1(double a, double b){
  
  double c = a + b;
  printf("Ergebnis: %f\n", c);
  return c;
}

// subtraction
double sub1(double a, double b){
  
  double c = a - b;
  printf("Ergebnis: %f\n", c);
  return c;
}

// multiplication
double mul1(double a, double b){
  
  double c = a * b;
  printf("Ergebnis: %f\n", c);
  return c;
}

// division
double div1(double a, double b){
  
  double c = a / b;
  printf("Ergebnis: %f\n", c);
  return c;
}

// modulo
double mod1(double a, double b){
  
  int x = a;
  int y = b;
  int c = x % y;
  printf("Ergebnis: %d\n", c);
  return c;
}

// exponential
double pow1(double a, double b){
  
  double c = pow(a,b);
  printf("Ergebnis: %f\n", c);
  return c;
}

// n-th root
double root1(double a, double b){
  
  double c = pow(a,1/b);
  printf("Ergebnis: %f\n", c);
  return c;


}


//Factorial calculation
unsigned long int fac(unsigned long int a){
  if (a == 0){
    return 1;
  }
  else if( a > 20){
  
    printf("20! ist die Grenze\n");
    printf("Speichfehler!, Wert wird auf Eingabe zurückgesetzt\n");
    return a;
  }
  else return (a * fac(a - 1));
}

//Binomial calculation
unsigned long int binomial(unsigned long int n, unsigned long int k){

  unsigned long int bi;
  long int d = n-k;

  if (d < 0){
      return 0;
  }
  else if (n == 0 && k == 0){
      return 1;
  }
  else if (n == 1 && k == 0){
      return 1;
  }
  else{

      n = fac(n);
      k = fac(k);
      d = fac(d);

      return bi = n/(k*d);
  }
}

