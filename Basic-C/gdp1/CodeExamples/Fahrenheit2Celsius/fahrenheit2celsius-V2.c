/* Drucke Umrechnungstabelle von Fahrenheit nach Celsius */
/* Richtige Berechnung: 5/9.0 rechnet float              */
/* Falsche  Berechnung: 5/9   rechnet int                */

#include <stdio.h>
#define OK 0

int main() {
    int fahrenheitWert;

    printf("Grad Fahrenheit\tGrad Celsius\n");
    for(fahrenheitWert = 0;
        fahrenheitWert <= 300;
        fahrenheitWert += 20){
        int celsiusWert;
        /* Achtung: Zahlformat                         */
        /* 5/9 ergibt ganzzahlige Rechnung             */
        /* Alternative: 5 * (fahrenheitWert - 32) / 9; */
        celsiusWert = 5/9.0 * (fahrenheitWert - 32);

        /* Formatierung: %10d druckt rechtsbuendig     */
        printf("%10d\t%7d\n", fahrenheitWert,celsiusWert);
    }
    return OK;
}
