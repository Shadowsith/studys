#include<stdio.h>
#include<string.h>

//======== Globale Variablen ======

char text[20];

//======== Funktionen ==========

//Alle Funktionen
int cmds () {
  printf("Alle Befehle des Programms:\n");
  printf("input_text\n");
  printf("output_text\n");
  printf("endall\n");
  return 0;
}
//Texteingabe
int input_text () {           
  printf("Gebe einen Text ein: ");
  fflush(stdout);
  fgets(text, 20, stdin);
  return 0;
}

//Textausgabe
int output_text () {
  if (strlen(text) > 0) {
  printf("%s", text);
  return 0;
  }
  else {
  printf("Kein Wert eingegeben, nutze input_text\n");
  return 1;
  }
}

//Programmende
int endall () {
    printf("Programmende");
    return 1;
}



