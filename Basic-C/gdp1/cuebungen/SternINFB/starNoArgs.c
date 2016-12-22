#include <stdio.h>
#include <stdlib.h>

#define ZEILEN 	 39+2 // 13 Zeichen + 2 Sterne für Rahmen
#define SPALTEN  39+2 // 13 Zeichen + 2 Sterne für Rahmen


void rahmen(char einfeld[][SPALTEN]) {
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
  for(z=1; z < ZEILEN - 1; z++){
   for(s=1; s < SPALTEN - 1; s++){
    einfeld[z][s] = ' ';
    }
   }
}

void arm(char einfeld[][SPALTEN], int z0, int s0, int dz, int ds){

 int cur_z = z0;
 int cur_s = s0;
 char code = 'A';

 // Schleife: solange wir nicht beim '*' (Rand) ankommen
 while(einfeld[cur_z][cur_s] != '*'){
    einfeld[cur_z][cur_s] = code;
    code++;
    cur_z += dz; // cur_z = cur_z + dz
    cur_s += ds; // cur_s = cur_s + ds
    }
}

void stern(char einfeld[][SPALTEN], int z0, int s0) {
  arm(einfeld, z0, s0,-1, -1); // links oben
  arm(einfeld, z0, s0, -1, 0);  // oben
  arm(einfeld, z0, s0, -1, 1);
  arm(einfeld, z0, s0,  0, 1);
  arm(einfeld, z0, s0,  1, 1);
  arm(einfeld, z0, s0,  1, 0);
  arm(einfeld, z0, s0,  1, -1);
  arm(einfeld, z0, s0, 0, -1);
}

void ausgabe(char einfeld[][SPALTEN] ){
 int z;
 int s;
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
 stern(feld, (ZEILEN)/2, (SPALTEN)/2); // (13+2)/2
 ausgabe(feld);
 

return EXIT_SUCCESS;
}
