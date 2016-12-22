#include<stdio.h>

int main(void) {

printf("Hallo beim Collartz Problem, bitte eine Zahl eingeben\n");

int n;
scanf("%d", &n);

while (n >= 1 || n == 0 ) {

    if (n > 0 && n != 1) {

    int nRest = n%2;

    if (nRest > 0) {
        printf("Es ist eine ungerade Zahl\n");
        n = 3*n+1;
        printf("%d\n", n);
        }   
    else {
     printf("Es ist eine gerade Zahl\n");
     n = n*0.5;
     printf("%d\n", n);
    }
    }
    else if (n == 1) {
    printf("Die Collartzfolge endet in einer Endlosschleife von 4,2,1...\n");
    printf("Aus Gründen der Performance wird das Programm vorzeitig beendet...\n");
    break;
    }
    else if (n == 0) {
    printf("Die eingegebene Zahl darf nicht 0 sein!\n");
    break;
    }
    
}

return 0;
}
