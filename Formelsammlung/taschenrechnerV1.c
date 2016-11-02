#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

#define OK 0

int main(void)
{
  float a;
  float b;
  float c;
  int chooseoperator;
  printf("\n\nWillkommen in meinem kleinen Taschenrechnerprogramm\n");
  printf("Hier können bis zu 2 Zahlen miteinander verrechnet werden!\n\n");
  printf("Wählen sie einen der angezeigten mathematischen Operatoren um fortzufahren!\n");
  printf("1 für Addition\n2 für Subtraktion\n3 für Multiplikation\n4 für Division\n5 für potenzieren\n6 für radizieren\n");
  printf("Beachte, dass du für Gleitkommawerte hinter die Zahlen einen Punkt '.' setzen musst!\n");
  fflush(stdout);
  //scanf("%[^0-9]%f",  , &chooseoperator);
  while (scanf("%d", &chooseoperator))
  { 
   if (chooseoperator == 1)
   {
    printf("Du kannst nun 2 Zahlen addieren\n"); 
    printf("Gebe nun für Zahl a und b eine Zahl ein\n");
    fflush(stdout);
    scanf("%f %f",&a, &b);
    printf("Du rechnest nun %.2f + %.2f\n", a, b);
    c = a + b;
    break;
   }
    else
    {
     if (chooseoperator == 2)
     {
      printf("Du kannst nun Zahl a durch Zahl b subtrahieren\n"); 
      printf("Gebe nun für Zahl a und b eine Zahl ein\n");
      fflush(stdout);
      scanf("%f %f", &a, &b);
      printf("Du rechnest nun %.2f - %.2f\n", a, b);
      c = a - b;
      break;
     }
      else
      {
       if (chooseoperator == 3)
       {
        printf("Du kannst nun 2 Zahlen multiplizieren\n"); 
        printf("Gebe nun für Zahl a und b eine Zahl ein\n");
        fflush(stdout);
        scanf("%f %f", &a, &b);
        printf("Du rechnest nun %.2f * %.2f\n", a, b);
        c = a * b;
	break;
       }
        else
	{
	 if (chooseoperator == 4)
	 {
	  printf("Du kannst nun Zahl b von Zahl a dividieren\n"); 
          printf("Gebe nun für Zahl a und b eine Zahl ein\n");
          fflush(stdout);
          scanf("%f %f", &a, &b);
          printf("Du rechnest nun %.2f / %.2f\n", a, b);
	  if (b == 0)
	  { 
	   printf("Du darfst nicht durch 0 Teilen!\nStarte das Programm erneut!\n");
	   return OK;
	  }
          c = a / b;
	  break;
	 }
	  if (chooseoperator == 5)
	  {
 	   printf("Du kannst nun die Potenz b von Zahl a berechnen\n"); 
           printf("Gebe nun für Zahl a und b eine Zahl ein\n");
           fflush(stdout);
           scanf("%f %f", &a, &b);
           printf("Du rechnest nun %.2f^%.2f\n", a, b);
           c = pow(a,b);
	   break;
	  } 
           else
	   {
	    if (chooseoperator == 6)
	    {
	     printf("Du kannst nun die b-te Wurzel von Zahl a berechnen\n"); 
             printf("Gebe nun für Zahl a und b eine Zahl ein\n");
             fflush(stdout);
             scanf("%f %f", &a, &b);
             printf("Du rechnest nun %.2f-te√%.2f\n", b, a);
             c = pow(a,1/b);
	     break;
	    }
	     else 
	     {
	      printf("Du hast einen falschen Wert eingegeben!\nWiederhole deine Eingabe!\n");
	      fflush(stdout);
	      scanf("%d", &chooseoperator);
	     } 
	  }
       }
      }
     }
    } 
  printf("Das Ergebnis ist %.3f\n", c);
  return OK;
}
 


