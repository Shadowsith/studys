#include <stdio.h>
#include <stdlib.h>

void ** allozieren(int zeilen, int spalten){
    // Alloziere Array für Pointer
    char ** newAPA = malloc(zeilen*sizeof(char *));
    if (newAPA == NULL){
      return NULL;
    }
    // Alloziere einzeln Zeilen
    int z;
    for ( z = 0; z < zeilen; z++){
         newAPA[z] = malloc(spalten * sizeof(char));
         // fehlt noch Fehlerbehandlung
         if(newAPA[z] == NULL){
         freigeben(newAPA, z);
         return NULL;
         }
         // TODO 

    }
    // fehlt noch die Fehlerbehandlung
    return newAPA;
}

// Funktionen
void freigeben(char **feld, int zeilen){
  int z;
  for(z = 0; z< zeilen, z++){
    free(feld[z]);
  }
  // am Schluss
  free(feld)

}
void rahmen(char **einfeld, int zeilen, int spalten) {
  int s;
  int z;
  
  // Oberer und unterer Rand in einer Schleife
  for(s=0; s < spalten; s++) {
    einfeld[0       ][s] = '*';
    einfeld[zeilen-1][s] = '*';
  }

  // Linker und rechter Rand
  for(z=0; z < zeilen; z++) {
    einfeld[z][0        ] = '*';
    einfeld[z][spalten-1] = '*';
  }

  // Innenbereich mit Leerzeichen
  for(z=1; z < zeilen -1; z++) {
    for(s=1; s < spalten-1; s++) {
      einfeld[z][s] = ' ';
    }
  }

}

void arm(char **einfeld, int zeilen, int spalten, int z0, int s0,
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

void stern(char **einfeld, int zeilen, int spalten,  int z0, int s0) {
  arm(einfeld, zeilen, spalten, z0, s0, -1, -1); // links oben
  arm(einfeld, zeilen, spalten, z0, s0, -1,  0); //       oben
  arm(einfeld, zeilen, spalten, z0, s0, -1,  1); 
  arm(einfeld, zeilen, spalten, z0, s0,  0,  1); 
  arm(einfeld, zeilen, spalten, z0, s0,  1,  1); 
  arm(einfeld, zeilen, spalten, z0, s0,  1,  0); 
  arm(einfeld, zeilen, spalten, z0, s0,  1, -1); 
  arm(einfeld, zeilen, spalten, z0, s0,  0, -1);
}


void ausgabe(char **einfeld, int zeilen, int spalten) {          // Da ein globales Array benutzt wurde, hat ausgabe() keine Parameter
  
  int z;
  int s;

  for(z=0; z < zeilen; z++) {
    for(s=0; s < spalten; s++) {
      printf("%c", einfeld[z][s]);
    }
    printf("\n");
  }
}



int main(int argc, char* argv[]) {
  
  // Lokales Array :3

  char **feld;
  
  // Parameter einlesen

  // bin/starNoArgs 4 8

  int z0;
  int s0;

  int zeilen = 13;
  int spalten = 20;

  if (argc != 3){
    printf(" Usage: %s z0 s0\n", argv[0]);
    printf(" Wobei z0 = Index der Ursprungszeile\n");
    printf("       s0 = Index der Ursprungsspalte\n");
    return EXIT_FAILURE;
  }

  z0 = atoi(argv[1]);
  s0 = atoi(argv[2]);

  //z0, s0 prüfen
  if ( z0 <= 0 || z0 >= zeilen - 1 &&
       s0 <= 0 || s0 <= spalten -1 ) {
    printf("Es muss gelten: 0 < z0 < %d-1\n", zeilen-1);
    printf("Es muss gelten: 0 < z0 < %d-1\n", spalten-1);
 } 

  feld = allozieren(zeilen, spalten);
  rahmen(feld, zeilen, spalten );
  stern(feld, zeilen, spalten,  z0, s0 );
  ausgabe(feld,zeilen, spalten) ;
  freigeben(feld, zeilen);
  return EXIT_SUCCESS;    // aus <stdlib.h>

}
