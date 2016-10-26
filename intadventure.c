#include <stdio.h>	//input-output
#include <stdlib.h>	//allgemeines
#include <string.h>	//string-funktionen

//Dieses Textadventure ist ein reines Fanprojekt für Studienzwecke und kann frei von jedem weiterentwickelt werden!


int main(void)
{
  char name[100]; 	//<-- Char Array = String

  printf("Gebe deinen Spielername ein: \n(Hinweis: Spielername ist ungleich Charaktername!)\n");
  scanf("%s", name);						
  //Zuweisung des Spielernamens (String)
  //Bei Strings wird anders als bei char, int etc. kein Adressoperator & gebraucht
  printf("Hallo %s, willkommen beim Textadventure \n", name);
  printf("Wähle bitte eine Charakterklasse aus \n");
  printf("Krieger (1) \nBogenschütze (2)\nMagier (3)\n");
  int playerclass;                                              //RPG-Klassendeklaration 
  char check[100];
  int warrior;
  int archer;
  int mage;
  char iclass[20];
  scanf("%[^0-9]%d", check, &playerclass); 
  // [^0-9] ist hier um zu prüfen ob die Tastatureingabe zwischen 0-9 ist
  // Buchstaben werden ignoriert!
  
  while (1) //Prüft ob die richtige Eingabe getätigt wurde
  {
   if ( playerclass == 1)					//Prüfung der RPG-KLasse
   {
    printf("Du hast die Klasse Krieger gewählt!\n");
    playerclass == warrior;					//Deklaration für Spätere RPG-Events
    strcpy( iclass, "Krieger");
    //Man kann einem String nicht einfach einen anderen Wert zuweisen!
    //Die Stringfunktion strcpy = String-Copy erfüllt diesen Zweck
    //strcpy( Stringname, "NeuerWert")!r, =^ (Stringname = "NeuerWert")!f
    break;
   }
   else
   {
     if( playerclass == 2)
     {
      printf("Du hast die Klasse Bogenschütze gewählt!\n");
      playerclass == archer;
      strcpy(iclass, "Bogenschütze"); 
      break;
     }
      else
      {
       if ( playerclass == 3)
       {
        printf("Du hast die Klasse Magier gewählt!\n");
        playerclass == mage;
	strcpy(iclass, "Magier");
        break;
       }
       else
  	 {
  	  printf("Du hast eine falsche Eingabe getätigt! \n");			//Wenn weder 1-3 eingegeben wird musst du nochmals eingeben, damit Spiel weiter geht
	  printf("Wähle erneut zwischen Krieger ('1' eingeben!) Bogenschütze ('2' eingeben!) oder Magier ('3' eingeben!) \n");  
 	  scanf("%[^0-9]%d", check,  &playerclass);
	 }
      }
     
   }
  }
  printf("%s, wähle für deinen Charakter bitte eine Rasse aus! \n", name);
  printf("Mensch (4)\nElf (5)\nZwerg (6)\nOrk (7)\n");
  int playerrace;
  int human;
  int elven;
  int dwarf;
  int ork;
  char irace[10];
  scanf("%[^0-9]%d", check,  &playerrace);
  while (1)
  {
   if ( playerrace == 4 )
   { 
    printf("Du hast dich für einen Menschen entschieden!\n");
    playerrace == human;
    strcpy(irace, "Mensch");
    break;
   }
    else 
    {
     if ( playerrace == 5 )
     {
      printf("Du hast dich für einen Elfen entschieden!\n");
      playerrace == elven;
      strcpy(irace, "Elf");
      break;
     }
     else
     {
      if ( playerrace == 6 )
      {
       printf("Du hast dich für einen Zwerg entschieden!\n");
       playerrace == dwarf;
       strcpy(irace, "Zwerg");
       break;
      }
      else
      {
       if ( playerrace == 7 )
       {
        printf("Du hast dich für einen Ork entschieden!\n");
	playerrace == ork;
	strcpy(irace, "Ork");
	break;
       }
       else
       {
        printf("Du hast eine falsche Eingabe getätigt! \n");
	printf("Wähle erneut zwischen Mensch ('4'), Elf ('5'), Zwerg ('6') oder Ork ('7')\n");
        scanf("%[^0-9]%d", check, &playerrace);
       }
      }
     }
    }
   }
   printf("%s, gebe deinem Charakter nun ein Geschlecht!\n", name);
   printf("Drücke 8 für männlich oder 9 für weiblich!\n");
   int playergender;
   int male;
   int female;
   char igend[10];
   scanf("%[^0-9]%d", check,  &playergender);
   while (1)
   { 
    if ( playergender == 8)
    {
     printf("Dein Charakter ist nun männlich!\n");
     playergender == male;
     strcpy(igend, "männlich");
     break;
    }
     else
     {
      if ( playergender == 9 )
      { 
       printf("Deine Charakterin ist nun weiblich!\n");
       playergender == female;
       strcpy(igend, "weiblich");
       break;
      }
       else
       {
        printf("Deine Eingabe war falsch!\n");
	printf("Drücke erneut die Taste 8 für einen Charakter oder 9 für eine Charakterin!\n");
	scanf("%[^0-9]%d", check,  &playergender);
       }
      }
    }
    char playername[100];
    printf("Gebe deiner/deinem Charakter/in einen Namen!\n");
    scanf("%s", playername);
    printf("Wunderbar, dein Charakter heißt nun %s!\n", playername);
    printf("Willst du dir noch einmal alle deine Daten anzeigen lassen?\n");
    printf("Für Ja drücke 0 , für Nein drücke 1\n");
    int yesno;
    scanf("%d", &yesno);
    if ( yesno = 0 )
    {
     printf("Dein Charakter heißt %s, hat die Klasse %s, ist ein %s und ist %s!\n\n", playername, iclass, irace, igend);
    }
    else {}
    
 
       

  return 0;
  
}

