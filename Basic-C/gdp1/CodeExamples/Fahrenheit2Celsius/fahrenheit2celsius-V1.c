/* Drucke Umrechnungstabelle von Fahrenheit nach Celsius */
/* Falsche Berechnung: 5/9 rechnet int                   */
#include <stdio.h>
#define OK 0

int main() {
    int fahrenheitWert;
    /* fahrenheiWert = 0; */
    fahrenheitWert = 0;

    printf("Grad Fahrenheit\tGrad Celsius\n");
    /* while (fahrenheitWert <= 300) { */ 
    while (fahrenheitWert <= 300) {
        int celsiusWert;
        /* celsiusWert = 5/9 * (fahrenheitWert-32);    */
        /* Achtung: Zahlformat                         */
        /* 5/9 ergibt ganzzahlige Rechnung             */
        celsiusWert = 5/9 * (fahrenheitWert - 32);

        /* Ausgabe fahrenheitWert celsiusWert; */
        printf("%d\t%d\n", fahrenheitWert,celsiusWert);
        /* fahrenheitWert = fahrenheitWert + 20; */
        fahrenheitWert = fahrenheitWert + 20;
    }
    return OK;
}
