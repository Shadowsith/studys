#include <stdio.h>
#include <string.h>

int stringLaenge(char string[]) {
     
   int i = 0;
   int a = 0;
   do {
   
   a = string[i];
    

   i++;
   }
   while ( a != 0 );
   return i-1;
}

int main(void) {

char eingabe[] = " ";
int b;
int c;

scanf("%s",eingabe);

while (getchar() != '\n');

b = stringLaenge(eingabe);
c = strlen(eingabe);


printf("%d %d\n",b,c);
fflush(stdout);

return 0;

}
