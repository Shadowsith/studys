#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
 int a;
 int b = 3;
 printf("Gebe Int-Wert für a ein\n");
 scanf("%d", &a);
 char test[20] = "0";
 scanf("%s", test);
 printf("%s\n\n", test);
// test[20] = "Hallo";
 if ( a < b )
 { 
  strcpy(test, "Hallo");
  printf("%s\n", test);
 }
 else
 {
  strcpy ( test, "Tschüss");
  printf("%s\n", test);
 }
 printf("%s\n", test);
}
