#include <stdio.h>
#include <stdlib.h>

#define ZEILEN 	 13+2 // 13 Zeichen + 2 Sterne für Rahmen
#define SPALTEN  13+2 // 13 Zeichen + 2 Sterne für Rahmen

// Globales Array !! 
char feld[ZEILEN][SPALTEN];

void rahmen() {
  // Oberer und unterer Rand
  int s;
  int z;
  for ( s = 0; s < SPALTEN; s++){
    feld[0         ][s] = '*';
    feld[ZEILEN - 1][s] = '*';

  // Linker und rechter Rand
  for( z = 0; s < ZEILEN; z++){
    feld[z][0          ] = '*';
    feld[z][SPALTEN - 1] = '*';
   }
  // Innenbereich mit Leerzeichen
  for(z=1; z < ZEILEN; z++){
   for(s=1; s < SPALTEN; s++) {
    feld[z][s] = ' ';
    }
   }
  }
}

void ausgabe(){
 int z,s;
 for (z = 0; z < ZEILEN; z++){
 for (s = 0; s < SPALTEN; s++){
      printf("%c", feld[z][s]);
  }
  printf("\n");
 }

}

int main(void) {
 

 rahmen();
 ausgabe();
 

return EXIT_SUCCESS;
}
