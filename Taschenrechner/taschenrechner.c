#include <math.h>
#include <stdio.h>
#include <string.h>

// Texte

char calctext2[30] = "Du kannst nun 2 Zahlen";
char add1text[15]  = "addieren";
char sub1text[15]  = "subtrahieren";
char divs1text[15] = "dividieren";
char modulo1text[15]   = "dividieren mit Rest";
char mult1text[15] = "multiplizieren";
char multiply1text[15] = "potenzieren";
char rootext1text[15] = "radizieren";


int welcome () {
  printf("\n\nWillkommen in meinem kleinen Taschenrechnerprogramm\n");
  printf("Hier können bis zu 2 Zahlen miteinander verrechnet werden!\n\n");
  printf("Wählen sie einen der angezeigten mathematischen Operatoren um fortzufahren!\n");
  printf("1 für Addition\n2 für Subtraktion\n3 für Multiplikation\n4 für Division\n5 für potenzieren\n6 für radizieren\n");
  printf("Beachte, dass du für Gleitkommawerte hinter die Zahlen einen Punkt '.' setzen musst!\n");
  fflush(stdout);
  return 0;
}

int putoperator () {


int textadd1 () {
  printf("%s %s.\n", calctext2, add1text);
  return 0;
}
  
int textsub1 () {
  printf("%s %s.\n", calctext2, sub1text);
  return 0;
}

int textdivs1 () {
  printf("%s %s.\n", calctext2, divs1text);
  return 0;
}

int textmodulo1 () {
  printf("%s %s.\n", calctext2, modulo1text);

int textmult1() {
  printf("%s %s.\n", calctext2, mult1text);
  return 0;
}

int textmultiply1() {
  printf("%s %s.\n", calctext2, multiply1text);
  return 0;
}

int textrootext1 () {
  printf("%s %s.\n", calctext2, rootext1text);
  return 0;
}

// Berechnungen
int add1( float a, float b) {
         return a + b;
}

int sub1 (float a, float b) {
         return a - b;
}

int mult1 (float a, float b) {
          return a * b;
}

int divs1  (float a, float b) {
          return a/b;
}

int modulo1 (int a, int b) {
            return a%b;
}

int multiply1 (float a, float b) {
            return pow(a,b);
}

int rootext1 (float a, float b) {
            return pow(a,1/b);
}


