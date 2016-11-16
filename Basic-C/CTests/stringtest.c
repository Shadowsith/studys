#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
 char test[100];
 printf("Gebe 'k' oder 'a' ein!!\n");
 while(1)
  {
   scanf("%s", test);
   if ((strcmp (test, "k") == 0) || (strcmp (test, "a") == 0))
   { 
    break;
   }
   else
   {
   printf("Falsche Eingabe!\n");
   }
  }
 return 0;
}
