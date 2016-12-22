#include <stdio.h>
#include <stdlib.h>

#define ZEILEN 	 13+2 // 13 Zeichen + 2 Sterne für Rahmen
#define SPALTEN  13+2 // 13 Zeichen + 2 Sterne für Rahmen


void rahmen(char einfeld[ZEILEN][SPALTEN]) {
  // Oberer und unterer Rand
  int s;
  int z;
  for ( s = 0; s < SPALTEN; s++){
    einfeld[0         ][s] = '*';
    einfeld[ZEILEN - 1][s] = '*';
   }
  // Linker und rechter Rand
  for( z = 0; s < ZEILEN; z++){
    einfeld[z][0          ] = '*';
    einfeld[z][SPALTEN - 1] = '*';
   }
  // Innenbereich mit Leerzeichen
  for(z=1; z < ZEILEN; z++){
   for(s=1; s < SPALTEN; s++) {
    einfeld[z][s] = ' ';
    }
   }
  }

void ausgabe(char einfeld[ZEILEN][SPALTEN] ){
 int z,s;
 for (z = 0; z < ZEILEN; z++){
 for (s = 0; s < SPALTEN; s++){
      printf("%c", einfeld[z][s]);
  }
  printf("\n");
 }

}

int main(void) {
 
// Lokales Array !! 
char feld[ZEILEN][SPALTEN];

 rahmen(feld);
 ausgabe(feld);
 

return EXIT_SUCCESS;
}
