#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  char name[100];

  printf("Gebe deinen Spielername ein: \n(Hinweis: Spielername ist ungleich Charaktername!)\n");
  scanf("%s", name);						//Zuweisung des Spielernamens (String)
  printf("Hallo %s, willkommen beim Testadventure \n", name);
  printf("Wähle bitte eine Charakterklasse aus \n");
  printf("Krieger (1) \nBogenschütze (2)\nMagier (3)\n");
  int playerclass;						//RPG-Klassendeklaration
  int warrior;
  int archer;
  int mage;
  scanf("%i", &playerclass);
  while ( playerclass == 1 || 2 ||  3 || playerclass != 1 || 2 || 3 ) //Prüft ob die richtige Eingabe getätigt wurde
  {
   if ( playerclass == 1)					//Prüfung der RPG-KLasse
   {
    printf("Du hast die Klasse Krieger gewählt!\n");
    playerclass == warrior;					//Deklaration für Spätere RPG-Events
    break;
   }
   else
   {
     if( playerclass == 2)
     {
      printf("Du hast die Klasse Bogenschütze gewählt!\n");
      playerclass == archer;
      break;
     }
      else
      {
       if ( playerclass == 3)
       {
        printf("Du hast die Klasse Magier gewählt!\n");
        playerclass == mage;
        break;
       }
        else
  	 {	
  	  printf("Du hast eine falsche Eingabe getätigt! \n");									//Wenn weder 1-3 eingegeben wird musst du nochmals eingeben, damit Spiel weiter geht
	  printf("Wähle erneut zwischen Krieger ('1' eingeben!) Bogenschütze ('2' eingeben!) oder Magier ('3' eingeben!) \n");  
 	  scanf("%i", &playerclass);
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
  scanf("%i", &playerrace);
  while ( playerrace == 4 || 5 || 6 || 7 || playerrace != 4 || 5 || 6 || 7)
  {
   if ( playerrace == 4 )
   { 
    printf("Du hast dich für einen Menschen entschieden!\n");
    playerrace == human;
    break;
   }
    else 
    {
     if ( playerrace == 5 )
     {
      printf("Du hast dich für einen Elfen entschieden!\n");
      playerrace == elven;
      break;
     }
     else
     {
      if ( playerrace == 6 )
      {
       printf("Du hast dich für einen Zwerg entschieden!\n");
       playerrace == dwarf;
       break;
      }
      else
      {
       if ( playerrace == 7 )
       {
        printf("Du hast dich für einen Ork entschieden!\n");
	playerrace == ork;
	break;
       }
       else
       {
        printf("Du hast eine falsche Eingabe getätigt! \n");
	printf("Wähle erneut zwischen Mensch ('4'), Elf ('5'), Zwerg ('6') oder Ork ('7')\n");
        scanf("%i", &playerrace);
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
   scanf("%i", &playergender);
   while ( playergender == 8 || 9 || playergender != 8 || 9 )
   { 
    if ( playergender == 8)
    {
     printf("Dein Charakter ist nun männlich!\n");
     playergender == male;
     break;
    }
     else
     {
      if ( playergender == 9 )
      { 
       printf("Deine Charakterin ist nun weiblich!\n");
       playergender == female;
       break;
      }
       else
       {
        printf("Deine Eingabe war falsch!\n");
	printf("Drücke erneut die Taste 8 für einen Charakter oder 9 für eine Charakterin!\n");
	scanf("%i", &playergender);
       }
      }
    }
    char playername[100];
    printf("Gebe deiner/deinem Charakter/in einen Namen!\n");
    scanf("%s", playername);
    printf("Wunderbar, dein Charakter heißt nun %s!\n", playername);
 
        

  return 0;
  
}

