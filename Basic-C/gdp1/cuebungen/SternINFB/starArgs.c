#include <stdio.h>
#include <stdlib.h>

#define ZEILEN 13+2      // 13 Zeilen für das Bild + 2 Zeilen für Sternenrahmen
#define SPALTEN 13+2      // 13 Spalten für das Bild + 2 Spalten für Sternenrahmen

// Funktionen
void rahmen(char einfeld[][SPALTEN]) {
  int s;
  int z;
  
  // Oberer und unterer Rand in einer Schleife
  for(s=0; s < SPALTEN; s++) {
    einfeld[0       ][s] = '*';
    einfeld[ZEILEN-1][s] = '*';
  }

  // Linker und rechter Rand
  for(z=0; z < ZEILEN; z++) {
    einfeld[z][0        ] = '*';
    einfeld[z][SPALTEN-1] = '*';
  }

  // Innenbereich mit Leerzeichen
  for(z=1; z < ZEILEN-1; z++) {
    for(s=1; s < SPALTEN-1; s++) {
      einfeld[z][s] = ' ';
    }
  }

}

void arm(char einfeld[][SPALTEN], int z0, int s0,
    int dz, int ds) {
  int cur_z = z0;
  int cur_s = s0;
  char code = 'A';
  
  // Schleife solange wir nicht beim '*' (Rand) ankommen 
  while(einfeld[cur_z][cur_s] != '*' ) {
    einfeld[cur_z][cur_s] = code;
    code++;
    cur_z += dz;  // cur_z = cur_z + schrittweiter in Zeilenrichtung 
    cur_s += ds; 
  }

}

void stern(char einfeld[][SPALTEN], int z0, int s0) {
  arm(einfeld, z0, s0, -1, -1); // links oben
  arm(einfeld, z0, s0, -1,  0); //       oben
  arm(einfeld, z0, s0, -1,  1); 
  arm(einfeld, z0, s0,  0,  1); 
  arm(einfeld, z0, s0,  1,  1); 
  arm(einfeld, z0, s0,  1,  0); 
  arm(einfeld, z0, s0,  1, -1); 
  arm(einfeld, z0, s0,  0, -1);
}


void ausgabe(char einfeld[][SPALTEN]) {          // Da ein globales Array benutzt wurde, hat ausgabe() keine Parameter
  
  int z;
  int s;

  for(z=0; z < ZEILEN; z++) {
    for(s=0; s < SPALTEN; s++) {
      printf("%c", einfeld[z][s]);
    }
    printf("\n");
  }
}



int main(int argc, char* argv[]) {
  
  // Lokales Array :3

  char feld[ZEILEN][SPALTEN];
  
  // Parameter einlesen

  // bin/starNoArgs 4 8

  int z0;
  int s0;


  if (argc != 3){
    printf(" Usage: %s z0 s0\n", argv[0]);
    printf(" Wobei z0 = Index der Ursprungszeile\n");
    printf("       s0 = Index der Ursprungsspalte\n");
    return EXIT_FAILURE;
  }

  z0 = atoi(argv[1]);
  s0 = atoi(argv[2]);

  //z0, s0 prüfen
  if ( z0 <= 0 || z0 >= ZEILEN - 1 &&
       s0 <= 0 || s0 <= SPALTEN -1 ) {
    printf("Es muss gelten: 0 < z0 < %d-1\n", ZEILEN-1);
    printf("Es muss gelten: 0 < z0 < %d-1\n", SPALTEN-1);
 } 


  rahmen(feld);
  stern(feld, z0, s0 ); // wegen Zeilen 13+2/2 = 14 statt (13+2)/2 = 7[,5]
  ausgabe(feld);
  return EXIT_SUCCESS;    // aus <stdlib.h>

}
