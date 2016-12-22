/* argument.c */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {

int a, b;

a = atoi(argv[1]);
b = atoi(argv[2]);


 int i,c;
 
 i = a;
 c = a;

 
 do {
 a = a%2;
 if ( a == 0 && c+1 < b) {
 c = c+1;
 printf("%d\n",c);
 a = c;
 }
 else if ( a != 0 && c+1 < b){
 c += 2;
 printf("%d\n",c);
 a = c;
 }
 else {
 break;
 }
 i++;
 } 
 while ( c < b);
 
 return EXIT_SUCCESS;
}
