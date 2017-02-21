#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#include "main.h"
#include "functions.h"
#include "matrix.h"


int main(void) {

  double a,b,c;
  a = b = c = 0;
  int m, n;
  int** matrix;

  printf("\nWillkommen beim Taschenrechner V3\n");

  showasciicalculator();

  printf("Mit dem Kommando 'help' können Sie alle Funktionen sehen\n\n");

  char chooseoperation[20];
  char choosematrixoperation[20];

  do{
      scanf("%s",chooseoperation);
      while (getchar() != '\n');

      if (strcmp(chooseoperation,"help") == 0){
        
        showavailableoptions();
      }
      else if(strcmp(chooseoperation,"input") == 0){
           
        printf("a: ");
        a = input(a);
        printf("b: ");
        b = input(b);
      }
      else if(strcmp(chooseoperation,"+") == 0){
            
        c = add1(a,b);
      }
      else if(strcmp(chooseoperation,"-") == 0){
            
        c = sub1(a,b);
      }
      else if(strcmp(chooseoperation,"*") == 0){

        c = mul1(a,b);
      }
      else if(strcmp(chooseoperation,"/") == 0){

        c = div1(a,b);
      } 
      else if(strcmp(chooseoperation, "%") == 0){
            
        c = mod1(a,b);           
      }
      else if(strcmp(chooseoperation,"pow") == 0){
            
        c = pow1(a,b);
      }
      else if(strcmp(chooseoperation,"root") == 0){

        c = root1(a,b);
      }
      else if (strcmp(chooseoperation,"!") == 0){
        unsigned long int x, y;
        x = a;
        y = b;

        a = fac(x);
        printf("a!: %.f\n",a);
        b = fac(y);
        printf("b!: %.f\n",b);
      }
      else if (strcmp(chooseoperation,"binomial") == 0){
        unsigned long int n, k;

        n = a;
        k = b;
        c = binomial(n,k);
        printf("%.f über %.f ist: %.f\n", a, b, c);
      }
      else if(strcmp(chooseoperation,"M") == 0){
        printf("\nSie sind jetzt im Unterprogramm der Matrixberechnung\n");
        printf("Bitte geben Sie die erste Matrix vollständig ein um Berechnungen durchführen zu können:\n");
        m  = matrixrows(m);
        n  = matrixcols(n);
        matrix = newmatrix(matrix,m,n);
        printmatrix(matrix,m,n);
        matrixinput();
        
        do{
          
          scanf("%s",choosematrixoperation);
          while (getchar() != '\n');

          if (strcmp(choosematrixoperation,"Msk") == 0){

            matrix = scalarmultiplication(matrix,m,n);
          }
          else if (strcmp(choosematrixoperation,"print") == 0){
          
            printmatrix(matrix,m,n);
          }
          else if (strcmp(choosematrixoperation,"MA") == 0){

            matrix = matrixaddition(matrix,m,n);
          }
          else if (strcmp(choosematrixoperation,"MS") == 0){

            matrix = matrixsubtraction(matrix,m,n);
          }
          else if (strcmp(choosematrixoperation,"MM") == 0){

            matrix = matrixmultiplication(matrix,m,n);
          }
          else if (strcmp(choosematrixoperation,"MV") == 0){

          }
          else if (strcmp(choosematrixoperation,"MDet") == 0){

          }
          else if (strcmp(choosematrixoperation,"Mend") == 0){

            freematrix(matrix,m,n);
            printf("\nSie verlassen nun das Matrixunterprogramm!\n");
          }
          else printf("Diesen Matrixbefehl gibt es nicht!\n");
        }
        while (strcmp(choosematrixoperation,"Mend") != 0);
      
      }
      else if(strcmp(chooseoperation,"forward") == 0){
        a = c;
      }
      else if(strcmp(chooseoperation,"replace") == 0){
        char aorb[3];
        printf("Willst du a oder b ersetzen \?\n");
        printf("Druecke [a/b]: ");
        fflush(stdout);
        scanf("%s", aorb);
        while (getchar() != '\n');
            
        if (strcmp(aorb,"a") == 0){
          printf("Ersetzte a: ");
          a = input(a);
        }
        else if(strcmp(aorb,"b") == 0){
          printf("Ersetzte b: ");
          b = input(b);
        }
        else printf("Du hast eine falsche Eingabe gemacht, kein Wert wird ersetzt\n");
      }
      else if(strcmp(chooseoperation,"show") == 0){
              printf("Zwischenergebnis: %f\n", c);
      }
      else if(strcmp(chooseoperation,"clear") == 0){
              a = b = 0;
      }
      else if(strcmp(chooseoperation,"reset") == 0){
              a = b = c = 0;
      }

      else if(strcmp(chooseoperation,"end") == 0){
              break;
      }
      else if(strcmp(chooseoperation,"asciiart") == 0){
              showvirtualasciicalc(c);
      }
      else printf("Diesen Befehl gibt es nicht\n");
  }
  while(strcmp(chooseoperation,"end") != 0);

  return OK;

}
